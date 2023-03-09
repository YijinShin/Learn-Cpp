#pragma once
#include "Define.h"
#include "Player.h"

class CMainGmae
{
private:
	HDC		m_DC
public:
	CMainGmae();
	~CMainGmae();

	void Initialize();
	void Update();
	void Render();
	void Release();
};

