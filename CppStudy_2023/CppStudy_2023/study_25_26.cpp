/* [ C++ study with TCP school 25~27part]
topic : 배열과 포인터

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

* 포인터간의 연산
	- *,/ 는 안됨
	- +, - 는 가능. -> 두 포인터간의 거리를 나타낸다.
	- 포인터끼리 대입, 비교 가능 

	int num;   > 얘의 주소값이 1이라고 하자 
	int* ptr = &num; > ptr안에 1이 들어가. 
	ptr + 1 은 5 라는 주소값을 가짐. 왜? int니까 4byte씩 더해지는거임. 
	포인터에 더하거나 빼는 상수가 의미하는 실제 byte크기는 포인터 변수의 타입에 의해 결정됨 
	즉, 
		int arr[3];
		int* arr_ptr = arr;

		arr[1]의 주소값은 arr_ptr + 4가 아니라 arr_ptr + 1이다. 여기서 1은 4byte를 의미해서 [ arr_ptr에 저장된 주소 + 4 ] 한 주소값이 반환됨

	정리 ) 더하기, 빼기, 대입, 비교 가능 

* 배열과 포인터
	- 둘은 아주 비슷하며, 서로 대체 가능 

	- 사실 배열의 이름은 배열이 시작되는 첫 주소를 의미함. 
	int* arr[3] 이면 arr은 arr[0]의 주소값을 의미한다. 
	arr + 4 == arr[1]의 주소값
	arr + 8 == arr[2]의 주소값

	그러니까 반대로 *(arr+4) 는 arr[1]의 주소값에 저장된 데이터를 의미한다. 
	즉 *(arr+4) == arr[1] 

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

	// [ 포인터와 배열 ]
	{
		cout << endl;
		
		int arr[] = { 10,20,30 };
		int* arr_ptr = arr;		// arr는 이렇게 넣으면 배열의 첫 시작 주소가 여기들어간다.

		// 포인터를 이용해서 배열의 요소접근하기
		cout << "배열 그냥 뽑아보면 주소가 나온다: " << arr+0 << ", " << arr + 1 << ", " << arr + 2 << endl;
		cout << "배열에 주소값을 더해서 배열 접근: " << *(arr + 0) << ", " << *(arr + 1) << ", " << *(arr + 2) << endl;
		cout << "포인터를 이용해 배열 접근: " << arr_ptr[0] << ", " << arr_ptr[1] << ", " << arr_ptr[2] << endl;
		cout << "포인터를 이용해 배열 접근: " << *(arr_ptr + 0) << ", " << *(arr_ptr + 1) << ", " << *(arr_ptr + 2) << endl;
		
		// 단! 배열의 크기를 곧 포인터의 크기라고 생각해선 안된다. 
		cout << "배열 크기 : " << sizeof(arr) << endl;
		cout << "포인터를 이용한 배열 크기 계산..은 안됨: " << sizeof(arr_ptr) << endl; // arr_ptr은 어디까지나 포인터 변수라서 당연히 8byte가 나옴 
		
	}
}