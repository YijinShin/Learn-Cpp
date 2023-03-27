#pragma once
#include "CObj.h"
#include <vector>

class CTileMgr
{
private:
	CTileMgr();
	~CTileMgr();
private:
	vector<CObj*>			m_vecTile;
private:
	static CTileMgr*		m_pInstance;

public:
	static CTileMgr*		Get_Instance() {
		if (!m_pInstance)
			m_pInstance = new CTileMgr;
		return m_pInstance;
	}

	static void				Destroy_Instance() {
		if (m_pInstance) {
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

public:
	void	Initialize();
	void	Update();
	void	Late_Update();
	void	Render(HDC hDC);
	void	Release();

public:
	void		Picking(POINT _pt, int _iDrawID, int _iOption);
	
	void		Save_TileData();
	void		Load_TileData();

};

