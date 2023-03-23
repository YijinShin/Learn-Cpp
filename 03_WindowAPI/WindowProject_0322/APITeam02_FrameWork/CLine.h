#pragma once
#include "Include.h"

class CLine
{
private:
	LINE	m_tLine;

public:
	CLine();
	CLine(LINEPOINT _tLpoint, LINEPOINT _tRpoint);
	CLine(LINE& _tLine);
	~CLine();
	
	void	Render(HDC hDC);

public:
	const LINE& Get_Line() const { return m_tLine; }
};

