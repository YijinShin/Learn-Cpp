#pragma once
#include <iostream>
using namespace std;

class Monster {
private:
	char szName_[20];
	int iHP_;
	int iLV_;	//level
	int iOffenceP_;	// °ø°Ý·Â
	bool isDead;
protected:

public:
	Monster(char szName[], int iLV);
	~Monster();
	void Damaged(int iDamage);
	void DisplayInfo();
	bool GetIsDead();
	const char* GetName();
	int GetOffencePower();
};

// constructor
Monster::Monster(char szName[], int iLV) : isDead(false) {
	strcpy_s(szName_, sizeof(szName_), szName);
	iLV_ = iLV;
	iHP_ = iLV * 30;
	iOffenceP_ = iLV * 3;
}

Monster::~Monster() {
	
}

void Monster::Damaged(int iDamage) {
	iHP_ = iHP_ - iDamage;

	if (iHP_ <= 0) {
		iHP_ = 0;
		isDead = true;
	}
}

void Monster::DisplayInfo() {
	cout << "_____________________________________________________________" << endl;
	cout << "| Name: " << szName_ << "\tLv: "<< iLV_ << endl;
	cout << "| HP: " << iHP_ << "\t Offence Power: " << iOffenceP_ << endl;
	cout << "_____________________________________________________________" << endl;
}

bool Monster::GetIsDead() {
	return isDead;
}

const char* Monster::GetName() {
	return szName_;
}

int Monster::GetOffencePower() {
	return iOffenceP_;
}