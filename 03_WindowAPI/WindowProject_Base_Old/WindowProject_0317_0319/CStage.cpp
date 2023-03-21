#include "stdafx.h"
#include "CStage.h"

// Desing
#include "CObjMgr.h"
#include "AbstractFactory.h"
#include "CLineMgr.h"

// Object
#include "CPlayer.h"


int		CStage::m_eStageID = STAGE_A;
float	CStage::m_fNkey_CoolTime = GetTickCount();

void CStage::Initialize()
{
	switch (m_eStageID)
	{
	case STAGE_START:
		
		// TODO : 필요한 오브젝트 생성

		break;
	case STAGE_A:
		
		// Line 생성
		CLineMgr::Get_Instance()->Initialize(m_eStageID);
		// player 생성
		CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer>::Create(WINCX / 2.f, WINCY / 1.5f));
		
		break;
	case STAGE_B:
	
		// Line 생성
		CLineMgr::Get_Instance()->Initialize(m_eStageID);
		// TODO : 필요한 오브젝트 생성
		

		break;
	case STAGE_C:
	
		// Line 생성
		CLineMgr::Get_Instance()->Initialize(m_eStageID);
		// TODO : 필요한 오브젝트 생성

		break;
	case STAGE_D:
	
		// Line 생성
		CLineMgr::Get_Instance()->Initialize(m_eStageID);
		// TODO : 필요한 오브젝트 생성

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
void CStage::Update() 
{
	CObjMgr::Get_Instance()->Update();
}

/* FIX */
bool CStage::Late_Update() 
{
	// 각 오브젝트 Late_Update
	CObjMgr::Get_Instance()->Late_Update();

	// 스테이지 종료 여부 리턴 
	return CheckStageEnd();
}

/* FIX */
void CStage::Render(HDC hDC) 
{
	CLineMgr::Get_Instance()->Render(hDC);
	CObjMgr::Get_Instance()->Render(hDC);
}

/* FIX */
void CStage::Release() 
{
	CLineMgr::Get_Instance()->Release();
	CObjMgr::Get_Instance()->Release();
}

/* FIX */
void CStage::GoNextStage()
{
	++ m_eStageID;				// 스테이지 ID 변경
	Release();					// 기존 ObjList, Line 청소하기 
	Initialize();				// 새 스테이지 init하기 
}

bool CStage::CheckStageEnd()
{
	bool bIsEnd(false);

	// TODO : 스테이지 종료 체크 

	// [for Test] 스테이지 강제 넘김 N 키
	if (GetAsyncKeyState('N')) {
		if (m_fNkey_CoolTime + 500 < GetTickCount()) {
			bIsEnd = true;
			m_fNkey_CoolTime = GetTickCount();
		}
	}

	return bIsEnd;
}
