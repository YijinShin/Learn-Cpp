#include "stdafx.h"
#include "CPlayer.h"
#include "CBullet.h"
#include "AbstractFactory.h"

CPlayer::CPlayer() :m_pBulletList(nullptr), m_AimPos(pair<float, float>(0, 0)), m_fAimLength(100.f)
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
	//Set_Angle();
	//Set_AimPos();
	Set_AimPos3();

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
}

void CPlayer::Release()
{
	// m_pBulletList 어케 해야함? 
}

// 기타 함수 ====================================================================

void CPlayer::Key_Input()
{
	if (GetAsyncKeyState(VK_UP)) {
		m_tInfo.fY -= m_fSpeed;
	}
	if (GetAsyncKeyState(VK_DOWN)) {
		m_tInfo.fY += m_fSpeed;
	}
	if (GetAsyncKeyState(VK_LEFT)) {
		m_tInfo.fX -= m_fSpeed;
	}
	if (GetAsyncKeyState(VK_RIGHT)) {
		m_tInfo.fX += m_fSpeed;
	}
	if (GetAsyncKeyState(VK_SPACE)) {
		m_pBulletList->push_back(CAbstractFactory<CBullet>::Create(m_tInfo.fX, m_tInfo.fY, DIR_UP));
		m_pBulletList->push_back(CAbstractFactory<CBullet>::Create(m_tInfo.fX, m_tInfo.fY, DIR_LU));
		m_pBulletList->push_back(CAbstractFactory<CBullet>::Create(m_tInfo.fX, m_tInfo.fY, DIR_RU));
	}
	if (GetAsyncKeyState('W')) {
		m_pBulletList->push_back(CAbstractFactory<CBullet>::Create(m_tInfo.fX, m_tInfo.fY, DIR_UP));
	}
	if (GetAsyncKeyState('A')) {
		m_pBulletList->push_back(CAbstractFactory<CBullet>::Create(m_tInfo.fX, m_tInfo.fY, DIR_LEFT));
	}
	if (GetAsyncKeyState('S')) {
		m_pBulletList->push_back(CAbstractFactory<CBullet>::Create(m_tInfo.fX, m_tInfo.fY, DIR_DOWN));
	}
	if (GetAsyncKeyState('D')) {
		m_pBulletList->push_back(CAbstractFactory<CBullet>::Create(m_tInfo.fX, m_tInfo.fY, DIR_RIGHT));
	}
	if (GetAsyncKeyState('Q')) {
		m_fAngle += 5;
		if (m_fAngle <= 0) m_fAngle += 360;
	}
	if (GetAsyncKeyState('E')) {
		m_fAngle -= 5;
		if (m_fAngle >= 360) m_fAngle -= 360;
	}
}

void CPlayer::Set_Angle()
{
	GetCursorPos(&ptMouse);
	ScreenToClient(g_hWnd, &ptMouse);

	float fXDist = abs((float)ptMouse.x - m_tInfo.fX);
	float fYDist = abs((float)ptMouse.y - m_tInfo.fY);

	m_fAngle = RadianToDegree(atan2(fYDist, fXDist));

	if (  ) {

	}
}

float  CPlayer::RadianToDegree(float fRadian) {
	return (180.f/ PI) * fRadian;
}

float  CPlayer::DegreeToRadian(float fDegree) {
	return (PI / 180.f) * fDegree;
}


void CPlayer::Set_AimPos()
{
	GetCursorPos(&ptMouse);
	ScreenToClient(g_hWnd, &ptMouse);
	
	// 원점 백터에 각도 추가 
	pair<float, float > vector;
	vector.second = (float)cos(m_fAngle * (PI / 180.f));
	vector.first = (float)sin(m_fAngle * (PI / 180.f));

	// 길이 고치기 
	vector.first *= 100.f;
	vector.second *= 100.f;

	// 플레이어 원점에서 시작하는 백터로 옮겨주기 
	m_AimPos.first = m_tInfo.fX + vector.first;
	m_AimPos.second = m_tInfo.fY + vector.second;
}
