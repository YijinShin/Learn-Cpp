#pragma once

class MyBmp;

class CBmpMgr
{
private:
	CBmpMgr();
	~CBmpMgr();

private:
	map<const TCHAR*, MyBmp*>	m_mapBit;

public:
	static CBmpMgr*				m_pInstance;

public:
	static CBmpMgr*				Get_Instance() {
		if (!m_pInstance)
			m_pInstance = new CBmpMgr;

		return m_pInstance;
	}

	static void					Destory_Instance(){
		if (m_pInstance) {
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

public:
	void						Insert_MyBmp(const TCHAR* pFilePath, const TCHAR* pImgKey);
	HDC							Find_MyBmp(const TCHAR* pImgKey);
	
	void						Release();

};

