#include "Inventory.h"

#include "stdafx.h"
#include "EquipmentItem.h"
#include "ConsumableItem.h"

CInventory::CInventory() 
{
	m_vecEquipments = new vector<CEquipmentItem*>(5);
	m_vecConbumables = new vector<CConsumableItem*>(5);
}

CInventory::~CInventory()
{
	Release();
}

void CInventory::Initialize()
{
	// 기본 장비 넣어두기 
}

void CInventory::Release()
{
	Safe_Delete(m_vecEquipments);
	Safe_Delete(m_vecConbumables);
}

void CInventory::Rander() const
{
	
}

void CInventory::AddItem(CEquipmentItem _cEquipmentItem)
{
	m_vecEquipments->push_back(new CEquipmentItem(_cEquipmentItem));
}

void CInventory::AddItem(CConsumableItem _cConsumableItem)
{
	m_vecConbumables->push_back(new CConsumableItem(_cConsumableItem));
}

void CInventory::LossItem(int _iType, int _iId)
{	
	if (_iType == 1) 
		m_vecEquipments->erase(m_vecEquipments->begin() + _iId);
	else if (_iType == 2)
		m_vecConbumables->erase(m_vecConbumables->begin() + _iId);
}

int CInventory::IsFull(int _iType)
{
	if (_iType == 1) {
		return m_vecEquipments->size();
	}else if (_iType == 2) {
		return m_vecConbumables->size();
	}
	return 0;
}

bool CInventory::isExist(int _iType, int _iId)
{
	bool isExist(false);

	if (_iType == 1) {
		for (int i = 0; i < m_vecEquipments->size() < i++) {
			if ((*m_vecEquipments)[i]->GetId() == _iId) {
				isExist = true;
				break;
			}
		}
	}
	else if (_iType == 2) {
		for (int i = 0; i < m_vecConbumables->size() < i++) {
			if ((*m_vecConbumables)[i]->GetId() == _iId) {
				isExist = true;
				break;
			}
		}
	}
	return isExist;
}



