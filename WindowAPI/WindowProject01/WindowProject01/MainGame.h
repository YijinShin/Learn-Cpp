#pragma once
#include "Define.h"

class CObj;
class CPlayer;
class Bullet;

class CMainGame
{
private:
	HDC			m_DC;
	RECT		m_tFence;
	list<CObj*> m_BulletList;

	CObj*		m_pPlayer;
	CObj*		m_pMonster;

public:
	CMainGame();
	~CMainGame();

	void Initialize();
	void Update();
	void Render();
	void Release();
};

