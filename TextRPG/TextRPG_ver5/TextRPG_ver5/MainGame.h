#pragma once
#include "Player.h"
#include "Field.h"

class CMainGame
{
private:
	CPlayer* m_pCplayer;
	CField* m_pCfield;

public:
	CMainGame();
	~CMainGame();

	// Main func
	void Initialize(void);
	void Update(void);
	void Release(void);

	// Etc
};

