#include "stdafx.h"
#include "Obj.h"

CObj::CObj(): m_fSpeed(0.f), m_eDir(DIR_END)
{
	ZeroMemory(&m_tInfo, sizeof(INFO));
	ZeroMemory(&m_tRect, sizeof(RECT));
}

CObj::~CObj()
{
}

void CObj::Update_Rect()
{
	// 키 입력이든 뭐든 해서 m_tInfo에 새로운 값이 들어갔으면 => 그걸 기반으로 Rect를 그릴 때 쓸 좌표를 계산함
	m_tRect.left	= LONG(m_tInfo.fX - (m_tInfo.fCX * 0.5f));
	m_tRect.top		= LONG(m_tInfo.fY - (m_tInfo.fCY * 0.5f));
	m_tRect.right	= LONG(m_tInfo.fX + (m_tInfo.fCX * 0.5f));
	m_tRect.bottom	= LONG(m_tInfo.fY + (m_tInfo.fCY * 0.5f));
}

void CObj::Set_Fence(RECT _tFence)
{
	m_tFence = _tFence;
	Set_Pos(m_tFence.left + m_tInfo.fCX, m_tFence.top + m_tInfo.fCY);
}