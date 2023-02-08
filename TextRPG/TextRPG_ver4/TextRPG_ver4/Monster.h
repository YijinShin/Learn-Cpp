#pragma once
#include "Define.h"


class Monster {
private:
	int m_iTotalHP;
	int m_iCurrHP;
	int m_iLv;
	int m_iOffencePower;
	bool m_isDead;

public:
	Monster();
	Monster(int _iLv);
	~Monster();

	void Damaged(int _iDamageHP);
	bool IsDead();

	int GetiOffencePower();

	void DisplayInfo();
};