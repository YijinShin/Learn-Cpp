#pragma once
#include "Include.h"

// Scene 
#include "CScene.h"
#include "CStage_SYJ.h"
#include "CEditor.h"
#include "CLogo.h"
#include "CMenu.h"

class CSceneMgr
{
private:
	CSceneMgr();
	~CSceneMgr();

private:
	CScene*					m_pScene;
	int						m_ePreScene;
	int						m_eCurrScene;

public:
	static CSceneMgr*		m_pInstance;

public:
	static CSceneMgr*		Get_Instance() {
		if (!m_pInstance) 
			m_pInstance = new CSceneMgr;
		
		return m_pInstance;
	}

	static void				Destroy_Instance(){
		if (m_pInstance) {
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

public:
	void					Initialize();
	void					Update();
	void					Late_Update();
	void					Render(HDC hDC);
	void					Release();

	void					Change_Scene(int  eSCID);
	int						Get_CurrSceneId() { return m_eCurrScene; }
	int						Get_PreSceneId() { return m_ePreScene; }
};

