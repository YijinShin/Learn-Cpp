#pragma once
#include "CObj.h"

class CFlag: public CObj
{
private:

public:
	CFlag();
	virtual ~CFlag();

	virtual void	Initialize()	override;
	virtual int		Update()		override;
	virtual void	Late_Update()	override;
	virtual void	Render(HDC hDC)	override;
	virtual void	Release()		override;
};

