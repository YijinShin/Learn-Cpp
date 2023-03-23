#include "stdafx.h"
#include "MyBmp.h"

MyBmp::MyBmp():m_hMemDC(nullptr), m_hOldmap(nullptr), m_hBitmap(nullptr)
{
}

MyBmp::~MyBmp()
{
}

void MyBmp::Load_Bmp(const TCHAR* pFilePath)
{
	// 메인 DC가져와 저장
	HDC hDC = GetDC(g_hWnd);

	// 메인 DC와 호환되는 새로운 DC를 생성
	m_hMemDC = CreateCompatibleDC(hDC);

	// 가져온 메인 DC는 '안전하게'삭제하기
	ReleaseDC(g_hWnd, hDC);

	// 파일에서 데이터 읽어와 BITMAP으로 저장 
	m_hBitmap = (HBITMAP)LoadImage( NULL,
									pFilePath,
									IMAGE_BITMAP,
									0,
									0,
									LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	// 읽어온 BITMAP를 m_hMemDC와 연결할 GDI 오브젝트로 선택하고, 기존에 선택되었던 GDI오브젝트는 저장해두기 
	m_hOldmap = (HBITMAP)SelectObject(m_hMemDC, m_hBitmap);
}

void MyBmp::Release()
{
	// 기존 GDI오브젝트를 다시 m_hMemDC와 연결시키기
	SelectObject(m_hMemDC, m_hOldmap);
	// 파일에서 읽어왔던 BITMAP은 완전히 삭제하기 
	DeleteObject(m_hBitmap);
	// 맴버 DC도 완전히 삭제하기
	DeleteDC(m_hMemDC);
}
