#pragma once
#include <iostream>
using namespace std;

typedef struct tagPlayerInfo {

	char szName_[20];
	char iJob_[20];	// 1:전사, 2: 법사, 3: 궁수
	int iHP_;
	int iCurrHP_;
	//int iMP_;
	int iLV_;	//level
	int iOffenceP_;	// 공격력
	bool isDead;
}PLAYER, * PPLAYER;


void InitPlayer(PPLAYER player, char szName[], int iJob) {
	player->iLV_ = 1;
	player->isDead = false;
	strcpy_s(player->szName_, sizeof(player->szName_), szName);
	if (iJob == 1) {
		strcpy_s(player->iJob_, sizeof(player->iJob_), "Worrior");
		player->iHP_ = 100;
		player->iOffenceP_ = 10;
	}
	else if (iJob == 2) {
		strcpy_s(player->iJob_, sizeof(player->iJob_), "Wizard");
		player->iHP_ = 80;
		player->iOffenceP_ = 30;
	}
	else if (iJob == 3) {
		strcpy_s(player->iJob_, sizeof(player->iJob_), "Archer");
		player->iHP_ = 90;
		player->iOffenceP_ = 20;
	}
	else {
		strcpy_s(player->iJob_, sizeof(player->iJob_), " ");
		player->iHP_ = 0;
		player->iOffenceP_ = 0;
	}
	player->iCurrHP_ = player->iHP_;
}


void Damaged(PPLAYER player, int iDamage) {
	player->iCurrHP_ = player->iCurrHP_ - iDamage;

	if (player->iCurrHP_ <= 0) {
		player->iCurrHP_ = 0;
		player->isDead = true;
	}
}

void DisplayInfo(PPLAYER player) {
	cout << "_____________________________________________________________" << endl;
	cout << "| Name: " << player->szName_ << " (" << player->iJob_ << ")\tLv: " << player->iLV_ << endl;
	cout << "| HP: " << player->iCurrHP_ << "/" << player->iHP_ << "\t Offence Power: " << player->iOffenceP_ << endl;
	cout << "_____________________________________________________________" << endl;
}


bool GetIsDead(PPLAYER player) {
	return player->isDead;
}


int GetOffencePower(PPLAYER player) {
	return player->iOffenceP_;
}
void LevelUp(PPLAYER player) {
	player->iLV_++;

	// HP increase
	player->iHP_ = player->iHP_ + 30;
	player->iCurrHP_ = player->iHP_;

	//Offence Poser increase
	player->iOffenceP_ = player->iOffenceP_ + 2;
}
