#include "stdafx.h"
#include "CMonster_type1.h"

CMonster_type1::CMonster_type1(): m_pTargetList(nullptr), m_iTimer(0)
{
	ZeroMemory(&m_tPlayerInfo, sizeof(INFO));
}

CMonster_type1::~CMonster_type1()
{
}

void CMonster_type1::Initialize()
{	
	m_tInfo.fCX = 60.f;
	m_tInfo.fCY = 60.f;

	m_fSpeed = 5.f;
}

int CMonster_type1::Update()
{	
	m_iTimer++;
	
	if (m_bDead) return OBJ_DEAD;

	if(m_iTimer >= 50){
		m_tPlayerInfo = ((*m_pTargetList).front())->GetInfo();
		m_iTimer = 0;
	}
	// 플레이어의 중점과 - 몬스터의 중점을 기반으로 다음 몬스터 중점 구하기 
	Calc_Dir();
	// rect 업데이트
	__super::Set_Rect();
	return OBJ_NOEVENT;
}

void CMonster_type1::Render(HDC hDC)
{
	Rectangle(hDC,
		m_tRect.left, m_tRect.top,
		m_tRect.right, m_tRect.bottom);

	TCHAR	szBuff[100] = L"";
	swprintf_s(szBuff, L"P_fx, P_fy: %f, %f", m_tPlayerInfo.fX, m_tPlayerInfo.fY);
	TextOut(hDC, 50, 130, szBuff, lstrlen(szBuff));
	swprintf_s(szBuff, L"M_fx, M_fy: %f, %f", m_tInfo.fX, m_tInfo.fY);
	TextOut(hDC, 50, 160, szBuff, lstrlen(szBuff));
}


void CMonster_type1::Calc_Dir()
{
	// 삼각함수의 역함수 

	// 백터
	
	if (m_tInfo.fX != m_tPlayerInfo.fX || m_tInfo.fY != m_tPlayerInfo.fY) {

		//POINT vector{};
		pair<float, float> vector;
		float fH(0.f);

		vector.first = (m_tPlayerInfo.fX - m_tInfo.fX);
		vector.second = (m_tPlayerInfo.fY - m_tInfo.fY);

	/*	if (m_tInfo.fX <= m_tPlayerInfo.fX && m_tInfo.fY <= m_tPlayerInfo.fY) {
			vector.x = (m_tPlayerInfo.fX - m_tInfo.fX);
			vector.second = (m_tPlayerInfo.fY - m_tInfo.fY);
		}
		else if (m_tInfo.fX <= m_tPlayerInfo.fX && m_tInfo.fY >= m_tPlayerInfo.fY) {
			vector.x = (m_tPlayerInfo.fX - m_tInfo.fX);
			vector.second = (m_tInfo.fY - m_tPlayerInfo.fY );
		}
		else if (m_tInfo.fX >= m_tPlayerInfo.fX && m_tInfo.fY <= m_tPlayerInfo.fY) {
			vector.x = (m_tPlayerInfo.fX - m_tInfo.fX);
			vector.second = (m_tPlayerInfo.fY - m_tInfo.fY);
		}
		else if (m_tInfo.fX >= m_tPlayerInfo.fX && m_tInfo.fY >= m_tPlayerInfo.fY) {
			vector.x = (m_tPlayerInfo.fX - m_tInfo.fX);
			vector.second = (m_tInfo.fY - m_tPlayerInfo.fY);
		}*/

		fH = sqrt(pow(vector.first, 2) + pow(vector.second, 2));

		vector.first /= fH;
		vector.second /= fH;

		//vector.x *= m_fSpeed;
		//vector.second *= m_fSpeed;

		m_tInfo.fX += vector.first * m_fSpeed;
		m_tInfo.fY += vector.second * m_fSpeed;
	}
	
}
