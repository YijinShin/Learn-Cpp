#include "stdafx.h"
#include "Player_SYJ.h"

//Design
#include "CKeyMgr.h"
#include "CLineMgr.h"
#include "CObjMgr.h"
#include "AbstractFactory.h"
#include "CScrollMgr.h"
#include "CBmpMgr.h"

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
	m_tInfo.fCX = 200.f;					// ũ�� 
	m_tInfo.fCY = 200.f;
	m_iHP = 10;							// ü��
	m_fSpeed = 10.f;					// �ӵ� 

	m_fJumpForce = 50.f;

	// Frame ���� �ʱ�ȭ 
	m_pFrameKey =const_cast<TCHAR*>( L"Player_RIGHT" );

	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd= 3;
	m_tFrame.iMotion = 0;
	m_tFrame.dwSpeed = 200;
	m_tFrame.dwTime = GetTickCount();

	// �ʿ��� �̹��� 
	CBmpMgr::Get_Instance()->Insert_MyBmp(L"../Image/Player/Player_DOWN.bmp", L"Player_DOWN");
	CBmpMgr::Get_Instance()->Insert_MyBmp(L"../Image/Player/Player_UP.bmp", L"Player_UP");
	CBmpMgr::Get_Instance()->Insert_MyBmp(L"../Image/Player/Player_LEFT.bmp", L"Player_LEFT");
	CBmpMgr::Get_Instance()->Insert_MyBmp(L"../Image/Player/Player_RIGHT.bmp", L"Player_RIGHT");

	CBmpMgr::Get_Instance()->Insert_MyBmp(L"../Image/Player/Player_LU.bmp", L"Player_LU");
	CBmpMgr::Get_Instance()->Insert_MyBmp(L"../Image/Player/Player_LD.bmp", L"Player_LD");
	CBmpMgr::Get_Instance()->Insert_MyBmp(L"../Image/Player/Player_RD.bmp", L"Player_RD");
	CBmpMgr::Get_Instance()->Insert_MyBmp(L"../Image/Player/Player_RU.bmp", L"Player_RU");

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
	Change_Motion();
	
	__super::Move_Frame();
}

void CPlayer_SYJ::Render(HDC hDC)
{
	MyPen = CreatePen(PS_SOLID, 5, RGB(168, 199, 55));
	OldPen = (HPEN)SelectObject(hDC, MyPen);

	int iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	/*Ellipse(hDC,
		m_tRect.left+ iScrollX, m_tRect.top+ iScrollY,
		m_tRect.right+ iScrollX, m_tRect.bottom+ iScrollY);*/

	// ��������Ʈ
	HDC	hMemDC = CBmpMgr::Get_Instance()->Find_MyBmp(m_pFrameKey);

	GdiTransparentBlt(hDC,
					(int)m_tRect.left + iScrollX,
					(int)m_tRect.top + iScrollY,
					(int)m_tInfo.fCX,
					(int)m_tInfo.fCY,
					hMemDC,
					m_tFrame.iFrameStart * (int)m_tInfo.fCX,
					m_tFrame.iMotion * (int)m_tInfo.fCY,
					(int)m_tInfo.fCX,
					(int)m_tInfo.fCY,
					RGB(0,0,0));
	
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
		m_pFrameKey = const_cast<TCHAR*>(L"Player_RIGHT");
		m_eCurrState = ST_WALK;
	}
	else if (CKeyMgr::Get_Instance()->Key_Pressing('A')
		|| CKeyMgr::Get_Instance()->Key_Pressing(VK_LEFT))
	{
		m_tInfo.fX -= m_fSpeed;
		m_pFrameKey = const_cast<TCHAR*>(L"Player_LEFT");
		m_eCurrState = ST_WALK;
	}
	else 
	{
		m_eCurrState = ST_IDLE;
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

void CPlayer_SYJ::Change_Motion()
{
	if(m_ePreState != m_eCurrState){
		switch (m_tFrame.iMotion)
		{
		case ST_IDLE:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 3;
			m_tFrame.iMotion = 0;
			m_tFrame.dwSpeed = 200;
			m_tFrame.dwTime = GetTickCount();
			break;
		case ST_WALK:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 5;
			m_tFrame.iMotion = 1;
			m_tFrame.dwSpeed = 200;
			m_tFrame.dwTime = GetTickCount();
			break;
		case ST_ATTCK:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 5;
			m_tFrame.iMotion = 2;
			m_tFrame.dwSpeed = 200;
			m_tFrame.dwTime = GetTickCount();
			break;
		case ST_HIT:

			break;
		case ST_DEAD:

			break;
		default:
			break;
		}

		m_ePreState = m_eCurrState;
	}
}

