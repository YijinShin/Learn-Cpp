#pragma once

#include "CObj.h"

class CObjMgr
{
private:
	CObjMgr();
	~CObjMgr();

	CObjMgr*		m_pInstance;
	list<CObj*>		m_ObjList[OBJ_END];

public:
};

