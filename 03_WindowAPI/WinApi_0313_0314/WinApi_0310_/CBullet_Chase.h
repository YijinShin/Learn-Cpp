#pragma once
#include "CBullet.h"

class CBullet_Chase: public CBullet
{
private:
	CObj* m_pTarget;
	list<CObj*>* m_pMonsterList;
public:
	CBullet_Chase();
	virtual ~CBullet_Chase();

	virtual void Initialize();
	virtual int Update();

	void Set_MonsterList(list<CObj*>* _pTargetList) { m_pMonsterList = _pTargetList; };
	void FindTarget();
	void Calc_Dir();
};

