#include "stdafx.h"
#include "Monster.h"
using namespace std;

CMonster::CMonster()
{
	memset(&m_monsterInfo, 0, sizeof(m_monsterInfo));
}

CMonster::~CMonster()
{
}

void CMonster::Initialize(int _iFieldLv)
{
	m_monsterInfo.iTotalHP_ = _iFieldLv * 30;
	m_monsterInfo.iOffencePower_ = _iFieldLv * 2;
	m_monsterInfo.iCurrHP_ = m_monsterInfo.iTotalHP_;
}

void CMonster::SetCurrHP(int _alpaHP)
{
	m_monsterInfo.iCurrHP_ = m_monsterInfo.iCurrHP_ + _alpaHP;
}

bool CMonster::IsDead()
{
	if (m_monsterInfo.iCurrHP_ <= 0) return true;
	else return false;
}

int CMonster::GetOffencePower()
{
	return m_monsterInfo.iOffencePower_;
}

void CMonster::DisplayInfo()
{
	cout << "_____________________________________________________________" << endl;
	cout << "| Name: ¸ó½ºÅÍ" << endl;
	cout << "| HP: " << m_monsterInfo.iCurrHP_ << "/" << m_monsterInfo.iTotalHP_ << "\t Offence Power: " << m_monsterInfo.iOffencePower_ << endl;
	cout << "_____________________________________________________________" << endl;
}
