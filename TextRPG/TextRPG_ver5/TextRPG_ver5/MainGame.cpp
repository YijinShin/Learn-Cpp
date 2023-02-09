#include "stdafx.h"
#include "MainGame.h"
using namespace std;

CMainGame::CMainGame() :m_pCplayer(nullptr), m_pCfield(nullptr)
{
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize(void)
{
	/* Setting player */
	m_pCplayer = new CPlayer;
	m_pCplayer->Initialize();

	/* Setting field */
	m_pCfield = new CField;
	m_pCfield->Initalize(m_pCplayer);

}

void CMainGame::Update(void)
{
	int iMenu(0);
	bool isEnd(false);

	while (1) {
		system("cls");

		m_pCplayer->DisplayInfo();

		// select menu
		cout << "[마을] 무엇을 할까. (1.던전, 2.종료): ";
		cin >> iMenu;

		// menu action
		switch (iMenu)
		{
		case 1:
			m_pCfield->Update();
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

void CMainGame::Release(void)
{
	SAFE_DELETE(m_pCplayer);
	SAFE_DELETE(m_pCfield);
}
