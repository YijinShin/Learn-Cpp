#pragma once
#include "Include.h"
#include "CObj.h"

class CPlayer: public CObj
{
private:

public:
	CPlayer();
	virtual ~CPlayer();

	virtual void		Initialize()	override;
	virtual int			Update()		override;
	virtual void		Late_Update()	override;
	virtual void		Render(HDC hDC)	override;
	virtual void		Release()		override;

	void		Key_Input();
};

