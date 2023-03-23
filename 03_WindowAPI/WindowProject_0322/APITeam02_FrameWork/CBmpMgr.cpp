#include "stdafx.h"
#include "CBmpMgr.h"

CBmpMgr*		CBmpMgr::m_pInstance = nullptr;

CBmpMgr::CBmpMgr()
{
}

CBmpMgr::~CBmpMgr()
{
}

void CBmpMgr::Insert_Bmp(const TCHAR* pFilePath, const TCHAR* pImgKey)
{
	// 같은 키가 있는지 확인 (이게 원래 map은 중복키를 인정하지 않지만 키가 상수 문자열인바람에 직접 확인해야하는것이다.)
	auto	iter = find_if(m_mapBit.begin(), m_mapBit.end(), CTagFinder(pImgKey));

	// 중복된 아이템이 없으면 
	if (iter == m_mapBit.end()) {
		
		// MyBmp 객체 만들기 
		CMyBmp* newBmp = new CMyBmp;
		newBmp->Load_Bmp(pFilePath);

		// MyBmp 객체를 map에 넣기 
		m_mapBit.emplace(pImgKey, newBmp);

	}	
}

HDC CBmpMgr::Find_Bmp(const TCHAR* pImgKey)
{
	auto	iter = find_if(m_mapBit.begin(), m_mapBit.end(), CTagFinder(pImgKey));

	if (iter == m_mapBit.end())
		return nullptr;

	return iter->second->Get_MemDC();
}

void CBmpMgr::Release()
{
	for_each(m_mapBit.begin(), m_mapBit.end(), CDeleteMap());
	
	m_mapBit.clear();
}
