#pragma once
#include "CLine.h"

class CLineMgr
{
private:
	CLineMgr();
	~CLineMgr();

private:
	static CLineMgr*	m_pInstance;
private:
	list<CLine*>		m_LineList;

public:
	void		Initialize();
	void		Render(HDC hDC);
	void		Release();

	bool		Collision_Line(float _fX, float _fY, float* pCalcY);
	bool		Check_LineExist(float _fX);

public:
	static CLineMgr*	Get_Instance() {
		if (!m_pInstance)
			m_pInstance = new CLineMgr;

		return m_pInstance;
	}

	static void		Destroy_Instance() {
		if (!m_pInstance) {
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

};

