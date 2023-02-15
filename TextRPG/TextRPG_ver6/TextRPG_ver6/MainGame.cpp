#include "stdafx.h"
#include "MainGame.h"

MainGame::MainGame(): m_cpField(nullptr), m_cpPlayer(nullptr)
{
}

MainGame::~MainGame()
{
	Release();
}

void MainGame::Initialize()
{
	// create, init player
	m_cpPlayer = new CPlayer;	
	m_cpPlayer->Initialize();	

	// create, init field
	m_cpField = new CField;
	m_cpField->Initialize(m_cpPlayer);
}

void MainGame::Update()
{
	bool isEnd(false);
	int iMenu(0);
	
	while (1) {
		system("cls");

		m_cpPlayer->DisplayINFO();

		// select menu
		cout << "[마을] 무엇을 할까. (1.던전, 2.종료): ";
		cin >> iMenu;
		switch (iMenu)
		{
		case 1:
			m_cpField->Update();
			break;
		case 2:
			isEnd = true;
			break;
		default:
			cout << "[마을] 잘못된 입력입니다." << endl;
			break;
		}

		if (isEnd) break;
		system("pause");
	}
}

void MainGame::Release()
{
	SAFE_DELETE(m_cpField);
	SAFE_DELETE(m_cpPlayer);
}
