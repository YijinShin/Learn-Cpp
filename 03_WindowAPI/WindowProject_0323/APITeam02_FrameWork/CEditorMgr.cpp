#include "stdafx.h"
#include "CEditorMgr.h"

#include "CKeyMgr.h"
#include "CScrollMgr.h"
#include "CObjMgr.h"
#include "CLineMgr.h"

void CEditorMgr::Initialize(int _eStageID)
{
	CLineMgr::Get_Instance()->Set_FileName(_eStageID);
	CObjMgr::Get_Instance()->Set_FileName(_eStageID);
}

void CEditorMgr::Update()
{

	CLineMgr::Get_Instance()->Update();

	Key_Input();
}

void CEditorMgr::Render(HDC hDC)
{
	// 마우스 좌표 출력하기 
	POINT	pt{};
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	int iScrollX= CScrollMgr::Get_Instance()->Get_ScrollX();
	int iScrollY = CScrollMgr::Get_Instance()->Get_ScrollY();

	TCHAR	szBuff[100] = L"";
	swprintf_s(szBuff, L"HP: % d", (int)pt.x - iScrollX);
	TextOut(hDC, pt.x, pt.y-20, szBuff, lstrlen(szBuff));
	swprintf_s(szBuff, L"HP: % d", (int)pt.y - iScrollY);
	TextOut(hDC, pt.x, pt.y , szBuff, lstrlen(szBuff));


	// 라인 그리기 
	CLineMgr::Get_Instance()->Render(hDC);
	CObjMgr::Get_Instance()->Render(hDC);
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

