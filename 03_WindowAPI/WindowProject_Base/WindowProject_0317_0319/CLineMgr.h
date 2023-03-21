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
private:
	LINEPOINT			m_tLinePoint[END];
	LPCWSTR				m_sFileName;

public:
	void		Initialize(int eStageID);
	void		Update();
	void		Render(HDC hDC);
	void		Release();

	void		Save_LineData();
	void		Lode_LineData();

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

