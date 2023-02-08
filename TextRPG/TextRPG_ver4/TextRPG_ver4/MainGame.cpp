#include "stdafx.h"
#include "Define.h"
#include "Player.h"
#include "Monster.h"
#include "MainGame.h"

using namespace std;

bool MainGame::Initialize() {
	// 일단 아무것도 안짬.
	return true;
}

//
void MainGame::Game(Player* pPlayer) {
	int iMenu(0);
	bool isEnd(false);

	while (1) {
		// Selete village Menu
		cout << "[마을] 무엇을 할까. (1.던전, 2.저장, 3.종료):  ";
		while (1) {
			cin >> iMenu;
			if (iMenu <= 0 || iMenu > 3)cout << "[마을] 잘못된 입력입니다. (1.던전, 2.저장, 3.종료): ";
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

	//cout << "[Text RPG_ver4] 1. 새로하기 2. 이어하기: ";	// class의 경우, 구조체 마냥 파일에 읽고 쓰기 어려움. 
	cout << "[Text RPG_ver4] 1. 새로하기: ";
	while (1) {
		cin >> iMenu;
		//if (iMenu <= 0 || iMenu > 2)cout << "[Text RPG_ver3] 잘못된 입력입니다. 1.새로하기, 2.이어하기: ";
		if (iMenu <= 0 || iMenu > 1)cout << "[Text RPG_ver3] 잘못된 입력입니다. 1.새로하기: ";
		else break;
	}
	if (iMenu == 1) *ppPlayer = CreateNewPlayer();
	else if (iMenu == 2) *ppPlayer = ReadPlayerData();
}

Player* MainGame::CreateNewPlayer() {
	int iJob(0);
	char szName[MAXCHERSIZE];

	cout << "[나레이션] 직업을 선택하세요 (1.전사, 2.법사, 3.궁수): ";
	while (1) {
		cin >> iJob;
		if (iJob <= 0 || iJob > 3)cout << "[나레이션] 잘못된 입력입니다. 직업을 다시 입력해주세요 (1.전사, 2.법사, 3.궁수): ";
		else break;
	}

	cout << "[나레이션]  캐릭터 이름을 입력해주세요(1~6글자): ";
	while (1) {
		cin >> szName;
		if (strlen(szName)<=0 || strlen(szName) > 6) cout << "[나레이션]  잘못된 입력입니다. 1~6글자 사이의 이름을 입력해주세요: ";
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
		cout << "[마을] 던전을 선택해주세요 (1. 초급, 2.중급, 3.고급, 4.돌아간다): ";
		while (1) {
			cin >> iMenu;
			if (iMenu <= 0 || iMenu > 4)cout << "[마을] 잘못된 입력입니다. (1. 초급, 2.중급, 3.고급, 4.돌아간다): ";
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
	cout << "[던전] 몬스터가 나타났습니다!" << endl;
	while (1) {
		system("cls");
		// Display state
		pPlayer->DisplayInfo();
		monster->DisplayInfo();

		// Selete fight Menu
		cout << "[던전]  1. 공격한다 2. 도망간다 :";
		while (1) {
			cin >> iMenu;
			if (iMenu <= 0 || iMenu > 4)cout << "[던전]  잘못된 입력입니다. 1. 공격한다 2. 도망간다 : ";
			else break;
		}
		// result
		switch (iMenu)
		{
		case 1:
			// Player attack Monster
			system("cls");
			cout << "[던전] 몬스터를 공격합니다!." << endl;
			monster->Damaged(pPlayer->GetiOffencePower());
			//check monster die
			if (monster->IsDead()) {
				cout << "[던전]  몬스터를 쓰러트렸습니다!" << endl;
				isEnd = true;
				isWin = true;
			}
			break;
		case 2:
			// Player run
			system("cls");
			cout << "[던전] 몬스터로부터 도망갑니다." << endl;
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
				cout << "[던전]  축하합니다! 레벨이 올랐습니다! 체력이 30, 공격력이 2증가합니다." << endl;
				pPlayer->LevelUp();
				pPlayer->Hilled(pPlayer->CalcFullHillHP());
			}
			break;
		}

		// Monster attack Player
		system("cls");
		cout << "[던전] 몬스터에게 공격당합니다!." << endl;
		pPlayer->Damaged(monster->GetiOffencePower());
		//check player die
		if (pPlayer->IsDead()) {
			cout << "[던전] 당신은 쓰러졌습니다. 마을로 돌아갑니다." << endl;
			pPlayer->Hilled(pPlayer->CalcFullHillHP());	// hill to full hp
			isEnd = true;
			isWin = false;
		}

		// end battle + check level up
		if (isEnd) {
			if (isWin) {
				cout << "[던전]  축하합니다! 레벨이 올랐습니다! 체력이 30, 공격력이 2증가합니다." << endl;
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
		cout << "[시스템]  세이브 파일을 찾았습니다." << endl;
		//write player info
		if (0 == fread(player, sizeof(player), 1, pSaveFile)) {
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
bool MainGame::SavePlayerData(Player* pPlayer) {
	FILE* pSaveFile = nullptr;

	// open succeed
	if (0 == fopen_s(&pSaveFile, "../TextRPGData/PlayerInfoSaveFile.txt", "wb")) {
		cout << "[시스템]  세이브 파일을 찾았습니다." << endl;
		//write player info
		if (0 == fwrite(pPlayer, sizeof(*pPlayer), 1, pSaveFile)) {
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
	return true;
}

