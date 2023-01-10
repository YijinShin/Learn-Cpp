/* [ C++ study with TCP school 25~27part]
topic : 포인터 

* 주소값 
	데이터의 첫 시작 메모리 주소로, 모든 변수나 상수의 가장 앞 1byte는 해당 변수의 주소값을 가지고 있다. 
	즉, int가 4바이트면, 그중 첫번째 1바이트는 해당 int 변수또는 상수의 '주소값'을 의미함


* 포인터란
	데이터의 주소값을 저장하는 변수

* 포인터 연산자
	- * : 참조 연산자 
		'포인터' 앞에 붙임
		'포인터에 저장된' 주소값에 저장된 '값'을 반환
	- & : 주소 연산자 
		'변수' 앞에 붙임
		해당 '변수'의 주소값을 반환

* 포인터 변수의 크기 
	포인터의 크기는 앞에 붙이는 타입과 관계없음. > 무조건 '주소값'을 저장하는 애니까

	따라서 포인터 변수 크기는 CPU에 의해 결정됨
		- 컴이 32bit면 포인터 변수 크기 = 4byte
		- 컴이 64bit면 포인터 변수 크기 = 8byte
*/
#include <iostream>

using namespace std;

int main() {
	// [ 포인터 선언 ]
	{
		int num = 100;
		int* ptr = &num; // 포인터 변수 선언

		int* ptr2, ptr3; // ptr2는 int* , ptr3은 int로 선언됨
		int* ptr4, * ptr5; // 둘다 int*로 선언됨

		int test = 100;
		int* ptr6 = &test;
		int** ptr7 = &ptr6; // 이중 포인터 
	}

	// [ 포인터의 크기 ]
	{
		// 포인터의 크기는 앞에 붙이는 타입과 관계없음. > 무조건 '주소값'을 저장하는 애니까

		/* 따라서 포인터 변수 크기는 CPU에 의해 결정됨
			- 컴이 32bit면 포인터 변수 크기 = 4byte
			- 컴이 64bit면 포인터 변수 크기 = 8byte
		*/
		int num = 1;
		int* ptr = &num;
		int** ptrr = &ptr;

		cout << "int size(byte): " << sizeof(num) << endl;
		cout << "pointer size(byte): " << sizeof(ptr) << endl; //8바이트
		cout << "이중 pointer size(byte): " << sizeof(ptrr) << endl;//8바이트
		cout << endl;
	}

	// [ 포인터 응용 ] 
	{
		int i1 = 100;
		double d1 = 3.14;

		int* int_ptr = &i1;
		double* double_ptr = &d1;
		
		int** int_ptrr = &int_ptr;

		cout << "i1의 주소값: " << &i1 << endl;
		cout << "int_ptr이 가지고 있는 주소값 : " << int_ptr << endl;
		cout << "int_ptr이 가지고 있는 주소값에 저장된 값: " << *int_ptr << endl;
		cout << endl;
		cout << "d1의 주소값: " << &d1 << endl;
		cout << "double_ptr이 가지고 있는 주소값 : " << double_ptr << endl;
		cout << "double_ptr이 가지고 있는 주소값에 저장된 값: " << *double_ptr << endl;
		cout << endl;
		cout << "int_ptr의 주소값: " << &int_ptr << endl;
		cout << "int_ptrr이 가지고 있는 주소값 : " << int_ptrr << endl;
		cout << "int_ptrr이 가지고 있는 주소값에 저장된 값 : " << *int_ptrr << endl;
		cout << "int_ptrr이 가지고 있는 주소값에 저장된 주소값에 저장된 값 : " << **int_ptrr << endl;

	}
}