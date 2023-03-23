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

	// TODO : �ʿ��� ������Ʈ ����
		//Player
	CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer_SYJ>::Create(300.f, 100.f));

	//Flag
	CObjMgr::Get_Instance()->Add_Object(OBJ_FLAG, CAbstractFactory<CFlag>::Create(700.f, 300.f));

	// �ش� ������ ����� �׶���(���)�̹����� map�� ����
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
	// �׶���DC �������� 
	HDC hGroundDC = CBmpMgr::Get_Instance()->Find_MyBmp(L"Ground");

	int iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	// �׶���DC�� �����DC�� ���̱� ( ȭ���� ���� ����. ���� �����ӿ� �׸� ��ü���� ������ �ʵ���)
	BitBlt(hDC,
		iScrollX, iScrollY, 1920, 1200,
		hGroundDC,
		0,
		0,
		SRCCOPY);

	// ��� ��ü�� �����DC�� �׸��� 
	CLineMgr::Get_Instance()->Render(hDC);
	CObjMgr::Get_Instance()->Render(hDC);
}

void CStage_SYJ::Release()
{
}
