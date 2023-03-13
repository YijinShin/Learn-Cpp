#pragma once
#include "Define.h"
#include "CObj.h"

class CBall: public CObj
{
private:
	DIRECTION	m_eDir;
	float m_fXSpeed;
	float m_fYSpeed;
	float m_fAngle;

public:
	CBall();
	virtual ~CBall();

	virtual void		Initialize()	override;
	virtual int			Update()		override;
	virtual void		Late_Update()	override;
	virtual void		Render(HDC hDC)	override;
	virtual void		Release()		override;

	void CollisionCheck(CObj* targetObj);
	void Set_XYSpeed();
};

