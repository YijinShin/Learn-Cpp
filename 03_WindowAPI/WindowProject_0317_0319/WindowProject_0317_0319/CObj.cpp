#include "stdafx.h"
#include "CObj.h"

CObj::CObj()
{
}

CObj::~CObj()
{
}

void CObj::Set_Rect()
{
	m_tRect.left = m_tInfo.fX - (m_tInfo.fCX / 2.f);
	m_tRect.right = m_tInfo.fX + (m_tInfo.fCX / 2.f);
	m_tRect.top = m_tInfo.fY - (m_tInfo.fCY / 2.f);
	m_tRect.bottom = m_tInfo.fY + (m_tInfo.fCY / 2.f);
}

