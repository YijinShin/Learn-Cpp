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
	// ���� DC������ ����
	HDC hDC = GetDC(g_hWnd);

	// ���� DC�� ȣȯ�Ǵ� ���ο� DC�� ����
	m_hMemDC = CreateCompatibleDC(hDC);

	// ������ ���� DC�� '�����ϰ�'�����ϱ�
	ReleaseDC(g_hWnd, hDC);

	// ���Ͽ��� ������ �о�� BITMAP���� ���� 
	m_hBitmap = (HBITMAP)LoadImage( NULL,
									pFilePath,
									IMAGE_BITMAP,
									0,
									0,
									LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	// �о�� BITMAP�� m_hMemDC�� ������ GDI ������Ʈ�� �����ϰ�, ������ ���õǾ��� GDI������Ʈ�� �����صα� 
	m_hOldmap = (HBITMAP)SelectObject(m_hMemDC, m_hBitmap);
}

void MyBmp::Release()
{
	// ���� GDI������Ʈ�� �ٽ� m_hMemDC�� �����Ű��
	SelectObject(m_hMemDC, m_hOldmap);
	// ���Ͽ��� �о�Դ� BITMAP�� ������ �����ϱ� 
	DeleteObject(m_hBitmap);
	// �ɹ� DC�� ������ �����ϱ�
	DeleteDC(m_hMemDC);
}
