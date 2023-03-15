#include "stdafx.h"
#include "MainGame.h"
#include "Player.h"
#include "Monster.h"
#include "AbstractFactory.h"
#include "CollisionMng.h"


// Player
#include "Player_SYJ.h"

// Monster

// Bullet

CMainGame::CMainGame(): m_iStage(0)
{
}


CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize(void)
{
	m_DC = GetDC(g_hWnd);
	
	// 스테이지 세팅 
	Set_ObjList();

}

void CMainGame::Update(void)
{
	for (size_t i = 0; i < OBJ_END; i++) {

		for (auto iter = m_objList[i].begin(); iter != m_objList[i].end();) {

			if ((*iter)->Update() == OBJ_DEAD) {

				Safe_Delete<CObj*>(*iter);
				iter = m_objList[i].erase(iter);

			}
			else iter++;
		}
	}
}

void CMainGame::LateUpdate()
{
	// 스테이지가 종료되면	=> m_objList를 다음 스테이지에 맞게 갱신 
	if (m_objList[OBJ_MONSTER].empty()) {
		m_iStage++;
		Release();				// m_objList 비우기 
		Set_ObjList();			// 스테이지에 맞게 세팅 
	}

	// 스테이지가 종료되지 않았으면 => 게임 객체의 Late_Update()
	else {
		for (int i = 0; i < OBJ_END; i++) {
			for (auto iter = m_objList[i].begin(); iter != m_objList[i].end(); iter++) {
				(*iter)->Late_Update();
			}
		}
	}

	// 총알과 몬스터 충돌 체크 
	CCollisionMng::Collision_Sphere(m_objList[OBJ_BULLET], m_objList[OBJ_MONSTER]);
	CCollisionMng::Collision_Sphere(m_objList[OBJ_MONSTERBULLET], m_objList[OBJ_PLAYER]);
}

void CMainGame::Render(void)
{
	Rectangle(m_DC, 0, 0, WINCX, WINCY);

	for (int i = 0; i < OBJ_END; i++) {
		for (auto iter = m_objList[i].begin(); iter != m_objList[i].end(); iter++) {
			(*iter)->Render(m_DC);
		}
	}
}

void CMainGame::Release(void)
{
	for (int i = 0; i < OBJ_END; i++) {
		for (auto iter = m_objList[i].begin(); iter != m_objList[i].end();) {

			Safe_Delete<CObj*>(*iter);
			iter = m_objList[i].erase(iter);
		}
	}
}

void CMainGame::Set_ObjList()
{
	// 스테이지 기본
	if (m_iStage == 0) {
		// Player
		m_objList[OBJ_PLAYER].push_back(CAbstractFactory<CPlayer>::Create(WINCX / 2.f, WINCY / 1.5f));
		dynamic_cast<CPlayer*>(m_objList[OBJ_PLAYER].front())->Set_BulletList(&m_objList[OBJ_BULLET]);

		// Monster
		m_objList[OBJ_MONSTER].push_back(CAbstractFactory<CMonster>::Create(WINCX / 3.f, WINCY / 4.f));
		dynamic_cast<CMonster*>(m_objList[OBJ_MONSTER].back())->Set_BulletList(&m_objList[OBJ_MONSTERBULLET]);
	}
	// 스테이지 SYJ
	else if (m_iStage == 0) {
		// Player
	
		// Monster

	}
	else if (m_iStage == 2) {
		// Player
		
		// Monster

	}
	else if (m_iStage == 3) {
		// Player
		
		// Monster

	}
	else if (m_iStage == 4) {
		// Player
		
		// Monster

	}
}


/* 
스테이지 끝났는지	
	-> 끝났으면 m_objList 초기화
	-> 다음 스테이지에 쓸 몬스터, 플레이어 넣기 


*/