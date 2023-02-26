#pragma once
#include <vector>
#include "Define.h"
using namespace std;

class CEquipmentItem;
class CConsumableItem;
class CPlayer;

class CInventory
{
private:
	vector< CEquipmentItem* >* m_vecEquipments;
	vector< CConsumableItem* >* m_vecConbumables;
public:
	CInventory();
	~CInventory();

	void Initialize();
	void Release();

	void Rander() const;
	void AddItem(CEquipmentItem _cEquipmentItem);
	void AddItem(CConsumableItem _cConsumableItem);
	void LossItem(int _iType, int _iId);

	int IsFull(int _iType);
	bool isExist(int _iType, int _iId);

	friend CPlayer;
};

