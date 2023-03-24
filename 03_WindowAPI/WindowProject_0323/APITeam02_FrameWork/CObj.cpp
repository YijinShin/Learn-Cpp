#include "stdafx.h"
#include "CObj.h"

CObj::CObj(): m_iHP(1), m_fSpeed(0.f), m_ePreState(ST_END), m_eCurrState(ST_IDLE)
{
	ZeroMemory(&m_tInfo, sizeof(INFO));
	ZeroMemory(&m_tRect, sizeof(RECT));
	ZeroMemory(&m_tFrame, sizeof(FRAME));
}

CObj::~CObj()
{
}

void CObj::Update_Rect()
{
	m_tRect.left	= (LONG)(m_tInfo.fX - (m_tInfo.fCX / 2.f));
	m_tRect.right	= (LONG)(m_tInfo.fX + (m_tInfo.fCX / 2.f));
	m_tRect.top		= (LONG)(m_tInfo.fY - (m_tInfo.fCY / 2.f));
	m_tRect.bottom	= (LONG)(m_tInfo.fY + (m_tInfo.fCY / 2.f));
}

void CObj::LookAt(POINT ptDistPos)
{
	CVector2 vector;
	vector.x = (float)ptDistPos.x - m_tInfo.fX;
	vector.y = (float)ptDistPos.y - m_tInfo.fY;
	vector.Normalize();
	m_tInfo.Dir = vector;
}

void CObj::Move_Frame()
{
	// ������ ���ϸ��̼� �ӵ����� 
	if (m_tFrame.dwTime + m_tFrame.dwSpeed < GetTickCount()) {
		
		// ������ �ε��� ������Ʈ 
		m_tFrame.iFrameStart++;
		m_tFrame.dwTime = GetTickCount();
		
		// ���� ������ �ε����� end frame�� �Ѿ�� �ʱ�ȭ 
		if (m_tFrame.iFrameStart > m_tFrame.iFrameEnd) {
			m_tFrame.iFrameStart = 0;
		}
	}
}

