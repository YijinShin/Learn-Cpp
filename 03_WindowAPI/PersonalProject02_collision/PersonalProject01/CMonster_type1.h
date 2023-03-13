#pragma once
#include "Include.h"
#include "CMonster.h"

class CMonster_type1: public CMonster
{
private:

public:
	CMonster_type1();
	virtual ~CMonster_type1();

	virtual void CollisionCheck(CObj* targetObj);

	virtual void Render(HDC hDC);
};

