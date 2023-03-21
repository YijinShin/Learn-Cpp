#pragma once
#include "Include.h"

class CStage
{
private:

public:
	static	int			m_eStageID;			// �� �������� ID


	static void			Initialize();
	static void			Update();
	static bool			Late_Update();
	static void			Render(HDC hDC);
	static void			Release();

	static void			GoNextStage();
	static bool			CheckStageEnd();

	// �������� ������ �ѱ�� NŰ�� ��Ÿ�� ������ ���� ����
	static float				m_fNkey_CoolTime;
};

