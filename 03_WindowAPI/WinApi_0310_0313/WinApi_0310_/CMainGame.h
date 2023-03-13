#pragma once
#include "Include.h"

class CObj;

class CMainGame
{
private:
	HDC		m_hDC;

	// 게임 오브젝트 
	list<CObj*>	m_ObjList[OBJ_END];	// 추상 팩토리 디자인 패턴 

	// FPS 출력을 위한
	int		m_iFPS;
	DWORD	m_dwTime;
	TCHAR	m_szFPS[32];


public:
	CMainGame();
	~CMainGame();

	void Initialize();
	int Update();
	void Late_Update();
	void Render();
	void Release();

};

