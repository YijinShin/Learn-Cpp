#include "stdafx.h"
#include "CBullet_Screw.h"

CBullet_Screw::CBullet_Screw()
{

}

CBullet_Screw::~CBullet_Screw()
{

}

void CBullet_Screw::Initialize()
{
	// 총알 지름 설정
	m_tInfo.fCX = 25.f;
	m_tInfo.fCY = 25.f;
	// 총알 속도 설정
	m_fSpeed = 4.f;
}

int CBullet_Screw::Update()
{
	return 0;
}

int CBullet_Screw::Late_Update()
{
	if (m_tRect.left <= FENCEINTERVAL || m_tRect.right >= WINCX - FENCEINTERVAL
		|| m_tRect.top <= FENCEINTERVAL || m_tRect.bottom >= WINCY - FENCEINTERVAL) {
		m_bDead = true;
	}
	else m_bDead = false;

	return 0;
}
