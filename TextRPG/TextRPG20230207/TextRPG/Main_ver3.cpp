/* [Ver3] structure, save file*/

#include <iostream>
#include "Monster_struct1.h"
#include "Player_struct2.h"

using namespace std;

void GameStartLodding(PPLAYER player);
PLAYER GetPlayerData();
PLAYER CreatePlayer();
void MainGame(PPLAYER player);
int SelectMoving();
int SelectDungeon();
int SelectFigheMenu();
void Dungeon(int iDungeonLv, PPLAYER player);
void SavePlayerData(PPLAYER player);


int main() {

	PLAYER player;

	// 1. �����ϱ� 2. �̾��ϱ� 
	GameStartLodding(&player);

	// Game start
	MainGame(&player);
	
	// End Game + Save player information
	SavePlayerData(&player);
	cout << "[�����̼�] ������ �����մϴ�." << endl;
}

void GameStartLodding(PPLAYER player) {
	int iFirstMenu(0);
	cout << "[Text RPG_ver3] 1.�����ϱ�, 2.�̾��ϱ� : ";
	while (1) {
		cin >> iFirstMenu;
		if (iFirstMenu < 1 || iFirstMenu > 2) {
			cout << "[Text RPG_ver3] �߸��� �Է��Դϴ�. 1.�����ϱ�, 2.�̾��ϱ� :  ";
		}
		else break;
	}
	// create new player
	if (iFirstMenu == 1) {
		*player = CreatePlayer();
	}
	// get exist player from save file
	else if (iFirstMenu == 2) {
		*player = GetPlayerData();
	}
}

PLAYER GetPlayerData() {
	PLAYER player;

	FILE* pSaveFile = nullptr;

	// open succeed
	if (0 == fopen_s(&pSaveFile, "../TextRPGData/PlayerInfoSaveFile.txt", "rb")) {
		cout << "[�ý���]  ���̺� ������ ã�ҽ��ϴ�." << endl;
		//write player info
		if (0 == fread(&player, sizeof(player), 1, pSaveFile)) {
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

PLAYER CreatePlayer() {
	PLAYER newPlayer;
	int iJob(0);
	char szName[20];

	// get job
	cout << "[�����̼�] ������ �����ϼ��� (1.����, 2.����, 3.�ü�): ";
	while (1) {
		cin >> iJob;
		if (iJob < 1 || iJob > 3) {
			cout << "[�����̼�] �߸��� �Է��Դϴ�. ������ �ٽ� �Է����ּ��� (1.����, 2.����, 3.�ü�): ";
		}
		else break;
	}

	// get name
	cout << "[�����̼�]  ĳ���� �̸��� �Է����ּ���(1~6����): ";
	while (1) {
		bool isGetNameSucceed(true);
		try {
			cin >> szName;
		}
		catch (const std::exception& e) {
			cout << "[�����̼�]  �߸��� �Է��Դϴ�. 1~6���� ������ �̸��� �Է����ּ���.";
			isGetNameSucceed = false;
		}
		if (isGetNameSucceed) break;
	}

	InitPlayer(&newPlayer, szName, iJob);
	return newPlayer;
}

void MainGame(PPLAYER player) {
	int iSelectedMenu(0);
	int iSelectHuntingLv(0);

	while (1) {
		cout << endl;
		// get first menu input
		iSelectedMenu = SelectMoving();
		DisplayInfo(player);

		// go to next scene
		if (iSelectedMenu == 1) {

			while (1) {
				cout << endl;
				int iDungeonResult(0);

				//get second menu input
				iSelectHuntingLv = SelectDungeon();
				DisplayInfo(player);

				if (iSelectHuntingLv != 4) {
					Dungeon(iSelectHuntingLv, player);
				}
				else if (iSelectHuntingLv == 4) {
					break;
				}
			}
		}
		// save data
		else if (iSelectedMenu == 2) {
			SavePlayerData(player);
		}
		// end first scene
		else if (iSelectedMenu == 3) break;
	}
}

int SelectMoving() {
	int iSelectedMenu(0);

	cout << "[�����̼�]  ������ �Ͻðڽ��ϱ�? (1:�����, 2:����, 3:����): ";
	while (1) {
		cin >> iSelectedMenu;
		if (iSelectedMenu < 1 || iSelectedMenu > 3) {
			cout << "[�����̼�] �߸��� �Է��Դϴ�. ������ �Ͻðڽ��ϱ�? (1:�����, 2:����, 3:����): ";
		}
		else break;
	}
	system("cls");
	return iSelectedMenu;
}

int SelectDungeon() {
	int iSelectedMenu(0);
	cout << "[�����̼�]  ����͸� �������ּ���. (1: �ʱ�, 2: �߱�, 3: ���, 4: ���ư���): ";
	while (1) {
		cin >> iSelectedMenu;
		if (iSelectedMenu < 1 || iSelectedMenu > 4) {
			cout << "[�����̼�]  �߸��� �Է��Դϴ�. ����͸� �������ּ���. (1: �ʱ�, 2: �߱�, 3: ���, 4: ���ư���): ";
		}
		else break;
	}
	
	system("cls");
	return iSelectedMenu;
}

int SelectFigheMenu() {
	int iSelectedMenu(0);
	cout << " 1. �����Ѵ�\t2. �������� : ";
	while (1) {
		cin >> iSelectedMenu;
		if (iSelectedMenu < 1 || iSelectedMenu > 2) {
			cout << " �߸��� �Է��Դϴ�. 1. �����Ѵ�\t2. �������� : ";
		}
		else break;
	}
	system("cls");
	return iSelectedMenu;
}

void Dungeon(int iDungeonLv, PPLAYER player) {

	int iSelectedMenu(0);
	bool isEndFight(false);
	int iEndState(0);	// 1:win, 2:lose, 3:run

	MONSTER monster;
	// create monster
	char szName[20] = "������";
	monster.InitMonster(szName, iDungeonLv);
	cout << "[�����̼�]  " << monster.GetName() << "�� ��Ÿ�����ϴ�!" << endl;

	// fight
	while (1) {
		cout << endl;

		// display player, monster state
		monster.DisplayInfo();

		// get input 
		iSelectedMenu = SelectFigheMenu();
		system("cls");
		DisplayInfo(player);

		// attack
		if (iSelectedMenu == 1) {

			// player attack monster
			monster.Damaged(GetOffencePower(player));

			// monster attack player
			Damaged(player,monster.GetOffencePower());

			// check monster dead => dungeon over
			if (monster.GetIsDead()) {
				cout << "[�����̼�]  " << monster.GetName() << "�� ����Ʈ�Ƚ��ϴ�! " << endl;
				iEndState = 1;
				break;
			}

			// check player dead => dungeon over
			if (GetIsDead(player)) {
				cout << "[�����̼�]  ����� ���������ϴ�." << endl;
				iEndState = 2;
				break;
			}
		}
		// run => dungeon over
		else {
			cout << "[�����̼�]  " << monster.GetName() << "�κ��� �������ϴ�. " << endl;
			iEndState = 3;
			break;
		}
	}

	// result
	if (iEndState == 1) {
		cout << "[�����̼�]  �����մϴ�! ������ �ö����ϴ�! ü���� 30, ���ݷ��� 2�����մϴ�." << endl;
		LevelUp(player);
	}
	DisplayInfo(player);
}

void SavePlayerData(PPLAYER player) {

	FILE* pSaveFile = nullptr;

	// open succeed
	if (0 == fopen_s(&pSaveFile, "../TextRPGData/PlayerInfoSaveFile.txt", "wb")) {
		cout << "[�ý���]  ���̺� ������ ã�ҽ��ϴ�." << endl;
		//write player info
		if (0 == fwrite(player, sizeof(*player), 1, pSaveFile)) {
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
}
