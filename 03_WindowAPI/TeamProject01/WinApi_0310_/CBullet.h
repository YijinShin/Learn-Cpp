#pragma once
#include "Include.h"
#include "CObj.h"


class CBullet: public CObj
{
private:	
public:
	CBullet();
	virtual ~CBullet();

	virtual void	Initialize()	override;
	virtual	int		Update()		override;
	virtual int		Late_Update()	override;
	virtual void	Render(HDC hDC)	override;
	virtual void	Release()		override;
};

