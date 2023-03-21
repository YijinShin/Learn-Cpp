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
	m_tInfo.fCX = 90.f;					// ũ�� 
	m_tInfo.fCY = 90.f;
	m_iHP = 10;							// ü��
	m_fSpeed = 10.f;					// �ӵ� 

	m_fJumpForce = 20.f;
}

int CPlayer::Update()
{
	if (m_iHP <= 0) return OBJ_DEAD;	// ��� ó�� 

	Update_Dir();						// ���� ���� ������Ʈ

	if (m_bIsJump) {					// ���� ó�� 
		Jump2();
	}
	else Key_Input();					// �Է� ó�� (Info ������Ʈ)	

	__super::Update_Rect();				// RECT ������Ʈ

	return OBJ_NOEVENT;
}

void CPlayer::Late_Update()
{
	// ���� ��Ÿ��
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
	
	// �̵� (�����¿�)
	if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A')) {

		// ���� �̵� 
		m_tInfo.fX -= m_fSpeed;
		if (CLineMgr::Get_Instance()->Collision_Line(m_tInfo.fX, m_tInfo.fY, &fCalcY)) {
			m_tInfo.fY = fCalcY;
		}
		else {
			// ���� ���� ��� x��ǥ ���󺹱�
			m_tInfo.fX += m_fSpeed;
		}
	

	}
	if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D')) {
		// �����̵� 
		m_tInfo.fX += m_fSpeed;
		if (CLineMgr::Get_Instance()->Collision_Line(m_tInfo.fX, m_tInfo.fY, &fCalcY)) {
			m_tInfo.fY = fCalcY;
		}
		else {
			// ���� ���� ��� x��ǥ ���󺹱�
			m_tInfo.fX -= m_fSpeed;
		}

	}

	// ���� (��Ŭ��)
	if (GetAsyncKeyState(VK_LBUTTON)) {
		if (m_iBulletCoolTime == 0) {
			Create_Bullet();
			m_iBulletCoolTime = GetTickCount();
		}
	}

	// ���� 
	if (GetAsyncKeyState(VK_SPACE)) {
		// ���� ���� ���� ����
		m_cJumpDir.x = (float)cos(90 * DegreeToRadian); //0;
		m_cJumpDir.y = (float)sin(90 * DegreeToRadian); //1;
		// ���� 
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

	LookAt(ptMouse);			// ���콺 �����͸� �ٶ󺸴� ���� ���� ���� ����� m_tInfo.Dir�� ����
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

	//  �ְ� ���� ä���ð�
	float fMaxHightTime = (m_fJumpForce * m_cJumpDir.y) / G;

	// x, y��ǥ ���
	m_tInfo.fX += m_fJumpForce * m_cJumpDir.x * fT2;								// x: V0 * cos�� * t
	m_tInfo.fY -= (m_fJumpForce * m_cJumpDir.y * fT2) - ((G * fT2 * fT2) / 2.f);	// y: V0 * sin�� * t - 1/2 * g * t^2

	// �ϰ��߿�  y��ǥ�� ���� �������� Ȯ���ϱ�
	if (fT2 == fMaxHightTime) {
		m_bIsDown = true;
	}
	if(m_bIsDown){
		float fCalcY(0.f);
		CLineMgr::Get_Instance()->Collision_Line(m_tInfo.fX, m_tInfo.fY, &fCalcY);
		if (m_tInfo.fY >= fCalcY) {
			m_tInfo.fY = fCalcY;						// x��ǥ �������� y�� �����ϱ� 
			m_bIsJump = false;							// 
			m_bIsDown = false;							//
		}
	}
}

void CPlayer::Jump2()
{	
	// �ð� ���
	m_fJumpTime++;
	float fT = m_fJumpTime / 5.f;

	// x, y��ǥ ���
	m_tInfo.fX += m_fJumpForce * m_cJumpDir.x * fT;								// x: V0 * cos�� * t
	m_tInfo.fY -= (m_fJumpForce * m_cJumpDir.y * fT) - ((G * fT * fT)/2.f);		// y: V0 * sin�� * t - 1/2 * g * t^2

	// �ϰ��߿�  y��ǥ�� ���� �������� Ȯ���ϱ�
	float fCalcY(0.f);
	CLineMgr::Get_Instance()->Collision_Line(m_tInfo.fX, m_tInfo.fY, &fCalcY);
	if (m_tInfo.fY >= fCalcY){						
		m_tInfo.fY = fCalcY;						// x��ǥ �������� y�� �����ϱ� 
		m_bIsJump = false;							
	}
}
