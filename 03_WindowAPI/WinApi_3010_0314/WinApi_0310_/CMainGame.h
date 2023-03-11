#pragma once
#include "Include.h"

class CObj;

class CMainGame
{
private:
	HDC		m_hDC;

	// ���� ������Ʈ 
	list<CObj*>	m_ObjList[OBJ_END];	// �߻� ���丮 ������ ���� 

	// FPS ����� ����
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

