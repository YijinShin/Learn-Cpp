/* [ C++ study with TCP school 12~19part ]
topic : 메모리 동적 할당

* 메모리 영역
	데이터 영역 / 스텍 영역 / 힙 영역 
	- 데이터 영역, 스텍 영역에 할당되는 메모리의 크기 ->  컴파일 타임(compile time)에 미리 결정됨
	- 힙 영역에 메모리가 할당되는 메모리의 크기 ->  프로그램이 실행되는 도중인 런 타임(run time)에 사용자가 직접 결정 가능 

* 메모리 동적 할당(dynamic allocation)
	런타임에 메모리를 할당 받는 것. 
	즉, 이때 할당받는 메모리는 전부 동적 힙 영역에 할당받는 것. 

* 동적 할당 연산자 
	- C 언어
		- malloc()
		- calloc()
	- C++
		- new : 포인터에 메모리 할당 ( 이 때 할당하는 메모리는 자유 기억공간이라고 불리는 메모리 공간(memory pool)에 할당받는다.)
				만약 할당해줄 메모리 공간이 없으면 null 포인터를 반환한다. 
		- delete : 할당받은 메모리를 다시 운영체제로 반환
*/

#include <iostream>

using namespace std;

int main() {
	// [ 동적할당 연산자 ] 
	{
		// [new]
		int* ptr_int = new int; // 포인터에 메모리 할당 (4byte)
		*ptr_int = 10; // *가 참조 연산자니까 .. 포인터가 가지고 있는 주소값에 -> 10이라는 데이터를 쓴 것.

		double* ptr_double = new double;
		*ptr_double = 3.14;

		cout << "int를 할당받은 ptr_int의 크기: " << sizeof(ptr_int) << endl; // 어쨌든 포인터 변수니까 당연히 8바이트
		cout << "* ptr_int의 크기: " << sizeof(*ptr_int) << endl; // 안에 들어있는 데이터가 int니까 4바이트
		cout << "double를 할당받은 ptr_double의 크기: " << sizeof(ptr_int) << endl; // 어쨌든 포인터 변수니까 당연히 8바이트
		cout << "* ptr_int의 크기: " << sizeof(*ptr_double) << endl; // 안에 들어있는 데이터가 double이니까 8바이트

		// [delete]
		// 동적 할당을 위해 선언했던 포인터들은 다 쓰고나면 delete로 해제해주기 
		delete ptr_int;
		delete ptr_double;
	}
}