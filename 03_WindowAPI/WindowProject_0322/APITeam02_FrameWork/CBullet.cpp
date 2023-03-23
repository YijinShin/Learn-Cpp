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
	m_tInfo.fCX = 20.f;				// ũ�� 
	m_tInfo.fCY = 20.f;					
	m_iHP = 1;						// ü��
	m_fSpeed = 5.f;					// �ӵ� 
}

int CBullet::Update()
{
	if (m_iHP <= 0) return OBJ_DEAD;

	Update_Info_CenterPos();		// INFO ������Ʈ
	__super::Update_Rect();			// RECT ������Ʈ

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
	// ������ �������� ����
	m_tInfo.fX += m_tInfo.Dir.x * m_fSpeed;
	m_tInfo.fY += m_tInfo.Dir.y * m_fSpeed;
}
