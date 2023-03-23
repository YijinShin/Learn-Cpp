#include "stdafx.h"
#include "CSceneMgr.h"


CSceneMgr*		CSceneMgr::m_pInstance = nullptr;

CSceneMgr::CSceneMgr():m_pScene(nullptr), m_ePreScene(SC_END), m_eCurrScene(SC_LOGO)
{
}

CSceneMgr::~CSceneMgr()
{
	Release();
}

/* FIX */
void CSceneMgr::Initialize()
{
}

/* FIX */
void CSceneMgr::Update()
{
	m_pScene->Update();
}

/* FIX */
void CSceneMgr::Late_Update()
{
	m_pScene->Late_Update();
}

/* FIX */
void CSceneMgr::Render(HDC hDC)
{
	m_pScene->Render(hDC);
}

/* FIX */
void CSceneMgr::Release()
{
	Safe_Delete(m_pScene);
}


void CSceneMgr::Change_Scene(int  eSCID)
{	
	m_eCurrScene = eSCID;

	// 만약 새로운 씬으로 바꿔야한다면 
	if (m_ePreScene != m_eCurrScene) {

		// 기존 Scene을 비운다.
		Safe_Delete(m_pScene);

		// 새로운 Scene을 동적할당한다. 
		switch (eSCID)
		{
		case SC_LOGO:
			m_pScene = new CLogo;
			break;
		case SC_MENU:
			m_pScene = new CMenu;
			break;
		case SC_EDIT:
			m_pScene = new CEditor;

			if(m_ePreScene != SC_END)
				dynamic_cast<CEditor*>(m_pScene)->Set_StageID(m_ePreScene);		// 에디트 후 저장할 파일명을 위해. 
			else
				dynamic_cast<CEditor*>(m_pScene)->Set_StageID(SC_STAGE_SYJ);		// 에디트 후 저장할 파일명을 위해. 
			break;
		case SC_STAGE_AJS:
			m_pScene = new CStage_SYJ;
			break;
		case SC_STAGE_PIS:
			m_pScene = new CStage_SYJ;
			break;
		case SC_STAGE_SHH:
			m_pScene = new CStage_SYJ;
			break;
		case SC_STAGE_SYJ:
			m_pScene = new CStage_SYJ;
			break;
		case SC_END:

			break;

		default:
			break;
		}

		// 무사히 Scene을 생성했다면
		if (m_pScene) 
			m_pScene->Initialize();
		
		m_ePreScene = m_eCurrScene;
	}
}
