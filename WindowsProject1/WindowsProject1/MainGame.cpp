#include "MainGame.h"
#include "framework.h"
#include "Define.h"
CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	m_DC = GetDC(); // 윈도우 헨들이 필요함. hWnd라는변수이름. 근데 이게 지역변수라 전역을 선언해서 가져와야함. 
	/* GetDC는 DC를 얻어오면서 레퍼런스 카운트가 올라가고, ReleaseDC를 통해 레퍼런스 카운트를 체크하겠다는 것. 
	   삭제 자체는 시스템이 결정함. */
}

void CMainGame::Render()
{
	Ellipse(m_DC, WINCX, WINCX, WINCY, WINCY);
}

void CMainGame::Release()
{
	ReleaseDC(p_Hwnd, m_DC);
}
