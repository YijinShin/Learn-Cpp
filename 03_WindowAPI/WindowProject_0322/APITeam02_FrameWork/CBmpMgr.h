#pragma once
#include "MyBmp.h"

class CBmpMgr
{
private:
	CBmpMgr();
	~CBmpMgr();

public:
	map< const TCHAR* , CMyBmp* >	m_mapBit;

public:
	static CBmpMgr*					m_pInstance;	

public:
	static CBmpMgr*			Get_Instance() {
		if (!m_pInstance)
			m_pInstance = new CBmpMgr;

		return m_pInstance;
	}

	static void				Destroy_Instance() {
		if (m_pInstance) {
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

public:
	void					Insert_Bmp(const TCHAR*  pFilePath, const TCHAR* pImgKey);
	HDC						Find_Bmp(const TCHAR* pImgKey);
	void					Release();
};

