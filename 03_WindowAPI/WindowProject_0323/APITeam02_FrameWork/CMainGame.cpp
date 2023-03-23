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
	
	// ����۷� �� �� �� �̹����� map�� �����Ѵ�.
	CBmpMgr::Get_Instance()->Insert_MyBmp(L"../Image/BackBuffer.bmp", L"Back");

	// ù ���� LOGO������ ���� 
	CSceneMgr::Get_Instance()->Change_Scene(SC_LOGO);
	

}

void CMainGame::Update()
{
	// Stage <-> Editor ���� ��� Ȯ�� 
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
	// ��� ��ü�� �׸� ����� DC�� �����´�. 
	HDC hMemDC = CBmpMgr::Get_Instance()->Find_MyBmp(L"Back");

	// �����DC�� ����DC�� ���δ�
	BitBlt(m_hDC,				// ���� DC
			0, 0, WINCX, WINCY, // ��Ʈ���� ���� ������
			hMemDC,				// �����  �̹��� dc
			0,					// ��Ʈ���� ��� ���� x��ǥ
			0,					// ��Ʈ���� ��� ���� y��ǥ
			SRCCOPY);			

	// ��� ��ü�� �����DC�� ���δ�. 
	CSceneMgr::Get_Instance()->Render(hMemDC);

}

void CMainGame::Release()
{
	CSceneMgr::Get_Instance()->Destroy_Instance();
	CKeyMgr::Get_Instance()->Destroy_Instance();

	/* ��׵� �ؾ��ϴ°���? */
	//CBmpMgr::Get_Instance()->Destroy_Instance();
	//CScrollMgr::Get_Instance()->Destroy_Instance();
	//CLineMgr::Get_Instance()->Destroy_Instance();
	//CObjMgr::Get_Instance()->Destroy_Instance();
}

void CMainGame::Key_Input()
{
	int eCurrScene = CSceneMgr::Get_Instance()->Get_CurrSceneId();

	// ���������� ����Ʈ ���� �ִ°�츸 ���
	if (eCurrScene != SC_LOGO
		&& eCurrScene != SC_MENU
		&& eCurrScene != SC_END) {

		// �����;����� ���� 
		if (CKeyMgr::Get_Instance()->Key_Down('E')) {
			CSceneMgr::Get_Instance()->Change_Scene(SC_EDIT);
		}

		// �������������� ���� (�������� 1���� ����)
		if (CKeyMgr::Get_Instance()->Key_Down('M')) {
			CSceneMgr::Get_Instance()->Change_Scene(SC_STAGE_AJS);
		}

		// ������������ ��쿡�� ��� 
		if (eCurrScene != SC_EDIT) {

			// ���� ���������� �̵�
			if (CKeyMgr::Get_Instance()->Key_Down('N')) {
				CSceneMgr::Get_Instance()->Change_Scene(eCurrScene + 1);
			}
		}
	}
}
