/* [ C++ study with TCP school 20~22part]
topic : 문자열 <문자형 배열 사용> -> cin(), cin.get(), cin.get().ignore()
		문자열 <string>			-> getline()

- 문자열의 끝에는 항상 NULL(\0)문자가 있어야함. 
- NULL의 아스키 코드 값은 0 

* 문자열을 저장할 수 있는 방법
	
	[ 문자형 배열 사용 ]
		- 처음에 배열 선언시 지정한 메모리 크기까지만 저장가능함. 

		- cin : 띄어쓰기 또는 엔터 전까지만 배열에 저장함. 
		- cin.get() : 띄어쓰기까지 저장가능. 엔터만 끝이라고 생각함. 
		- cin.get().ignore() : 사이즈 맞춰서 알아서 잘라서 읽어옴. 

	[ string 사용 ]
		- 사이즈 상관없음 
		- getline() : 띄어쓰기 읽어옴

* 버퍼를 비우기
	- cin.ignore() : 버퍼비우기. 괄호 안에 암것도 없으면 문자 한개만큼만 비움. cin.ignore(10)이면 10개만큼 비움
					 기본적으로 iostream 표준 입력 버퍼에서는 공백, 개행의 '이전'문자까지 가져옴. 그러면 입력후 엔터칠때 그 '엔터' 또는 '공백'은 입력 버퍼에 남아있음 
					 그래서 cin이 아니라 공백까지 다 저장하는 get()이나 getline()을 쓴다해도 마지막 남아있는 공백문자 1자를 지우기 위해서 ignore()정도는 해주는게 좋음. 
	- cin.clear() : stream을 good state로 돌려줌. (엄연히 말하면 버퍼를 비우는건아님)

*/

#include <iostream>
#include <string>

using namespace std;

int main() {
	const int SIZE = 10; // 심볼릭 상수 
	
	// [ 문자형 배열로 문자열 저장 + cin ]
	{
		// 띄어쓰기 있으면 입력 딱 끝나버림 + SIZE 넘게 입력하면 에러뜸 
		char name[SIZE]; 
		char left[SIZE];
		
		cout << "이름을 입력하세요: ";
		cin >> name;							// 여기서 "가 나다" 라고 입력하면 name에는 "가"만 들어가고, 
												// 이거 다음으로 나오는 cin은 씹힐것이다. 거기에 버퍼에 남아있던 "나다"가 들어감.
		cout << name << "님 반갑습니다." << endl;

		cin.get(left, SIZE).get();							// 버퍼에 뭔가 남아있으면 남은 값이 들어가버려서 씹힘
		cout << "버퍼에 남은 글자가 있습니다.: "<< left<<endl;

	}
	cout << "-------------------------------------" << endl;


	// [ 문자형 배열로 문자열 저장 + get() ]
	{
		// 띄어쓰기 있어도 다 문자형 배열에 저장함. but SIZE넘으면 에러뜸 
		
		char name2[SIZE];
		char left[SIZE];

		cout << "이름을 입력하세요: ";
		cin.get(name2, SIZE).get();				
		cout << name2 << "님 반갑습니다." << endl;
	}
	cout << "-------------------------------------" << endl;

	

	// [ 문자형 배열로 문자열 저장 + get() + ignore() ]
	{
		// 띄어쓰기 있어도 다 문자형 배열에 저장함. + SIZE넘게 입력해도 에러 안뜨고 알아서 잘라서 받음. 

		char name[SIZE];
		char left[SIZE];

		cout << "이름을 입력하세요: ";
		cin.get(name, SIZE).ignore(SIZE, '\n');	 //여기서 10개 이상 입력해도 딱 10개만 가져오는데, 이때 나머지는 버퍼에 남아있는게 아니다. 다 버림. 
		cout << name << "님 반갑습니다." << endl;
	}
	cout << "-------------------------------------" << endl;

	// [ string ] 사용
	{
		string str;
		cout << "이름을 입력하세요: ";
		getline(cin, str);
		cout << str << "님 반갑습니다." << endl;
	}
}