#pragma once

#include "CObj.h"

class CObjMgr
{
private:
	CObjMgr();
	~CObjMgr();

private:
	static CObjMgr*		m_pInstance;
	
private:
	list<CObj*>		m_ObjList[OBJ_END];

public:
	void	Add_Object(OBJID eObjID, CObj* pObj);

public:
	void	Update();
	void	Late_Update();
	void	Render(HDC hDC);
	void	Release();

public:
	static CObjMgr*		Get_Instance() {
		if (!m_pInstance) 
			m_pInstance = new CObjMgr;
		
		return m_pInstance;
	}

	static void		Destroy_Instance() {
		if (!m_pInstance) {
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}
};

