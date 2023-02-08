#pragma once
#include <iostream>
using namespace std;

typedef struct tagMonsterInfo {

	char szName_[20];
	int iHP_;
	int iLV_;	//level
	int iOffenceP_;	// °ø°Ý·Â
	bool isDead;
	void Damaged(int iDamage);
	void DisplayInfo();
	bool GetIsDead();
	const char* GetName();
	int GetOffencePower();
	void InitMonster(char szName[], int iLV);
}MONSTER, *PMONSTER;

void tagMonsterInfo::InitMonster(char szName[], int iLV) {
	isDead = false;
	strcpy_s(szName_, sizeof(szName_), szName);
	iLV_ = iLV;
	iHP_ = iLV * 30;
	iOffenceP_ = iLV * 3;
}

void tagMonsterInfo::Damaged(int iDamage) {
	iHP_ = iHP_ - iDamage;

	if (iHP_ <= 0) {
		iHP_ = 0;
		isDead = true;
	}
}

void tagMonsterInfo::DisplayInfo() {
	cout << "_____________________________________________________________" << endl;
	cout << "| Name: " << szName_ << "\tLv: " << iLV_ << endl;
	cout << "| HP: " << iHP_ << "\t Offence Power: " << iOffenceP_ << endl;
	cout << "_____________________________________________________________" << endl;
}

bool tagMonsterInfo::GetIsDead() {
	return isDead;
}

const char* tagMonsterInfo::GetName() {
	return szName_;
}

int tagMonsterInfo::GetOffencePower() {
	return iOffenceP_;
}