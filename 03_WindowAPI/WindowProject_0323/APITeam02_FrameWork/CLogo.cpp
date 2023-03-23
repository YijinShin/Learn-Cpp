#include "stdafx.h"
#include "CLogo.h"

#include "CKeyMgr.h"
#include "CSceneMgr.h"
#include "CBmpMgr.h"

CLogo::CLogo()
{
}

CLogo::~CLogo()
{
	Release();
}

void CLogo::Initialize()
{
	CBmpMgr::Get_Instance()->Insert_MyBmp(L"../Image/Logo/Logo.bmp", L"Logo");
}

void CLogo::Update()
{
}

void CLogo::Late_Update()
{
	Key_Input();
}

void CLogo::Render(HDC hDC)
{
	HDC hLogoDC = CBmpMgr::Get_Instance()->Find_MyBmp(L"Logo");

	BitBlt(hDC,
		0,0,
		WINCX, WINCY,
		hLogoDC,
		0,0,
		SRCCOPY);
}

void CLogo::Release()
{
}

void CLogo::Key_Input()
{
	if (CKeyMgr::Get_Instance()->Key_Down(VK_RETURN))
	{
		//CSceneMgr::Get_Instance()->Change_Scene(SC_MENU);
		CSceneMgr::Get_Instance()->Change_Scene(SC_MENU);
		return;
	}
}
