/* 복사 생성자 */

#include "stdafx.h"
using namespace std;

/* 디폴트 복사 생성자 사용 */
class CTest1 {
private:
	int m_iData;
	int m_iSrc;
public:

};

/* 사용자 정의 복사 생성자 사용 */
class CTest2 {
private:
	int m_iData;
	int m_iSrc;
public:

};

class CTest3 {
private:
	int m_iData;
	int m_iSrc;
public:
	

};

static int iSrc;		//초기화 하지 않은 전역 static 변수 

class CTest {
public:
	static int m_iData;		// class 내의 static 맴버 변수 
};

class CTest4 {
public:
	 static int m_iA;
	static  int m_iB;

	 static int* m_iptrA;
	static int* m_iptrB;
};

int num = 10;
static int* const iptrB = &num;
static const int* iptrA = &num;

int CTest4::m_iA = 0;
int CTest4::m_iB = 0;
//int CTest4::m_iptrA = nullptr;
//int CTest4::m_iptrB = &num;

static const int* const iptrC = &num;

void AddCnt() {
	static int iCnt;
	iCnt++;
	cout << iCnt;
}

int main() {
	{
		for (int i = 0; i < 5; i++) AddCnt();
		cout << endl << endl;
	}

	/* 전역 static const int* 포인터, static int* const 포인터*/
	{
		int num2 = 20;
		iptrA = &num2;
		//iptrB = &num2 //  ERROR const 라서 못바꿈
		//*iptrA = 20;	// ERROR 읽기 전용 포인터라 참조값 못바꿈

		cout << *iptrC << endl;
		//iptrC = &num2;
		//*iptrC = 20;
		
	}

	/*  */
	{
		int num = 10;

		//CTest4::m_iA = 10;
		//CTest4::m_iB = 10;
		//CTest4::m_iptrA = &num;
		//CTest4::m_iptrB = &num;
	}

	/* static 초기화 되는거 확인 */
	{
	/* 일반 변수 */

	/* static 변수 */
	static int iNum;		// 초기화 하지 않은, 함수 내에서 선언한 static 변수 
	cout << iNum << endl;	// 0이 들어있음. 
	cout << iSrc << endl;	// 0이 들어있음. 
	//cout << CTest::m_iData << endl;	//ERROR!
	}
}
