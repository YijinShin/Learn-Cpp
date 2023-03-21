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
		
		// TODO : �ʿ��� ������Ʈ ����

		break;
	case STAGE_A:
		
		// Line ����
		CLineMgr::Get_Instance()->Initialize(m_eStageID);
		// player ����
		CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer>::Create(WINCX / 2.f, WINCY / 1.5f));
		
		break;
	case STAGE_B:
	
		// Line ����
		CLineMgr::Get_Instance()->Initialize(m_eStageID);
		// TODO : �ʿ��� ������Ʈ ����
		

		break;
	case STAGE_C:
	
		// Line ����
		CLineMgr::Get_Instance()->Initialize(m_eStageID);
		// TODO : �ʿ��� ������Ʈ ����

		break;
	case STAGE_D:
	
		// Line ����
		CLineMgr::Get_Instance()->Initialize(m_eStageID);
		// TODO : �ʿ��� ������Ʈ ����

		break;
	case STAGE_END:
		
		// TODO : �ʿ��� ������Ʈ ����

		break;
	default:
		// ������ ������ �����ٴ� �˸� ���
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
	// �� ������Ʈ Late_Update
	CObjMgr::Get_Instance()->Late_Update();

	// �������� ���� ���� ���� 
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
	++ m_eStageID;				// �������� ID ����
	Release();					// ���� ObjList, Line û���ϱ� 
	Initialize();				// �� �������� init�ϱ� 
}

bool CStage::CheckStageEnd()
{
	bool bIsEnd(false);

	// TODO : �������� ���� üũ 

	// [for Test] �������� ���� �ѱ� N Ű
	if (GetAsyncKeyState('N')) {
		if (m_fNkey_CoolTime + 500 < GetTickCount()) {
			bIsEnd = true;
			m_fNkey_CoolTime = GetTickCount();
		}
	}

	return bIsEnd;
}
