/*
* 상수 포인터 (constant pointer)
	: 값이 변하지 않는 포인터 변수

* 상수포인터 VS 읽기 전용 포인터 VS 읽기전용상수포인터
	- int* const
	- const int*
	- const int* const

-------------------------------------------------------------------------------
배열
- 연속된 메모리공간에 할당됨
- 배열의 이름 = 배열 전체의 첫번째 주소값이다. ==> 배열의 이름 ==  상수 포인터

*/

#include <iostream>

using namespace std;

int main() {

	// [ const가 앞에 붙을 경우 ] => 이건 상수 포인터가 아님. 이건 읽기 전용 포인터임
	{
		const int* Non_constPtr;	// P가 가리키고 있는 공간의 값을 상수화하는 것. 
		// 즉, 읽기 전용 포인터로 만들겠다는 것. (메모리 공간의 값을 가져오는건 됨. but 포인터를사용해서 값을 변경하는건 안됨

		int a(10);
		int b(20);

		Non_constPtr = &a;
		Non_constPtr = &b;	// 이건 상수포인터가 아니니까 포인터 값 변경 가능 

		b = 30;			// b자체는 const가 아니니까 변경가능
		//*constPtr = 30;	// constPtr은 const이기 때문에 이렇게 변경 불가능. 
	}

	// [상수 포인터 : [자료형*] const [변수이름]]
	{
		int a(10);
		int b(10);

		int* const constPtr = &a;	// 심볼릭 상수니까 당연히 선언과 동시에 초기화 해야함. ( const니까!! 그 뒤로는 절대 못바꿈. 이거 안하면 안에 쓰레기갚인 상태로 값 더이상 못바꾸는거임!)

		//constPtr = &b;			// 상수 포인터니까 이렇게 값 변경 불가능. 

		*constPtr = 20;				// 읽기 전용은 아니니까 이렇게 값 참조로 변경 가능 

		cout << a << endl;
	}

	// [ 읽기 전용 상수 포인터 ] 
	{
		int a;
		const int* const Read_const_ptr = &a;	// 위에 두개를 합친거임. 

		/*	- 선언시 무조건 초기화해야하고
		*	- 선언 후 더이상 값을 바꾸지 못하며
		*	- *Read_const_ptr = 10 이런식으로 값을 참조해서 변경하는 것도 불가능하다.
		*/

		const char* str_constchar_pointer = "hello";	// 읽기전용 포인터니까 선언과 동시에 초기화 해야함.
		const char str_constchar[6] = "hello";			// 읽기전용 포인터니까 선언과 동시에 초기화 해야함.
		char* str_char;

		str_char = "hello";

		cout << str_constchar << "," << str_char << endl;

		str_char[1] = 'E';
		//str_constchar_pointer = 'E'// 읽기 전용 포인터니까 당연히 이렇게 수정안됨
		//str_constchar[1] = 'E';	// 읽기 전용 포인터니까 당연히 이렇게 수정안됨

		cout << str_constchar << "," << str_char << endl;

	}

	{
		int arr[3] = { 1,2,3 };
		int* arr_ptr = arr;

		cout << arr[1] + 1 << endl;
		cout << *(arr_ptr + 1) << endl;
	}

	// 포인터 배열 VS 배열 포인터 
	{
		int a;
		int b;
		int c;

		int* intPtr_arr[3] = { &a, &b, &c };	// 이게 배열 포인터

		
	}
}


/*
1. 이중포문과 배열을 이용하여 다음과같이 출력하기

1	2	3	4	5
6	7	8	9	10
11	12	13	14	15
...
				25까지 

2. 로또 만들기
- 1차원 배열이용하여 1~45의 숫자중 무작위로 6개, 5회차 출력하기
- 같은 회차 단계에서 중복되는 숫자는 없어야함.
- 출력시 오름차순으로 정렬(버블정렬)


*/