#pragma once
#include "Obj.h"

class CMonster: public CObj
{
private:
	int m_iBulletTimer;			// 총알을 몇초마다 쏠 것인지 결정하는 타이머 

	list<CObj*>* m_pBulletList;

public:
	CMonster();
	virtual ~CMonster();

	// CObj을(를) 통해 상속됨
	virtual void Initialize(void) override;

	virtual int Update(void) override;

	virtual void Late_Update(void) override;

	virtual void Render(HDC hDC) override;

	virtual void Release(void) override;

	// TODO 
	virtual void Calc_Center();
	virtual void Create_Bullet();

	virtual void Set_BulletList(list<CObj*>* _pBulletList) { m_pBulletList = _pBulletList; }

};
