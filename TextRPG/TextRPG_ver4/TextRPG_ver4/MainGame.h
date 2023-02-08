#pragma once
#include "Player.h"

class MainGame {
private:

public:
	bool Initialize();	// initialize game

	//
	void Game(Player* pPlayer);
	void Update();
	void Release(Player* pPlayer);

	// 게임 진행 
	void SettingPlayer(Player** ppPlayer);
	Player* CreateNewPlayer();
	void Dungeon(Player* pPlayer);
	void Battle(Player* pPlayer, int iLv);

	// SAVE
	Player* ReadPlayerData();
	bool SavePlayerData(Player* pPlayer);


};