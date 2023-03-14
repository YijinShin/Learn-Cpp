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

	// 중점 계산
	Calc_Center();

	// RECT 갱신
	__super::Update_Rect();

	// 일정 시간마다 총알 생성
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
	// 몸통 그리기 
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
