#pragma once
#include "Include.h"

class CObj
{
private:
	// veriable
	RECT		m_tRect;
	INFO		m_tInfo;
	CVector2	DirVector;	// 방향 단위 백터

	// function

public:
	CObj();
	virtual ~CObj();

	// base Function
	virtual void	Initialize()	PURE;
	virtual int		Update()		PURE;
	virtual void	Late_Update()	PURE;
	virtual void	Render()		PURE;
	virtual void	Release()		PURE;

	// Set Function		
	virtual	void	Set_Rect();											// Info를 기반으로 Rect 계산 
	virtual	void	Set_Info_CenterPos(float _fX, float _fY) {			// Cbj의 중점 좌표를 변경
						m_tInfo.fX = _fX;
						m_tInfo.fY = _fY;
					}
	virtual	void	Set_Info_Size(float _fCX, float _fCY) {				// Obj의 크기를 변경
						m_tInfo.fCX = _fCX;
						m_tInfo.fCY = _fCY;
					}

	// Get Funtion
	RECT	Get_Rect()	const { return m_tRect; }
	INFO	Get_Info()	const { return m_tInfo; }

	// etc Function
	
};

