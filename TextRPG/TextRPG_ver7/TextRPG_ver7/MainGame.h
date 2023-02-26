#pragma once

class CPlayer;
class CField;
class CMall;

class CMainGame
{
private:
	CPlayer* m_cpPlayer;
	CField* m_cpField;
	CMall* m_cpMall;

public:
	CMainGame();
	~CMainGame();

	void Initialize();
	void Update();
	void Release();
};

