#include "stdafx.h"
#include "Player.h"

using namespace std;

Player::Player(): m_iTotalHP(0), m_iCurrHP(0), m_iLv(1), m_iOffencePower(0), m_isDead(false) {
	strcpy_s(m_playerInfo.m_szName, "");
	strcpy_s(m_playerInfo.m_szJob, "");
}

Player::Player(char _szName[], int _iJob) : m_iTotalHP(0), m_iCurrHP(0), m_iLv(1), m_iOffencePower(0), m_isDead(false) {
	strcpy_s(m_playerInfo.m_szName, _szName);
	if (_iJob == 1) {
		strcpy_s(m_playerInfo.m_szJob, "전사");
		m_iTotalHP = 100;
		m_iOffencePower = 10;
	}
	else if (_iJob == 2) {
		strcpy_s(m_playerInfo.m_szJob, "법사");
		m_iTotalHP = 80;
		m_iOffencePower = 30;
	} 
	else if (_iJob == 3) {
		strcpy_s(m_playerInfo.m_szJob, "궁수");
		m_iTotalHP = 90;
		m_iOffencePower = 20;
	} 
	m_iCurrHP = m_iTotalHP;
}

Player::~Player() {
	cout << " [시스템] 플레이어가 소멸됩니다." << endl;
}


void Player::Damaged(int _iDamageHP) {
	m_iCurrHP = m_iCurrHP - _iDamageHP;
}
void Player::Hilled(int _iHillHP) {
	m_iCurrHP = m_iCurrHP + _iHillHP;
}
void Player::LevelUp() {
	m_iLv++;
	m_iTotalHP = m_iTotalHP + 30;
	m_iOffencePower = m_iOffencePower + 2;
}
bool Player::IsDead() {
	if (m_iCurrHP <= 0) return true;
	else return false;
}

int Player::CalcFullHillHP() {
	return (m_iTotalHP - m_iCurrHP);
}

int Player::GetiOffencePower() {
	return m_iOffencePower;
}

void Player::DisplayInfo() {
	cout << "_____________________________________________________________" << endl;
	cout << "| Name: " << m_playerInfo.m_szName << " (" << m_playerInfo.m_szJob << ")\tLv: " << m_iLv << endl;
	cout << "| HP: " << m_iCurrHP << "/" << m_iTotalHP << "\t Offence Power: " << m_iOffencePower << endl;
	cout << "_____________________________________________________________" << endl;
}
