#include "stdafx.h"
#include "CBullet_Chase.h"

CBullet_Chase::CBullet_Chase() : m_pTarget(nullptr), m_pMonsterList(nullptr)
{
}

CBullet_Chase::~CBullet_Chase()
{
}

void CBullet_Chase::Initialize()
{
	// 총알 지름 설정
	m_tInfo.fCX = 25.f;
	m_tInfo.fCY = 25.f;
	// 총알 속도 설정
	m_fSpeed = 10.f;
	// 총알 타겟 설정 
	//FindTarget();
}

int CBullet_Chase::Update()
{

	if (m_bDead) return OBJ_DEAD;

	// 플레이어의 중점과 - 몬스터의 중점을 기반으로 다음 몬스터 중점 구하기 
	Calc_Dir();
	// rect 업데이트
	__super::Set_Rect();
	return OBJ_NOEVENT;
}



void CBullet_Chase::FindTarget()
{
	pair<float, CObj*> currTargetInfo;
	currTargetInfo.first = sqrt( pow(WINCX/2.f, 2) + pow(WINCY / 2.f, 2));
	
	for (auto iter : *m_pMonsterList) {
		float fDist = sqrt(pow(m_tInfo.fX - iter->GetInfo().fX, 2) + pow(m_tInfo.fY - iter->GetInfo().fY, 2));

		if (fDist < currTargetInfo.first) {
			currTargetInfo.first = fDist;
			currTargetInfo.second = iter;
		}
	}
	m_pTarget = currTargetInfo.second;
}

void CBullet_Chase::Calc_Dir()
{
	if (m_tInfo.fX != m_pTarget->GetInfo().fX || m_tInfo.fY != m_pTarget->GetInfo().fY) {

		//POINT vector{};
		pair<float, float> vector;
		float fH(0.f);

		vector.first = (m_pTarget->GetInfo().fX - m_tInfo.fX);
		vector.second = (m_pTarget->GetInfo().fY - m_tInfo.fY);


		fH = sqrt(pow(vector.first, 2) + pow(vector.second, 2));

		vector.first /= fH;
		vector.second /= fH;

		m_tInfo.fX += vector.first * m_fSpeed;
		m_tInfo.fY += vector.second * m_fSpeed;
	}
}


