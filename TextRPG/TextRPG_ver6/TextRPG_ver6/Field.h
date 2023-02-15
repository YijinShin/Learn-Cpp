#pragma once
#include "Player.h"
#include "Monster.h"

class CField
{
private:
	CMonster* m_cpMonster;
	CPlayer* m_cpPlayer;
public:
	CField();
	~CField();

	void Initialize(CPlayer* _cpPlayer);
	void Update();
	void Release();

	void Battle(int _iLv);
	void Attack(bool& refIsEnd, bool& refIsWin);
	void Run(bool& refIsEnd);
};

