#include "stdafx.h"
#include "CPlayer.h"
#include "CBullet.h"

CPlayer::CPlayer():m_pBulletList(nullptr)
{
}

CPlayer::~CPlayer()
{
	Release();
}


//	�ַ� �帧 �Լ�  ====================================================================

void CPlayer::Initialize()
{
	// �÷��̾� ù ��ġ, ���� ���� 
	m_tInfo.fX = WINCX / 2.f;
	m_tInfo.fY = WINCY / 1.5f;
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

	return OBJ_NOEVENT;
}

int CPlayer::Late_Update()
{
	return 0;
}

void CPlayer::Render(HDC hDC)
{
	Rectangle(hDC,
		m_tRect.left,	m_tRect.top,
		m_tRect.right,	m_tRect.bottom );
}

void CPlayer::Release()
{
	// m_pBulletList ���� �ؾ���? 
}

// ��Ÿ �Լ� ====================================================================

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
		m_pBulletList->push_back(Create_Bullet(DIR_UP));
		m_pBulletList->push_back(Create_Bullet(DIR_LU));
		m_pBulletList->push_back(Create_Bullet(DIR_RU));
	}
	if (GetAsyncKeyState('W')) {
		m_pBulletList->push_back(Create_Bullet(DIR_UP));
	}
	if (GetAsyncKeyState('A')) {
		m_pBulletList->push_back(Create_Bullet(DIR_LEFT));
	}
	if (GetAsyncKeyState('S')) {
		m_pBulletList->push_back(Create_Bullet(DIR_DOWN));
	}
	if (GetAsyncKeyState('D')) {
		m_pBulletList->push_back(Create_Bullet(DIR_RIGHT));
	}
}

CObj* CPlayer::Create_Bullet(DIR _eDir)
{
	CObj* pBullet = new CBullet;
	pBullet->Initialize();
	pBullet->Set_Pos(m_tInfo.fX, m_tInfo.fY);
	dynamic_cast<CBullet*>(pBullet)->Set_Dir(_eDir);
	return pBullet;
}
