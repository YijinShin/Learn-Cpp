#pragma once
#include "CObj.h"
#include "CLine.h"

class CPlayer: public CObj
{
private:
	DWORD			m_iBulletCoolTime;

	list<CLine*>*	m_pLineList;

	CVector2		m_cJumpDir;						// 점프하는 방향 단위 백터
	float			m_fJumpForce;					// 점프 하는 힘
	float			m_fJumpTime;					// 점프에 대입할 시간 t
	float			m_fJumpHight;					// 점프 높이 
	bool			m_bIsJump;						// 점프 중인지 확인 

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
	
	virtual void	Jump();							// 점프 
	virtual void	Move();							// 라인을 따라 좌우로 이동 
};

