#include "MainGame.h"

#include "stdafx.h"
#include "Define.h"
#include "Player.h"
#include "Field.h"
#include "Mall.h"


CMainGame::CMainGame() : m_cpField(nullptr), m_cpPlayer(nullptr), m_cpMall(nullptr)
{
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	// create, init player
	m_cpPlayer = new CPlayer;
	m_cpPlayer->Initialize();

	// create, init field
	m_cpField = new CField;
	m_cpField->Initialize(m_cpPlayer);

	// create, init mall
	m_cpMall = new CMall;
	m_cpMall->Initialize(m_cpPlayer);
}

void CMainGame::Update()
{
	bool isEnd(false);
	int iMenu(0);

	while (1) {
		system("cls");

		m_cpPlayer->Rander();

		// select menu
		cout << "[����] ������ �ұ�. (1.����, 2.������, 3.����,): ";
		cin >> iMenu;
		switch (iMenu)
		{
		case 1:
			m_cpField->Update();
			break;
		case 2:
			m_cpMall->Update();
			break;
		case 3:
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

void CMainGame::Release()
{
	Safe_Delete(m_cpField);
	Safe_Delete(m_cpPlayer);
}
