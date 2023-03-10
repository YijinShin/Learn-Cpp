#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"

CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
}

void CPlayer::Initialize()
{
	// 플레이어의 위치, 가로 세로 길이 세팅
	m_tInfo = { WINCX / 2.f,	WINCY / 2.f,	100.f,	100.f };
	// 플레이어의 속도 세팅 
	m_fSpeed = 10.f;
}

int CPlayer::Update()
{
	// 키 입력 처리 
	Key_Input();
	// 사각형 좌표(m_tRect) 업데이트하기 
	__super::Update_Rect();
	return 0;
}

void CPlayer::Render(HDC hDC)
{
	// 플레이어 그리기 
	Rectangle( hDC, 
		m_tRect.left, m_tRect.top,
		m_tRect.right, m_tRect.bottom);
}

void CPlayer::Release()
{
}

void CPlayer::Key_Input()
{
	/* 위치를 바꾸는 키라면 m_tInfo를 업데이트하기
	  이 정보를 바탕으로 ( m_tRect는 __super::Update_Rect()에서 수행함.)*/
	if (GetAsyncKeyState(VK_UP))		// 상
		m_tInfo.fY -= m_fSpeed;
	if (GetAsyncKeyState(VK_DOWN))		// 하
		m_tInfo.fY += m_fSpeed;
	if (GetAsyncKeyState(VK_LEFT))		// 좌
		m_tInfo.fX -= m_fSpeed;
	if (GetAsyncKeyState(VK_RIGHT))		// 우
		m_tInfo.fX += m_fSpeed;
	if (GetAsyncKeyState('W'))			// W
		m_pBulletList->push_back(Create_Bullet(DIR_UP));
	if (GetAsyncKeyState('A'))			// A
		m_pBulletList->push_back(Create_Bullet(DIR_LEFT));
	if (GetAsyncKeyState('S'))			// S
		m_pBulletList->push_back(Create_Bullet(DIR_DOWN));
	if (GetAsyncKeyState('D'))			// D
		m_pBulletList->push_back(Create_Bullet(DIR_RIGHT));
	if (GetAsyncKeyState(VK_SPACE))		// 스페이스
	{ 
		m_pBulletList->push_back(Create_Bullet(DIR_LU));
		m_pBulletList->push_back(Create_Bullet(DIR_RU));
		m_pBulletList->push_back(Create_Bullet(DIR_UP));
	}
}

CObj* CPlayer::Create_Bullet(DIRECTION _eDir)
{
	CObj* pBullet = new CBullet;
	dynamic_cast<CBullet*>(pBullet)->Set_Pos(m_tInfo.fX, m_tInfo.fY);	// 총알 생성 위치 설정
	pBullet->Initialize();
	pBullet->Set_Dir(_eDir);	// 총알 방향 설정
	return pBullet;
}
