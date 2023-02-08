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

	// 1. 새로하기 2. 이어하기 
	GameStartLodding(&player);

	// Game start
	MainGame(&player);
	
	// End Game + Save player information
	SavePlayerData(&player);
	cout << "[나레이션] 게임을 종료합니다." << endl;
}

void GameStartLodding(PPLAYER player) {
	int iFirstMenu(0);
	cout << "[Text RPG_ver3] 1.새로하기, 2.이어하기 : ";
	while (1) {
		cin >> iFirstMenu;
		if (iFirstMenu < 1 || iFirstMenu > 2) {
			cout << "[Text RPG_ver3] 잘못된 입력입니다. 1.새로하기, 2.이어하기 :  ";
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
		cout << "[시스템]  세이브 파일을 찾았습니다." << endl;
		//write player info
		if (0 == fread(&player, sizeof(player), 1, pSaveFile)) {
			cout << "[시스템] 플레이어 정보 읽기를 실패했습니다." << endl;
		}
		else {
			cout << "[시스템] 플레이어 정보를 읽거옵니다." << endl;
		}

	}
	// open failed
	else {
		cout << "[시스템]  세이브 파일을 찾지 못했습니다." << endl;
	}

	fclose(pSaveFile);

	return player;
}

PLAYER CreatePlayer() {
	PLAYER newPlayer;
	int iJob(0);
	char szName[20];

	// get job
	cout << "[나레이션] 직업을 선택하세요 (1.전사, 2.법사, 3.궁수): ";
	while (1) {
		cin >> iJob;
		if (iJob < 1 || iJob > 3) {
			cout << "[나레이션] 잘못된 입력입니다. 직업을 다시 입력해주세요 (1.전사, 2.법사, 3.궁수): ";
		}
		else break;
	}

	// get name
	cout << "[나레이션]  캐릭터 이름을 입력해주세요(1~6글자): ";
	while (1) {
		bool isGetNameSucceed(true);
		try {
			cin >> szName;
		}
		catch (const std::exception& e) {
			cout << "[나레이션]  잘못된 입력입니다. 1~6글자 사이의 이름을 입력해주세요.";
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

	cout << "[나레이션]  무엇을 하시겠습니까? (1:사냥터, 2:저장, 3:종료): ";
	while (1) {
		cin >> iSelectedMenu;
		if (iSelectedMenu < 1 || iSelectedMenu > 3) {
			cout << "[나레이션] 잘못된 입력입니다. 무엇을 하시겠습니까? (1:사냥터, 2:저장, 3:종료): ";
		}
		else break;
	}
	system("cls");
	return iSelectedMenu;
}

int SelectDungeon() {
	int iSelectedMenu(0);
	cout << "[나레이션]  사냥터를 선택해주세요. (1: 초급, 2: 중급, 3: 고급, 4: 돌아간다): ";
	while (1) {
		cin >> iSelectedMenu;
		if (iSelectedMenu < 1 || iSelectedMenu > 4) {
			cout << "[나레이션]  잘못된 입력입니다. 사냥터를 선택해주세요. (1: 초급, 2: 중급, 3: 고급, 4: 돌아간다): ";
		}
		else break;
	}
	
	system("cls");
	return iSelectedMenu;
}

int SelectFigheMenu() {
	int iSelectedMenu(0);
	cout << " 1. 공격한다\t2. 도망간다 : ";
	while (1) {
		cin >> iSelectedMenu;
		if (iSelectedMenu < 1 || iSelectedMenu > 2) {
			cout << " 잘못된 입력입니다. 1. 공격한다\t2. 도망간다 : ";
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
	char szName[20] = "슬라임";
	monster.InitMonster(szName, iDungeonLv);
	cout << "[나레이션]  " << monster.GetName() << "이 나타났습니다!" << endl;

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
				cout << "[나레이션]  " << monster.GetName() << "을 쓰러트렸습니다! " << endl;
				iEndState = 1;
				break;
			}

			// check player dead => dungeon over
			if (GetIsDead(player)) {
				cout << "[나레이션]  당신은 쓰러졌습니다." << endl;
				iEndState = 2;
				break;
			}
		}
		// run => dungeon over
		else {
			cout << "[나레이션]  " << monster.GetName() << "로부터 도망갑니다. " << endl;
			iEndState = 3;
			break;
		}
	}

	// result
	if (iEndState == 1) {
		cout << "[나레이션]  축하합니다! 레벨이 올랐습니다! 체력이 30, 공격력이 2증가합니다." << endl;
		LevelUp(player);
	}
	DisplayInfo(player);
}

void SavePlayerData(PPLAYER player) {

	FILE* pSaveFile = nullptr;

	// open succeed
	if (0 == fopen_s(&pSaveFile, "../TextRPGData/PlayerInfoSaveFile.txt", "wb")) {
		cout << "[시스템]  세이브 파일을 찾았습니다." << endl;
		//write player info
		if (0 == fwrite(player, sizeof(*player), 1, pSaveFile)) {
			cout << "[시스템] 플레이어 정보 저장을 실패했습니다." << endl;
		}
		else {
			cout << "[시스템] 플레이어 정보를 저장했습니다." << endl;
		}
		
	}
	// open failed
	else {
		cout << "[시스템]  세이브 파일을 찾지 못했습니다." << endl;
	}

	fclose(pSaveFile);
}
