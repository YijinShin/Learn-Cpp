#include "stdafx.h"
#include "CCollisionMgr.h"
#include "CStageMgr.h"

CCollisionMgr::CCollisionMgr()
{
}

CCollisionMgr::~CCollisionMgr()
{
}

bool CCollisionMgr::Collision_Flag_Player(list<CObj*> _Dst, list<CObj*> _Src)
{
	RECT		rc{};

	for (auto& _flag : _Dst)
	{
		for (auto& _player : _Src)
		{
			//if ( IntersectRect( &rc, &(_flag->Get_Rect()), &(_player->Get_Rect()) ))
		//	{
		//		return true;
		//	}
		}
	}
	return false;
}

