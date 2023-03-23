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
	// ���� Ű�� MyBmp�� �����ϴ��� ã��
	auto iter = find_if(m_mapBit.begin(), m_mapBit.end(), CTagFinder(pImgKey));
	
	// �������� �ʴ´ٸ� �߰��ϱ� 
	if(iter == m_mapBit.end()){

		// ���ο� MyBmp ��ü ����, ���Ͽ��� ���� ������ �����ϱ� 
		MyBmp* pNewBit = new MyBmp;
		pNewBit->Load_Bmp(pFilePath);
		
		// map�� �ֱ�
		m_mapBit.emplace(pImgKey, pNewBit);
	}
}

HDC CBmpMgr::Find_MyBmp(const TCHAR* pImgKey)
{
	auto iter = find_if(m_mapBit.begin(), m_mapBit.end(), CTagFinder(pImgKey));

	// ã�� Ű�� MyBmp�� ������ null��ȯ
	if (iter == m_mapBit.end())
		return nullptr;

	// ã������ �ش� Bitmap�� �׷��� DC��ȯ
	return iter->second->Get_mDC();
}

void CBmpMgr::Release()
{
	for_each(m_mapBit.begin(), m_mapBit.end(), CDeleteMap());
	m_mapBit.clear();
}
