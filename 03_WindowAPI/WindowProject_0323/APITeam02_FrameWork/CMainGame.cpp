#include "stdafx.h"
#include "CMainGame.h"

// desing
#include "CStageMgr.h"
#include "CEditorMgr.h"
#include "CKeyMgr.h"
#include "CBmpMgr.h"
#include "CScrollMgr.h"

#include "CSceneMgr.h"



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
	
	// 백버퍼로 깔 때 쓸 이미지를 map에 저장한다.
	CBmpMgr::Get_Instance()->Insert_MyBmp(L"../Image/BackBuffer.bmp", L"Back");

	// 첫 씬은 LOGO씬으로 시작 
	CSceneMgr::Get_Instance()->Change_Scene(SC_LOGO);
	

}

void CMainGame::Update()
{
	// Stage <-> Editor 변경 명령 확인 
	Key_Input();

	CSceneMgr::Get_Instance()->Update();

}

void CMainGame::Late_Update()
{
	CSceneMgr::Get_Instance()->Late_Update();
	CScrollMgr::Get_Instance()->Scroll_Lock();

}

void CMainGame::Render()
{	
	// 모든 객체를 그릴 백버퍼 DC를 가져온다. 
	HDC hMemDC = CBmpMgr::Get_Instance()->Find_MyBmp(L"Back");

	// 백버퍼DC를 메인DC에 붙인다
	BitBlt(m_hDC,				// 메인 DC
			0, 0, WINCX, WINCY, // 비트맵의 세로 사이즈
			hMemDC,				// 출력할  이미지 dc
			0,					// 비트맵의 출력 시작 x좌표
			0,					// 비트맵의 출력 시작 y좌표
			SRCCOPY);			

	// 모든 객체를 백버퍼DC에 붙인다. 
	CSceneMgr::Get_Instance()->Render(hMemDC);

}

void CMainGame::Release()
{
	CSceneMgr::Get_Instance()->Destroy_Instance();
	CKeyMgr::Get_Instance()->Destroy_Instance();

	/* 얘네도 해야하는거지? */
	//CBmpMgr::Get_Instance()->Destroy_Instance();
	//CScrollMgr::Get_Instance()->Destroy_Instance();
	//CLineMgr::Get_Instance()->Destroy_Instance();
	//CObjMgr::Get_Instance()->Destroy_Instance();
}

void CMainGame::Key_Input()
{
	int eCurrScene = CSceneMgr::Get_Instance()->Get_CurrSceneId();

	// 스테이지나 에디트 씬에 있는경우만 허용
	if (eCurrScene != SC_LOGO
		&& eCurrScene != SC_MENU
		&& eCurrScene != SC_END) {

		// 에디터씬으로 변경 
		if (CKeyMgr::Get_Instance()->Key_Down('E')) {
			CSceneMgr::Get_Instance()->Change_Scene(SC_EDIT);
		}

		// 스테이지씬으로 변경 (스테이지 1부터 시작)
		if (CKeyMgr::Get_Instance()->Key_Down('M')) {
			CSceneMgr::Get_Instance()->Change_Scene(SC_STAGE_AJS);
		}

		// 스테이지씬인 경우에만 허용 
		if (eCurrScene != SC_EDIT) {

			// 다음 스테이지로 이동
			if (CKeyMgr::Get_Instance()->Key_Down('N')) {
				CSceneMgr::Get_Instance()->Change_Scene(eCurrScene + 1);
			}
		}
	}
}
