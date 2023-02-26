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
	cout << "No. " << m_stBITEMINFO.iId << "\t이름: " << m_stBITEMINFO.szName << endl;
	cout << "가격: " << m_stBITEMINFO.iPrice << " Gold" << endl;
	cout << "설명: " << m_stBITEMINFO.strInfo << "\t힐: +" << m_stCITEMINFO.iEffect_HillHP << "\t데미지: -" << m_stCITEMINFO.iEffect_DamageHP << endl;
	cout << "*******************************" << endl;
}

