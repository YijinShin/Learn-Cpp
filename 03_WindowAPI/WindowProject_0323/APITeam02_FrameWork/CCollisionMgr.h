#pragma once
#include "CObj.h"


class CCollisionMgr
{
public:
	CCollisionMgr();
	~CCollisionMgr();

public:

	// �⺻ Collision �Լ� 


	// TODO : ���α׷��� �ʿ��� �浹 �Լ� �ۼ��ϱ� 
	static void		Collision_Flag_Player(list<CObj*> _Dst, list<CObj*> _Src);

};