#include "stdafx.h"
#include "Player_SYJ.h"
#include "Define.cpp"


CPlayer_SYJ::CPlayer_SYJ()
{
}

CPlayer_SYJ::~CPlayer_SYJ()
{
}

int CPlayer_SYJ::Update()
{
	if (m_isDead) return OBJ_DEAD;

	Key_Input();

	// 마우스 방향으로 DirVector 바꾸기 
	Calc_Dir_Mouse();
	
	__super::Update_Rect();

	return OBJ_NOEVENT;

}

void CPlayer_SYJ::Calc_Dir_Mouse()
{
	POINT	ptMouse{};

	GetCursorPos(&ptMouse);
	ScreenToClient(g_hWnd, &ptMouse);

	m_tInfo.Dir = LookAt( m_tInfo, ptMouse);
	m_tInfo.Dir = m_tInfo.Dir * m_fSpeed;
}

void CPlayer_SYJ::Key_Input(void)
{
	if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W')) {
		m_tInfo.fX += m_tInfo.Dir.x * m_fSpeed;
		m_tInfo.fY += m_tInfo.Dir.y * m_fSpeed;
	}
	if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S')) {
		m_tInfo.fX -= m_tInfo.Dir.x * m_fSpeed;
		m_tInfo.fY -= m_tInfo.Dir.y * m_fSpeed;
	}
	if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A')) {
		m_tInfo.fX += m_tInfo.Dir.y * m_fSpeed;
		m_tInfo.fY -= m_tInfo.Dir.x * m_fSpeed;
	}
	if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D')) {
		m_tInfo.fX -= m_tInfo.Dir.y * m_fSpeed;
		m_tInfo.fY += m_tInfo.Dir.x * m_fSpeed;
	}

	if (GetAsyncKeyState('Q'))
		m_fDegree -= m_fRotateSpeed;

	if (GetAsyncKeyState('E'))
		m_fDegree += m_fRotateSpeed;

	if (GetAsyncKeyState(VK_LBUTTON ) || GetAsyncKeyState(VK_SPACE)) {
		Create_Bullet();
	}
}
