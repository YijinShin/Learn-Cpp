/*
	cin, get, getline 과 ignore을 자세하게 알아보자.

	cin.ignore()은 버퍼에 남아있는 문자 하나를 지운다.
	cin.ignore(10) 이면 10개를 지우는 것.

	
	cin() : 공백, 개행 문자의 '직전'문자까지만 읽어온다. 
			따라서 사용자가 입력한 '첫번째 공백 문자 이후'나 '마지막 엔터'는 버퍼에 남는다.
			즉, ignore()을 써서 버퍼를 비울 필요가 있다. 

	get() : 공백, 개행 문자까지 읽어온다. 
			따라서 사용자가 입력하고 친 마지막 엔터는 버퍼에 남지 않는다.
			즉, get()다음에는 ignore()써서 버퍼 비울 필요가 없다. 
	
	getlie() : get과 마찬가지로 공백, 개행 문자까지 읽어온다. 
	
	
	경우 
		- cin 다음에 cin 쓰기		-> 버퍼에 남아있던 공백, 개행문자 무시함 -> ignore필요없음. 
		- cin 다음에 get 쓰기		-> 버퍼에 남아있던 공백, 개행문자 부터 읽어옴 -> ignore필요함
		- cin 다음에 getline 쓰기	-> 버퍼에 남아있던 공백, 개행문자 부터 읽어옴 -> ignore필요함
		- get/getline 다음에 get/getline 쓰기	-> 애초에 앞의 get/getline이 버퍼에 공백, 개행을 안남겨서 -> ignore필요없음


*/

#include <iostream>
#include <string>

using namespace std;

int main() {
	
	// [case1:	cin 다음에 cin ]
	{
		char str[10];
		char test[10];

		cin >> str;
		cin >> test;
		cout << "str: " << str << " / test: " << test << endl;
	}
	
	// [case2:	cin 다음에 get ]
	{
		char str[10];
		char test[10];

		cin >> str;
		cin.ignore(); // 이거 없으면 다음 입력 걍 버퍼에 남아있던 공백문자 들어가버림
		cin.get(test, 10).get();
		cout << "str: " << str << " / test: " << test << endl;
	}
	
	// [case3:	cin 다음에 getline ]
	{
		char arr_str[10];
		string str_str;

		cin >> arr_str;
		cin.ignore(); // 이거 없으면 다음 입력 걍 버퍼에 남아있던 공백문자 들어가버림
		getline(cin,str_str);
		cout << "arr_str: " << arr_str << " / str_str: " << str_str << endl;
	}
	
	// [case4:	cin 다음에 getline ]
	{
		char arr_str[10];
		string str_str;

		cin.get(arr_str,10).get();
		getline(cin, str_str);
		cout << "arr_str: " << arr_str << " / str_str: " << str_str << endl;
	}
}