#include "stdafx.h"
#include "CObj.h"

CObj::CObj(): m_iHP(1), m_fSpeed(0.f)
{
	ZeroMemory(&m_tInfo, sizeof(INFO));
	ZeroMemory(&m_tRect, sizeof(RECT));
}

CObj::~CObj()
{
}

void CObj::Update_Rect()
{
	m_tRect.left	= (LONG)(m_tInfo.fX - (m_tInfo.fCX / 2.f));
	m_tRect.right	= (LONG)(m_tInfo.fX + (m_tInfo.fCX / 2.f));
	m_tRect.top		= (LONG)(m_tInfo.fY - (m_tInfo.fCY / 2.f));
	m_tRect.bottom	= (LONG)(m_tInfo.fY + (m_tInfo.fCY / 2.f));
}

void CObj::LookAt(POINT ptDistPos)
{
	CVector2 vector;
	vector.x = (float)ptDistPos.x - m_tInfo.fX;
	vector.y = (float)ptDistPos.y - m_tInfo.fY;
	vector.Normalize();
	m_tInfo.Dir = vector;
}

