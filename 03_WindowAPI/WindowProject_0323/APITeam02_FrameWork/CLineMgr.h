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
	void		Initialize(int _eStageID);
	void		Update();
	void		Render(HDC hDC);
	void		Release();

	void		Save_LineData();
	void		Lode_LineData();

	void		Set_FileName(int eStageID);

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

// TODO 추가된 함수 
public:
	bool		SYJ_Collision_Line(float _fX, float _fY, float* pCalcY);
	
};

