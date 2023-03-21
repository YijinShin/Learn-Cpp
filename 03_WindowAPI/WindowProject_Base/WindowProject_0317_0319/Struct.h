#pragma once
#include "Vector2.h"

typedef	struct tagInfo {
	float	fCX;			// RECT ���α���		
	float	fCY;			// RECT ���α���
	float	fX;				// ���� ��ǥ
	float	fY;				// ���� ��ǥ 

	CVector2	Dir;		// ���� ���� ��ǥ 

	tagInfo() :fCX(0.f), fCY(0.f), fX(0.f), fY(0.f) {}
}INFO;


typedef struct tagLinePoint {
	float	fX;
	float	fY;

	tagLinePoint() { ZeroMemory(this, sizeof(tagLinePoint)); }
	tagLinePoint(float _fX, float _fY) :fX(_fX), fY(_fY) {}
}LINEPOINT;

typedef struct tagLine {
	LINEPOINT	tLpoint;
	LINEPOINT	tRpoint;

	tagLine() { ZeroMemory(this, sizeof(tagLinePoint)); }
	tagLine(LINEPOINT _tLpoint, LINEPOINT _tRpoint) :
		tLpoint(_tLpoint), tRpoint(_tRpoint) {}
}LINE;


// TODO : ���α׷��� �ʿ��� �ڵ带 �߰��ϼ���