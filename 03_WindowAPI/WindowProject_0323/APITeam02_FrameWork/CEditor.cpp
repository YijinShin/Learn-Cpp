#include "stdafx.h"
#include "CEditor.h"

#include "CEditorMgr.h"
#include "CLineMgr.h"
#include "CObjMgr.h"
#include "CScrollMgr.h"
#include "CKeyMgr.h"
#include "CTileMgr.h"

CEditor::CEditor()
{
}

CEditor::~CEditor()
{
}

void CEditor::Initialize()
{
	CLineMgr::Get_Instance()->Initialize(m_eStageID);
	CObjMgr::Get_Instance()->Initialize(m_eStageID);

	// [타일 에디터] =========================================
	CTileMgr::Get_Instance()->Initialize();
}

void CEditor::Update()
{
	Key_Input();

	//CLineMgr::Get_Instance()->Update();
	//CObjMgr::Get_Instance()->Update();

	// [타일 에디터] =========================================
	CTileMgr::Get_Instance()->Update();
}

void CEditor::Late_Update()
{
	// [타일 에디터] =========================================
	CTileMgr::Get_Instance()->Late_Update();
}

void CEditor::Render(HDC hDC)
{
	// [타일 에디터] =========================================
	CTileMgr::Get_Instance()->Render(hDC);

	// 마우스 좌표 출력하기 
	POINT	pt{};
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	int iScrollX = CScrollMgr::Get_Instance()->Get_ScrollX();
	int iScrollY = CScrollMgr::Get_Instance()->Get_ScrollY();

	TCHAR	szBuff[100] = L"";
	swprintf_s(szBuff, L"HP: % d", (int)pt.x - iScrollX);
	TextOut(hDC, pt.x, pt.y - 20, szBuff, lstrlen(szBuff));
	swprintf_s(szBuff, L"HP: % d", (int)pt.y - iScrollY);
	TextOut(hDC, pt.x, pt.y, szBuff, lstrlen(szBuff));
	
	// 라인 그리기 
	CLineMgr::Get_Instance()->Render(hDC);
	CObjMgr::Get_Instance()->Render(hDC);
	TextOut(hDC, 100, 100, L"Editor Mode", 20);

}

void CEditor::Release()
{
	CLineMgr::Get_Instance()->Release();
	// [타일 에디터] =========================================
	CTileMgr::Get_Instance()->Release();
}


void CEditor::Key_Input()
{
	if (CKeyMgr::Get_Instance()->Key_Down(VK_LBUTTON)
		|| CKeyMgr::Get_Instance()->Key_Pressing('T')) {
		
		POINT pt{};
		GetCursorPos(&pt);
		ScreenToClient(g_hWnd, &pt);

		pt.x -= (int)CScrollMgr::Get_Instance()->Get_ScrollX();
		pt.y -= (int)CScrollMgr::Get_Instance()->Get_ScrollY();

		CTileMgr::Get_Instance()->Picking(pt, 1, 0);
	}


	if (CKeyMgr::Get_Instance()->Key_Down('S')) {

		CLineMgr::Get_Instance()->Save_LineData();
		// [타일 에디터] =========================================
		CTileMgr::Get_Instance()->Save_TileData();
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

void CEditor::Set_StageID(int _eStageID)
{
	m_eStageID = _eStageID;
}

