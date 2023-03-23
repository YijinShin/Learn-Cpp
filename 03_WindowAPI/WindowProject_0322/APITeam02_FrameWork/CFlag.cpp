#include "stdafx.h"
#include "CFlag.h"

CFlag::CFlag()
{
}

CFlag::~CFlag()
{
}

void CFlag::Initialize()
{
}

int CFlag::Update()
{
	return 0;
}

void CFlag::Late_Update()
{
}

void CFlag::Render(HDC hDC)
{
	MyPen = CreatePen(PS_SOLID, 5, RGB(204, 55, 50));
	OldPen = (HPEN)SelectObject(hDC, MyPen);

	MoveToEx(hDC, (int)m_tInfo.fX, (int)m_tInfo.fY,nullptr);
	LineTo(hDC, (int)(m_tInfo.fX + m_tInfo.fCX), (int)(m_tInfo.fY + m_tInfo.fCY/2.f));
	LineTo(hDC, (int)m_tInfo.fX, (int)(m_tInfo.fY + m_tInfo.fCY));
	LineTo(hDC, (int)m_tInfo.fX, (int)m_tInfo.fY);

	SelectObject(hDC, OldPen);
	DeleteObject(MyPen);
}

void CFlag::Release()
{

}
