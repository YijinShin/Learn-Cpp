#include "Monster.h"

#include "stdafx.h"

CMonster::CMonster()
{
}

CMonster::~CMonster()
{
}

void CMonster::Rander()const
{
	cout << "_____________________________________________________________" << endl;
	cout << "| Name: ¸ó½ºÅÍ" << "\t Gold: " << m_stBCINFO.iGold << endl;
	cout << "| HP: " << m_stBCINFO.iCurrHP << "/" << m_stBCINFO.iTotalHP << "\t Offence Power: " << m_stBCINFO.iOffencePower << endl;
	cout << "_____________________________________________________________" << endl;
}

void CMonster::SetType(int _iFieldLv)
{
	m_stBCINFO.iTotalHP = _iFieldLv * 30;
	m_stBCINFO.iOffencePower = _iFieldLv * 2;
	m_stBCINFO.iGold = _iFieldLv * 10;
	m_stBCINFO.iCurrHP = m_stBCINFO.iTotalHP;
}

