#pragma once
#include "Include.h"
/* [ MyBmp ]
Bmp �ϳ��� �����ϴ� Node��� �����ϸ� �ȴ�. */

class MyBmp
{
private:
	HDC			m_hMemDC;				// �ش� Bmp�� �׸� DC
	HBITMAP		m_hOldmap;
	HBITMAP		m_hBitmap;

public:
	MyBmp();
	~MyBmp();

public:
	HDC			Get_mDC() { return m_hMemDC; }				// �ش� Bmp�� �׷����ִ� DC�� ��ȯ
	
	void		Load_Bmp(const TCHAR* pFilePath);		// ���Ͽ��� Bmp�� ������ ������. 
	void		Release();								
};

