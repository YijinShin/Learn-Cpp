#include "stdafx.h"
#include "CEditorMgr.h"

#include "CKeyMgr.h"
#include "CLineMgr.h"
#include "CScrollMgr.h"

void CEditorMgr::Initialize(int _eStageID)
{
	CLineMgr::Get_Instance()->Set_FileName(_eStageID);
}

void CEditorMgr::Update()
{
	CLineMgr::Get_Instance()->Update();

	Key_Input();
}

void CEditorMgr::Render(HDC hDC)
{
	CLineMgr::Get_Instance()->Render(hDC);
	TextOut(hDC, 100, 100, L"Editor Mode", 20);
}

void CEditorMgr::Release()
{
	CLineMgr::Get_Instance()->Release();
}

void CEditorMgr::Key_Input()
{
	if (CKeyMgr::Get_Instance()->Key_Down('S')) {
		CLineMgr::Get_Instance()->Save_LineData();
	}

	// 스크롤 이동 
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_LEFT)) {
		CScrollMgr::Get_Instance()->Set_ScrollX(10.f);
	}
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_RIGHT)) {
		CScrollMgr::Get_Instance()->Set_ScrollX(-10.f);
	}
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_UP)) {
		CScrollMgr::Get_Instance()->Set_ScrollY(10.f);
	}
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_DOWN)) {
		CScrollMgr::Get_Instance()->Set_ScrollY(-10.f);
	}
	
}
