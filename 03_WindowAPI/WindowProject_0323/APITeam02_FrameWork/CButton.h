#pragma once
#include "CObj.h"

class CButton : public CObj
{
private:
	int			m_iDrawID;
public:
	CButton();
	virtual ~CButton();

public:
	// CObj��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
};

