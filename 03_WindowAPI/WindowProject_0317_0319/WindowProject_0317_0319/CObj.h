#pragma once
#include "Include.h"

class CObj
{
private:
	// veriable
	RECT		m_tRect;
	INFO		m_tInfo;
	CVector2	DirVector;	// ���� ���� ����

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
	virtual	void	Set_Rect();											// Info�� ������� Rect ��� 
	virtual	void	Set_Info_CenterPos(float _fX, float _fY) {			// Cbj�� ���� ��ǥ�� ����
						m_tInfo.fX = _fX;
						m_tInfo.fY = _fY;
					}
	virtual	void	Set_Info_Size(float _fCX, float _fCY) {				// Obj�� ũ�⸦ ����
						m_tInfo.fCX = _fCX;
						m_tInfo.fCY = _fCY;
					}

	// Get Funtion
	RECT	Get_Rect()	const { return m_tRect; }
	INFO	Get_Info()	const { return m_tInfo; }

	// etc Function
	
};

