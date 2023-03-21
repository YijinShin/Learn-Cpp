#include "stdafx.h"
#include "CMainGame.h"

// desing
#include "CStageMgr.h"
#include "CEditorMgr.h"
#include "CKeyMgr.h"



CMainGame::CMainGame(): m_GameMode(MODE_GAME)
{
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	m_hDC = GetDC(g_hWnd);
	
	if(m_GameMode == MODE_GAME)
		CStageMgr::Initialize();

}

void CMainGame::Update()
{
	// 모드 바꾸기 (게임 <-> 에디터)
	if (CKeyMgr::Get_Instance()->Key_Down('M')) {
		if (m_GameMode == MODE_GAME) {
			m_GameMode = MODE_EDITOR;
			CStageMgr::Release();
			CEditorMgr::Initialize();
		}
		else if (m_GameMode == MODE_EDITOR) {
			m_GameMode = MODE_GAME;
			CEditorMgr::Release();
			CStageMgr::Initialize();
		}
	}

	if (m_GameMode == MODE_GAME)
		CStageMgr::Update();
	else if (m_GameMode == MODE_EDITOR) {
		CEditorMgr::Update();
	}
}

void CMainGame::Late_Update()
{
	if (m_GameMode == MODE_GAME) {
		if (CStageMgr::Late_Update()) {
			CStageMgr::GoNextStage();
		}
	}
}

void CMainGame::Render()
{
	Rectangle(m_hDC, 0, 0, WINCX, WINCY);
	
	if (m_GameMode == MODE_GAME)
		CStageMgr::Render(m_hDC);
	if (m_GameMode == MODE_EDITOR) 
		CEditorMgr::Render(m_hDC);
	
}

void CMainGame::Release()
{
	if (m_GameMode == MODE_GAME)
		CStageMgr::Release();
}
