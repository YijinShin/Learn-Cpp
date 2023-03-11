#include "stdafx.h"
#include "CObj.h"

CObj::CObj() : m_fSpeed(0.f), m_bDead(false), m_eDir(DIR_UP)
{
	ZeroMemory(&m_tRect, sizeof(RECT));
	ZeroMemory(&m_tInfo, sizeof(INFO));
}

CObj::~CObj()
{
}

bool CObj::CheckCrash(list<CObj*> targetObjList)
{
	RECT resultRc;

	for (auto iter : targetObjList) {
		RECT targetRect = iter->GetRect();
		if (IntersectRect(&resultRc, &m_tRect, &targetRect)) {
			m_bDead = true;
			iter->Set_Dead(true);
		}
	}

	return false;
}

void CObj::Set_Rect()
{
	m_tRect.left = m_tInfo.fX - (m_tInfo.fCX / 2.f);
	m_tRect.right = m_tInfo.fX + (m_tInfo.fCX / 2.f);
	m_tRect.top = m_tInfo.fY - (m_tInfo.fCY / 2.f);
	m_tRect.bottom = m_tInfo.fY + (m_tInfo.fCY / 2.f);
}
