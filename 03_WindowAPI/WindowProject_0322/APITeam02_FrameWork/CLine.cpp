#include "stdafx.h"
#include "CLine.h"

#include "CScrollMgr.h"


CLine::CLine()
{
	ZeroMemory( &m_tLine, sizeof(LINE));
}

CLine::CLine(LINEPOINT _tLpoint, LINEPOINT _tRpoint): m_tLine(_tLpoint, _tRpoint)
{
}

CLine::CLine(LINE& _tLine): m_tLine(_tLine)
{
}

CLine::~CLine()
{
}

void CLine::Render(HDC hDC)
{
	int iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	MoveToEx(hDC, (int)m_tLine.tLpoint.fX + iScrollX, (int)m_tLine.tLpoint.fY + iScrollY, nullptr);
	LineTo(hDC, (int)m_tLine.tRpoint.fX + iScrollX, (int)m_tLine.tRpoint.fY + iScrollY);
}
