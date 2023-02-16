#include "stdafx.h"
#include "FieldCreature.h"
#include "Monster.h"

CMonster::CMonster()
{
	memset(&m_stMINFO, 0, sizeof(MINFO));
}

CMonster::~CMonster()
{

}

void CMonster::Initialize()
{
}

void CMonster::DisplayINFO() const
{
	cout << "_____________________________________________________________" << endl;
	cout << "| Name: ����" << endl;
	cout << "| HP: " << m_stFcINFO.iCurrHP << "/" << m_stFcINFO.iTotalHP << "\t Offence Power: " << m_stFcINFO.iOffencePower << endl;
	cout << "_____________________________________________________________" << endl;
}

void CMonster::SetType(int _iFieldLv)
{
	m_stFcINFO.iTotalHP = _iFieldLv * 30;
	m_stFcINFO.iOffencePower = _iFieldLv * 2;
	m_stFcINFO.iCurrHP = m_stFcINFO.iTotalHP;
}
