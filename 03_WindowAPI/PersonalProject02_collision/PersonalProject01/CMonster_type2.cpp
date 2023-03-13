#include "stdafx.h"
#include "CMonster_type2.h"

CMonster_type2::CMonster_type2()
{
}

CMonster_type2::~CMonster_type2()
{
}

void CMonster_type2::Render(HDC hDC)
{
	Rectangle(hDC,
		m_tRect.left, m_tRect.top,
		m_tRect.right, m_tRect.bottom);
}

void CMonster_type2::CollisionCheck(CObj* targetObj)
{
	RECT	tResult;
	RECT	tTargetRect = targetObj->Get_Rect();
	INFO	tTargetInfo = targetObj->Get_Info();
	float	fMaxDist = (m_tInfo.fX / 2.f) + (sqrt( pow(tTargetInfo.fCX/2.f, 2) + pow(tTargetInfo.fCY / 2.f, 2)));
	float	fDist = (sqrt(pow(abs(m_tInfo.fX - targetObj->Get_Info().fX), 2)
		+ pow(abs(m_tInfo.fY - targetObj->Get_Info().fY), 2)));

	// 충돌 함수로 체크
	if (IntersectRect(&tResult, &m_tRect, &tTargetRect)) {
		m_bIsDead = true;
		// 중점간의 거리 체크
		if (fMaxDist < fDist) {
			m_bIsDead = true;
		}
	}
}
