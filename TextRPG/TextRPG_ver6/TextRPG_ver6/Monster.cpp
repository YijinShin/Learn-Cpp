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

void CMonster::DisplayINFO() const
{
	cout << "_____________________________________________________________" << endl;
	cout << "| Name: ¸ó½ºÅÍ" << endl;
	cout << "| HP: " << m_stFcINFO.iCurrHP << "/" << m_stFcINFO.iTotalHP << "\t Offence Power: " << m_stFcINFO.iOffencePower << endl;
	cout << "_____________________________________________________________" << endl;
}
