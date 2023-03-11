#pragma once
#include "CObj.h"


class CPlayer: public CObj
{
private:
	list<CObj*>* m_pBulletList;
public:
	CPlayer();
	virtual ~CPlayer();

	virtual void	Initialize()	override;
	virtual	int		Update()		override;
	virtual int		Late_Update()	override;
	virtual void	Render(HDC hDC)		override;
	virtual void	Release()		override;

	void Key_Input();
	CObj* Create_Bullet(DIR _eDir);
	
	void Set_BulletList(list<CObj*>* _pBulletList) { m_pBulletList = _pBulletList; }

};

