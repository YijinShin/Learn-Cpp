#pragma once
#include "Field.h"

class CPlayer;

class MainGame
{
private:
	CPlayer* m_cpPlayer;
	CField* m_cpField;
public:
	MainGame();
	~MainGame();

	void Initialize();
	void Update();
	void Release();
};

