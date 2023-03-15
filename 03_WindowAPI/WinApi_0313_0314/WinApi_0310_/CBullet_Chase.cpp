#include "stdafx.h"
#include "CBullet_Chase.h"

CBullet_Chase::CBullet_Chase() : m_pTarget(nullptr), m_pMonsterList(nullptr)
{
}

CBullet_Chase::~CBullet_Chase()
{
}

void CBullet_Chase::Initialize()
{
	// �Ѿ� ���� ����
	m_tInfo.fCX = 25.f;
	m_tInfo.fCY = 25.f;
	// �Ѿ� �ӵ� ����
	m_fSpeed = 10.f;
	// �Ѿ� Ÿ�� ���� 
	//FindTarget();
}

int CBullet_Chase::Update()
{

	if (m_bDead) return OBJ_DEAD;

	// �÷��̾��� ������ - ������ ������ ������� ���� ���� ���� ���ϱ� 
	Calc_Dir();
	// rect ������Ʈ
	__super::Set_Rect();
	return OBJ_NOEVENT;
}



void CBullet_Chase::FindTarget()
{
	pair<float, CObj*> currTargetInfo;
	currTargetInfo.first = sqrt( pow(WINCX/2.f, 2) + pow(WINCY / 2.f, 2));
	
	for (auto iter : *m_pMonsterList) {
		float fDist = sqrt(pow(m_tInfo.fX - iter->GetInfo().fX, 2) + pow(m_tInfo.fY - iter->GetInfo().fY, 2));

		if (fDist < currTargetInfo.first) {
			currTargetInfo.first = fDist;
			currTargetInfo.second = iter;
		}
	}
	m_pTarget = currTargetInfo.second;
}

void CBullet_Chase::Calc_Dir()
{
	if (m_tInfo.fX != m_pTarget->GetInfo().fX || m_tInfo.fY != m_pTarget->GetInfo().fY) {

		//POINT vector{};
		pair<float, float> vector;
		float fH(0.f);

		vector.first = (m_pTarget->GetInfo().fX - m_tInfo.fX);
		vector.second = (m_pTarget->GetInfo().fY - m_tInfo.fY);


		fH = sqrt(pow(vector.first, 2) + pow(vector.second, 2));

		vector.first /= fH;
		vector.second /= fH;

		m_tInfo.fX += vector.first * m_fSpeed;
		m_tInfo.fY += vector.second * m_fSpeed;
	}
}


