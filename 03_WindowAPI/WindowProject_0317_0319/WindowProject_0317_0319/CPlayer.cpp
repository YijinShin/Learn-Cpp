#include "stdafx.h"
#include "CPlayer.h"
#include "CBullet.h"

#include "AbstractFactory.h"
#include "CObjMgr.h"
#include "CLineMgr.h"

CPlayer::CPlayer():m_iBulletCoolTime(GetTickCount64()), m_pLineList(nullptr), 
		m_fJumpForce(0.f), m_fJumpTime(0.f), m_fJumpHight(0.f), m_bIsJump(false)
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

	m_fJumpForce = 20.f;

	m_pLineList = CLineMgr::Get_Instance() -> Get_LineList();		// line 가져오기 ( 플에이어가 발디디는 땅)
}

int CPlayer::Update()
{
	if (m_iHP <= 0) return OBJ_DEAD;	// 사망 처리 

	Update_Dir();						// 방향 백터 업데이트

	if (m_bIsJump) {					// 점프 처리 
		Jump();
	}
	else Key_Input();					// 입력 처리 (Info 업데이트)	

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
	Rectangle(hDC,
		m_tRect.left, m_tRect.top,
		m_tRect.right, m_tRect.bottom);

	MoveToEx(hDC, (int)m_tInfo.fX, (int)m_tInfo.fY, nullptr);
	LineTo(hDC, 
		(int)(m_tInfo.fX + m_tInfo.Dir.x * 50),
		(int)(m_tInfo.fY + m_tInfo.Dir.y * 50));
}

void CPlayer::Release()
{
}

void CPlayer::Key_Input()
{
	// 이동 (상하좌우)
	if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W')) {
	}
	if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S')) {
	}
	if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A')) {
		// 왼쪽에 길이 더 있는지 체크 
		auto	iter = m_pLineList->begin();
		if (m_tRect.left <= (*iter)->Get_Line().tLpoint.fX)
			return;
		m_tInfo.fX -= m_fSpeed;
		m_tInfo.fY = Calc_yPos();
	}
	if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D')) {
		// 오른쪽에 길이 더 있는지 체크 
		auto	iter = m_pLineList->begin();
		if (m_tRect.right >= m_pLineList->back()->Get_Line().tRpoint.fX)
			return;
		m_tInfo.fX += m_fSpeed;
		m_tInfo.fY = Calc_yPos();
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
		// 점프 방향 백터 설정
		m_cJumpDir.x = (float)cos(90 * DegreeToRadian); //0;
		m_cJumpDir.y = (float)sin(90 * DegreeToRadian); //1;
		// 점프 
		//m_fJumpTime = GetTickCount();
		m_fJumpTime = 0.f;
		m_bIsJump = true;
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

void CPlayer::Jump()
{	
	// 시간 계산
	m_fJumpTime ++;
	float fT = m_fJumpTime / 5.f;

	// x, y좌표 계산
		// x: V0 * cosθ * t
		// y: V0 * sinθ * t - 1/2 * g * t^2
 	m_tInfo.fX += m_fJumpForce * m_cJumpDir.x * fT;
	m_tInfo.fY -= (m_fJumpForce * m_cJumpDir.y * fT) - ((G * fT * fT)/2.f); 

	/*	// 화면 상단으로 벗어나지 않도록 
	if (m_tRect.top <= 0) {
		m_cJumpDir.y = -1;
	}
	*/

	// y좌표로 점프 끝났는지 확인하기
	float fYPos = Calc_yPos();

	if (m_tInfo.fY >= fYPos ){
		m_tInfo.fY = fYPos;						// x좌표 기준으로 y값 보정하기 
		m_bIsJump = false;						
	}
}

float CPlayer::Calc_yPos()
{
	auto	iter = m_pLineList->begin();
	LINE	line{};
	float	fYPos(0.f);

	while ( iter != m_pLineList->end()) {

		line = (*iter)->Get_Line();

		if (line.tLpoint.fX <= m_tInfo.fX && m_tInfo.fX <= line.tRpoint.fX) {

			float	m = (line.tRpoint.fY - line.tLpoint.fY) / (line.tRpoint.fX - line.tLpoint.fX);  // 기울기 
			float   n = line.tLpoint.fY - m * line.tLpoint.fX;										// y절편  
			fYPos = m * m_tInfo.fX + n;
			break;
		}
		iter++;
	}
	return fYPos;
}
