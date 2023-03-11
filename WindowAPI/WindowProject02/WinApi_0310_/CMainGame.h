#pragma once
#include "Include.h"

class CObj;

class CMainGame
{
private:
	HDC		m_hDC;

	CObj*		m_pPlayer;
	CObj*		m_pMonster;
	list<CObj*>	m_BulletList;

public:
	CMainGame();
	~CMainGame();

	void Initialize();
	int Update();
	void Late_Update();
	void Render();
	void Release();

};

