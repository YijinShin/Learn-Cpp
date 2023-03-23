#pragma once
#include "Include.h"

class CScrollMgr
{
private:
	CScrollMgr();
	~CScrollMgr();

private:
	float			m_fScrollX;
	float			m_fScrollY;
	
public:
	static CScrollMgr*		m_pInstance;

public:
	static CScrollMgr*		Get_Instance() {
		if (!m_pInstance)
			m_pInstance = new CScrollMgr;
		return m_pInstance;
	}

	static void				Destroy_Instance() {
		if (m_pInstance) {
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

public:
	float					Get_ScrollX() { return m_fScrollX; }
	float					Get_ScrollY() { return m_fScrollY; }
	void					Set_ScrollX(float _fX) { m_fScrollX += _fX; }
	void					Set_ScrollY(float _fY) { m_fScrollY += _fY; }

	void					Scroll_Lock();
};

