#pragma once
#include "Obj.h"
class CBullet: public CObj
{
private:
	RECT m_tFence;
public:
	CBullet();
	virtual ~CBullet();

	virtual void Initialize() override;
	virtual int Update()override;
	virtual void Render(HDC hDC)override;
	virtual void Release()override;
	void Set_Pos(float _fX, float _fY) {
		m_tInfo.fX = _fX;
		m_tInfo.fY = _fY;
	}
	bool isEnd();
};