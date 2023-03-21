#include "stdafx.h"
#include "CCollisionMgr.h"


CCollisionMgr::CCollisionMgr()
{
}


CCollisionMgr::~CCollisionMgr()
{
}

/*
void CCollisionMgr::Collision_Rect(list<CObj*> _Dst, list<CObj*> _Src)
{
	RECT		rc{};

	for (auto& _monster : _Dst)
	{
		for (auto& Src : _Src)
		{
			if (IntersectRect(&rc, &(_monster->Get_Rect()), &(Src->Get_Rect())) && !_monster->Is_Dead() && !Src->Is_Dead())
			{
				_monster->Decrease_HP(Src->Get_Attack());
				Src->Decrease_HP(_monster->Get_Attack());
			}
		}
	}
}
*/
