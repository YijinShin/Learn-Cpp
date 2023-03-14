#include "stdafx.h"
#include "CShield.h"

CShield::CShield():m_tPlayerInfo(nullptr)
{
}

CShield::~CShield()
{
    Release();
}

void CShield::Initialize()
{
    m_tInfo.fCX = 40.f;
    m_tInfo.fCY = 40.f;

    m_fSpeed = 100.f;
}

int CShield::Update()
{
    // �÷��̾� ��ġ�� �÷��̾� ������Ʈ���� ������
    // ���� �̵� 
    m_fAngle += 2;
    // ���� ���
    Calc_Dir();
    // Rect ����
    __super::Set_Rect();
    return 0;
}

int CShield::Late_Update()
{
    return 0;
}

void CShield::Render(HDC hDC)
{
    Ellipse(hDC,
        m_tRect.left, m_tRect.top,
        m_tRect.right, m_tRect.bottom);
}

void CShield::Release()
{
}

void CShield::Calc_Dir()
{
    m_tInfo.fX = m_tPlayerInfo->fX + (float)cos(m_fAngle * (PI/180.f)) * m_fSpeed;
    m_tInfo.fY = m_tPlayerInfo->fY + (float)sin(m_fAngle * (PI / 180.f)) * m_fSpeed;
}


