#include "stdafx.h"
#include "CStage_SYJ.h"

#include "Include.h"

#include "AbstractFactory.h"
#include "CObjMgr.h"
#include "CBmpMgr.h"
#include "CLineMgr.h"
#include "CScrollMgr.h"

#include "Player_SYJ.h"
#include "CFlag.h"

CStage_SYJ::CStage_SYJ()
{
}

CStage_SYJ::~CStage_SYJ()
{
}

void CStage_SYJ::Initialize()
{
	m_eStageID = SC_STAGE_SYJ;

	CLineMgr::Get_Instance()->Initialize(m_eStageID);
	CObjMgr::Get_Instance()->Initialize(m_eStageID);

	// TODO : 필요한 오브젝트 생성
		//Player
	CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer_SYJ>::Create(300.f, 100.f));

	//Flag
	CObjMgr::Get_Instance()->Add_Object(OBJ_FLAG, CAbstractFactory<CFlag>::Create(700.f, 300.f));

	// 해당 씬에서 사용할 그라운드(배경)이미지를 map에 저장
	CBmpMgr::Get_Instance()->Insert_MyBmp(L"../Image/BackGround.bmp", L"Ground");

}

void CStage_SYJ::Update()
{
	CObjMgr::Get_Instance()->Update();
}

void CStage_SYJ::Late_Update()
{
	CObjMgr::Get_Instance()->Late_Update();
}

void CStage_SYJ::Render(HDC hDC)
{
	// 그라운드DC 가져오기 
	HDC hGroundDC = CBmpMgr::Get_Instance()->Find_MyBmp(L"Ground");

	int iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	// 그라운드DC를 백버퍼DC에 붙이기 ( 화면을 덮는 개념. 이전 프레임에 그린 객체들이 보이지 않도록)
	BitBlt(hDC,
		iScrollX, iScrollY, 1920, 1200,
		hGroundDC,
		0,
		0,
		SRCCOPY);

	// 모든 객체는 백버퍼DC에 그리기 
	CLineMgr::Get_Instance()->Render(hDC);
	CObjMgr::Get_Instance()->Render(hDC);
}

void CStage_SYJ::Release()
{
}
