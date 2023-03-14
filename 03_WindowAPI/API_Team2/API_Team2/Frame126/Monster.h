#pragma once
#include "Obj.h"

class CMonster: public CObj
{
private:
	int m_iBulletTimer;			// �Ѿ��� ���ʸ��� �� ������ �����ϴ� Ÿ�̸� 

	list<CObj*>* m_pBulletList;

public:
	CMonster();
	virtual ~CMonster();

	// CObj��(��) ���� ��ӵ�
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
