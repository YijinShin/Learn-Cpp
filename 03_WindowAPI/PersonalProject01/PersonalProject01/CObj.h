#pragma once
#include "Include.h"

class CObj
{
private:

protected:

	INFO	m_tInfo;
	RECT	m_tRect;
	float	m_fSpeed;
	bool	m_bIsDead;

public:
	CObj();
	virtual ~CObj();

	virtual void		Initialize()	PURE;
	virtual int			Update()		PURE;
	virtual void		Late_Update()	PURE;
	virtual void		Render(HDC hDC)	PURE;
	virtual void		Release()		PURE;

	void	Set_Rect();
	void	Set_Pos(float _fX, float _fY) {
		m_tInfo.fX = _fX;
		m_tInfo.fY = _fY;
	}

	RECT	Get_Rect() const {
		return m_tRect;
	}
};


