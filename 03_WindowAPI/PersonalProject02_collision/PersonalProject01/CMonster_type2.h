#pragma once
#include "CMonster.h"

class CMonster_type2: public CMonster
{
private:

public:
	CMonster_type2();
	virtual ~CMonster_type2();

	virtual void Render(HDC hDC);
	virtual void CollisionCheck(CObj* targetObj);
};

