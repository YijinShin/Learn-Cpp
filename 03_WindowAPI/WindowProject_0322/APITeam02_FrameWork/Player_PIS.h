#pragma once

#include "CPlayer.h"

class Player_PIS : public CPlayer
{
public:
	Player_PIS();
	virtual ~Player_PIS();

public:
	virtual void	Initialize()	override;
	virtual int		Update()		override;
	virtual void	Late_Update()	override;
	virtual void	Render(HDC hdc)	override;
	virtual void	Release()		override;
};