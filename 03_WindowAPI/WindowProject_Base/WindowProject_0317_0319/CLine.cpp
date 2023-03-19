#include "stdafx.h"
#include "CLine.h"

CLine::CLine()
{
	ZeroMemory( &m_tLine, sizeof(LINE));
}

CLine::CLine(LINEPOINT _tLpoint, LINEPOINT _tRpoint): m_tLine(_tLpoint, _tRpoint)
{
}

CLine::~CLine()
{
}

void CLine::Render(HDC hDC)
{
	MoveToEx(hDC, (int)m_tLine.tLpoint.fX, (int)m_tLine.tLpoint.fY, nullptr);
	LineTo(hDC, (int)m_tLine.tRpoint.fX, (int)m_tLine.tRpoint.fY);
}
