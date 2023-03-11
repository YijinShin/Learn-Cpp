#pragma once
#include "Include.h"

class CObj
{
private:

protected:
	RECT		m_tRect;
	INFO		m_tInfo;
	float		m_fSpeed;
	bool		m_bDead;

public:
	CObj();
	virtual ~CObj();

	virtual void		Initialize()	PURE;
	virtual	int			Update()		PURE;	
	virtual int			Late_Update()	PURE;
	virtual void		Render(HDC hDC)	PURE;
	virtual void		Release()		PURE;

	void		Set_Rect();
	void		Set_Pos(float _fX, float _fY) {
		m_tInfo.fX = _fX;
		m_tInfo.fY = _fY;
	}
};

