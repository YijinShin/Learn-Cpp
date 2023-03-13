#include "stdafx.h"
#include "CMainGame.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "AbstractFactory.h"

CMainGame::CMainGame(): m_dwTime(GetTickCount()), m_iFPS(0)
{
	ZeroMemory(m_szFPS, sizeof(TCHAR)*32);
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	// HDC 가져오기 
	m_hDC = GetDC(g_hWnd);
	
	// 플레이어 생성 
	m_ObjList[OBJ_PLAYER].push_back(CAbstractFactory<CPlayer>::Create( WINCX/2.f, WINCY / 1.5f));
	dynamic_cast<CPlayer*>(m_ObjList[OBJ_PLAYER].front())->Set_BulletList(&m_ObjList[OBJ_BULLET]);

	// 몬스터 생성
	m_ObjList[OBJ_MONSTER].push_back(CAbstractFactory<CMonster>::Create( WINCX / 2.f, WINCY / 3.f));

	// 총알은 플레이어에서 생성함. 
}

int CMainGame::Update()
{
	for (size_t i = 0; i < OBJ_END; i++) {

		for (auto iter = m_ObjList[i].begin(); iter != m_ObjList[i].end();) {

			if ((*iter)->Update() == OBJ_DEAD) {
				Safe_Delete<CObj*>(*iter);
				iter = m_ObjList[i].erase(iter);
			}
			else iter++;

		}

	}

	return 0;
}

void CMainGame::Late_Update()
{

	// 
	for (int i = 0; i < OBJ_END; i++) {

		for (auto iter = m_ObjList[i].begin(); iter != m_ObjList[i].end(); iter++) {

			(*iter)->Late_Update();

		}
	}

	// 몬스터와 총알의 충돌 
	for (auto iter : m_ObjList[OBJ_BULLET]) {
		iter->CheckCrash(m_ObjList[OBJ_MONSTER]);
	}
}

void CMainGame::Render()
{
	// Frame 출력
	++m_iFPS;

	if (m_dwTime + 1000 < GetTickCount()) {
		swprintf_s(m_szFPS, L"FPS: %d", m_iFPS);
		SetWindowText(g_hWnd, m_szFPS);

		m_iFPS = 0;
		m_dwTime = GetTickCount();
	}

	// 게임 오브젝트 출력 
	Rectangle(m_hDC, 0, 0, WINCX, WINCY);

	Rectangle(m_hDC, FENCEINTERVAL, FENCEINTERVAL, WINCX - FENCEINTERVAL, WINCY - FENCEINTERVAL);

	for (size_t i = 0; i < OBJ_END; i++) {

		for (auto iter = m_ObjList[i].begin(); iter != m_ObjList[i].end(); iter++) {

			(*iter)->Render(m_hDC);

		}
	}

	// 문자열 (총알 개수) 출력
	float playerAngle = dynamic_cast<CPlayer*>(m_ObjList[OBJ_PLAYER].front())->Get_Angle();
	TCHAR	szBuff[32] = L"";	
	swprintf_s(szBuff, L"Bullet: %f", playerAngle);


	TextOut(m_hDC, 50, 50, szBuff, lstrlen(szBuff));
}

void CMainGame::Release()
{
	for (int i = 0; i < OBJ_END; i++) {

		for (auto iter = m_ObjList[i].begin(); iter != m_ObjList[i].end();) {

			Safe_Delete<CObj*>(*iter);
			iter = m_ObjList[i].erase(iter);

		}
	}
}
