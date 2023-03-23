#include "stdafx.h"
#include "Player_SYJ.h"

//Design
#include "CKeyMgr.h"
#include "CLineMgr.h"
#include "CObjMgr.h"
#include "AbstractFactory.h"
#include "CScrollMgr.h"

//Object
#include "CBullet.h"



CPlayer_SYJ::CPlayer_SYJ(): 
			m_fJumpForce(0.f), m_bIsJump(false), m_bIsDown(false), m_fJumpTime(0.f), m_fOldJumpHight(0.f)
{
}

CPlayer_SYJ::~CPlayer_SYJ()
{
}

void CPlayer_SYJ::Initialize()
{
	m_tInfo.fCX = 25.f;					// ũ�� 
	m_tInfo.fCY = 25.f;
	m_iHP = 10;							// ü��
	m_fSpeed = 10.f;					// �ӵ� 

	m_fJumpForce = 50.f;

}

int CPlayer_SYJ::Update()
{
	//if (!m_bIsJump)	
	Key_Input();

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CPlayer_SYJ::Late_Update()
{
	
	Jump();
	OffSet();

}

void CPlayer_SYJ::Render(HDC hDC)
{
	MyPen = CreatePen(PS_SOLID, 5, RGB(168, 199, 55));
	OldPen = (HPEN)SelectObject(hDC, MyPen);

	int iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	Ellipse(hDC,
		m_tRect.left+ iScrollX, m_tRect.top+ iScrollY,
		m_tRect.right+ iScrollX, m_tRect.bottom+ iScrollY);

	SelectObject(hDC, OldPen);
	DeleteObject(MyPen);
}

void CPlayer_SYJ::Release()
{
}

void CPlayer_SYJ::Create_Bullet()
{	
	CObj* pObj = CAbstractFactory<CBullet>::Create(m_tInfo.fX, m_tInfo.fY);
	pObj->Set_Dir(m_tInfo.Dir);
	CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, pObj);

}

void CPlayer_SYJ::Key_Input()
{
	float fCalcY(0.f);

	// �¿� �̵�
	if (CKeyMgr::Get_Instance()->Key_Pressing('D')
		|| CKeyMgr::Get_Instance()->Key_Pressing(VK_RIGHT)) 
	{
		m_tInfo.fX += m_fSpeed;
	}
	if (CKeyMgr::Get_Instance()->Key_Pressing('A')
		|| CKeyMgr::Get_Instance()->Key_Pressing(VK_LEFT))
	{
		m_tInfo.fX -= m_fSpeed;
	}

	// ���� ���� 
	if (CKeyMgr::Get_Instance()->Key_Down(VK_SPACE))
	{
		// ���� ���� ���� 
		m_cJumpDir.x = 0;
		m_cJumpDir.y = 1;
		// ���� �ð� �ʱ�ȭ
		m_fJumpTime = 0.f;
		// ���� ���� ��ġ ����
		m_cPosBeforJump.x = m_tInfo.fX;
		m_cPosBeforJump.y = m_tInfo.fY;
		// ���������� �˸�
		m_bIsJump = true;
		// ���� �ְ� ���� 
		m_fOldJumpHight = m_tInfo.fY;
		
	}

	// ����
	if (CKeyMgr::Get_Instance()->Key_Down(VK_CONTROL))
	{
		Create_Bullet();
	}
}

void CPlayer_SYJ::Jump()
{
	float	fCalcY(0.f);

	// ������ �ƴѰ��
	if (!m_bIsJump) {

		// �÷��̾� Y�� �߷°�� ���ϱ�
		m_tInfo.fY += G;
		
		// ���� ���� ��������� �߷°�� �ٽ� ���� 
		if (CLineMgr::Get_Instance()->SYJ_Collision_Line(m_tInfo.fX, m_tInfo.fY, &fCalcY)) {
			m_tInfo.fY = fCalcY;
		}

		// ���������� ���������� Ȯ��
			// [������] ������ �����ϸ� ���� ó���� �ȵ�..
		if (m_tInfo.fY >= 1000.f) {
			// �������̶�� ������ �������� �̵���Ŵ
			m_tInfo.fX = 400.f;
			m_tInfo.fY = 300.f;
			// ���� ���Խ�Ű�� 
		}
	}

	// �������ΰ��
	else{

		m_fJumpTime++;
		float fT = m_fJumpTime / 2.f;

		m_tInfo.fX += m_cJumpDir.x * m_fJumpForce * fT;
		m_tInfo.fY = m_cPosBeforJump.y - ((m_cJumpDir.y * m_fJumpForce * fT) - ((fT * fT * G) / 2.f));

		
		if ( m_fOldJumpHight < m_tInfo.fY)
			m_bIsDown = true;

		m_fOldJumpHight = m_tInfo.fY;

		if (m_bIsDown) {
			if (CLineMgr::Get_Instance()->SYJ_Collision_Line(m_tInfo.fX, m_tInfo.fY, &fCalcY)) {
				m_tInfo.fY = fCalcY;
				m_bIsDown = false;
				m_bIsJump = false;
			}
		}
		
	}
}


void CPlayer_SYJ::OffSet()
{
	float		fOffsetMinX = 200.f;
	float		fOffsetMaxX = 600.f;
	float		fOffsetMinY = 200.f;
	float		fOffsetMaxY = 400.f;

	int			iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int			iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	if (fOffsetMinX > m_tInfo.fX + iScrollX)
		CScrollMgr::Get_Instance()->Set_ScrollX(m_fSpeed);
	if (fOffsetMaxX < m_tInfo.fX + iScrollX)
		CScrollMgr::Get_Instance()->Set_ScrollX(-m_fSpeed);

	if (fOffsetMinY > m_tInfo.fY + iScrollY)
		CScrollMgr::Get_Instance()->Set_ScrollY(m_fSpeed);
	if (fOffsetMaxY < m_tInfo.fY + iScrollY)
		CScrollMgr::Get_Instance()->Set_ScrollY(-m_fSpeed);
}
