#pragma once
#include "Obj.h"
class CPlayer :	public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

	virtual void Set_BulletList(list<CObj*>* _pBulletList) { m_pBulletList = _pBulletList; }
	virtual void Create_Bullet();

private:
	void		Key_Input(void);

	list<CObj*>* m_pBulletList;
};

