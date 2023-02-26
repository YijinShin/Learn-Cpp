#pragma once
#include "BaseItem.h"
#include "Define.h"

class CConsumableItem: public CBaseItem
{
private:
	CITEMINFO m_stCITEMINFO;
public:
	CConsumableItem();
	CConsumableItem(BITEMINFO _BITEMINFO, int iEffect_HillHP, int iEffect_DamageHP);
	~CConsumableItem();

	virtual void Rander() const;
};

