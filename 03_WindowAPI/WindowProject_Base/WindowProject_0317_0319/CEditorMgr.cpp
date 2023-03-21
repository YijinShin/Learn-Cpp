#include "stdafx.h"
#include "CEditorMgr.h"

#include "CKeyMgr.h"
#include "CLineMgr.h"

void CEditorMgr::Initialize()
{
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
}
