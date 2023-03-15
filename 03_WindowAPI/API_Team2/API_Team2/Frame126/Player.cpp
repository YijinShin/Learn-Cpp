#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"
#include "AbstractFactory.h"

CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	m_tInfo.fX = 400.f;		// ���� X
	m_tInfo.fY = 300.f;		// ���� Y

	m_tInfo.fCX = 100.f;	// �÷��̾� ���� ������
	m_tInfo.fCY = 100.f;	// �÷��̾� ���� ������

	m_tInfo.Dir = Vector2(1.f, 0.f);

	m_fSpeed = 10.f;
	m_fRotateSpeed = 2.f;
	m_fDegree = 0.f;
}

int CPlayer::Update()
{
	if (m_isDead) return OBJ_DEAD;
	
	Key_Input();

	if (m_fDegree >= 360.f || m_fDegree <= -360.f)
		m_fDegree = 0.f;
	m_tInfo.Dir.Rotate(m_fDegree);


	// ���ʿ��� ���� �Ǵ� �������� ��ȭ�� ���� ������ Update_Rect�Լ��� ȣ��
	Update_Rect();

	return OBJ_NOEVENT;
}

void CPlayer::Late_Update()
{
}

void CPlayer::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

	MoveToEx(hDC, m_tInfo.fX, m_tInfo.fY, nullptr);
	LineTo(hDC, m_tInfo.fX + m_tInfo.Dir.x * 100, m_tInfo.fY + m_tInfo.Dir.y * 100);
}

void CPlayer::Release(void)
{
	
}

void CPlayer::Create_Bullet()
{
	m_pBulletList->push_back(CAbstractFactory<CBullet>::Create(m_tInfo));
}

void CPlayer::Key_Input(void)
{
	if (GetAsyncKeyState(VK_LEFT))
		m_tInfo.fX -= m_fSpeed;

	if (GetAsyncKeyState(VK_RIGHT))
		m_tInfo.fX += m_fSpeed;

	if (GetAsyncKeyState(VK_UP))
		m_tInfo.fY -= m_fSpeed;

	if (GetAsyncKeyState(VK_DOWN))
		m_tInfo.fY += m_fSpeed;

	if (GetAsyncKeyState('Q'))
		m_fDegree -= m_fRotateSpeed;

	if (GetAsyncKeyState('E'))
		m_fDegree += m_fRotateSpeed;
	if (GetAsyncKeyState(VK_SPACE)) {
		Create_Bullet();
	}
}
