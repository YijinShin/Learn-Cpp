#pragma once
#include "Include.h"

class CStage
{
private:

public:
	static	int			m_eStageID;			// 현 스테이지 ID


	static void			Initialize();
	static void			Update();
	static bool			Late_Update();
	static void			Render(HDC hDC);
	static void			Release();

	static void			GoNextStage();
	static bool			CheckStageEnd();

	// 스테이지 강제로 넘기는 N키의 쿨타임 적용을 위한 변수
	static float				m_fNkey_CoolTime;
};

