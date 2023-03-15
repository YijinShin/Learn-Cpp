#pragma once
#include "Obj.h"

class CCollisionMng
{
public:
	CCollisionMng();
	~CCollisionMng();

public:
	static void	Collision_Rect(list<CObj*> _Dst, list<CObj*> _Src);
	static void	Collision_Sphere(list<CObj*> _Dst, list<CObj*> _Src);

	static bool	Check_Sphere(CObj* pDst, CObj* pSrc);

};


