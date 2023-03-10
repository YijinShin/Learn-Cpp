#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"

CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
}

void CPlayer::Initialize()
{
	// �÷��̾��� ��ġ, ���� ���� ���� ����
	m_tInfo = { WINCX / 2.f,	WINCY / 2.f,	100.f,	100.f };
	// �÷��̾��� �ӵ� ���� 
	m_fSpeed = 10.f;
}

int CPlayer::Update()
{
	// Ű �Է� ó�� 
	Key_Input();
	// �簢�� ��ǥ(m_tRect) ������Ʈ�ϱ� 
	__super::Update_Rect();
	return 0;
}

void CPlayer::Render(HDC hDC)
{
	// �÷��̾� �׸��� 
	Rectangle( hDC, 
		m_tRect.left, m_tRect.top,
		m_tRect.right, m_tRect.bottom);
}

void CPlayer::Release()
{
}

void CPlayer::Key_Input()
{
	/* ��ġ�� �ٲٴ� Ű��� m_tInfo�� ������Ʈ�ϱ�
	  �� ������ �������� ( m_tRect�� __super::Update_Rect()���� ������.)*/
	if (GetAsyncKeyState(VK_UP))		// ��
		m_tInfo.fY -= m_fSpeed;
	if (GetAsyncKeyState(VK_DOWN))		// ��
		m_tInfo.fY += m_fSpeed;
	if (GetAsyncKeyState(VK_LEFT))		// ��
		m_tInfo.fX -= m_fSpeed;
	if (GetAsyncKeyState(VK_RIGHT))		// ��
		m_tInfo.fX += m_fSpeed;
	if (GetAsyncKeyState('W'))			// W
		m_pBulletList->push_back(Create_Bullet(DIR_UP));
	if (GetAsyncKeyState('A'))			// A
		m_pBulletList->push_back(Create_Bullet(DIR_LEFT));
	if (GetAsyncKeyState('S'))			// S
		m_pBulletList->push_back(Create_Bullet(DIR_DOWN));
	if (GetAsyncKeyState('D'))			// D
		m_pBulletList->push_back(Create_Bullet(DIR_RIGHT));
	if (GetAsyncKeyState(VK_SPACE))		// �����̽�
	{ 
		m_pBulletList->push_back(Create_Bullet(DIR_LU));
		m_pBulletList->push_back(Create_Bullet(DIR_RU));
		m_pBulletList->push_back(Create_Bullet(DIR_UP));
	}
}

CObj* CPlayer::Create_Bullet(DIRECTION _eDir)
{
	CObj* pBullet = new CBullet;
	dynamic_cast<CBullet*>(pBullet)->Set_Pos(m_tInfo.fX, m_tInfo.fY);	// �Ѿ� ���� ��ġ ����
	pBullet->Initialize();
	pBullet->Set_Dir(_eDir);	// �Ѿ� ���� ����
	return pBullet;
}
