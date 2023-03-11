#include "stdafx.h"
#include "CMonster.h"

CMonster::CMonster()
{
}

CMonster::~CMonster()
{
    Release();
}

void CMonster::Initialize()
{
    // 몬스터 크기, 위치 설정
    m_tInfo.fCX = 50.f;
    m_tInfo.fCY = 50.f;
    m_tInfo.fX = WINCX / 2.f;
    m_tInfo.fY = FENCEINTERVAL + 100.f;
    // 몬스터 속도 설정
    m_fSpeed = 6.f;
}

int CMonster::Update()
{
    if (m_bDead) return OBJ_DEAD;
    
    m_tInfo.fX += m_fSpeed;

    __super::Set_Rect();

    return OBJ_NOEVENT;
}

int CMonster::Late_Update()
{
    if (m_tRect.left <= FENCEINTERVAL || m_tRect.right >= WINCX - FENCEINTERVAL)
        m_fSpeed *= (-1);
    return 0;
}

void CMonster::Render(HDC hDC)
{
    Rectangle(hDC,
        m_tRect.left, m_tRect.top,
        m_tRect.right, m_tRect.bottom);
}

void CMonster::Release()
{
}
