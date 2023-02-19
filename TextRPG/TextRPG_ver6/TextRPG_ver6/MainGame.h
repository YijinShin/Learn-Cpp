#pragma once

class CPlayer;
class CField;
class CMall;

class MainGame
{
private:
	CPlayer* m_cpPlayer;
	CField* m_cpField;
	CMall* m_cpMall;

public:
	MainGame();
	~MainGame();

	void Initialize();
	void Update();
	void Release();
};

