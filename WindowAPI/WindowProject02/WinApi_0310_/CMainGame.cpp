#include "stdafx.h"
#include "CMainGame.h"
#include "CPlayer.h"
#include "CMonster.h"

CMainGame::CMainGame(): m_pPlayer(nullptr), m_pMonster(nullptr)
{
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	// HDC 가져오기 
	m_hDC = GetDC(g_hWnd);
	
	// 플레이어 생성 
	m_pPlayer = new CPlayer;
	m_pPlayer->Initialize();
	dynamic_cast<CPlayer*>(m_pPlayer)->Set_BulletList(&m_BulletList);

	// 몬스터 생성
	m_pMonster = new CMonster();
	m_pMonster->Initialize();

	// 총알은 플레이어에서 생성함. 
}

int CMainGame::Update()
{
	int iResult = m_pPlayer->Update();
	if (iResult == OBJ_DEAD) {
		Safe_Delete<CObj*>(m_pPlayer);
		m_pPlayer = nullptr;
	}

	iResult = m_pMonster->Update();
	if (iResult == OBJ_DEAD) {
		Safe_Delete<CObj*>(m_pMonster);
		m_pMonster = nullptr;
	}
	
	for (auto& iter : m_BulletList) {
		iResult = iter->Update();
		if (iResult == OBJ_DEAD) {
			Safe_Delete<CObj*>(iter);
			m_BulletList.erase(iter);
		}
	}

	return 0;
}

void CMainGame::Late_Update()
{
	m_pPlayer->Late_Update();

	m_pMonster->Late_Update();

	for (auto& iter : m_BulletList)
		iter->Late_Update();
}

void CMainGame::Render()
{
	Rectangle(m_hDC, 0, 0, WINCX, WINCY);

	Rectangle(m_hDC, FENCEINTERVAL, FENCEINTERVAL, WINCX - FENCEINTERVAL, WINCY - FENCEINTERVAL);

	m_pPlayer->Render(m_hDC);

	m_pMonster->Render(m_hDC);

	for (auto& iter : m_BulletList)
		iter->Render(m_hDC);
}

void CMainGame::Release()
{
	Safe_Delete<CObj*>(m_pPlayer);	// 플레이어 해제	
	Safe_Delete<CObj*>(m_pMonster);	// 몬스터 해제 
	for(auto& iter: m_BulletList)	// 총알 해제 
		Safe_Delete<CObj*>(iter);
}
