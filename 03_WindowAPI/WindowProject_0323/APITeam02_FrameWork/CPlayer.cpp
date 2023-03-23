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
	m_tInfo.fCX = 90.f;					// ũ�� 
	m_tInfo.fCY = 90.f;
	m_iHP = 10;							// ü��
	m_fSpeed = 10.f;					// �ӵ� 
}

int CPlayer::Update()
{
	if (m_iHP <= 0) return OBJ_DEAD;	// ��� ó�� 

	Update_Dir();						// ���� ���� ������Ʈ
	Key_Input();						// �Է� ó�� (Info ������Ʈ)	
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
	// �̵� (�����¿�)
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

	// ���� (��Ŭ��)
	if (GetAsyncKeyState(VK_LBUTTON)) {
		if (m_iBulletCoolTime == 0) {
			Create_Bullet();
			m_iBulletCoolTime = GetTickCount();
		}
	}

	// ���� 
	if (GetAsyncKeyState(VK_SPACE)) {

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

