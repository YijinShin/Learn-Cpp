#include "stdafx.h"
#include "Obj.h"


CObj::CObj()
{
	ZeroMemory(&m_tInfo, sizeof(INFO));
	ZeroMemory(&m_tRect, sizeof(RECT));

	m_fSpeed = 0.f;
	m_fRotateSpeed = 0.f;
	m_fDegree = 0.f;
	m_isDead = false;

	m_tInfo.Dir.x = 0.f;
	m_tInfo.Dir.y = 1.f;
}


CObj::~CObj()
{
}

void CObj::Update_Rect(void)
{
	m_tRect.left	= long(m_tInfo.fX - (m_tInfo.fCX / 2.f));
	m_tRect.top		= long(m_tInfo.fY - (m_tInfo.fCY / 2.f));
	m_tRect.right	= long(m_tInfo.fX + (m_tInfo.fCX / 2.f));
	m_tRect.bottom	= long(m_tInfo.fY + (m_tInfo.fCY / 2.f));
}
