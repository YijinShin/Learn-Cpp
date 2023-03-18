#pragma once
#include "CObj.h"

class CPlayer: public CObj
{
private:
	DWORD			m_iBulletCoolTime;

public:
	CPlayer();
	virtual ~CPlayer();

	// Pure virtual Function
	virtual void	Initialize()	override;
	virtual int		Update()		override;
	virtual void	Late_Update()	override;
	virtual void	Render(HDC hDC)	override;
	virtual void	Release()		override;

	// Set function

	// Get function

protected:
	virtual void	Key_Input();					// 키보드 조작 
	virtual void	Update_Dir();					// 마우스 커서 위치에 따라 포신 회전 

	virtual void	Create_Bullet();				// 총알 생성 
};

