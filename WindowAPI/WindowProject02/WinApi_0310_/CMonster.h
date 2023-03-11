#pragma once
#include "CObj.h"

class CMonster: public CObj
{
private:
public:
	CMonster();
	virtual ~CMonster();

	virtual void		Initialize()	override;
	virtual	int			Update()		override;
	virtual int			Late_Update()	override;
	virtual void		Render(HDC hDC)	override;
	virtual void		Release()		override;
};

