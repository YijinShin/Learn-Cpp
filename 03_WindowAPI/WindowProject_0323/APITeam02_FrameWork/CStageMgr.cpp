#include "stdafx.h"
#include "CStageMgr.h"

// Desing
#include "CObjMgr.h"
#include "AbstractFactory.h"
#include "CLineMgr.h"
#include "CKeyMgr.h"
#include "CCollisionMgr.h"
#include "CObjMgr.h"


// Object
#include "CPlayer.h"
#include "Player_SYJ.h"
#include "CFlag.h"


int		CStageMgr::m_eStageID = STAGE_SYJ;			// 본인 스테이지를 테스트하고 싶으면 stageID를 본인 이니셜로 바꾸기. 

CStageMgr::CStageMgr()
{
}

CStageMgr::~CStageMgr()
{

}

void CStageMgr::Initialize()
{
	switch (m_eStageID)
	{
	case STAGE_START:
		
		// TODO : 필요한 오브젝트 생성
		

		break;
	case STAGE_AJS:

		// Line 생성
		CLineMgr::Get_Instance()->Initialize(m_eStageID);

		// TODO : 필요한 오브젝트 생성
	
		
		break;
	case STAGE_PIS:
	
		// Line 생성
		CLineMgr::Get_Instance()->Initialize(m_eStageID);

		// TODO : 필요한 오브젝트 생성
		

		break;
	case STAGE_SHH:
	
		// Line 생성
		CLineMgr::Get_Instance()->Initialize(m_eStageID);

		break;
	case STAGE_SYJ:
	
		// Line 생성
		CLineMgr::Get_Instance()->Initialize(m_eStageID);

		// TODO : 필요한 오브젝트 생성
		//Player
		CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer_SYJ>::Create(300.f, 100.f));
		
		//Flag
		CObjMgr::Get_Instance()->Add_Object(OBJ_FLAG, CAbstractFactory<CFlag>::Create(700.f, 300.f));
		
		//Monster & Obstacle
			//CObjMgr::Get_Instance()->Initialize(m_eStageID);

		break;
	case STAGE_END:
		
		// TODO : 필요한 오브젝트 생성

		break;
	default:
		// 게임이 완전히 끝났다는 알림 띄움
		MessageBox(g_hWnd, _T("Game Over!"), _T("Congraturation!"), MB_OK);
		break;
	}
}

/* FIX */
void CStageMgr::Update() 
{
	CObjMgr::Get_Instance()->Update();
}

/* FIX */
bool CStageMgr::Late_Update() 
{
	// 각 오브젝트 Late_Update
	CObjMgr::Get_Instance()->Late_Update();
	// 스테이지 종료 여부 리턴 
	return CheckStageEnd();
}

/* FIX */
void CStageMgr::Render(HDC hDC) 
{
	CObjMgr::Get_Instance()->Render(hDC);
	CLineMgr::Get_Instance()->Render(hDC);
}

/* FIX */
void CStageMgr::Release() 
{
	CLineMgr::Get_Instance()->Release();
	CObjMgr::Get_Instance()->Release();
}

/* FIX */
void CStageMgr::GoNextStage()
{
	++ m_eStageID;				// 스테이지 ID 변경

	MessageBox(g_hWnd,L"Go to Next stage!", L"Clear!",MB_OK);

	Release();					// 기존 ObjList, Line 청소하기 
	Initialize();				// 새 스테이지 init하기 
}

bool CStageMgr::CheckStageEnd()
{
	bool bIsEnd(false);

	// TODO : 스테이지 종료 체크 
		// 충돌판단 : 플레이어 + 플래그 
		
	// [for Test] 스테이지 강제 넘김 N 키
	if (CKeyMgr::Get_Instance()->Key_Down('N')) 
		bIsEnd = true;

	return bIsEnd;
}
