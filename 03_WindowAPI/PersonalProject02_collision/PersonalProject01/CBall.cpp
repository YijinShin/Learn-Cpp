#include "stdafx.h"
#include "CBall.h"

CBall::CBall() : m_eDir(DIR_DOWN), m_fAngle(-90.f), m_fYSpeed(0.f), m_fXSpeed(0.f), m_eCTarget(CTARGET_NULL)
{
}

CBall::~CBall()
{
	Release();
}


void CBall::ChangeDir() {

	if (m_eCTarget == CTARGET_BOTTOM)
		m_bIsDead = true;
	else {
		switch (m_eDir)
		{
		case DIR_UP:
			m_eDir = DIR_DOWN;
			m_fAngle *= (-1);
			break;
		case DIR_DOWN:
			m_eDir = DIR_UP;
			m_fAngle *= (-1);
			break;
		case DIR_LU:
			switch (m_eCTarget)
			{
			case CTARGET_TOP:
				m_eDir = DIR_LD;
				m_fAngle = 180 - m_fAngle;
				break;
			case CTARGET_LEFT:
				m_eDir = DIR_RD;
				m_fAngle = 180 - m_fAngle;
				break;
			default:
				break;
			}
			break;
		case DIR_LD:
			break;
		case DIR_RU:
			break;
		case DIR_RD:
			break;
		default:
			break;
		}
	}
}

void CBall::Set_DirSpeed()
{
	switch (m_eDir)
	{
	case DIR_UP:
		m_fAngle *= (-1);
		break;
	case DIR_DOWN:
		m_fAngle *= (-1);
		break;
	case DIR_LU:
		m_fAngle *= (-1);
		break;
	case DIR_LD:
		break;
	case DIR_RU:
		break;
	case DIR_RD:
		break;
	default:
		break;
	}
}

void CBall::Initialize()
{
	m_tInfo.fCX = 15.f;
	m_tInfo.fCY = 15.f;

	m_fSpeed = 0.f;
}

int CBall::Update()
{

	__super::Set_Rect();
	return 0;
}

void CBall::Late_Update()
{
}

void CBall::Render(HDC hDC)
{
	Ellipse(hDC,
		m_tRect.left, m_tRect.top,
		m_tRect.right, m_tRect.bottom);
}

void CBall::Release()
{
}
