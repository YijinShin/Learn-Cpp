#include <iostream>
#include "Monster.h"
#include "Player.h"

using namespace std;

int SelectFirstMenu();
int SelectSecondMenu();
void Dungeon(int iDungeonLv, Player* player);
int SelectThridMenu();

int main() {

	int iJob(0);
	char szName[15];
	int iSelectedMenu(0);
	int iSelectHuntingLv(0);
	int isGameEnd(false);

	// make new character
	cout << "[나레이션]  직업을 선택하세요. (1: 전사, 2: 법사, 3: 궁수): ";
	cin >> iJob;
	cout << "[나레이션]  캐릭터 이름을 입력해주세요(1~6글자): ";
	while (1) {
		bool isGetNameSucceed(true);
		try {
			cin >> szName;
		}
		catch (const std::exception& e) {
			"[나레이션]  잘못된 입력입니다. 1~6글자 사이의 이름을 입력해주세요.";
			isGetNameSucceed = false;
		}
		if (isGetNameSucceed) break;
	}
	Player player(szName, iJob);
	
	//First Scene()
	while (1) {
		cout << endl;
		// get first menu input
		iSelectedMenu = SelectFirstMenu();
		player.DisplayInfo();

		// go to next scene
		if (iSelectedMenu == 1) {

			while (1) {
				cout << endl;
				int iDungeonResult(0);

				//get second menu input
				iSelectHuntingLv = SelectSecondMenu();
				player.DisplayInfo();

				if (iSelectHuntingLv != 4) {
					Dungeon(iSelectHuntingLv, &player);
				}
				else if (iSelectHuntingLv == 4) {
					break;
				}

			}
		}
		// end first scene
		else if (iSelectedMenu == 2) break;
	}

	cout << "[나레이션]  게임을 종료합니다."<<endl;
}

int SelectFirstMenu() {
	int iSelectedMenu(0);

	cout << "[나레이션]  무엇을 하시겠습니까? (1:사냥터, 2: 종료): ";
	while (1) {
		bool isGetMenuSucceed(true);
		cin >> iSelectedMenu;
		if (iSelectedMenu < 1 || iSelectedMenu > 2) isGetMenuSucceed = false;
		if (isGetMenuSucceed) break;
	}
	system("cls");
	return iSelectedMenu;
}


int SelectSecondMenu() {
	int iSelectMenu(0);
	cout << "[나레이션]  사냥터를 선택해주세요. (1: 초급, 2: 중급, 3: 고급, 4: 돌아간다): ";
	while (1) {
		bool isGetMenuSucceed(true);
		cin >> iSelectMenu;
		if (iSelectMenu < 1 || iSelectMenu > 4) isGetMenuSucceed = false;
		if (isGetMenuSucceed) break;
	}
	system("cls");
	return iSelectMenu;
}

int SelectThridMenu() {
	int iSelectMenu(0);
	cout << " 1. 공격한다\t2. 도망간다 : ";
	while (1) {
		bool isGetMenuSucceed(true);
		cin >> iSelectMenu;
		if (iSelectMenu < 1 || iSelectMenu > 2) isGetMenuSucceed = false;
		if (isGetMenuSucceed) break;
	}
	system("cls");

	return iSelectMenu;
}

void Dungeon(int iDungeonLv, Player* player) {

	int iSelectedMenu(0);
	bool isEndFight(false);
	int iEndState(0);	// 1:win, 2:lose, 3:run

	// create monster
	char szName[10] = "슬라임";
	Monster monster(szName, iDungeonLv);
	cout << "[나레이션]  " << monster.GetName() << "이 나타났습니다!" << endl;

	// fight
	while (1) {
		cout << endl;

		// display player, monster state
		monster.DisplayInfo();

		// get input 
		iSelectedMenu = SelectThridMenu();
		system("cls");
		player->DisplayInfo();

		if (iSelectedMenu == 1) {
			
			// player attack monster
			monster.Damaged(player->GetOffencePower());

			// monster attack player
			player->Damaged(monster.GetOffencePower());

			// check monster dead => dungeon over
			if (monster.GetIsDead()) {
				cout << "[나레이션]  " << monster.GetName() << "을 쓰러트렸습니다! " << endl;
				iEndState = 1;
				break;
			}

			// check player dead => dungeon over
			if (player->GetIsDead()) {
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
		player->LevelUp();
	}
}
