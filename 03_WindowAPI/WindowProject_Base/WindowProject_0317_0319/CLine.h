#pragma once
#include "Include.h"

class CLine
{
private:
	LINE	m_tLine;

public:
	CLine();
	CLine(LINEPOINT _tLpoint, LINEPOINT _tRpoint);
	~CLine();
	
	void	Render(HDC hDC);
};

