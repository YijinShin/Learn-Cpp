#include <iostream>

using namespace std;

int main() {
	
	{
		char str1[50] = "hello";	// 여기서 "hello"이거!! 이게 문자열 상수이다. 
		
		const char* str = "hello";	// 일단 문자열 상수라고 말하는 타입은 이걸 말하는게 맞다.
		char* str2 = "hello";	// 이렇게 선언하면 일단 오류가 나는데, 타입이 안맞음. 

	}

}