#pragma once
#include "CObj.h"

class CObstacle: public CObj
{
private:

public:
	CObstacle();
	virtual ~CObstacle();

	// Base Function
	virtual void	Initialize()	override;
	virtual int		Update()		override;
	virtual void	Late_Update()	override;
	virtual void	Render(HDC hDC)	override;
	virtual void	Release()		override;
};

