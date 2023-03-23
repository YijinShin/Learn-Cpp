#pragma once
#include "Include.h"

class CStageMgr
{
private:

public:
	static	int			m_eStageID;			// 현 스테이지 ID

public:
	CStageMgr();
	~CStageMgr();

public:
	static void			Initialize();
	static void			Update();
	static bool			Late_Update();
	static void			Render(HDC hDC);
	static void			Release();

	static void			GoNextStage();
	static bool			CheckStageEnd();

	static int			Get_StageID() { return m_eStageID; }

};

