#pragma once
#include "Obj.h";

class CPlayer: public CObj
{
private:

public:
	CPlayer();
	virtual		~CPlayer();

	virtual	void	Initialize();
	virtual int		Update();
	virtual void	Render();
	virtual void	Release();
};

