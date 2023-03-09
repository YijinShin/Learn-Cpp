#pragma once

#define		WINCX		800
#define		WINCY		600

#define		PURE		= 0	// 순수 가상함수 만들 때 사용

enum DIRECTION { DIR_LEFT, DIR_UP, DIR_RIGHT, DIR_DOWN, DIR_LU, DIR_RU, DIR_END };

extern HWND g_hWnd;			// 윈도우 헨들러. WindowProject01에서 선언된 전역변수의 복사


typedef struct tagInfo {
	float fX;
	float fY;
	float fCX;
	float fCY;
}INFO;