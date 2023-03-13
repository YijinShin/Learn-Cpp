#include "stdafx.h"
#include "CMonster_type1.h"

CMonster_type1::CMonster_type1()
{
}

CMonster_type1::~CMonster_type1()
{
}


void CMonster_type1::CollisionCheck(CObj* targetObj)
{
	RECT	tResult;
	RECT	tTargetRect = targetObj->Get_Rect();
	float	fMaxDist = (m_tInfo.fX / 2.f) + (targetObj->Get_Info().fX / 2.f);
	float	fDist = ( sqrt(pow(abs( m_tInfo.fX - targetObj->Get_Info().fX), 2 )
						+ pow(abs(m_tInfo.fY - targetObj->Get_Info().fY), 2)) );
	
	// �浹 �Լ��� üũ
	if (IntersectRect(&tResult, &m_tRect, &tTargetRect)) {
		m_bIsDead = true;
		// �������� �Ÿ� üũ
		if (fMaxDist < fDist) {
			m_bIsDead = true;
		}
	}
}

void CMonster_type1::Render(HDC hDC)
{
	Ellipse(hDC,
		m_tRect.left, m_tRect.top,
		m_tRect.right, m_tRect.bottom);
}


