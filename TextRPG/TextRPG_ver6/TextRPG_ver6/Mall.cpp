#include "stdafx.h"
#include "Mall.h"

#include "Player.h"
#include "Store.h"

CMall::CMall(): m_cpPlayer(nullptr), m_cpStore(nullptr)
{
}

CMall::~CMall()
{
	Release();
}

void CMall::Initialize(CPlayer* _cpPlayer)
{
	// create, init store
	m_cpStore = new CStore;
	m_cpStore->Initialize(_cpPlayer);
	
	// set player
	m_cpPlayer = _cpPlayer;
}

void CMall::Update()
{
	int iMenu(0);
	int isEnd(false);

	while (1) {
		system("cls");

		//select menu
		cout << "[상점가] 어떤 상점에 갈까? (1.장비상점, 2.잡화점, 3.돌아간다): ";
		cin >> iMenu;
		if (iMenu == 1 || iMenu == 2) {
			m_cpStore->SetType(iMenu);
			m_cpStore->Update();
		}
		else if (iMenu == 3) isEnd = true;
		else cout << "[상점가] 잘못된 입력입니다. " << endl;

		if (isEnd) break;
		system("pause");
	}
}

void CMall::Release()
{
	SAFE_DELETE(m_cpStore);
}
