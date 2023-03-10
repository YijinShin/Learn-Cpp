#include "stdafx.h"
#include "study_extern_CTest.h"

int g_iData;				// 일반 전역변수 선언 ( 전역이라 static아니라도 0으로 초기화 됨 )
int g_iSrc;					// 일반 전역변수 선언 ( 전역이라 static아니라도 0으로 초기화 됨 )
static int g_iData_static;	// static 전역변수	( 전역이라 0으로 초기화 됨. 심지어 static이라 이걸 함수 안에 선언해도 0초기화됨 )

int main() {
	CTest t1;
	t1.Draw();
}