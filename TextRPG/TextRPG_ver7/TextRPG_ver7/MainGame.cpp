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
		cout << "[마을] 무엇을 할까. (1.던전, 2.상점가, 3.종료,): ";
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
			cout << "[마을] 잘못된 입력입니다." << endl;
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
