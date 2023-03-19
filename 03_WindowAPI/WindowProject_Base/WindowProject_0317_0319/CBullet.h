#pragma once
#include "CObj.h"

class CBullet: public CObj
{
private:

public:
	CBullet();
	virtual ~CBullet();

	// Pure virtual Function
	virtual void	Initialize()	override;
	virtual int		Update()		override;
	virtual void	Late_Update()	override;
	virtual void	Render(HDC hDC)	override;
	virtual void	Release()		override;

	// Set function

	// Get function

	// Etc function
	virtual void Update_Info_CenterPos();
};

