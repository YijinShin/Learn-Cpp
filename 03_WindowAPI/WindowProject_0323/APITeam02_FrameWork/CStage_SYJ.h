#pragma once
#include "CScene.h"

class CStage_SYJ : public CScene
{
private:

public:
	CStage_SYJ();
	virtual ~CStage_SYJ();

public:
	// CScene��(��) ���� ��ӵ�
	virtual void Initialize() override;

	virtual void Update() override;

	virtual void Late_Update() override;

	virtual void Render(HDC hDC) override;

	virtual void Release() override;


};

