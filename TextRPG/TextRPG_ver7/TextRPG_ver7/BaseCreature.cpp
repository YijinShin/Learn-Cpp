#include "stdafx.h"
#include "BaseCreature.h"

CBaseCreature::CBaseCreature()
{	// �����ڴ� inline �� ����. 
	memset(&m_stBCINFO, 0, sizeof(m_stBCINFO));
}

CBaseCreature::~CBaseCreature()
{	// �Ҹ��ڴ� inline �� ����. 
}

bool CBaseCreature::IsDead()
{
	if (m_stBCINFO.iCurrHP <= 0) return true;
	else return false;
}
