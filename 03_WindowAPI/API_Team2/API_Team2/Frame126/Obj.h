#pragma once

#include "Include.h"

class CObj abstract
{
public:
	CObj();
	virtual ~CObj();

public:
	virtual void		Initialize(void)	PURE;
	virtual int			Update(void)		PURE;
	virtual void		Late_Update(void)	PURE;
	virtual void		Render(HDC hDC)		PURE;
	virtual void		Release(void)		PURE;

public:
	void			Update_Rect(void);

	void			Set_Pos(float _fX, float _fY) { m_tInfo.fX = _fX; m_tInfo.fY = _fY; }
	void			Set_Size(float _fCX, float _fCY) { m_tInfo.fCX = _fCX; m_tInfo.fCY = _fCY; }
	void			Set_Degree(float _fDegree) { m_fDegree = _fDegree; }

protected:
	INFO			m_tInfo;
	RECT			m_tRect;
	Vector2			m_direction;

	float			m_fSpeed;
	float			m_fRotateSpeed;
	float			m_fDegree;

	bool			m_isDead;
};

