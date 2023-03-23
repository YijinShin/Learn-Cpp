#include "stdafx.h"
#include "CButton.h"

#include "CKeyMgr.h"
#include "CBmpMgr.h"
#include "CSceneMgr.h"

CButton::CButton():m_iDrawID(0)
{
}

CButton::~CButton()
{
}

void CButton::Initialize()
{
	m_tInfo.fCX = 150.f;
	m_tInfo.fCY = 150.f;
}

int CButton::Update()
{
	__super::Update_Rect();
	return OBJ_NOEVENT;
}

void CButton::Late_Update()
{
	// 마우스 위치를 잡기
	POINT	pt{};
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	// 마우스 좌표가가 지정된 RECT(이 버튼 객체)안에 있는지 확인
	if (PtInRect(&m_tRect, pt)) {
		// 버튼 영역안에 있는 경우

		// 버튼의 렌더 영역 바꿔주기 
		m_iDrawID = 1;

		// 좌클릭을 하면 씬 바꾸기 
		if (CKeyMgr::Get_Instance()->Key_Down(VK_LBUTTON))
		{
			if (!lstrcmp(L"Start", m_pFrameKey))
				CSceneMgr::Get_Instance()->Change_Scene(SC_STAGE_SYJ);

			else if (!lstrcmp(L"Edit", m_pFrameKey)) {
				CSceneMgr::Get_Instance()->Change_Scene(SC_EDIT);
			}
			else if (!lstrcmp(L"Exit", m_pFrameKey))
				DestroyWindow(g_hWnd);

			return;
		}

	}
	else
	{
		// 버튼의 렌더 영역 바꿔주기
		m_iDrawID = 0;
	}
}

void CButton::Render(HDC hDC)
{
	HDC hMemDC = CBmpMgr::Get_Instance()->Find_MyBmp(m_pFrameKey);

	GdiTransparentBlt(hDC,
		(int)m_tRect.left,
		(int)m_tRect.top,
		(int)m_tInfo.fCX,
		(int)m_tInfo.fCY,
		hMemDC,
		m_iDrawID * (int)m_tInfo.fCX,
		0,
		(int)m_tInfo.fCX,
		(int)m_tInfo.fCY,
		RGB(255, 255, 255));				// 제거할 색깔 
}

void CButton::Release()
{
}
