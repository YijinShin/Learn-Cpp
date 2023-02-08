#include "stdafx.h"
#include "Monster.h"

using namespace std;

Monster::Monster() : m_iTotalHP(0), m_iCurrHP(0), m_iLv(1), m_iOffencePower(0), m_isDead(false) {
	cout << " [�ý���] ���� ������ ������ �߻��߽��ϴ�."<< endl;
}

Monster::Monster(int _iLv): m_iTotalHP(0), m_iCurrHP(0), m_iLv(1), m_iOffencePower(0), m_isDead(false) {
	m_iTotalHP = _iLv * 30;
	m_iCurrHP = m_iTotalHP;
	m_iOffencePower = _iLv * 3;
}

Monster::~Monster() {
	cout << " [����] ���Ͱ� �Ҹ�˴ϴ�." << endl;
}

void Monster::Damaged(int _iDamageHP) {
	m_iCurrHP = m_iCurrHP - _iDamageHP;
}

bool Monster::IsDead() {
	if (m_iCurrHP <= 0) return true;
	else return false;
}

int Monster::GetiOffencePower() {
	return m_iOffencePower;
}

void Monster::DisplayInfo() {
	cout << "_____________________________________________________________" << endl;
	cout << "| Name: Monster" <<"/ HP: " << m_iCurrHP << " / " << m_iTotalHP << "\t Offence Power : " << m_iOffencePower << endl;
	cout << "_____________________________________________________________" << endl;
}
