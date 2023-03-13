#include "stdafx.h"
#include "CMainGame.h"
#include "AbstractFactory.h"
#include "CObj.h"
#include "CMonster.h"
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


	// create Ball
	m_ObjList[OBJ_Ball].push_back(CAbstractFactory<CBall>::Create( WINCX/2.f, WINCY/2.f));

	// create Monster
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
