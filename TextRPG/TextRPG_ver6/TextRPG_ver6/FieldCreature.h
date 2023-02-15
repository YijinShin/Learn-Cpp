#pragma once
#include "Define.h"

class CFieldCreature
{
private:
	
protected:
	FCINFO m_stFcINFO;

	CFieldCreature();
	~CFieldCreature();

public:
	bool IsDead();
	void Damaged(int _iAttack);

	/* Set function */
	void SetCurrHP(int _iCurrHP);
	void SetOffencePower(int _iOffencePower);

	/* Get function */
	int GetOffencePower() const;
	int GetTotalHP() const;

};

