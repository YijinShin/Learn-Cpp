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
		cout << "[����] ������ �ұ�. (1.����, 2.����): ";
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
			cout << "[����] �߸��� �Է��Դϴ�." << endl;
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
