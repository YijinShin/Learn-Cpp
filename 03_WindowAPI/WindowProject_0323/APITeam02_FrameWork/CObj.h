#pragma once
#include "Include.h"

class CObj
{
protected:
	// variable
	RECT		m_tRect;
	INFO		m_tInfo;

	int			m_iHP;

	float		m_fSpeed;
	
	TCHAR* m_pFrameKey;

	// for color
	HPEN	 MyPen;
	HPEN	OldPen;
	


	// function

public:
	CObj();
	virtual ~CObj();

	// Pure virtual Function
	virtual void	Initialize()	PURE;
	virtual int		Update()		PURE;
	virtual void	Late_Update()	PURE;
	virtual void	Render(HDC hDC)	PURE;
	virtual void	Release()		PURE;

	// Set function									
	void	Set_Info_CenterPos(float _fX, float _fY) {			
						m_tInfo.fX = _fX;
						m_tInfo.fY = _fY;
					}
	void	Set_Info_Size(float _fCX, float _fCY) {				
						m_tInfo.fCX = _fCX;
						m_tInfo.fCY = _fCY;
					}
	void	Set_HP(int _iHP)			{ m_iHP = _iHP; }
	void	Set_fSpeed(float _fSpeed)	{ m_fSpeed = _fSpeed; }
	void	Set_Dir(CVector2 _cDir)		{ m_tInfo.Dir = _cDir; }
	void	Set_FrameKey(TCHAR* pFrameKey) { m_pFrameKey = pFrameKey; }
	
	// Get funtion
	RECT	Get_Rect()	const { return m_tRect; }
	INFO	Get_Info()	const { return m_tInfo; }
	int		Get_HP()	const { return m_iHP; }
	float	Get_Speed()	const { return m_fSpeed; }

	// Etc function
	virtual	void	Update_Rect();
	void			LookAt(POINT ptDistPos);		// Obj가 DistPos 를 바라보는 방향 단위 백터 계산하는 함수 


};

