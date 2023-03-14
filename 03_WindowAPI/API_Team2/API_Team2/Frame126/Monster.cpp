#include "stdafx.h"
#include "Monster.h"
#include "Bullet.h"
#include "AbstractFactory.h"


CMonster::CMonster() : m_pBulletList(nullptr), m_iBulletTimer(0)
{
}

CMonster::~CMonster()
{
	Release();
}

void CMonster::Initialize(void)
{

	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 50.f;

	m_fSpeed = 4.f;
}

int CMonster::Update(void)
{
	if (m_isDead) return OBJ_DEAD;

	// ���� ���
	Calc_Center();

	// RECT ����
	__super::Update_Rect();

	// ���� �ð����� �Ѿ� ����
	m_iBulletTimer++;
	if (m_iBulletTimer >= 50) {
		Create_Bullet();
		m_iBulletTimer = 0;
	}


	return OBJ_NOEVENT;
}

void CMonster::Late_Update(void)
{

}

void CMonster::Render(HDC hDC)
{
	// ���� �׸��� 
	Rectangle(hDC,
		m_tRect.left, m_tRect.top,
		m_tRect.right, m_tRect.bottom);
}

void CMonster::Release(void)
{
}

void CMonster::Calc_Center()
{
}

void CMonster::Create_Bullet() {
	m_pBulletList->push_back(CAbstractFactory<CBullet>::Create( m_tInfo.fX, m_tInfo.fY));
}
