#include "stdafx.h"
#include "MainGame.h"
#include "Player.h"
#include "Monster.h"

CMainGame::CMainGame(): m_pPlayer(nullptr)
{
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	// 그림을 그릴 DC를 받아오기 
	m_DC = GetDC(g_hWnd);	// 윈도우 헨들러가 인자로 필요함.
	// 울타리 크기 설정하기 
	m_tFence.left = 100;
	m_tFence.top = 100;
	m_tFence.bottom = WINCY - 100;
	m_tFence.right = WINCX - 100;
	// player 
	if (!m_pPlayer) {
		m_pPlayer = new CPlayer;
		m_pPlayer->Initialize();
	}
	// monster
	if (!m_pMonster) {
		m_pMonster = new CMonster;
		m_pMonster->Initialize();
		dynamic_cast<CMonster*>(m_pMonster)->Set_Fence(m_tFence);
		m_pMonster->Set_Dir(DIR_LEFT);
	}
	
	// bullet
	dynamic_cast<CPlayer*>(m_pPlayer)->Set_Bullet(&m_BulletList);
}

void CMainGame::Update()
{
	// 플레이어 업데이트
	m_pPlayer->Update();
	// 몬스터 업데이트
	m_pMonster->Update();
	// 총알 업데이트 
	for (auto& iter : m_BulletList) {
		iter->Update();
	}
}

void CMainGame::Render()
{
	// 배경 그리기 
	Rectangle(m_DC, 0, 0, WINCX, WINCY);	// 잔상 없애는 방법으로 배경에 거대한 사각형을 그리기 (더블 버퍼링 기법)
	// 울타리 그리기
	Rectangle(m_DC, m_tFence.left, m_tFence.top, m_tFence.right, m_tFence.bottom);
	// 총알 그리기 
	for (auto& iter : m_BulletList)
		iter->Render(m_DC);
	// 울타리 밖 배경 그리기
	Rectangle(m_DC, 0, 0, WINCX, m_tFence.top);
	Rectangle(m_DC, 0, WINCY - m_tFence.top, WINCX, WINCY);
	Rectangle(m_DC, 0, m_tFence.top, m_tFence.top, WINCY - m_tFence.top);
	Rectangle(m_DC, m_tFence.top, WINCX - m_tFence.left, WINCX, WINCY - m_tFence.top);
	// 플레이어 그리기
	m_pPlayer->Render(m_DC);
	// 몬스터 그리기
	m_pMonster->Render(m_DC);
	
}

void CMainGame::Release()
{

}
