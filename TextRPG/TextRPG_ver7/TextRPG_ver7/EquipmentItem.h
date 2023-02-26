#pragma once
#include "Define.h"
#include "BaseItem.h"

class CEquipmentItem: public CBaseItem
{
private:
	EITEMINFO m_stEITEMINFO;
public:
	CEquipmentItem();
	CEquipmentItem(BITEMINFO _BITEMINFO, int _iEffect_OffencePower, int _iEffect_DefencePower);
	CEquipmentItem(const CEquipmentItem& origin);
	virtual ~CEquipmentItem();

	virtual void Rander() const;

};

