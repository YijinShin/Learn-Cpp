#pragma once
#include "CScene.h"

class CLogo : public CScene
{
public:
	CLogo();
	virtual ~CLogo();

public:
	// CScene��(��) ���� ��ӵ�
	virtual void Initialize() override;

	virtual void Update() override;

	virtual void Late_Update() override;

	virtual void Render(HDC hDC) override;

	virtual void Release() override;

public:
	void		Key_Input();
};

