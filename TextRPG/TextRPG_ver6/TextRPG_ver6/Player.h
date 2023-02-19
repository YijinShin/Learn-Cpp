#pragma once
#include "FieldCreature.h"

class CPlayer: public CFieldCreature
{
private:
	PINFO m_stPINFO;
public:
	CPlayer();
	~CPlayer();

	void Initialize();

	void DisplayINFO() const;
	void LevelUp();
	void SetJob();
	void SetName();

	void AddGold(int _iGold);
};

