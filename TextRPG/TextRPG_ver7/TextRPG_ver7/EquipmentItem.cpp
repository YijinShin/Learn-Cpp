#include "EquipmentItem.h"

#include "stdafx.h"

CEquipmentItem::CEquipmentItem()
{
	memset(&m_stEITEMINFO, 0, sizeof(m_stEITEMINFO));
}

CEquipmentItem::CEquipmentItem(BITEMINFO _BITEMINFO, int _iEffect_OffencePower, int _iEffect_DefencePower)
	: CBaseItem(_BITEMINFO)
{
	m_stEITEMINFO.iEffect_OffencePower = _iEffect_OffencePower;
	m_stEITEMINFO.iEffect_DefencePower = _iEffect_DefencePower;
}

CEquipmentItem::~CEquipmentItem()
{
}

void CEquipmentItem::Rander() const
{
	cout << "*******************************" << endl;
	cout << "No. " << m_stBITEMINFO.iId << "\t�̸�: " << m_stBITEMINFO.szName << endl;
	cout << "����: " << m_stBITEMINFO.iPrice << " Gold" << endl;
	cout << "����: " << m_stBITEMINFO.strInfo << "\t����: "<<m_stEITEMINFO.iEffect_OffencePower<<"\t���: " << m_stEITEMINFO.iEffect_DefencePower << endl;
	cout << "*******************************" << endl;
}


