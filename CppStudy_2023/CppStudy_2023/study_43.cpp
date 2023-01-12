/* [ C++ study with TCP school 43part]
topic: 네임 스페이스

* 내부 식별자(identifier)
		변수, 함수, 구조체, 클래스 등 


* 네임스페이스 
		- 식별자 간의 충돌가능성이 있다(이름이 겹친다거나) => 내부식별자에 유효 범위를 제공하기 위해 네임스페이스 사용
		- 블록 내에서는 정의 불가능. 
		- 외부 연결 가지게 됨
		- 일반적으로는 헤더파일에 정의함. 


*/

#include <iostream>
#include <string>

#include "study_43.h"	// 내가 정의한 네임스페이스 쓰기 위해 내가 만든 헤더파일 include 하기

using namespace std;
using namespace Test;	// Test2는 using안했으니까 쓸거면 Test2:: 붙여서 호출해야함

int main() {
	cout << "이름을 입력하세요: ";
	getline(cin, name);		// 앞에 ::(범위지정연산자)없으니까 당연히 Test 네임스페이스의 name변수에 저장될 것이다. 
	Display();				//	앞에 ::(범위지정연산자)없으니까 당연히 Test 네임스페이스의 Display()가 실행될 것이다. 
	
	
	cout << "이름을 입력하세요: ";
	getline(cin, Test2::name);
	Test2::Display();
}