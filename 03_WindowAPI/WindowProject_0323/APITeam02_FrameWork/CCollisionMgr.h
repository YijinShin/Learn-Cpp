#pragma once
#include "CObj.h"


class CCollisionMgr
{
public:
	CCollisionMgr();
	~CCollisionMgr();

public:

	// 기본 Collision 함수 


	// TODO : 프로그램에 필요한 충돌 함수 작성하기 
	static void		Collision_Flag_Player(list<CObj*> _Dst, list<CObj*> _Src);

};