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
	void			Set_Dead() { m_isDead = true; }
	void			Set_Vector2(Vector2 _fVec2) { m_tInfo.Dir = _fVec2; };


	INFO			Get_Info() const { return m_tInfo; }
	RECT			Get_Rect() const { return m_tRect; }


	Vector2	LookAt(INFO	_inSource, INFO _inTarget) {
		Vector2 newVector(_inTarget.fX - _inSource.fX, _inTarget.fY - _inSource.fY);
		return	newVector.GetNormalize();
	}

	Vector2	LookAt(INFO	_inSource, POINT _inTarget) {
		Vector2 newVector(_inTarget.x - _inSource.fX, _inTarget.y - _inSource.fY);
		return	newVector.GetNormalize();
	}


protected:
	INFO			m_tInfo;
	RECT			m_tRect;

	float			m_fSpeed;
	float			m_fRotateSpeed;
	float			m_fDegree;

	bool			m_isDead;
};

