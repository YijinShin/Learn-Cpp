#pragma once

#define		WINCX		800
#define		WINCY		600

#define		PURE		= 0	// ���� �����Լ� ���� �� ���

enum DIRECTION { DIR_LEFT, DIR_UP, DIR_RIGHT, DIR_DOWN, DIR_LU, DIR_RU, DIR_END };

extern HWND g_hWnd;			// ������ ��鷯. WindowProject01���� ����� ���������� ����


typedef struct tagInfo {
	float fX;
	float fY;
	float fCX;
	float fCY;
}INFO;