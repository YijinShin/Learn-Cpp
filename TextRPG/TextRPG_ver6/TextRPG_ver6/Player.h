#pragma once
#include "FieldCreature.h"

class CPlayer: public CFieldCreature
{
private:
	PINFO m_stPINFO;
public:
	CPlayer();
	~CPlayer();

	void Initialize();

	void DisplayINFO() const;
	void LevelUp();
	void SetJob();
	void SetName();

	void WorkInventory(bool isField);

	// gold 
	void EarnGold(int _iGold);
	void PurchaseGold(int _iGold);

	// inventory, item 
	void ShowInventory()const;
	int FindItemIndex(int _iItemId) const;
	void RemoveItem(int _iItemIndex);
	void EarnItem(ITEMINFO _item);
	int GetResellPrice(int _iItemIndex) const;
	int GetInventoryCnt() const;

};

