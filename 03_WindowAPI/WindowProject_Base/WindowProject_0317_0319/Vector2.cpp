#include "stdafx.h"
#include "Vector2.h"

CVector2::CVector2(): x(0.f), y(0.f)
{
}

CVector2::~CVector2()
{
}

void CVector2::Normalize()
{
	float fLength = (float)sqrt( x*x + y*y );
	x /= fLength;
	y /= fLength;
}


