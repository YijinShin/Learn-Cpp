#include "stdafx.h"
#include "CStageMgr.h"

// Desing
#include "CObjMgr.h"
#include "AbstractFactory.h"
#include "CLineMgr.h"
#include "CKeyMgr.h"
#include "CCollisionMgr.h"

// Object
#include "CPlayer.h"
#include "Player_SYJ.h"


int		CStageMgr::m_eStageID = STAGE_SYJ;			// ���� ���������� �׽�Ʈ�ϰ� ������ stageID�� ���� �̴ϼȷ� �ٲٱ�. 

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
		
		// TODO : �ʿ��� ������Ʈ ����
		
		/* // ���� 
			// player ����
			CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer>::Create(WINCX / 2.f, WINCY / 1.5f));
		*/

		break;
	case STAGE_AJS:

		// Line ����
		CLineMgr::Get_Instance()->Initialize(m_eStageID);

		// TODO : �ʿ��� ������Ʈ ����
	
		
		break;
	case STAGE_PIS:
	
		// Line ����
		CLineMgr::Get_Instance()->Initialize(m_eStageID);

		// TODO : �ʿ��� ������Ʈ ����
		

		break;
	case STAGE_SHH:
	
		// Line ����
		CLineMgr::Get_Instance()->Initialize(m_eStageID);

		break;
	case STAGE_SYJ:
	
		// Line ����
		CLineMgr::Get_Instance()->Initialize(m_eStageID);

		// TODO : �ʿ��� ������Ʈ ����
		//Player
		CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer_SYJ>::Create(WINCX / 2.f, WINCY / 1.5f));
		//Monster
		//Obstacle


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
void CStageMgr::Update() 
{
	CObjMgr::Get_Instance()->Update();
}

/* FIX */
bool CStageMgr::Late_Update() 
{
	// �� ������Ʈ Late_Update
	CObjMgr::Get_Instance()->Late_Update();

	// �������� ���� ���� ���� 
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
	++ m_eStageID;				// �������� ID ����
	Release();					// ���� ObjList, Line û���ϱ� 
	Initialize();				// �� �������� init�ϱ� 
}

bool CStageMgr::CheckStageEnd()
{
	bool bIsEnd(false);

	// TODO : �������� ���� üũ 
		// �浹�Ǵ� : �÷��̾� + �÷��� 


	// [for Test] �������� ���� �ѱ� N Ű
	if (CKeyMgr::Get_Instance()->Key_Down('N')) 
		bIsEnd = true;

	return bIsEnd;
}
