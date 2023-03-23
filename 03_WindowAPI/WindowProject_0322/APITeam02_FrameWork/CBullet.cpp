#include "stdafx.h"
#include "CBullet.h"

CBullet::CBullet()
{
}

CBullet::~CBullet()
{
	Release();
}

void CBullet::Initialize()
{
	m_tInfo.fCX = 20.f;				// 크기 
	m_tInfo.fCY = 20.f;					
	m_iHP = 1;						// 체력
	m_fSpeed = 5.f;					// 속도 
}

int CBullet::Update()
{
	if (m_iHP <= 0) return OBJ_DEAD;

	Update_Info_CenterPos();		// INFO 업데이트
	__super::Update_Rect();			// RECT 업데이트

	return OBJ_NOEVENT;
}

void CBullet::Late_Update()
{
}

void CBullet::Render(HDC hDC)
{
	MyPen = CreatePen(PS_SOLID, 5, RGB(168, 199, 55));
	OldPen = (HPEN)SelectObject(hDC, MyPen);

	Rectangle(hDC,
		m_tRect.left, m_tRect.top,
		m_tRect.right, m_tRect.bottom);
	MoveToEx(hDC, (int)m_tInfo.fX, (int)m_tInfo.fY, nullptr);
	LineTo(hDC,
		(int)(m_tInfo.fX + m_tInfo.Dir.x * 10),
		(int)(m_tInfo.fY + m_tInfo.Dir.y * 10));

	SelectObject(hDC, OldPen);
	DeleteObject(MyPen);
}

void CBullet::Release()
{
}

void CBullet::Update_Info_CenterPos()
{
	// 정해진 방향으로 직진
	m_tInfo.fX += m_tInfo.Dir.x * m_fSpeed;
	m_tInfo.fY += m_tInfo.Dir.y * m_fSpeed;
}
