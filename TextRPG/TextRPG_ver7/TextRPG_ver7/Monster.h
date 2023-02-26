#pragma once
#include "BaseCreature.h"

class CMonster: public CBaseCreature
{
private:
public:
	CMonster();
	~CMonster();

	virtual void Rander() const;
	void SetType(int _iFieldLv);
};

