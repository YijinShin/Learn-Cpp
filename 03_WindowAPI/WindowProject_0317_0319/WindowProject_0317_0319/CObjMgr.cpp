#include "stdafx.h"
#include "CObjMgr.h"

CObjMgr*	CObjMgr::m_pInstance = nullptr;

CObjMgr::CObjMgr()
{
}

CObjMgr::~CObjMgr()
{
	Release();
}

void CObjMgr::Add_Object(OBJID eObjID, CObj* pObj)
{
	if (eObjID >= OBJ_END || pObj == nullptr) return;
	m_ObjList[eObjID].push_back(pObj);

}

void CObjMgr::Update()
{
	int iResult(0);

	for (size_t i = 0; i < OBJ_END; i++) {
		for (auto iter = m_ObjList[i].begin(); iter != m_ObjList[i].end();) {
			iResult = (*iter)->Update();

			if (iResult == OBJ_DEAD) {
				Safe_Delete<CObj*>(*iter);
				iter = m_ObjList[i].erase(iter);
			}
			else iter++;
		}
	}
}

void CObjMgr::Late_Update()
{
	for (size_t i = 0; i < OBJ_END; i++) {
		for (auto iter: m_ObjList[i]) {
			iter->Late_Update();
		}
	}
}

void CObjMgr::Render(HDC hDC)
{
	for (size_t i = 0; i < OBJ_END; i++) {
		for (auto iter : m_ObjList[i]) {
			iter->Render(hDC);
		}
	}
}

void CObjMgr::Release()
{
	for (size_t i = 0; i < OBJ_END; i++) {
		for_each( m_ObjList[i].begin(), m_ObjList[i].end(), Safe_Delete<CObj*>);
		m_ObjList[i].clear();
	}
}
