#include "stdafx.h"
#include "study_extern_CTest.h"
using namespace std;

//extern int g_iData = 100;	//extern�� �׳� �̷� ������ �����Ѵٴ� ��Ǹ� �˷��ش�. ���� �ְų� �� ���� ����. 
extern int g_iData;
extern int g_iData_static;	// ���������� �̰� static���� ���� �˹ٰ� �ƴ�. �� �˷��� �ִ°Ŷ� ���⼭�� ������ �ȳ���. 

extern int aaaa;			//  ���������� �̰� ������ ���� ������ �����ϴ��� �˹ٰ� �ƴ�. �� �˷��� �ִ°Ŷ� ���⼭�� ������ �ȳ���. 


void CTest::Draw() {
	cout << g_iData << endl;
	//cout << g_iSrc << endl;			// main.cpp�� �������� �����ϳ�, study_exturn_CTest.cpp�� �� ���� �̸� ��ü�� ���� �Ұ���. extern�������. 
	//cout << g_iData_static << endl;	// static�� �ش� ������ ����� ���� �̿��� ���Ͽ��� ȣ�� �Ұ���. 
}