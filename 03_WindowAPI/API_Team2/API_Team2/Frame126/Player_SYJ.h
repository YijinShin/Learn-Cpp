#pragma once
#include "Player.h"

class CPlayer_SYJ: public CPlayer
{
private:
	virtual	void		Key_Input(void);
public:
	CPlayer_SYJ();
	virtual ~CPlayer_SYJ();

	virtual int Update();

	void Calc_Dir_Mouse();
};

