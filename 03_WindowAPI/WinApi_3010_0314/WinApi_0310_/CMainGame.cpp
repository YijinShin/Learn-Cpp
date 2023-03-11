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
	// HDC �������� 
	m_hDC = GetDC(g_hWnd);
	
	// �÷��̾� ���� 
	m_ObjList[OBJ_PLAYER].push_back(CAbstractFactory<CPlayer>::Create( WINCX/2.f, WINCY / 1.5f));
	dynamic_cast<CPlayer*>(m_ObjList[OBJ_PLAYER].front())->Set_BulletList(&m_ObjList[OBJ_BULLET]);

	// ���� ����
	m_ObjList[OBJ_MONSTER].push_back(CAbstractFactory<CMonster>::Create( WINCX / 2.f, WINCY / 3.f));

	// �Ѿ��� �÷��̾�� ������. 
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
	for (int i = 0; i < OBJ_END; i++) {

		for (auto iter = m_ObjList[i].begin(); iter != m_ObjList[i].end(); iter++) {

			(*iter)->Late_Update();

		}
	}
}

void CMainGame::Render()
{
	// Frame ���
	++m_iFPS;

	if (m_dwTime + 1000 < GetTickCount()) {
		swprintf_s(m_szFPS, L"FPS: %d", m_iFPS);
		SetWindowText(g_hWnd, m_szFPS);

		m_iFPS = 0;
		m_dwTime = GetTickCount();
	}

	// ���� ������Ʈ ��� 
	Rectangle(m_hDC, 0, 0, WINCX, WINCY);

	Rectangle(m_hDC, FENCEINTERVAL, FENCEINTERVAL, WINCX - FENCEINTERVAL, WINCY - FENCEINTERVAL);

	for (size_t i = 0; i < OBJ_END; i++) {

		for (auto iter = m_ObjList[i].begin(); iter != m_ObjList[i].end(); iter++) {

			(*iter)->Render(m_hDC);

		}
	}

	// ���ڿ� (�Ѿ� ����) ���
	TCHAR	szBuff[32] = L"";		/* TCHAR: Window Api���� ����ϴ� char �ڷ����̶�� �����ϸ� ��.�����ڵ� ���. 
											  (char:�ƽ�Ű �ڵ�, TCHAR : �����ڵ�)
											  �����ڵ�� �տ� L�� �ٿ�����.*/
	swprintf_s(szBuff, L"Bullet: %d", m_ObjList[OBJ_BULLET].size());
		/* wsprintf: �Ҽ��� �ڸ� ������ ����� �Ұ���. 
					 Win api���� �����ϴ� �Լ�. ��� ������ ���������� ����. 
		   swprintf_s: ��� ���� ����.
		               visual c++���� �����ϴ� �Լ�. */

	TextOut(m_hDC, 50, 50, szBuff, lstrlen(szBuff));
		/* lstrlen: �����ڵ� ���ڿ� ���� ���ϴ� �Լ� (strlen: �ƽ�Ű�ڵ� ��� ���ڿ� ���� ���ϴ� �Լ�) 
		���ڿ� ��� �Լ� 
			1. TextOut
			2. DrawText (m_hDC, szBuff, lstrlen(szBuff), &rc, DT_CENTER) // ��ġ�� ���ϱ� ���� RECT�� �ʿ���. 	
		*/
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
