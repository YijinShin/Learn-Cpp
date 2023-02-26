#pragma once
#include "Define.h"

class CBaseItem
{
protected:
	BITEMINFO m_stBITEMINFO;
public:
	CBaseItem();
	CBaseItem(BITEMINFO _BITEMINFO);
	virtual ~CBaseItem();

	virtual void Rander() const = 0;
	int GetId() const { return m_stBITEMINFO.iId; };
};

