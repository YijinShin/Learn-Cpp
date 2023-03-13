#pragma once
#include "CObj.h"


class CPlayer : public CObj
{
private:
	float m_fAimLength;
	pair<float, float> m_AimPos;
	list<CObj*>* m_pBulletList;

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

	void Set_BulletList(list<CObj*>* _pBulletList) { m_pBulletList = _pBulletList; }

	void Set_Angle();

	float Get_Angle() const { return m_fAngle; }

	float RadianToDegree(float fRadian);

	float  DegreeToRadian(float fDegree);

	void Set_AimPos();
};

