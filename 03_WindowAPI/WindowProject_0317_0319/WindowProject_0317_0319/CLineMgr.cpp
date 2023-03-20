#include "stdafx.h"
#include "CLineMgr.h"

CLineMgr* CLineMgr::m_pInstance = new CLineMgr;

CLineMgr::CLineMgr()
{
}

CLineMgr::~CLineMgr()
{
	Release();
}

void CLineMgr::Initialize()
{
	LINEPOINT	tPoint[6]{
		{100.f, 450.f},
		{300.f, 450.f},
		{500.f, 250.f},
		{700.f, 250.f},
		{100.f, 250.f},
		{300.f, 250.f}
	};
	m_LineList.push_back(new CLine(tPoint[4], tPoint[5]));
	m_LineList.push_back(new CLine(tPoint[0], tPoint[1]));
	m_LineList.push_back(new CLine(tPoint[1], tPoint[2]));
	m_LineList.push_back(new CLine(tPoint[2], tPoint[3]));

}

void CLineMgr::Render(HDC hDC)
{
	for (auto iter : m_LineList)
		iter->Render(hDC);
}

void CLineMgr::Release()
{
	for_each(m_LineList.begin(), m_LineList.end(), Safe_Delete<CLine*>);
	m_LineList.clear();
}

bool CLineMgr::Collision_Line(float _fX, float _fY, float* pCalcY)
{
	float Height(0.f);
	//CLine* tTargetLine(nullptr);
	float fMinYDist(WINCY);
	bool	bIsExist(false);
	for (auto iter : m_LineList) {

		float fX1 = iter->Get_Line().tLpoint.fX;
		float fX2 = iter->Get_Line().tRpoint.fX;
		float fY1 = iter->Get_Line().tLpoint.fY;
		float fY2 = iter->Get_Line().tRpoint.fY;
		
		if (fX1 <= _fX && _fX < fX2) {
			
			// y좌표 구하기 
			float	fM = (fY2 - fY1) / (fX2 - fX1);  // 기울기 
			float   fN = fY1 - fM * fX1;			// y절편  
			float	fCalcY = fM * _fX + fN;
	
			// 현재 Y 좌표와 가장 가까운 라인 찾기 
			if (fMinYDist > abs(fCalcY - _fY)) {
				fMinYDist = abs(fCalcY - _fY);
				*pCalcY = fCalcY;
				//tTargetLine = iter;
				bIsExist = true;
			}

		}
	}
	return bIsExist;
}

