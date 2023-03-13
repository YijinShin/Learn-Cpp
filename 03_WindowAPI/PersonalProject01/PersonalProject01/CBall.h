#pragma once
#include "Include.h"
#include "CObj.h"

class CBall: public CObj
{
private:
	DIRECTION m_eDir;

	COLLISIONTARGET m_eCTarget;

	float m_fAngle;
	float m_fXSpeed;
	float m_fYSpeed;

	void	ChangeDir();
	void	Set_DirSpeed();

public:
	CBall();
	virtual ~CBall();


	virtual void		Initialize()	override;
	virtual int			Update()		override;
	virtual void		Late_Update()	override;
	virtual void		Render(HDC hDC)	override;
	virtual void		Release()		override;

};

