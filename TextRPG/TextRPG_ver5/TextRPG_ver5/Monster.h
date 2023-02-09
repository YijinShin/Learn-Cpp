#pragma once
#include "Define.h"

class CMonster
{
private:
	MONSTERINFO m_monsterInfo;
public:
	CMonster();
	~CMonster();

	// init monster
	void Initialize(int _iFieldLv);

	// change state
	void SetCurrHP(int _alpaHP);

	// get state
	bool IsDead();
	int GetOffencePower();

	void DisplayInfo();
};

