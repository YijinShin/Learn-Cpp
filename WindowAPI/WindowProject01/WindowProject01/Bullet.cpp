#include "stdafx.h"
#include "Bullet.h"

CBullet::CBullet()
{
}

CBullet::~CBullet()
{
}

void CBullet::Initialize()
{
	// 총알의 가로 세로 길이 세팅
	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 50.f;
	// 총알 속도 세팅 
	m_fSpeed = 3.f;
}

int CBullet::Update()
{
	switch (m_eDir)
	{
	case DIR_LEFT:
		m_tInfo.fX -= m_fSpeed;
		break;

	case DIR_UP:
		m_tInfo.fY -= m_fSpeed;
		break;

	case DIR_RIGHT:
		m_tInfo.fX += m_fSpeed;
		break;

	case DIR_DOWN:
		m_tInfo.fY += m_fSpeed;
		break;

	case DIR_LU:
		m_tInfo.fX -= m_fSpeed;
		m_tInfo.fY -= m_fSpeed;
		break;

	case DIR_RU:
		m_tInfo.fX += m_fSpeed;
		m_tInfo.fY -= m_fSpeed;
		break;
	}

	__super::Update_Rect();

	return 0;
}

void CBullet::Render(HDC hDC)
{
	Ellipse(hDC, 
		m_tRect.left, m_tRect.top,
		m_tRect.right, m_tRect.bottom);
}

void CBullet::Release()
{
}
