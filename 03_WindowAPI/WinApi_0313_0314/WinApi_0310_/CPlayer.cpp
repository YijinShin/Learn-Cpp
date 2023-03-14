#include "stdafx.h"
#include "CPlayer.h"
#include "CBullet.h"
#include "CShield.h"
#include "AbstractFactory.h"

CPlayer::CPlayer() :m_pBulletList(nullptr), m_pShieldList(nullptr), m_AimPos(pair<float, float>(0, 0)), m_fAimLength(100.f)
{
}

CPlayer::~CPlayer()
{
	Release();
}


//	주류 흐름 함수  ====================================================================

void CPlayer::Initialize()
{
	// 플레이어 가로 세로 
	m_tInfo.fCX = 90.f;
	m_tInfo.fCY = 90.f;

	// 플레이어 속도
	m_fSpeed = 10.f;
}

int CPlayer::Update()
{
	if (m_bDead) return OBJ_DEAD;
	
	// key 입력 받기 
	Key_Input();
	// m_tRect 업데이트: 업데이트 된 m_tInfo를 기준으로 계산하기
	__super::Set_Rect();


	// 포신 위치 업데이트하기 
	//Calc_Angle();	// 각도 업데이트
	Set_Angle_Mouse();
	//Calc_DirVector();// 각도를 기반으로 방향 백터 업데이트
	Set_AimPos();	// 방향 백터를 기반으로 에임 좌표 업데이트

	// 쉴드에게 플레이어 좌표 넘겨주기 
	for (auto iter : (*m_pShieldList)) {
		dynamic_cast<CShield*>(iter)->Set_PlayerInfo(&m_tInfo);
	}
	
	return OBJ_NOEVENT;
}

int CPlayer::Late_Update()
{
	return 0;
}

void CPlayer::Render(HDC hDC)
{
	// 원 그리기 
	Ellipse(hDC,
		m_tRect.left,	m_tRect.top,
		m_tRect.right,	m_tRect.bottom );

	// 선(포신) 그리기 
	MoveToEx(hDC, m_tInfo.fX, m_tInfo.fY, NULL);
	LineTo(hDC, m_AimPos.first, m_AimPos.second);

	Ellipse(hDC,
		(float)ptMouse.x - 5.f, (float)ptMouse.y - 5.f,
		(float)ptMouse.x + 5.f, (float)ptMouse.y + 5.f);

	// 문자열 (총알 개수) 출력
	TCHAR	szBuff[100] = L"";
	swprintf_s(szBuff, L"fx, fy: %f, %f", m_tInfo.fX, m_tInfo.fY);
	TextOut(hDC, 50, 100, szBuff, lstrlen(szBuff));
	//swprintf_s(szBuff, L"RightDirVector: %f, %f", -m_DirVector.second, m_DirVector.first);
	//TextOut(hDC, 50, 150, szBuff, lstrlen(szBuff));
}

void CPlayer::Release()
{
	// m_pBulletList 어케 해야함? 
}

// 기타 함수 ====================================================================

void CPlayer::Key_Input()
{
	if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W')) {
		m_tInfo.fX += m_DirVector.first*m_fSpeed;
		m_tInfo.fY += m_DirVector.second * m_fSpeed;
	}
	if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S')) {
		m_tInfo.fX -= m_DirVector.first * m_fSpeed;
		m_tInfo.fY -= m_DirVector.second * m_fSpeed;
	}
	if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A')) {
		m_tInfo.fX -= m_RightDirVector.first * m_fSpeed;
		m_tInfo.fY -= m_RightDirVector.second * m_fSpeed;
	}
	if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D')) {
		m_tInfo.fX += m_RightDirVector.first * m_fSpeed;
		m_tInfo.fY += m_RightDirVector.second * m_fSpeed;
	}
	/*
	if (GetAsyncKeyState(VK_SPACE) || GetAsyncKeyState('W')) {
		
	}
	if (GetAsyncKeyState('W')) {
		//m_pBulletList->push_back(CAbstractFactory<CBullet>::Create(m_tInfo.fX, m_tInfo.fY, DIR_UP, m_DirVector));
	}
	if (GetAsyncKeyState('A')) {
		//m_pBulletList->push_back(CAbstractFactory<CBullet>::Create(m_tInfo.fX, m_tInfo.fY, DIR_LEFT, m_DirVector));
	}
	if (GetAsyncKeyState('S')) {
		//m_pBulletList->push_back(CAbstractFactory<CBullet>::Create(m_tInfo.fX, m_tInfo.fY, DIR_DOWN, m_DirVector));
	}
	if (GetAsyncKeyState('D')) {
		//m_pBulletList->push_back(CAbstractFactory<CBullet>::Create(m_tInfo.fX, m_tInfo.fY, DIR_RIGHT, m_DirVector));
	}
	*/
	if (GetAsyncKeyState('Q')) {
		m_pBulletList->push_back(CAbstractFactory<CBullet>::Create(m_tInfo.fX, m_tInfo.fY, DIR_UP, m_DirVector));
		//m_fAngle += 5.f;
	}
	if (GetAsyncKeyState('E')) {
		m_pBulletList->push_back(CAbstractFactory<CBullet>::Create(m_tInfo.fX, m_tInfo.fY, DIR_UP, m_DirVector));
		m_pBulletList->push_back(CAbstractFactory<CBullet>::Create(m_tInfo.fX, m_tInfo.fY, DIR_LU, m_DirVector));
		m_pBulletList->push_back(CAbstractFactory<CBullet>::Create(m_tInfo.fX, m_tInfo.fY, DIR_RU, m_DirVector));
		//m_fAngle -= 5.f;
	}
	if (GetAsyncKeyState('R')) {
		m_pShieldList->push_back(CAbstractFactory<CShield>::Create(m_tInfo.fX, m_tInfo.fY));
	}
	if (GetAsyncKeyState('T')) {
		Create_Shield();
	}
}

void CPlayer::Mouse_Input()
{
	// 마우스 클릭시 
	// 총알 정면발사 
}

void CPlayer::Calc_Angle()
{
	// 0~ 360 으로 바꾸기 
	if (m_fAngle >= 360.f) m_fAngle -= 360.f;
	if (m_fAngle <= 0.f) m_fAngle += 360.f;
}

void CPlayer::Set_Angle_Mouse()
{
	GetCursorPos(&ptMouse);
	ScreenToClient(g_hWnd, &ptMouse);
	
	pair<float, float> vector;
	vector.first = ptMouse.x - m_tInfo.fX;
	vector.second = ptMouse.y - m_tInfo.fY;
	float h = sqrt( pow(vector.first,2) + pow(vector.second,2) );

	m_DirVector.first = vector.first / h;
	m_DirVector.second = vector.second / h;
}

void CPlayer::Calc_DirVector()
{
	// 원점 백터에 각도 추가 
	m_DirVector.first = (float)sin(m_fAngle * (PI / 180.f));
	m_DirVector.second = (float)cos(m_fAngle * (PI / 180.f));

	m_RightDirVector.first = -m_DirVector.second;
	m_RightDirVector.second = m_DirVector.first;
}

void CPlayer::Create_Shield()
{
	m_pShieldList->push_back(CAbstractFactory<CShield>::Create(m_tInfo.fX, m_tInfo.fY));
	dynamic_cast<CShield*>(m_pShieldList->back())->Set_PlayerInfo(&m_tInfo);
}

void CPlayer::Set_AimPos()
{
	// 플레이어 원점에서 시작하는 백터로 옮겨주기 
	m_AimPos.first = m_tInfo.fX + m_DirVector.first * 100.f;
	m_AimPos.second = m_tInfo.fY + m_DirVector.second *100.f;
}
