#pragma once
#include "Obj.h"

class CPlayer: public CObj
{
private:
	list<CObj*>* m_pBulletList;

	void		Key_Input();

public:
	CPlayer();
	virtual ~CPlayer();

	virtual void	Initialize() override;
	virtual int		Update()override;
	virtual void	Render(HDC hDC)override;
	virtual void	Release()override;

	CObj*		Create_Bullet(DIRECTION _eDir);
	void		Set_Bullet(list<CObj*>* _pBullet) { m_pBulletList = _pBullet; }

};

