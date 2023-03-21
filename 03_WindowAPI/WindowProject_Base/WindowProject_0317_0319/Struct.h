#pragma once
#include "Vector2.h"

typedef	struct tagInfo {
	float	fCX;			// RECT 가로길이		
	float	fCY;			// RECT 세로길이
	float	fX;				// 중점 좌표
	float	fY;				// 중점 좌표 

	CVector2	Dir;		// 방향 단위 좌표 

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


// TODO : 프로그램에 필요한 코드를 추가하세요