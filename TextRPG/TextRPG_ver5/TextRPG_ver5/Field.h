#pragma once
#include "Monster.h"
#include "Player.h"

class CField
{
private:
	CPlayer* m_pCplayer;
	CMonster* m_pCmonster;
public:
	CField();
	~CField();

	void Initalize(CPlayer* pCplayer);
	void Update();
	void Release();

	// 
	void Battle(int fieldLv);
	void Attack(bool& isEnd, bool& isWin);
	void Run(bool& refIsEnd);
	

};

