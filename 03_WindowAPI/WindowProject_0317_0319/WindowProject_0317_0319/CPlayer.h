#pragma once
#include "CObj.h"
#include "CLine.h"

class CPlayer: public CObj
{
private:
	DWORD			m_iBulletCoolTime;

	list<CLine*>*	m_pLineList;

	CVector2		m_cJumpDir;						// �����ϴ� ���� ���� ����
	float			m_fJumpForce;					// ���� �ϴ� ��
	float			m_fJumpTime;					// ������ ������ �ð� t
	float			m_fJumpHight;					// ���� ���� 
	bool			m_bIsJump;						// ���� ������ Ȯ�� 

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
	virtual void	Key_Input();					// Ű���� ���� 
	virtual void	Update_Dir();					// ���콺 Ŀ�� ��ġ�� ���� ���� ȸ�� 

	virtual void	Create_Bullet();				// �Ѿ� ���� 
	
	virtual void	Jump();							// ���� 
	virtual void	Move();							// ������ ���� �¿�� �̵� 
};

