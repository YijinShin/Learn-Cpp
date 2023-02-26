#include "stdafx.h"
#include "BaseCreature.h"

CBaseCreature::CBaseCreature()
{	// 생성자는 inline 잘 안함. 
	memset(&m_stBCINFO, 0, sizeof(m_stBCINFO));
}

CBaseCreature::~CBaseCreature()
{	// 소멸자는 inline 잘 안함. 
}

bool CBaseCreature::IsDead()
{
	if (m_stBCINFO.iCurrHP <= 0) return true;
	else return false;
}
