#pragma once

#include "Include.h"

class CMainGame
{
private:

public:
	CMainGame();
	~CMainGame();

	void	Initialize();
	void	Update();
	void	Late_Update();
	void	Render();
	void	Release();
};

