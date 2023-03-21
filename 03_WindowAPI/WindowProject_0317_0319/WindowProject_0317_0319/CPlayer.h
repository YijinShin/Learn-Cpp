#pragma once
#include "CObj.h"
#include "CLine.h"

class CPlayer: public CObj
{
private:
	DWORD			m_iBulletCoolTime;

	CVector2		m_cJumpDir;						// 점프하는 방향 단위 백터
	float			m_fJumpForce;					// 점프 하는 힘
	float			m_fJumpTime;	
	float			m_fJumpTime2;
	float			m_fJumpHight;					// 점프 높이 
	float			m_fMaxHightTime;				// 최고점에서의 시간
	int				m_iMaxHightPauseTime;			// 최고점에서 멈추는 시간
	float			m_fStartJumpYPos;

	bool			m_bIsJump;						// 점프 중인지 확인 
	bool			m_bIsLeft;						// 왼쪽 키 누르는 중인지 확인
	bool			m_bIsRight;						// 오른쪽 키 누르는 중인지 확인 
	bool			m_bIsDown;			

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
	
	virtual void	Jump();		
	virtual void	Jump2();		// 점프 
};

