#include "stdafx.h"
#include "CCollisionMgr.h"

#include "CFlag.h"
#include "CStageMgr.h"

CCollisionMgr::CCollisionMgr()
{
}

CCollisionMgr::~CCollisionMgr()
{
}

void CCollisionMgr::Collision_Flag_Player(list<CObj*> _Dst, list<CObj*> _Src)
{
	RECT		rc{};

	for (auto& _flag : _Dst)
	{
		for (auto& _player : _Src)
		{
			RECT tFlagRect = _flag->Get_Rect();
			RECT tPlayerRect = _player->Get_Rect();
			if (IntersectRect(&rc, &tFlagRect, &tPlayerRect))
			{
				CStageMgr::GoNextStage();
			}
			
		}
	}
}

