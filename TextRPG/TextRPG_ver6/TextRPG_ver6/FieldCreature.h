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
	void Hilled(int _iHill) { 
		m_stFcINFO.iCurrHP += _iHill; 
		if (m_stFcINFO.iCurrHP > m_stFcINFO.iTotalHP) m_stFcINFO.iCurrHP = m_stFcINFO.iTotalHP;
	}

	/* Set function */
	void SetCurrHP(int _iCurrHP);
	void SetOffencePower(int _iOffencePower);
	void SetGold(int _iGold);

	/* Get function */
	int GetOffencePower() const;
	int GetTotalHP() const;
	int GetGold() const;

};

