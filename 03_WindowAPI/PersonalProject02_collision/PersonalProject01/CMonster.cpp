#include "stdafx.h"
#include "CMonster.h"

#include "Include.h"

CMonster::CMonster():m_eType(MON_1)
{
}

CMonster::~CMonster()
{
	Release();
}

void CMonster::Initialize()
{
	m_tInfo.fCX = 90.f;
	m_tInfo.fCY = 90.f;

	m_fSpeed = 5.f;
}

int CMonster::Update()
{
	if (m_bIsDead) return OBJ_DEAD;
	__super::Set_Rect();
	return OBJ_NOEVETN;
}

void CMonster::Late_Update()
{
}

void CMonster::Render(HDC hDC)
{
	Ellipse(hDC,
		m_tRect.left, m_tRect.top,
		m_tRect.right, m_tRect.bottom);
}

void CMonster::Release()
{
}

