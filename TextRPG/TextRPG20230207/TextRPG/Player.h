#pragma once
#include <iostream>
using namespace std;

class Player {
private:
	char szName_[20];
	char iJob_[20];	// 1:전사, 2: 법사, 3: 궁수
	int iHP_;
	int iCurrHP_;
	//int iMP_;
	int iLV_;	//level
	int iOffenceP_;	// 공격력
	bool isDead;
protected:

public:
	Player(char szName[], int iJob);
	void Damaged(int iDamage);
	void DisplayInfo();
	bool GetIsDead();
	int GetOffencePower();
	void LevelUp();
};

// constructor
Player::Player(char szName[], int iJob) : iLV_(1), isDead(false) {
	strcpy_s(szName_, sizeof(szName_), szName);
	if (iJob == 1) {
		strcpy_s(iJob_, sizeof(iJob_), "Worrior");
		iHP_ = 100;
		iOffenceP_ = 10;
	}
	else if (iJob == 2) {
		strcpy_s(iJob_, sizeof(iJob_), "Wizard");
		iHP_ = 80;
		iOffenceP_ = 30;
	}
	else if (iJob == 3) {
		strcpy_s(iJob_, sizeof(iJob_), "Archer");
		iHP_ = 90;
		iOffenceP_ = 20;
	}
	else {
		strcpy_s(iJob_, sizeof(iJob_), " ");
		iHP_ = 0;
		iOffenceP_ = 0;
	}
	iCurrHP_ = iHP_;
}

void Player::Damaged(int iDamage) {
	iCurrHP_ = iCurrHP_ - iDamage;

	if (iCurrHP_ <= 0) {
		iCurrHP_ = 0;
		isDead = true;
	}
}

void Player::DisplayInfo() {
	cout << "_____________________________________________________________" << endl;
	cout << "| Name: " << szName_ << " (" << iJob_ << ")\tLv: " << iLV_<< endl;
	cout << "| HP: " << iCurrHP_<< "/"<<iHP_ << "\t Offence Power: " << iOffenceP_ << endl;
	cout << "_____________________________________________________________" << endl;
}

bool Player::GetIsDead() {
	return isDead;
}

int Player::GetOffencePower() {
	return iOffenceP_;
}

void Player::LevelUp() {
	iLV_++;

	// HP increase
	iHP_ = iHP_ + 30;
	iCurrHP_ = iHP_;

	//Offence Poser increase
	iOffenceP_ = iOffenceP_ + 2;
}
