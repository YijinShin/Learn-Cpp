#pragma once
#include <Windows.h>
#include "CPlayer.h"

class CPlayer_SHH : public CPlayer
{

public:
	CPlayer_SHH();
	virtual ~CPlayer_SHH();

public:
	virtual void	Initialize()	override;
	virtual int		Update()		override;
	virtual void	Late_Update()	override;
	virtual void	Render(HDC hdc)	override;
	virtual void	Release()		override;
};