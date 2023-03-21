#include "stdafx.h"
#include "CMainGame.h"

#include "CStage.h"



CMainGame::CMainGame()
{
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	m_hDC = GetDC(g_hWnd);
	
	CStage::Initialize();
}

void CMainGame::Update()
{
	CStage::Update();
}

void CMainGame::Late_Update()
{
	if (CStage::Late_Update()) {
		CStage::GoNextStage();
	}
}

void CMainGame::Render()
{
	Rectangle(m_hDC, 0, 0, WINCX, WINCY);
	CStage::Render(m_hDC);
}

void CMainGame::Release()
{
	CStage::Release();
}
