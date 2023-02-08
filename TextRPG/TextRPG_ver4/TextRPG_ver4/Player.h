#pragma once
#include "Define.h"

// basic information of player 
typedef struct tagPlayerBasicInfo {
	char m_szName[MAXCHERSIZE];
	char m_szJob[MAXCHERSIZE];
}PLAYERINFO, *PPLAYERINFO;


class Player {
private:
	PLAYERINFO m_playerInfo;
	int m_iTotalHP;
	int m_iCurrHP;
	int m_iLv;
	int m_iOffencePower;
	bool m_isDead;

public:
	
	Player();
	Player(char _szName[], int _iJob);
	~Player();

	void Damaged(int _iDamageHP);
	void Hilled(int _iHillHP);
	void LevelUp();
	bool IsDead();

	int GetiOffencePower();
	int CalcFullHillHP();
	
	void DisplayInfo();
};