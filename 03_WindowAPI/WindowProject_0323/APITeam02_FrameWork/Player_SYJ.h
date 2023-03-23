#pragma once
#include "CPlayer.h"

class CPlayer_SYJ : public CPlayer
{
private:
	
	// Jump 관련 변수들
	CVector2				m_cPosBeforJump;
	CVector2				m_cJumpDir;
	float					m_fJumpForce;
	float					m_fJumpTime;
	bool					m_bIsJump;
	bool					m_bIsDown;
	float					m_fOldJumpHight;

	

public:
	CPlayer_SYJ();
	virtual ~CPlayer_SYJ();

public:
	virtual void	Initialize()	override;
	virtual int		Update()		override;
	virtual void	Late_Update()	override;
	virtual void	Render(HDC hdc)	override;
	virtual void	Release()		override;

	virtual void	Create_Bullet() override;

	void			Key_Input();

	void			Jump();					// 포물선점프	

	void			OffSet();
};