#pragma once
#include "FieldCreature.h"

class CMonster: public CFieldCreature
{
private:
	MINFO m_stMINFO;
public:
	CMonster();
	~CMonster();

	void Initialize();
	void DisplayINFO() const;

	void SetType(int _iFieldLv);
};

