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
	Set_Angle();	// ���� ������Ʈ
	Set_DirVector();// ������ ������� ���� ���� ������Ʈ
	Set_AimPos();	// ���� ���͸� ������� ���� ��ǥ ������Ʈ


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
}

void CPlayer::Release()
{
	// m_pBulletList ���� �ؾ���? 
}

// ��Ÿ �Լ� ====================================================================

void CPlayer::Key_Input()
{
	if (GetAsyncKeyState(VK_UP)) {
		//m_tInfo.fY -= m_fSpeed;
		m_tInfo.fX += m_DirVector.first*m_fSpeed;
		m_tInfo.fY += m_DirVector.second * m_fSpeed;
	}
	if (GetAsyncKeyState(VK_DOWN)) {
		//m_tInfo.fY += m_fSpeed;
		m_tInfo.fX -= m_DirVector.first * m_fSpeed;
		m_tInfo.fY -= m_DirVector.second * m_fSpeed;
	}
	if (GetAsyncKeyState(VK_LEFT)) {
		if ( 0<= m_fAngle <= 180) {
			m_tInfo.fX -= m_DirVector.first * m_fSpeed;
			m_tInfo.fY += m_DirVector.second * m_fSpeed;
		}
		else {
			m_tInfo.fX += m_DirVector.first * m_fSpeed;
			m_tInfo.fY += m_DirVector.second * m_fSpeed;
		}
		
	}
	if (GetAsyncKeyState(VK_RIGHT)) {
		if (0 <= m_fAngle <= 180) {
			m_tInfo.fX += m_DirVector.first * m_fSpeed;
			m_tInfo.fY -= m_DirVector.second * m_fSpeed;
		}
		else {
			m_tInfo.fX -= m_DirVector.first * m_fSpeed;
			m_tInfo.fY -= m_DirVector.second * m_fSpeed;
		}
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
		m_fAngle += 5.f;
		//if (m_fAngle <= 0.f) m_fAngle += 360.f;
	}
	if (GetAsyncKeyState('E')) {
		m_fAngle -= 5.f;
		//if (m_fAngle >= 360.f) m_fAngle -= 360.f;
	}
}

void CPlayer::Set_Angle()
{
	/*
	GetCursorPos(&ptMouse);
	ScreenToClient(g_hWnd, &ptMouse);

	float fXDist = abs((float)ptMouse.x - m_tInfo.fX);
	float fYDist = abs((float)ptMouse.y - m_tInfo.fY);

	m_fAngle = RadianToDegree(atan2(fYDist, fXDist));
	*/
	// 0~ 360 ���� �ٲٱ� 
	if (m_fAngle >= 360.f) m_fAngle -= 360.f;
	if (m_fAngle <= 0.f) m_fAngle += 360.f;
}

float  CPlayer::RadianToDegree(float fRadian) {
	return (180.f/ PI) * fRadian;
}

float  CPlayer::DegreeToRadian(float fDegree) {
	return (PI / 180.f) * fDegree;
}

void CPlayer::Set_DirVector()
{
	// ���� ���Ϳ� ���� �߰� 
	m_DirVector.first = (float)sin(m_fAngle * (PI / 180.f));
	m_DirVector.second = (float)cos(m_fAngle * (PI / 180.f));
}

void CPlayer::Set_AimPos()
{
	// �÷��̾� �������� �����ϴ� ���ͷ� �Ű��ֱ� 
	m_AimPos.first = m_tInfo.fX + m_DirVector.first * 100.f;
	m_AimPos.second = m_tInfo.fY + m_DirVector.second *100.f;
}
