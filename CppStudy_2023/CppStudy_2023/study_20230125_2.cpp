/*
클래스 생성자에 관하여. (블로그 class 초기화 방법들에 첨부한 코드)

*/


#include <iostream>

using namespace std;


// 그 어떠한 생성자도 선언하지 않은 경우
class Test1 {
public:
	int iData;
};

// 디폴트 생성자를 정의한 경우
class Test2 {
public:
	int iData;
	Test2() { iData = 10; };
};

// 디폴트 생성자 외의 생성자를 정의한 경우
class Test3 {
public:
	int iData;
	Test3(int iSrc) { iData = iSrc; };
};

// 디폴트 생성자와 오버라이딩 생성자를 모두 정의한 경우
class Test4 {
public:
	int iData;
	Test4() { iData = 10; };
	Test4(int iSrc) { iData = iSrc; };
};

int main() {

	// 그 어떠한 생성자도 선언하지 않은 경우
	{
		Test1 t1;
		Test1 t2 = Test1();

		//cout << t1.iData << endl;	//ERROR
		cout << t2.iData << endl;
	}

	// 디폴트 생성자를 정의한 경우
	{
		Test2 t1;
		Test2 t2 = Test2();

		cout << t1.iData << endl;	//ERROR
		cout << t2.iData << endl;
	}

	// 디폴트 생성자 외의 생성자를 정의한 경우
	{
		//Test3 t1;					//ERROR
		//Test3 t2 = Test3();		//ERROR
		Test3 t3 = Test3(4);

		cout << t3.iData << endl;
	}

	// 디폴트 생성자와 오버라이딩 생성자를 모두 정의한 경우
	{

		Test4 t1;				
		Test4 t2 = Test4();		
		Test4 t3 = Test4(4);

		cout << t1.iData << endl;
		cout << t2.iData << endl;
		cout << t3.iData << endl;

	}
}