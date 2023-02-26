#pragma once
#include "Define.h"
#include <vector>

class CEquipmentItem;
class CConsumableItem;
class CPlayer;

class CStore
{
private:
	STOREINFO m_stStoreInfo;
	vector< CEquipmentItem*> m_vecEquipments;
	vector<CConsumableItem*> m_vecConsumables;
	CPlayer* m_cpPlayer;
public:
	CStore();
	~CStore();

	void Initialize(CPlayer* _cpPlayer);
	void Update();
	void Release();

	void SetType(int _iType);
	void SellMenu();
	void BuyMenu();

	void ShowItemList();
	void Sell(int _iItemId);
	void Buy(int _iItemId);

	void ClearItemList();
};

