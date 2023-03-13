#pragma once
#include "Include.h"

class CObj;

class CMainGame
{
private:
	list<CObj*>		m_ObjList[OBJ_END];
	HDC		m_hDC;

public:
	CMainGame();
	~CMainGame();

	void Initialize();
	void Update();
	void Late_Update();
	void Render();
	void Release();
};

