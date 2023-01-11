/* [ C++ study with TCP school ]
topic : sting 클래스 

- C++ 에서 추가된 클래스
- std namespace에 있음
- '클래스'이다. 자료형이 아니라

* 입력 : getline(cin, [string 변수이름])

* 출력 : 똑같이 cout 사용 가능

* 인덱스로 각각의 문자 접근 가능 
 
* 대입 연산자 : = 으로 가능 
				문자형 배열인 경우, 한쪽 배열에서 다른 쪽 배열로 복사를 하는 격이라 strcpy() 같은걸 사용해야했다.
* 결합 연산 가능 : str + str2 이런거 가능. 
 
* string 메소드	
	- length()	: 문자열의 길이 ( 속한 문자의 개수 )
	- size()	: string변수의 실제 메모리 사이즈 
	- append()	: 문자열 추가 
	- find()	: 문자 또는 문자열 찾기 
	- compare()	: 두 문자열간 비교 
	- replace()
	- capacity() : 
	- max_size() : 문자열이 최대한 대입받으면 가질 수 있는 최대 문자열길이 

*/

#include <iostream>
#include <String>

using namespace std;

int main() {
	{
		string str;				// 선언
		cout << "이름 입력: ";
		getline(cin, str);		// 입력 
		cout << str << "님 반갑습니다." << endl; // 출력
	}

	cout << "------------------------------------------" << endl;

	{
		string str = "hello";
		char ch_str[] = "hello";

		// [length(), size()]
		cout << "1-1. str의 길이: " << str.length() << endl;
		cout << "1-2. str가 메모리에서 실제 사용하고 있는 크기(공간의 개수, 배열의 size) : " << str.size() << endl;	// char 공간을 5개 쓰고 있으니까 결과가 5
		cout << "1-3. str가 메모리 공간을 차지하는 byte수 : " << sizeof(str) << endl;
		cout << "1-4. 같은 hello를 가지고있는 문자형 배열이 메모리 공간을 차지하는 byte수 : " << sizeof(ch_str) << endl;
		cout << endl;


		// [append()]
		str.append(" world");
		cout << "2-1. append로 world 추가 :" << str << endl;
		str = "hello";
		str.append(" world", 3, 5); // 뒤에 ld만 추가함 
		cout << "2-2. append로 world 추가 :" << str << endl;
		str = "hello";
		str.append(" world", 3); // 앞에서 3개만 추가함. " wo"까지 추가함.  
		cout << "2-3. append로 world 추가 :" << str << endl;
		str = "hello";
		str.append(3, 'X'); // X를 3개 추가함.
		cout << "2-4. append로 world 추가 :" << str << endl;
		cout << endl;

		// [find()]
		cout << "3-1. 문자열 찾아, 시작 위치 반환: " << str.find("lo") << endl;
		cout << "3-2. 문자 찾아, 시작 위치 반환: " << str.find('l') << endl;
		cout << "3-3. 지정한 위치부터 문자 찾아, 시작 위치 반환: " << str.find('l', 3) << endl;
		if (str.find("wr") == string::npos) cout << "해당 문자열을 못찾았습니다. \n";			// string::npos : string 클래스에 정의된 static const size_type 이다. -1 즉, 거짓이 저장되어있다. 
		cout << endl;

		// [compare()]
		string s1 = "ABC";
		string s2 = "ABD";
		if (s1.compare(s2) == 0) { cout << "4. s1과 s2는 같다. " << endl; }
		else if(s1.compare(s2) < 0) { cout << "4. s1이 s2보다 사전 편찬 순으로 앞에 있다. " << endl; }
		else if(s1.compare(s2) > 0) { cout << "4. s1이 s2보다 사전 편찬 순으로 뒤에 있다. " << endl; }
		cout << endl;

		// [replace()]
		string test1 = "my name is yijin";
		string test2 = "junsu";
		test1.replace(11, test2.length(), test2);	// 11은 바꾸는 시작위치
		cout << "5. 바뀐 test1: " << test1 << endl;
		cout << endl;

		// [capacity()]



	}

}