#pragma once
#include "Include.h"

class CMainGame
{
private:
	HDC		m_hDC;
	int		m_GameMode;
public:
	CMainGame();
	~CMainGame();

	void	Initialize();
	void	Update();
	void	Late_Update();
	void	Render();
	void	Release();

public:	
	void	Key_Input();
};

