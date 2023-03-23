#include "stdafx.h"
#include "CPlayer.h"
#include "CBullet.h"

#include "AbstractFactory.h"
#include "CObjMgr.h"

CPlayer::CPlayer():m_iBulletCoolTime(GetTickCount64())
{
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	m_tInfo.fCX = 90.f;					// 크기 
	m_tInfo.fCY = 90.f;
	m_iHP = 10;							// 체력
	m_fSpeed = 10.f;					// 속도 
}

int CPlayer::Update()
{
	if (m_iHP <= 0) return OBJ_DEAD;	// 사망 처리 

	Update_Dir();						// 방향 백터 업데이트
	Key_Input();						// 입력 처리 (Info 업데이트)	
	__super::Update_Rect();				// RECT 업데이트

	return OBJ_NOEVENT;
}

void CPlayer::Late_Update()
{
	// 공격 쿨타임
	if (m_iBulletCoolTime + 200 < GetTickCount()) {
		m_iBulletCoolTime = (long)0;
	}
}

void CPlayer::Render(HDC hDC)
{
	MyPen = CreatePen(PS_SOLID, 5, RGB(168, 199, 55));
	OldPen = (HPEN)SelectObject(hDC, MyPen);

	Rectangle(hDC,
		m_tRect.left, m_tRect.top,
		m_tRect.right, m_tRect.bottom);

	MoveToEx(hDC, (int)m_tInfo.fX, (int)m_tInfo.fY, nullptr);
	LineTo(hDC, 
		(int)(m_tInfo.fX + m_tInfo.Dir.x * 50),
		(int)(m_tInfo.fY + m_tInfo.Dir.y * 50));

	SelectObject(hDC, OldPen);
	DeleteObject(MyPen);
}

void CPlayer::Release()
{
}

void CPlayer::Key_Input()
{
	// 이동 (상하좌우)
	if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W')) {
		m_tInfo.fX += m_tInfo.Dir.x * m_fSpeed;
		m_tInfo.fY += m_tInfo.Dir.y * m_fSpeed;
	}
	if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S')) {
		m_tInfo.fX -= m_tInfo.Dir.x * m_fSpeed;
		m_tInfo.fY -= m_tInfo.Dir.y * m_fSpeed;
	}
	if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A')) {
		m_tInfo.fX += m_tInfo.Dir.y * m_fSpeed;
		m_tInfo.fY -= m_tInfo.Dir.x * m_fSpeed;
	}
	if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D')) {
		m_tInfo.fX -= m_tInfo.Dir.y * m_fSpeed;
		m_tInfo.fY += m_tInfo.Dir.x * m_fSpeed;
	}

	// 공격 (좌클릭)
	if (GetAsyncKeyState(VK_LBUTTON)) {
		if (m_iBulletCoolTime == 0) {
			Create_Bullet();
			m_iBulletCoolTime = GetTickCount();
		}
	}

	// 점프 
	if (GetAsyncKeyState(VK_SPACE)) {

	}
}

void CPlayer::Update_Dir()
{
	POINT	ptMouse{};

	GetCursorPos(&ptMouse);
	ScreenToClient(g_hWnd, &ptMouse);

	LookAt(ptMouse);			// 마우스 포인터를 바라보는 방향 단위 백터 계산해 m_tInfo.Dir에 저장
}

void CPlayer::Create_Bullet()
{
	CObj* pObj = CAbstractFactory<CBullet>::Create(m_tInfo.fX, m_tInfo.fY);
	pObj->Set_Dir(m_tInfo.Dir);
	CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, pObj);
}

