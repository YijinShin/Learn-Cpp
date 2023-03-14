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


//	�ַ� �帧 �Լ�  ====================================================================

void CPlayer::Initialize()
{
	// �÷��̾� ���� ���� 
	m_tInfo.fCX = 90.f;
	m_tInfo.fCY = 90.f;

	// �÷��̾� �ӵ�
	m_fSpeed = 10.f;
}

int CPlayer::Update()
{
	if (m_bDead) return OBJ_DEAD;
	
	// key �Է� �ޱ� 
	Key_Input();
	// m_tRect ������Ʈ: ������Ʈ �� m_tInfo�� �������� ����ϱ�
	__super::Set_Rect();


	// ���� ��ġ ������Ʈ�ϱ� 
	//Calc_Angle();	// ���� ������Ʈ
	Set_Angle_Mouse();
	//Calc_DirVector();// ������ ������� ���� ���� ������Ʈ
	Set_AimPos();	// ���� ���͸� ������� ���� ��ǥ ������Ʈ

	// ���忡�� �÷��̾� ��ǥ �Ѱ��ֱ� 
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
	// �� �׸��� 
	Ellipse(hDC,
		m_tRect.left,	m_tRect.top,
		m_tRect.right,	m_tRect.bottom );

	// ��(����) �׸��� 
	MoveToEx(hDC, m_tInfo.fX, m_tInfo.fY, NULL);
	LineTo(hDC, m_AimPos.first, m_AimPos.second);

	Ellipse(hDC,
		(float)ptMouse.x - 5.f, (float)ptMouse.y - 5.f,
		(float)ptMouse.x + 5.f, (float)ptMouse.y + 5.f);

	// ���ڿ� (�Ѿ� ����) ���
	TCHAR	szBuff[100] = L"";
	swprintf_s(szBuff, L"fx, fy: %f, %f", m_tInfo.fX, m_tInfo.fY);
	TextOut(hDC, 50, 100, szBuff, lstrlen(szBuff));
	//swprintf_s(szBuff, L"RightDirVector: %f, %f", -m_DirVector.second, m_DirVector.first);
	//TextOut(hDC, 50, 150, szBuff, lstrlen(szBuff));
}

void CPlayer::Release()
{
	// m_pBulletList ���� �ؾ���? 
}

// ��Ÿ �Լ� ====================================================================

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
	// ���콺 Ŭ���� 
	// �Ѿ� ����߻� 
}

void CPlayer::Calc_Angle()
{
	// 0~ 360 ���� �ٲٱ� 
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
	// ���� ���Ϳ� ���� �߰� 
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
	// �÷��̾� �������� �����ϴ� ���ͷ� �Ű��ֱ� 
	m_AimPos.first = m_tInfo.fX + m_DirVector.first * 100.f;
	m_AimPos.second = m_tInfo.fY + m_DirVector.second *100.f;
}
