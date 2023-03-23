#pragma once
#include "Include.h"
/* [ MyBmp ]
Bmp 하나를 저장하는 Node라고 생각하면 된다. */

class MyBmp
{
private:
	HDC			m_hMemDC;				// 해당 Bmp를 그릴 DC
	HBITMAP		m_hOldmap;
	HBITMAP		m_hBitmap;

public:
	MyBmp();
	~MyBmp();

public:
	HDC			Get_mDC() { return m_hMemDC; }				// 해당 Bmp가 그려져있는 DC를 반환
	
	void		Load_Bmp(const TCHAR* pFilePath);		// 파일에서 Bmp를 가져와 저장함. 
	void		Release();								
};

