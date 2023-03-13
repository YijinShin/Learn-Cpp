#include "stdafx.h"
#include "CMainGame.h"
#include "AbstractFactory.h"
#include "CObj.h"
#include "CMonster_type1.h"
#include "CMonster_type2.h"
#include "CPlayer.h"
#include "CBall.h"

CMainGame::CMainGame()
{
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	// get HDC
	m_hDC = GetDC(g_hWnd);

	// create Player  
	m_ObjList[OBJ_PLAYER].push_back(CAbstractFactory<CPlayer>::Create(WINCX / 2.f, WINCY/1.3f));

	// create Monster
	m_ObjList[OBJ_MONSTER].push_back(CAbstractFactory<CMonster_type1>::Create(WINCX/4.f, WINCY/4.f, MON_1));
	m_ObjList[OBJ_MONSTER].push_back(CAbstractFactory<CMonster_type2>::Create(WINCX / 2.f, WINCY / 4.f, MON_2));
}

void CMainGame::Update()
{
	for (int i = 0; i < OBJ_END; i++) {
		for (auto iter = m_ObjList[i].begin(); iter != m_ObjList[i].end();) {
			if ((*iter)->Update() == OBJ_DEAD) {
				Safe_Delete<CObj*>(*iter);
				iter = m_ObjList[i].erase(iter);
			}
			else iter++;
		}
	}
}

void CMainGame::Late_Update()
{
	for (int i = 0; i < OBJ_END; i++) {
		for (auto iter : m_ObjList[i]) {
			iter -> Late_Update();
		}
	}

	// 몬스터와 총알의 충돌 
	for (auto iter : m_ObjList[OBJ_MONSTER]) {
		if (dynamic_cast<CMonster*>(iter)->Get_type() == MON_1) {
			dynamic_cast<CMonster_type1*>(iter)->CollisionCheck(m_ObjList[OBJ_PLAYER].front());
		}
		else if (dynamic_cast<CMonster*>(iter)->Get_type() == MON_2) {
			dynamic_cast<CMonster_type2*>(iter)->CollisionCheck(m_ObjList[OBJ_PLAYER].front());
		}
	}
}

void CMainGame::Render()
{
	// 배경
	Rectangle( m_hDC, 0, 0, WINCX, WINCY );
	// 게임 오브젝트 
	
	for (int i = 0; i < OBJ_END; i++) {
		for (auto iter : m_ObjList[i]) {
			iter -> Render(m_hDC);
		}
	}
}

void CMainGame::Release()
{
	for (int i = 0; i < OBJ_END; i++) {
		for (auto iter = m_ObjList[i].begin(); iter != m_ObjList[i].end();) {
			Safe_Delete<CObj*>(*iter);
			iter = m_ObjList[i].erase(iter);
		}
	}
}
