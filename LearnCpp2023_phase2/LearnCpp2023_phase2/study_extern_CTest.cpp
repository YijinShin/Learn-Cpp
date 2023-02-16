#include "stdafx.h"
#include "study_extern_CTest.h"
using namespace std;

//extern int g_iData = 100;	//extern은 그냥 이런 변수가 존재한다는 사실만 알려준다. 값을 넣거나 할 수는 없음. 
extern int g_iData;
extern int g_iData_static;	// 마찬가지로 이게 static인지 뭔지 알바가 아님. 걍 알려만 주는거라 여기서는 오류가 안난다. 

extern int aaaa;			//  마찬가지로 이게 실제로 전역 변수로 존재하는지 알바가 아님. 걍 알려만 주는거라 여기서는 오류가 안난다. 


void CTest::Draw() {
	cout << g_iData << endl;
	//cout << g_iSrc << endl;			// main.cpp에 전역으로 존재하나, study_exturn_CTest.cpp가 이 변수 이름 자체를 몰라 불가능. extern해줘야함. 
	//cout << g_iData_static << endl;	// static은 해당 변수가 선언된 파일 이외의 파일에서 호출 불가능. 
}