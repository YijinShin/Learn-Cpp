#include "stdafx.h"
#include "CPlayer.h"

CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 10.f;

	m_fSpeed = 10.f;
}

int CPlayer::Update()
{
	if (m_bIsDead) return OBJ_DEAD;

	Key_Input();

	__super::Set_Rect();
	return OBJ_NOEVETN;
}

void CPlayer::Late_Update()
{
}

void CPlayer::Render(HDC hDC)
{
	Rectangle(hDC,
		m_tRect.left, m_tRect.top,
		m_tRect.right, m_tRect.bottom);
}

void CPlayer::Release()
{
}

void CPlayer::Key_Input()
{
	if (GetAsyncKeyState(VK_LEFT) || 
		GetAsyncKeyState('A')) {
		if(m_tRect.left >= 0 ) m_tInfo.fX -= m_fSpeed;
	}
	if (GetAsyncKeyState(VK_RIGHT) ||
		GetAsyncKeyState('D')) {
		if (m_tRect.right <= WINCX) m_tInfo.fX += m_fSpeed;
	}
}
