#include "stdafx.h"
#include "CMainGame.h"
// Desing
#include "AbstractFactory.h"
#include "CObjMgr.h"
#include "CLineMgr.h"
// Object
#include "CPlayer.h"


CMainGame::CMainGame()
{
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	// HDC 汲沥
	m_hDC = GetDC(g_hWnd);
	// Line 积己
	CLineMgr::Get_Instance()->Initialize();
	// player 积己
	CObjMgr::Get_Instance()->Add_Object( OBJ_PLAYER, CAbstractFactory<CPlayer>::Create(WINCX/2.f, WINCY/1.5f ));
}

void CMainGame::Update()
{
	CObjMgr::Get_Instance()->Update();
}

void CMainGame::Late_Update()
{
	CObjMgr::Get_Instance()->Late_Update();
}

void CMainGame::Render()
{
	Rectangle(m_hDC, 0, 0, WINCX, WINCY);

	CLineMgr::Get_Instance()->Render(m_hDC);
	CObjMgr::Get_Instance()->Render(m_hDC);
}

void CMainGame::Release()
{
	CLineMgr::Get_Instance()->Release();
	CObjMgr::Get_Instance()->Release();
}
