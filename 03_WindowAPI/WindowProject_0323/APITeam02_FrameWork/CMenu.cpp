#include "stdafx.h"
#include "CMenu.h"

#include "AbstractFactory.h"
#include "CBmpMgr.h"
#include "CObjMgr.h"

#include "CButton.h"

CMenu::CMenu()
{
}

CMenu::~CMenu()
{
	Release();
}

void CMenu::Initialize()
{
	// 필요한 이미지 map에 저장하기 
	CBmpMgr::Get_Instance()->Insert_MyBmp(L"../Image/Button/Start.bmp", L"Start");
	CBmpMgr::Get_Instance()->Insert_MyBmp(L"../Image/Button/Edit.bmp", L"Edit");
	CBmpMgr::Get_Instance()->Insert_MyBmp(L"../Image/Button/Exit.bmp", L"Exit");
	CBmpMgr::Get_Instance()->Insert_MyBmp(L"../Image/Menu/Menu.bmp", L"Menu");

	// ObjList에 버튼 객체 만들어넣기
	CObj* pObj = CAbstractFactory<CButton>::Create(200.f, 400.f);
	pObj->Set_FrameKey(const_cast<TCHAR*>(L"Start"));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BUTTON,pObj);

	pObj = CAbstractFactory<CButton>::Create(400.f, 400.f);
	pObj->Set_FrameKey(const_cast<TCHAR*>(L"Edit"));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BUTTON, pObj);
	
	pObj = CAbstractFactory<CButton>::Create(600.f, 400.f);
	pObj->Set_FrameKey(const_cast<TCHAR*>(L"Exit"));
	CObjMgr::Get_Instance()->Add_Object(OBJ_BUTTON, pObj);

}

void CMenu::Update()
{
	CObjMgr::Get_Instance()->Update();
}

void CMenu::Late_Update()
{
	CObjMgr::Get_Instance()->Late_Update();
}

void CMenu::Render(HDC hDC)
{
	HDC hMenuDC = CBmpMgr::Get_Instance()->Find_MyBmp(L"Menu");

	BitBlt( hDC, 0,0, WINCX, WINCY, hMenuDC, 0,0,SRCCOPY);

	CObjMgr::Get_Instance()->Render(hDC);
}

void CMenu::Release()
{
	CObjMgr::Get_Instance()->Delete_ID(OBJ_BUTTON);
}
