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
	cout << "[�����̼�]  ������ �����ϼ���. (1: ����, 2: ����, 3: �ü�): ";
	cin >> iJob;
	cout << "[�����̼�]  ĳ���� �̸��� �Է����ּ���(1~6����): ";
	while (1) {
		bool isGetNameSucceed(true);
		try {
			cin >> szName;
		}
		catch (const std::exception& e) {
			"[�����̼�]  �߸��� �Է��Դϴ�. 1~6���� ������ �̸��� �Է����ּ���.";
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

	cout << "[�����̼�]  ������ �����մϴ�."<<endl;
}

int SelectFirstMenu() {
	int iSelectedMenu(0);

	cout << "[�����̼�]  ������ �Ͻðڽ��ϱ�? (1:�����, 2: ����): ";
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
	cout << "[�����̼�]  ����͸� �������ּ���. (1: �ʱ�, 2: �߱�, 3: ���, 4: ���ư���): ";
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
	cout << " 1. �����Ѵ�\t2. �������� : ";
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
	char szName[10] = "������";
	Monster monster(szName, iDungeonLv);
	cout << "[�����̼�]  " << monster.GetName() << "�� ��Ÿ�����ϴ�!" << endl;

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
				cout << "[�����̼�]  " << monster.GetName() << "�� ����Ʈ�Ƚ��ϴ�! " << endl;
				iEndState = 1;
				break;
			}

			// check player dead => dungeon over
			if (player->GetIsDead()) {
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
		player->LevelUp();
	}
}
