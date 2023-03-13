#include "stdafx.h"
#include "CBall.h"

CBall::CBall(): m_eDir(DIR_DOWN), m_fXSpeed(0.f), m_fYSpeed(0.f), m_fAngle(0.f)
{
}

CBall::~CBall()
{
}

void CBall::Initialize()
{
	m_tInfo.fCX = 10.f;
	m_tInfo.fCY = 10.f;

	m_fSpeed = 10.f;
}

int CBall::Update()
{
	if (m_bIsDead) return OBJ_DEAD;

	// m_tInfo ������Ʈ 

	__super::Set_Rect();

	return OBJ_NOEVETN;
}

void CBall::Late_Update()
{
}

void CBall::Render(HDC hDC)
{
}

void CBall::Release()
{
}

void CBall::CollisionCheck(CObj* targetObj)
{
	RECT tResult;
	RECT tTargetRect = targetObj->Get_Rect();
	INFO tTargetInfo = targetObj->Get_Info();
	
	float fMaxDist = (m_tInfo.fCX / 2.f) + ( sqrt ( abs( tTargetInfo.fCX / 2.f ) + abs( tTargetInfo.fCX / 2.f ) ) );
	
	pair<float, float> ResultRectCenterPos;

	if (IntersectRect(&tResult, &m_tRect, &tTargetRect)) {
		
		// ��¥ �浹�ߴ��� Ȯ�� ( �� - �簢��)
		if (fMaxDist <= ( sqrt ( abs(m_tInfo.fX - tTargetInfo.fX) + abs(m_tInfo.fY - tTargetInfo.fY) ) ) ) {
			// �߽��� ���
			ResultRectCenterPos.first = tResult.right - tResult.left;
			ResultRectCenterPos.second = tResult.bottom - tResult.top;

			// �߽����� �������� ��� ���� �΋H������ �Ǵ�
			if (m_tInfo.fX < ResultRectCenterPos.first) {		// right
				if (m_eDir == DIR_RU) {	 
					m_eDir = DIR_LU;			// ���� ����
					m_fAngle = 180 - m_fAngle;	// ���� ���� 
					Set_XYSpeed();					// ���ǵ� ���� 
				}
				if (m_eDir == DIR_RD) {
					m_eDir = DIR_LU;			// ���� ����
					m_fAngle = 180 - m_fAngle;	// ���� ���� 
					Set_XYSpeed();					// ���ǵ� ���� 
				}
			}
			else if (m_tInfo.fX > ResultRectCenterPos.first) {	// left

			}
			else if (m_tInfo.fY < ResultRectCenterPos.second) {	// top

			}
			else if (m_tInfo.fY > ResultRectCenterPos.second) {	// bottom

			}

		}
	}

}

void CBall::Set_XYSpeed()
{
	float fAngle = fmod(m_fAngle, 90);
	
	if (m_fAngle == 90.f || m_fAngle == 270.f) {
		m_fXSpeed = 0;
		m_fYSpeed = m_fSpeed;
	}
	else if (m_fAngle == 0.f || m_fAngle == 180.f) {
		m_fXSpeed = m_fSpeed;
		m_fYSpeed = 0;
	}
	else if ( 0 < fAngle <= 45 ) {
		m_fXSpeed = m_fSpeed;
		m_fYSpeed = (m_fSpeed * fAngle) / 45.f;
	}
	else if (45 < fAngle < 90) {
		m_fXSpeed = (m_fSpeed * fAngle) / 45.f; 
		m_fYSpeed = m_fSpeed;
	}
}
