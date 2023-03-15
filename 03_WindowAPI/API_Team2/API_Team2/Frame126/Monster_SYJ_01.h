#pragma once
#include "Monster.h"

class CMonster_SYJ_01: public CMonster
{
private:
	list<CObj*>* m_pTargetList;

	INFO	m_tTargetInfo;
	float	m_fChaseTimer;
	int		m_iRandTime;

	int Get_RandBulletTime();

public:
	CMonster_SYJ_01();
	virtual ~CMonster_SYJ_01();

	virtual int Update();

	void Get_TargetListkist(list<CObj*>* _pTargetList) { m_pTargetList = _pTargetList; }
	void Get_TargetPos(INFO _tTargetInfo) { m_tTargetInfo = _tTargetInfo; }

	void Calc_Dir_Player();
};

