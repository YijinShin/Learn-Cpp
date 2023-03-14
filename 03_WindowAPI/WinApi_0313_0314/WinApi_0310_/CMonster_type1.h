#pragma once
#include "CMonster.h"

class CMonster_type1: public CMonster
{
private:
	INFO m_tPlayerInfo;
	list<CObj*>* m_pTargetList;
	
	int m_iTimer;

public:
	CMonster_type1();
	virtual ~CMonster_type1();

	virtual void Initialize() override;
	virtual int Update() override;
	void Render(HDC hDC);
	virtual void Calc_Dir();

	void Set_TargetList(list<CObj*>* _pTargetList) { m_pTargetList = _pTargetList; }
	void Set_PlayerInfo(INFO _tPlayerInfo) { m_tPlayerInfo = _tPlayerInfo; }
};

