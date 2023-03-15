#include "stdafx.h"
#include "CollisionMng.h"


CCollisionMng::CCollisionMng()
{
}


CCollisionMng::~CCollisionMng()
{
}

void CCollisionMng::Collision_Rect(list<CObj*> _Dst, list<CObj*> _Src)
{
	RECT		rc{};

	for (auto& Dest : _Dst)
	{
		for (auto& Src : _Src)
		{
			if (IntersectRect(&rc, &(Dest->Get_Rect()), &(Src->Get_Rect())))
			{
				Dest->Set_Dead();
				Src->Set_Dead();
			}
		}
	}
}

void CCollisionMng::Collision_Sphere(list<CObj*> _Dst, list<CObj*> _Src)
{
	for (auto& Dest : _Dst)
	{
		for (auto& Src : _Src)
		{
			if (Check_Sphere(Dest, Src))
			{
				Dest->Set_Dead();
				Src->Set_Dead();
			}
		}
	}
}

bool CCollisionMng::Check_Sphere(CObj* pDst, CObj* pSrc)
{
	// abs() : 절대값을 만들어주는 함수

	float		fWidth = abs(pDst->Get_Info().fX - pSrc->Get_Info().fX);
	float		fHeight = abs(pDst->Get_Info().fY - pSrc->Get_Info().fY);

	float		fDistance = sqrt(fWidth * fWidth + fHeight * fHeight);

	float		fRadius = (pDst->Get_Info().fCX + pSrc->Get_Info().fCX) * 0.5f;

	return fRadius >= fDistance;
}
