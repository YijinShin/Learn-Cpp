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
	// ���� Ű�� �ִ��� Ȯ�� (�̰� ���� map�� �ߺ�Ű�� �������� ������ Ű�� ��� ���ڿ��ιٶ��� ���� Ȯ���ؾ��ϴ°��̴�.)
	auto	iter = find_if(m_mapBit.begin(), m_mapBit.end(), CTagFinder(pImgKey));

	// �ߺ��� �������� ������ 
	if (iter == m_mapBit.end()) {
		
		// MyBmp ��ü ����� 
		CMyBmp* newBmp = new CMyBmp;
		newBmp->Load_Bmp(pFilePath);

		// MyBmp ��ü�� map�� �ֱ� 
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
