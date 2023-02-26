#pragma once
#include "BaseCreature.h"

class CInventory;

class CPlayer: public CBaseCreature
{
private:
	PINFO m_stPINFO;
	CInventory* m_cpInventory;
public:
	CPlayer();
	~CPlayer();

	void Initialize();
	void Release();

	virtual void Rander() const;
	void LevelUp();
	void SetJob();
	void SetName();

	// Gold
	void EarnGold(int _iGold);
	void PurchaseGold(int _iGold);

	friend CInventory;

};

