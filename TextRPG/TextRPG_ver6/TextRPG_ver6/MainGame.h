#pragma once
#include "Player.h"

class MainGame
{
private:
	CPlayer* m_player;
public:
	MainGame();
	~MainGame();

	void Initialize();
	void Update();
	void Release();
};

