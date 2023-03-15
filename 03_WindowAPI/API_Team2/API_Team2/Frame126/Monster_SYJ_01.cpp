#include "stdafx.h"
#include "Monster_SYJ_01.h"
#include <time.h>

int CMonster_SYJ_01::Get_RandBulletTime()
{
	int iRandTime(0);
	
	srand(time(NULL));

	return  rand() % 50;
}

CMonster_SYJ_01::CMonster_SYJ_01() : m_fChaseTimer(0.f), m_iRandTime(0)
{
	m_iRandTime = Get_RandBulletTime();
}

CMonster_SYJ_01::~CMonster_SYJ_01()
{

}

int CMonster_SYJ_01::Update()
{	
	if (m_isDead) return OBJ_DEAD;

	// 중점 계산
	Calc_Dir_Player();

	// RECT 갱신
	__super::Update_Rect();

	// 일정 시간마다 총알 생성
	m_iBulletTimer++;
	if (m_iBulletTimer >= m_iRandTime ) {
		Create_Bullet();

		m_iBulletTimer = 0;
		m_iRandTime = Get_RandBulletTime();
	}

	// 일정 시간마다 플레이어 INFO가져오기 
	m_fChaseTimer++;
	if (m_fChaseTimer >= 40) {
		m_tTargetInfo = ((*m_pTargetList).front())->Get_Info();
		m_fChaseTimer = 0;
	}

	return OBJ_NOEVENT;
}

void CMonster_SYJ_01::Calc_Dir_Player()
{
	if (m_tInfo.fX != m_tTargetInfo.fX || m_tInfo.fY != m_tTargetInfo.fY) {
		m_tInfo.Dir = LookAt(m_tInfo, m_tTargetInfo);
		m_tInfo.Dir = m_tInfo.Dir* m_fSpeed;
		float fH(0.f);
	}
}

