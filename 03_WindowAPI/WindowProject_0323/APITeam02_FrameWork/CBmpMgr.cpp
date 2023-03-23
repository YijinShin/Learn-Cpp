#include "stdafx.h"
#include "CBmpMgr.h"

#include "Include.h"

#include "MyBmp.h"

CBmpMgr* CBmpMgr::m_pInstance = nullptr;

CBmpMgr::CBmpMgr()
{
}

CBmpMgr::~CBmpMgr()
{
	Release();
}

void CBmpMgr::Insert_MyBmp(const TCHAR* pFilePath, const TCHAR* pImgKey)
{	
	// 같은 키의 MyBmp이 존재하는지 찾기
	auto iter = find_if(m_mapBit.begin(), m_mapBit.end(), CTagFinder(pImgKey));
	
	// 존재하지 않는다면 추가하기 
	if(iter == m_mapBit.end()){

		// 새로운 MyBmp 객체 생성, 파일에서 정보 가져와 세팅하기 
		MyBmp* pNewBit = new MyBmp;
		pNewBit->Load_Bmp(pFilePath);
		
		// map에 넣기
		m_mapBit.emplace(pImgKey, pNewBit);
	}
}

HDC CBmpMgr::Find_MyBmp(const TCHAR* pImgKey)
{
	auto iter = find_if(m_mapBit.begin(), m_mapBit.end(), CTagFinder(pImgKey));

	// 찾는 키의 MyBmp가 없으면 null반환
	if (iter == m_mapBit.end())
		return nullptr;

	// 찾았으면 해당 Bitmap이 그려진 DC반환
	return iter->second->Get_mDC();
}

void CBmpMgr::Release()
{
	for_each(m_mapBit.begin(), m_mapBit.end(), CDeleteMap());
	m_mapBit.clear();
}
