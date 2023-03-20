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
	m_tInfo.fCX = 90.f;					// ũ�� 
	m_tInfo.fCY = 90.f;
	m_iHP = 10;							// ü��
	m_fSpeed = 10.f;					// �ӵ� 

	m_fJumpForce = 20.f;

	m_pLineList = CLineMgr::Get_Instance() -> Get_LineList();		// line �������� ( �ÿ��̾ �ߵ��� ��)
}

int CPlayer::Update()
{
	if (m_iHP <= 0) return OBJ_DEAD;	// ��� ó�� 

	Update_Dir();						// ���� ���� ������Ʈ

	if (m_bIsJump) {					// ���� ó�� 
		Jump();
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
	// �̵� (�����¿�)
	if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W')) {
	}
	if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S')) {
	}
	if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A')) {
		// ���ʿ� ���� �� �ִ��� üũ 
		auto	iter = m_pLineList->begin();
		if (m_tRect.left <= (*iter)->Get_Line().tLpoint.fX)
			return;
		m_tInfo.fX -= m_fSpeed;
		m_tInfo.fY = Calc_yPos();
	}
	if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D')) {
		// �����ʿ� ���� �� �ִ��� üũ 
		auto	iter = m_pLineList->begin();
		if (m_tRect.right >= m_pLineList->back()->Get_Line().tRpoint.fX)
			return;
		m_tInfo.fX += m_fSpeed;
		m_tInfo.fY = Calc_yPos();
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
	// �ð� ���
	m_fJumpTime ++;
	float fT = m_fJumpTime / 5.f;

	// x, y��ǥ ���
		// x: V0 * cos�� * t
		// y: V0 * sin�� * t - 1/2 * g * t^2
 	m_tInfo.fX += m_fJumpForce * m_cJumpDir.x * fT;
	m_tInfo.fY -= (m_fJumpForce * m_cJumpDir.y * fT) - ((G * fT * fT)/2.f); 

	/*	// ȭ�� ������� ����� �ʵ��� 
	if (m_tRect.top <= 0) {
		m_cJumpDir.y = -1;
	}
	*/

	// y��ǥ�� ���� �������� Ȯ���ϱ�
	float fYPos = Calc_yPos();

	if (m_tInfo.fY >= fYPos ){
		m_tInfo.fY = fYPos;						// x��ǥ �������� y�� �����ϱ� 
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

			float	m = (line.tRpoint.fY - line.tLpoint.fY) / (line.tRpoint.fX - line.tLpoint.fX);  // ���� 
			float   n = line.tLpoint.fY - m * line.tLpoint.fX;										// y����  
			fYPos = m * m_tInfo.fX + n;
			break;
		}
		iter++;
	}
	return fYPos;
}
