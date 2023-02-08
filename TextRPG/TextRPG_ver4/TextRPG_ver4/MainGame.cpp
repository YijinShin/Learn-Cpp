#include "stdafx.h"
#include "Define.h"
#include "Player.h"
#include "Monster.h"
#include "MainGame.h"

using namespace std;

bool MainGame::Initialize() {
	// �ϴ� �ƹ��͵� ��«.
	return true;
}

//
void MainGame::Game(Player* pPlayer) {
	int iMenu(0);
	bool isEnd(false);

	while (1) {
		// Selete village Menu
		cout << "[����] ������ �ұ�. (1.����, 2.����, 3.����):  ";
		while (1) {
			cin >> iMenu;
			if (iMenu <= 0 || iMenu > 3)cout << "[����] �߸��� �Է��Դϴ�. (1.����, 2.����, 3.����): ";
			else break;
		}
		// result
		switch (iMenu)
		{
		case 1:
			system("cls");
			Dungeon(pPlayer);
			break;
		case 2:
			system("cls");
			if(SavePlayerData(pPlayer))
			break;
		case 3:
			system("cls");
			if(SavePlayerData(pPlayer))
				Release(pPlayer);
			isEnd = true;
			break;
		default:
			break;
		}
		if (isEnd) break;
	}
}
void MainGame::Update() {

}
void MainGame::Release(Player* pPlayer) {
	SAFE_DELETE(pPlayer);
}

// -----------------------------------------------------------
void MainGame::SettingPlayer(Player** ppPlayer) {
	int iMenu(0);

	//cout << "[Text RPG_ver4] 1. �����ϱ� 2. �̾��ϱ�: ";	// class�� ���, ����ü ���� ���Ͽ� �а� ���� �����. 
	cout << "[Text RPG_ver4] 1. �����ϱ�: ";
	while (1) {
		cin >> iMenu;
		//if (iMenu <= 0 || iMenu > 2)cout << "[Text RPG_ver3] �߸��� �Է��Դϴ�. 1.�����ϱ�, 2.�̾��ϱ�: ";
		if (iMenu <= 0 || iMenu > 1)cout << "[Text RPG_ver3] �߸��� �Է��Դϴ�. 1.�����ϱ�: ";
		else break;
	}
	if (iMenu == 1) *ppPlayer = CreateNewPlayer();
	else if (iMenu == 2) *ppPlayer = ReadPlayerData();
}

Player* MainGame::CreateNewPlayer() {
	int iJob(0);
	char szName[MAXCHERSIZE];

	cout << "[�����̼�] ������ �����ϼ��� (1.����, 2.����, 3.�ü�): ";
	while (1) {
		cin >> iJob;
		if (iJob <= 0 || iJob > 3)cout << "[�����̼�] �߸��� �Է��Դϴ�. ������ �ٽ� �Է����ּ��� (1.����, 2.����, 3.�ü�): ";
		else break;
	}

	cout << "[�����̼�]  ĳ���� �̸��� �Է����ּ���(1~6����): ";
	while (1) {
		cin >> szName;
		if (strlen(szName)<=0 || strlen(szName) > 6) cout << "[�����̼�]  �߸��� �Է��Դϴ�. 1~6���� ������ �̸��� �Է����ּ���: ";
		else break;
	}

	Player* pPlayer = new Player(szName, iJob);
	return pPlayer;
}

void MainGame::Dungeon(Player* pPlayer) {
	int iMenu(0);
	bool isEnd(false);

	while (1) {

		pPlayer->DisplayInfo();

		// Selete dungeon Menu
		cout << "[����] ������ �������ּ��� (1. �ʱ�, 2.�߱�, 3.���, 4.���ư���): ";
		while (1) {
			cin >> iMenu;
			if (iMenu <= 0 || iMenu > 4)cout << "[����] �߸��� �Է��Դϴ�. (1. �ʱ�, 2.�߱�, 3.���, 4.���ư���): ";
			else break;
		}
		// result
		switch (iMenu)
		{
		case 1:
			system("cls");
			Battle(pPlayer, 1);
			break;
		case 2:
			system("cls");
			Battle(pPlayer, 2);
			break;
		case 3:
			system("cls");
			Battle(pPlayer, 3);
			break;
		case 4:
			isEnd = true;
			break;
		default:
			break;
		}
		if (isEnd) break;

		system("pause");
	}

}

void MainGame::Battle(Player* pPlayer, int iLv) {
	int iMenu(0);
	bool isEnd(false);
	bool isWin(false);
	Monster* monster = new Monster(iLv);	//create monster
	
	// fight 
	cout << "[����] ���Ͱ� ��Ÿ�����ϴ�!" << endl;
	while (1) {
		system("cls");
		// Display state
		pPlayer->DisplayInfo();
		monster->DisplayInfo();

		// Selete fight Menu
		cout << "[����]  1. �����Ѵ� 2. �������� :";
		while (1) {
			cin >> iMenu;
			if (iMenu <= 0 || iMenu > 4)cout << "[����]  �߸��� �Է��Դϴ�. 1. �����Ѵ� 2. �������� : ";
			else break;
		}
		// result
		switch (iMenu)
		{
		case 1:
			// Player attack Monster
			system("cls");
			cout << "[����] ���͸� �����մϴ�!." << endl;
			monster->Damaged(pPlayer->GetiOffencePower());
			//check monster die
			if (monster->IsDead()) {
				cout << "[����]  ���͸� ����Ʈ�Ƚ��ϴ�!" << endl;
				isEnd = true;
				isWin = true;
			}
			break;
		case 2:
			// Player run
			system("cls");
			cout << "[����] ���ͷκ��� �������ϴ�." << endl;
			isEnd = true;
			break;
		default:
			break;
		}
		pPlayer->DisplayInfo();
		monster->DisplayInfo();
		system("pause");

		// end battle + check level up
		if (isEnd) {
			if (isWin) {
				cout << "[����]  �����մϴ�! ������ �ö����ϴ�! ü���� 30, ���ݷ��� 2�����մϴ�." << endl;
				pPlayer->LevelUp();
				pPlayer->Hilled(pPlayer->CalcFullHillHP());
			}
			break;
		}

		// Monster attack Player
		system("cls");
		cout << "[����] ���Ϳ��� ���ݴ��մϴ�!." << endl;
		pPlayer->Damaged(monster->GetiOffencePower());
		//check player die
		if (pPlayer->IsDead()) {
			cout << "[����] ����� ���������ϴ�. ������ ���ư��ϴ�." << endl;
			pPlayer->Hilled(pPlayer->CalcFullHillHP());	// hill to full hp
			isEnd = true;
			isWin = false;
		}

		// end battle + check level up
		if (isEnd) {
			if (isWin) {
				cout << "[����]  �����մϴ�! ������ �ö����ϴ�! ü���� 30, ���ݷ��� 2�����մϴ�." << endl;
				pPlayer->LevelUp();
			}
			break;
		}

		pPlayer->DisplayInfo();
		monster->DisplayInfo();

		system("pause");
	}

	SAFE_DELETE( monster);
}

// SAVE -------------------------------------------------------
Player* MainGame::ReadPlayerData() {
	Player* player = new Player;
	FILE* pSaveFile = nullptr;

	// open succeed
	if (0 == fopen_s(&pSaveFile, "../TextRPGData/PlayerInfoSaveFile.txt", "rb")) {
		cout << "[�ý���]  ���̺� ������ ã�ҽ��ϴ�." << endl;
		//write player info
		if (0 == fread(player, sizeof(player), 1, pSaveFile)) {
			cout << "[�ý���] �÷��̾� ���� �б⸦ �����߽��ϴ�." << endl;
		}
		else {
			cout << "[�ý���] �÷��̾� ������ �аſɴϴ�." << endl;
		}

	}
	// open failed
	else {
		cout << "[�ý���]  ���̺� ������ ã�� ���߽��ϴ�." << endl;
	}

	fclose(pSaveFile);

	return player;
}
bool MainGame::SavePlayerData(Player* pPlayer) {
	FILE* pSaveFile = nullptr;

	// open succeed
	if (0 == fopen_s(&pSaveFile, "../TextRPGData/PlayerInfoSaveFile.txt", "wb")) {
		cout << "[�ý���]  ���̺� ������ ã�ҽ��ϴ�." << endl;
		//write player info
		if (0 == fwrite(pPlayer, sizeof(*pPlayer), 1, pSaveFile)) {
			cout << "[�ý���] �÷��̾� ���� ������ �����߽��ϴ�." << endl;
		}
		else {
			cout << "[�ý���] �÷��̾� ������ �����߽��ϴ�." << endl;
		}

	}
	// open failed
	else {
		cout << "[�ý���]  ���̺� ������ ã�� ���߽��ϴ�." << endl;
	}

	fclose(pSaveFile);
	return true;
}

