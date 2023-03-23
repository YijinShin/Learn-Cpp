#pragma once

#include "CPlayer.h"

class CPlayer_AJS : public CPlayer
{
public:
	CPlayer_AJS();
	virtual ~CPlayer_AJS();

public:
	virtual void	Initialize()	override;
	virtual int		Update()		override;
	virtual void	Late_Update()	override;
	virtual void	Render(HDC hDC)	override;
	virtual void	Release()		override;
};