#pragma once
#include "CScene.h"

class CEditor : public CScene
{
private:
public:
	CEditor();
	virtual ~CEditor();

public:
	// CScene��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;


	void		Key_Input();
	void		Set_StageID(int _eStageID);

};

