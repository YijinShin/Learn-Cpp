#include "stdafx.h"
#include "MyBmp.h"

CMyBmp::CMyBmp()
{
}

CMyBmp::~CMyBmp()
{
}

void CMyBmp::Load_Bmp(const TCHAR*	pFilePath)
{
	// DC 가져오기 
	HDC		hDC = GetDC(g_hWnd);

	// DC 복사하기 
		// 매개변수 DC와 호환되는 DC를 만드는 함수 .
	m_hMemDC = CreateCompatibleDC(hDC);

	// 가져온 DC는 파괴하기 
		// DC를 생성한 윈도우의 헨들, 삭제하려는 DC 
	ReleaseDC(g_hWnd, hDC);

	// 파일에서 BITMAP 읽어와 저장하기 
	m_hBitmap = (HBITMAP)LoadImage(NULL,		// 프로그램 인스턴스 핸들(프로그램에서 얻어올 것이 아니고 직접 파일을 읽어들일 것이기에 NULL)
		pFilePath,								// 파일의 경로
		IMAGE_BITMAP,							// 어떤 타입으로 읽어들일 것인가(이미지 파일)
		0,										// 이미지 가로 크기
		0,										// 이미지 세로 크기(파일에서 읽어들일 것이기 때문에 직접 사이즈를 지정해줄 이유 없음)
		LR_LOADFROMFILE | LR_CREATEDIBSECTION); // LR_LOADFROMFILE : 파일에서 이미지를 로드, LR_CREATEDIBSECTION : 읽어온 파일을 DIB형태로 변환

	// GDI 오브젝트를 선택하기 전에 기존에 가지고 있던 오브젝트를 반환
		// m_hBitmap 오브젝트를 m_hMemDC에 새로 등록시키고, 기존에 등록되어있던 GDI객체는 m_hOldmap으로 반환한다.
	m_hOldmap = (HBITMAP)SelectObject( m_hMemDC, m_hBitmap);
}

void CMyBmp::Release()
{
	// 옛날 객체를 다시 DC에 등록시킴
	SelectObject(m_hMemDC, m_hOldmap);
	// 맴버 HBITMAP 오브젝트 삭제하기 
	DeleteObject(m_hBitmap);
	// 맴버 완전히 삭제 (Release가 아니라 Delete해야함)
	DeleteDC(m_hMemDC);
}
