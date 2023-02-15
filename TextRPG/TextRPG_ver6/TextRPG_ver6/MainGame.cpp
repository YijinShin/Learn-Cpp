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
		cout << "[����] ������ �ұ�. (1.����, 2.����): ";
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
			cout << "[����] �߸��� �Է��Դϴ�." << endl;
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
