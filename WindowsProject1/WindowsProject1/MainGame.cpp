#include "MainGame.h"
#include "framework.h"
#include "Define.h"
CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	m_DC = GetDC(); // ������ ����� �ʿ���. hWnd��º����̸�. �ٵ� �̰� ���������� ������ �����ؼ� �����;���. 
	/* GetDC�� DC�� �����鼭 ���۷��� ī��Ʈ�� �ö󰡰�, ReleaseDC�� ���� ���۷��� ī��Ʈ�� üũ�ϰڴٴ� ��. 
	   ���� ��ü�� �ý����� ������. */
}

void CMainGame::Render()
{
	Ellipse(m_DC, WINCX, WINCX, WINCY, WINCY);
}

void CMainGame::Release()
{
	ReleaseDC(p_Hwnd, m_DC);
}
