#pragma once
#include "Include.h"

class CMainGame
{
private:
	HDC		m_hDC;

public:
	CMainGame();
	~CMainGame();

	void	Initialize();
	void	Update();
	void	Late_Update();
	void	Render();
	void	Release();
};

