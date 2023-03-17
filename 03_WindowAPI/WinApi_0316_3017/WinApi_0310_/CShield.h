#pragma once
#include "CObj.h"

class CShield: public CObj
{
private:
	const INFO* m_tPlayerInfo;
public:
	CShield();
	virtual ~CShield();

	// CObj��(��) ���� ��ӵ�
	virtual void Initialize() override;

	virtual int Update() override;

	virtual int Late_Update() override;

	virtual void Render(HDC hDC) override;

	virtual void Release() override;

	virtual void Calc_Dir();

	void Set_PlayerInfo(const INFO* _tPlayerInfo) { m_tPlayerInfo = _tPlayerInfo; }
};

