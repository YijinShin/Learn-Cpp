#pragma once
#include "Obj.h"

class CMonster: public CObj
{
private:
	RECT m_tFence;

	void Set_Pos(float _fX, float _fY) {
		m_tInfo.fX = _fX;
		m_tInfo.fY = _fY;
	}
public:
	CMonster();
	virtual ~CMonster();

	virtual void	Initialize() override;
	virtual int		Update()override;
	virtual void	Render(HDC hDC)override;
	virtual void	Release()override;

	void Set_Fence(RECT _tFence);
};

