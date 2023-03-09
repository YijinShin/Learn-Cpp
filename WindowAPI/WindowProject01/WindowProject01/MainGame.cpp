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
	// �׸��� �׸� DC�� �޾ƿ��� 
	m_DC = GetDC(g_hWnd);	// ������ ��鷯�� ���ڷ� �ʿ���.
	// ��Ÿ�� ũ�� �����ϱ� 
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
	// �÷��̾� ������Ʈ
	m_pPlayer->Update();
	// ���� ������Ʈ
	m_pMonster->Update();
	// �Ѿ� ������Ʈ 
	for (auto& iter : m_BulletList) {
		iter->Update();
	}
}

void CMainGame::Render()
{
	// ��� �׸��� 
	Rectangle(m_DC, 0, 0, WINCX, WINCY);	// �ܻ� ���ִ� ������� ��濡 �Ŵ��� �簢���� �׸��� (���� ���۸� ���)
	// ��Ÿ�� �׸���
	Rectangle(m_DC, m_tFence.left, m_tFence.top, m_tFence.right, m_tFence.bottom);
	// �Ѿ� �׸��� 
	for (auto& iter : m_BulletList)
		iter->Render(m_DC);
	// ��Ÿ�� �� ��� �׸���
	Rectangle(m_DC, 0, 0, WINCX, m_tFence.top);
	Rectangle(m_DC, 0, WINCY - m_tFence.top, WINCX, WINCY);
	Rectangle(m_DC, 0, m_tFence.top, m_tFence.top, WINCY - m_tFence.top);
	Rectangle(m_DC, m_tFence.top, WINCX - m_tFence.left, WINCX, WINCY - m_tFence.top);
	// �÷��̾� �׸���
	m_pPlayer->Render(m_DC);
	// ���� �׸���
	m_pMonster->Render(m_DC);
	
}

void CMainGame::Release()
{

}
