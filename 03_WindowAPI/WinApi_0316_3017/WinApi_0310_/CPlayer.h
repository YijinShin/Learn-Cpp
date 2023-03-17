#pragma once
#include "CObj.h"


class CPlayer : public CObj
{
private:
	float m_fAimLength;
	pair<float, float> m_AimPos;
	list<CObj*>* m_pBulletList;
	list<CObj*>* m_pMonsterList;
	list<CObj*>* m_pShieldList;

	POINT	ptMouse{};

public:
	CPlayer();
	virtual ~CPlayer();

	virtual void	Initialize()	override;
	virtual	int		Update()		override;
	virtual int		Late_Update()	override;
	virtual void	Render(HDC hDC)		override;
	virtual void	Release()		override;

	void Key_Input();
	void Mouse_Input();

	void Set_BulletList(list<CObj*>* _pBulletList) { m_pBulletList = _pBulletList; }
	void Set_ShieldList(list<CObj*>* _pShieldList) { m_pShieldList = _pShieldList; }
	void Set_MonsterList(list<CObj*>* _pMonsterList) { m_pMonsterList = _pMonsterList; }

	void Calc_Angle();
	void Set_Angle_Mouse();
	void Set_AimPos();
	void Calc_DirVector();

	float Get_Angle() const { return m_fAngle; }

	void Create_Shield();
	void Create_Bullet();
	void Create_BulletChase();
};

