#pragma once
#include "Define.h"

class CPlayer
{
private:
	PLAYERINFO m_playerInfo;
public:
	CPlayer();
	~CPlayer();

	// init player
	void Initialize();
	void SetName();

	// change state
	void SelecteJob();
	void SetCurrHP(int _alpaHP);
	void LevelUp();

	// get state
	bool IsDead();
	PLAYERINFO GetPlayerInfo();

	void DisplayInfo();

};

