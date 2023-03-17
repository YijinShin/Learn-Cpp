#include "stdafx.h"
#include "CBullet.h"

CBullet::CBullet()
{
}

CBullet::~CBullet()
{
}

void CBullet::Initialize()
{
	// 총알 지름 설정
	m_tInfo.fCX = 25.f;
	m_tInfo.fCY = 25.f;
	// 총알 속도 설정
	m_fSpeed = 10.f;
}

int CBullet::Update()
{
	if (m_bDead) return OBJ_DEAD;

	switch (m_eDir)
	{
	case DIR_UP:
		m_tInfo.fX += m_DirVector.first * m_fSpeed;
		m_tInfo.fY += m_DirVector.second * m_fSpeed;
		break;
	case DIR_DOWN:
		m_tInfo.fX -= m_DirVector.first * m_fSpeed;
		m_tInfo.fY -= m_DirVector.second * m_fSpeed;
		break;
	case DIR_LEFT:
		m_tInfo.fX -= m_RightDirVector.first * m_fSpeed;
		m_tInfo.fY -= m_RightDirVector.second * m_fSpeed;
		break;
	case DIR_RIGHT:
		m_tInfo.fX += m_RightDirVector.first * m_fSpeed;
		m_tInfo.fY += m_RightDirVector.second * m_fSpeed;
		break;
	case DIR_LU:
		m_tInfo.fX += (m_DirVector.first + m_RightDirVector.first) * m_fSpeed;
		m_tInfo.fY += (m_DirVector.second + m_RightDirVector.second) * m_fSpeed;
		break;
	case DIR_RU:
		m_tInfo.fX += (m_DirVector.first - m_RightDirVector.first) * m_fSpeed;
		m_tInfo.fY += (m_DirVector.second - m_RightDirVector.second) * m_fSpeed;
		break;
	default:
		break;
	}
	__super::Set_Rect();

	return OBJ_NOEVENT;
}

int CBullet::Late_Update()
{
	if (m_tRect.left <= FENCEINTERVAL || m_tRect.right >= WINCX - FENCEINTERVAL
		|| m_tRect.top <= FENCEINTERVAL || m_tRect.bottom >= WINCY - FENCEINTERVAL) {
		m_bDead = true;
	}
	else m_bDead = false;

	return 0;
}

void CBullet::Render(HDC hDC)
{
	Ellipse(hDC,
		m_tRect.left,	m_tRect.top,
		m_tRect.right, m_tRect.bottom);
}

void CBullet::Release()
{
}
