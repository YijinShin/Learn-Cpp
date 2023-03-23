#pragma once
#include "CScene.h"

class CStage_SYJ : public CScene
{
private:

public:
	CStage_SYJ();
	virtual ~CStage_SYJ();

public:
	// CScene을(를) 통해 상속됨
	virtual void Initialize() override;

	virtual void Update() override;

	virtual void Late_Update() override;

	virtual void Render(HDC hDC) override;

	virtual void Release() override;


};

