#include "stdafx.h"
#include "CTile.h"

#include "CBmpMgr.h"
#include "CScrollMgr.h"

CTile::CTile():m_iDrawID(0), m_iOption(0)
{
}

CTile::~CTile()
{
}

void CTile::Initialize()
{
	// 타일 크기 지정하기 
	m_tInfo.fCX = TILECX;
	m_tInfo.fCY = TILECY;

	// 필요한 타일 이미지 넣기 
	CBmpMgr::Get_Instance()->Insert_MyBmp( L"../Image/Tile.bmp", L"Tile");
}

int CTile::Update()
{
	__super::Update_Rect();
	return OBJ_NOEVENT;
}

void CTile::Late_Update()
{
}

void CTile::Render(HDC hDC)
{
	int iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	HDC hMemDC = CBmpMgr::Get_Instance()->Find_MyBmp(L"Tile");

	BitBlt(hDC,
			(int)m_tRect.left + iScrollX,
			(int)m_tRect.top + iScrollY,
			TILECX, TILECY,
			hMemDC,
			TILECX * m_iDrawID,
			0,
			SRCCOPY);
}

void CTile::Release()
{
}
