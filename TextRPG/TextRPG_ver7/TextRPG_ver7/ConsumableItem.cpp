#include "ConsumableItem.h"

#include "stdafx.h"

CConsumableItem::CConsumableItem()
{
	memset(&m_stCITEMINFO, 0, sizeof(m_stCITEMINFO));
}

CConsumableItem::CConsumableItem(BITEMINFO _BITEMINFO, int _iEffect_HillHP, int _iEffect_DamageHP)
	: CBaseItem(_BITEMINFO)
{
	m_stCITEMINFO.iEffect_HillHP = _iEffect_HillHP;
	m_stCITEMINFO.iEffect_DamageHP = _iEffect_DamageHP;
}

CConsumableItem::~CConsumableItem()
{
}

void CConsumableItem::Rander() const
{
	cout << "*******************************" << endl;
	cout << "No. " << m_stBITEMINFO.iId << "\t�̸�: " << m_stBITEMINFO.szName << endl;
	cout << "����: " << m_stBITEMINFO.iPrice << " Gold" << endl;
	cout << "����: " << m_stBITEMINFO.strInfo << "\t��: +" << m_stCITEMINFO.iEffect_HillHP << "\t������: -" << m_stCITEMINFO.iEffect_DamageHP << endl;
	cout << "*******************************" << endl;
}

