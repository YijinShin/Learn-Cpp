#include "stdafx.h"
#include "CPlayer.h"
#include "CBullet.h"

#include "AbstractFactory.h"
#include "CObjMgr.h"
#include "CLineMgr.h"

CPlayer::CPlayer():m_iBulletCoolTime(GetTickCount64()), 
		m_fJumpForce(0.f), m_fJumpTime(0.f), m_fJumpHight(0.f), m_bIsJump(false),
		m_fMaxHightTime(0.f), m_iMaxHightPauseTime(0), m_bIsDown(false), m_fStartJumpYPos(0.f)
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
}

int CPlayer::Update()
{
	if (m_iHP <= 0) return OBJ_DEAD;	// 사망 처리 

	Update_Dir();						// 방향 백터 업데이트

	if (m_bIsJump) {					// 점프 처리 
		Jump2();
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
	float fCalcY(0.f);
	
	// 이동 (상하좌우)
	if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A')) {

		// 중점 이동 
		m_tInfo.fX -= m_fSpeed;
		if (CLineMgr::Get_Instance()->Collision_Line(m_tInfo.fX, m_tInfo.fY, &fCalcY)) {
			m_tInfo.fY = fCalcY;
		}
		else {
			// 길이 없는 경우 x좌표 원상복구
			m_tInfo.fX += m_fSpeed;
		}
	

	}
	if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D')) {
		// 중점이동 
		m_tInfo.fX += m_fSpeed;
		if (CLineMgr::Get_Instance()->Collision_Line(m_tInfo.fX, m_tInfo.fY, &fCalcY)) {
			m_tInfo.fY = fCalcY;
		}
		else {
			// 길이 없는 경우 x좌표 원상복구
			m_tInfo.fX -= m_fSpeed;
		}

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
		m_fJumpTime2 = GetTickCount()/1000.f;
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
	float currTime = GetTickCount()/1000.f;
	float fT2 = (currTime - m_fJumpTime2);

	//  최고 높이 채공시간
	float fMaxHightTime = (m_fJumpForce * m_cJumpDir.y) / G;

	// x, y좌표 계산
	m_tInfo.fX += m_fJumpForce * m_cJumpDir.x * fT2;								// x: V0 * cosθ * t
	m_tInfo.fY -= (m_fJumpForce * m_cJumpDir.y * fT2) - ((G * fT2 * fT2) / 2.f);	// y: V0 * sinθ * t - 1/2 * g * t^2

	// 하강중에  y좌표로 점프 끝났는지 확인하기
	if (fT2 == fMaxHightTime) {
		m_bIsDown = true;
	}
	if(m_bIsDown){
		float fCalcY(0.f);
		CLineMgr::Get_Instance()->Collision_Line(m_tInfo.fX, m_tInfo.fY, &fCalcY);
		if (m_tInfo.fY >= fCalcY) {
			m_tInfo.fY = fCalcY;						// x좌표 기준으로 y값 보정하기 
			m_bIsJump = false;							// 
			m_bIsDown = false;							//
		}
	}
}

void CPlayer::Jump2()
{	
	// 시간 계산
	m_fJumpTime++;
	float fT = m_fJumpTime / 5.f;

	// x, y좌표 계산
	m_tInfo.fX += m_fJumpForce * m_cJumpDir.x * fT;								// x: V0 * cosθ * t
	m_tInfo.fY -= (m_fJumpForce * m_cJumpDir.y * fT) - ((G * fT * fT)/2.f);		// y: V0 * sinθ * t - 1/2 * g * t^2

	// 하강중에  y좌표로 점프 끝났는지 확인하기
	float fCalcY(0.f);
	CLineMgr::Get_Instance()->Collision_Line(m_tInfo.fX, m_tInfo.fY, &fCalcY);
	if (m_tInfo.fY >= fCalcY){						
		m_tInfo.fY = fCalcY;						// x좌표 기준으로 y값 보정하기 
		m_bIsJump = false;							
	}
}
