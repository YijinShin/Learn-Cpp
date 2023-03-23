#include "stdafx.h"
#include "CFlag.h"
#include "CScrollMgr.h"

#include "CStageMgr.h"

#include "CBmpMgr.h"

CFlag::CFlag():m_bIsStageEnd(false)
{
}

CFlag::~CFlag()
{
}

void CFlag::Initialize()
{
	m_tInfo.fCX = 20.f;
	m_tInfo.fCY = 20.f;
	
	// TODO: 이미지 추가하기 
	CBmpMgr::Get_Instance()->Insert_MyBmp(L"../Image/pokemon_mark.bmp", L"CFlag");
}

int CFlag::Update()
{
	__super::Update_Rect();
	return 0;
}

void CFlag::Late_Update()
{
	if (m_bIsStageEnd)
		CStageMgr::GoNextStage();
}

void CFlag::Render(HDC hDC)
{
	MyPen = CreatePen(PS_SOLID, 5, RGB(204, 55, 50));
	OldPen = (HPEN)SelectObject(hDC, MyPen);

	int iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	MoveToEx(hDC, (int)m_tInfo.fX + iScrollX, (int)m_tInfo.fY + iScrollY,nullptr);
	LineTo(hDC, (int)(m_tInfo.fX + m_tInfo.fCX) + iScrollX, (int)(m_tInfo.fY + m_tInfo.fCY/2.f) + iScrollY);
	LineTo(hDC, (int)m_tInfo.fX + iScrollX, (int)(m_tInfo.fY + m_tInfo.fCY) + iScrollY);
	LineTo(hDC, (int)m_tInfo.fX + iScrollX, (int)m_tInfo.fY + iScrollY);

	/* Bitmap 이미지 렌더해보기 */

		// 메인DC에 출력할 DC가져오기
		HDC hMemDC = CBmpMgr::Get_Instance()->Find_MyBmp(L"CFlag");

		// 가져온 DC를 메인DC에 출력하기 + 핑크색 배경 지우기 
		GdiTransparentBlt(hDC,							// 복사받을 최종 출력 dc
			(int)m_tRect.left + iScrollX,				// 복사받을 위치의 x좌표
			(int)m_tRect.top + iScrollY,				// 복사받을 위치의 y좌표
			(int)m_tInfo.fCX + 50,						// 비트맵의 가로 사이즈
			(int)m_tInfo.fCY + 50,						// 비트맵의 세로 사이즈
			hMemDC,										// 출력할  이미지 dc
			0,											//m_tFrame.iFrameStart * (int)m_tInfo.fCX, // 비트맵의 출력 시작 x좌표
			0,											//m_tFrame.iMotion * (int)m_tInfo.fCY, // 비트맵의 출력 시작 Y좌표
			(int)m_tInfo.fCX,							// 복사할 비트맵의 가로 사이즈
			(int)m_tInfo.fCY,							// 복사할 비트맵의 세로 사이즈
			RGB(255, 0, 255));							// 제거할 픽셀 색상값

		/*BitBlt(hDC,
				(int)m_tRect.left + iScrollX, 
				(int)m_tRect.top + iScrollY,
				(int)m_tInfo.fCX + 50,				// 50 이건 그냥 이미지 사이즈 맞추기 위해 더한것.
				(int)m_tInfo.fCY + 50,				// 50 이건 그냥 이미지 사이즈 맞추기 위해 더한것.
				hMemDC,
				0,
				0,
				SRCCOPY);*/ 
	

	SelectObject(hDC, OldPen);
	DeleteObject(MyPen);
}

void CFlag::Release()
{

}
