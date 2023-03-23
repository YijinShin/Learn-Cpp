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
	// DC �������� 
	HDC		hDC = GetDC(g_hWnd);

	// DC �����ϱ� 
		// �Ű����� DC�� ȣȯ�Ǵ� DC�� ����� �Լ� .
	m_hMemDC = CreateCompatibleDC(hDC);

	// ������ DC�� �ı��ϱ� 
		// DC�� ������ �������� ���, �����Ϸ��� DC 
	ReleaseDC(g_hWnd, hDC);

	// ���Ͽ��� BITMAP �о�� �����ϱ� 
	m_hBitmap = (HBITMAP)LoadImage(NULL,		// ���α׷� �ν��Ͻ� �ڵ�(���α׷����� ���� ���� �ƴϰ� ���� ������ �о���� ���̱⿡ NULL)
		pFilePath,								// ������ ���
		IMAGE_BITMAP,							// � Ÿ������ �о���� ���ΰ�(�̹��� ����)
		0,										// �̹��� ���� ũ��
		0,										// �̹��� ���� ũ��(���Ͽ��� �о���� ���̱� ������ ���� ����� �������� ���� ����)
		LR_LOADFROMFILE | LR_CREATEDIBSECTION); // LR_LOADFROMFILE : ���Ͽ��� �̹����� �ε�, LR_CREATEDIBSECTION : �о�� ������ DIB���·� ��ȯ

	// GDI ������Ʈ�� �����ϱ� ���� ������ ������ �ִ� ������Ʈ�� ��ȯ
		// m_hBitmap ������Ʈ�� m_hMemDC�� ���� ��Ͻ�Ű��, ������ ��ϵǾ��ִ� GDI��ü�� m_hOldmap���� ��ȯ�Ѵ�.
	m_hOldmap = (HBITMAP)SelectObject( m_hMemDC, m_hBitmap);
}

void CMyBmp::Release()
{
	// ���� ��ü�� �ٽ� DC�� ��Ͻ�Ŵ
	SelectObject(m_hMemDC, m_hOldmap);
	// �ɹ� HBITMAP ������Ʈ �����ϱ� 
	DeleteObject(m_hBitmap);
	// �ɹ� ������ ���� (Release�� �ƴ϶� Delete�ؾ���)
	DeleteDC(m_hMemDC);
}
