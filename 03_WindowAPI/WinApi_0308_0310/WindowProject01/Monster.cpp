#include "stdafx.h"
#include "Monster.h"

CMonster::CMonster()
{
	ZeroMemory(&m_tFence, sizeof(RECT));
}

CMonster::~CMonster()
{
}

void CMonster::Initialize()
{
	// 플레이어의 위치, 가로 세로 길이 세팅
	m_tInfo = { 130,	130,	70.f,	70.f };
	// 몬스터의 속도 세팅 
	m_fSpeed = 5.f;
}

int CMonster::Update()
{
	if (m_eDir == DIR_LEFT) {
		if ((m_tInfo.fX - m_tInfo.fCX / 2) <= m_tFence.left) m_eDir = DIR_RIGHT;
		else m_tInfo.fX -= m_fSpeed;
	}
	else if (m_eDir == DIR_RIGHT) {
		if ((m_tInfo.fX + m_tInfo.fCX / 2) >= m_tFence.right) m_eDir = DIR_LEFT;
		else m_tInfo.fX += m_fSpeed;
	}
	__super::Update_Rect();

	return 0;
}

void CMonster::Render(HDC hDC)
{
	Rectangle(hDC,
		m_tRect.left, m_tRect.top,
		m_tRect.right, m_tRect.bottom);
}

void CMonster::Release()
{
}

void CMonster::Set_Fence(RECT _tFence)
{
	m_tFence = _tFence; 

	Set_Pos(m_tFence.left + m_tInfo.fCX, m_tFence.top + m_tInfo.fCY);
}
