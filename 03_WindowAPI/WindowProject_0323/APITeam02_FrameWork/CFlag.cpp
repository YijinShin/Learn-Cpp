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
	
	// TODO: �̹��� �߰��ϱ� 
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

	/* Bitmap �̹��� �����غ��� */

		// ����DC�� ����� DC��������
		HDC hMemDC = CBmpMgr::Get_Instance()->Find_MyBmp(L"CFlag");

		// ������ DC�� ����DC�� ����ϱ� + ��ũ�� ��� ����� 
		GdiTransparentBlt(hDC,							// ������� ���� ��� dc
			(int)m_tRect.left + iScrollX,				// ������� ��ġ�� x��ǥ
			(int)m_tRect.top + iScrollY,				// ������� ��ġ�� y��ǥ
			(int)m_tInfo.fCX + 50,						// ��Ʈ���� ���� ������
			(int)m_tInfo.fCY + 50,						// ��Ʈ���� ���� ������
			hMemDC,										// �����  �̹��� dc
			0,											//m_tFrame.iFrameStart * (int)m_tInfo.fCX, // ��Ʈ���� ��� ���� x��ǥ
			0,											//m_tFrame.iMotion * (int)m_tInfo.fCY, // ��Ʈ���� ��� ���� Y��ǥ
			(int)m_tInfo.fCX,							// ������ ��Ʈ���� ���� ������
			(int)m_tInfo.fCY,							// ������ ��Ʈ���� ���� ������
			RGB(255, 0, 255));							// ������ �ȼ� ����

		/*BitBlt(hDC,
				(int)m_tRect.left + iScrollX, 
				(int)m_tRect.top + iScrollY,
				(int)m_tInfo.fCX + 50,				// 50 �̰� �׳� �̹��� ������ ���߱� ���� ���Ѱ�.
				(int)m_tInfo.fCY + 50,				// 50 �̰� �׳� �̹��� ������ ���߱� ���� ���Ѱ�.
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
