#include "stdafx.h"
#include "Bullet.h"

CBullet::CBullet()
{
}

CBullet::~CBullet()
{
}

void CBullet::Initialize(void)
{
	m_tInfo.fCX = 20.f;
	m_tInfo.fCY = 20.f;
	
	m_fSpeed = 10.f;
}

int CBullet::Update(void)
{
	Calc_Center();
	__super::Update_Rect();

	return 0;
}

void CBullet::Late_Update(void)
{
}

void CBullet::Render(HDC hDC)
{
	Ellipse(hDC,
		m_tRect.left, m_tRect.top,
		m_tRect.right, m_tRect.bottom);
}

void CBullet::Release(void)
{
}

void CBullet::Calc_Center()
{
	m_tInfo.fY += m_fSpeed;
}
