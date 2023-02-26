#pragma once
#include "Define.h"

class CBaseCreature
{
protected:
	BCINFO m_stBCINFO;
	CBaseCreature();
	virtual ~CBaseCreature();
public:
	
	bool IsDead();
	virtual void Rander() const = 0;

	// Set
	inline void Damaged(int iDamageHP) { m_stBCINFO.iCurrHP -= iDamageHP; }
	inline void Hilled(int iHillHP) { m_stBCINFO.iCurrHP += iHillHP; }
	inline void SetCurrHP(int _iCurrHP) { m_stBCINFO.iCurrHP = _iCurrHP; }
	inline void SetOffencePower(int _iOffencePower) { m_stBCINFO.iOffencePower = _iOffencePower; }
	
	// Get 
	inline int GetOffencePower() const { return m_stBCINFO.iOffencePower; }
	inline int GetTotalHP() const { return m_stBCINFO.iTotalHP; };
	inline int GetGold() const { return m_stBCINFO.iGold; };
};

