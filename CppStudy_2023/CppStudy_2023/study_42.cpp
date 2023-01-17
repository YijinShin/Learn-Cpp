/* [ C++ study with TCP school 42 part]
topic: 유효 범위 / 연결 / 변수의 종류

* 유효 범위 (scope) 
	변수가 하나의 파일( 변환단위 (translation unit)) 내에서 사용될 수 있는 범위를 의미함
	( 함수 내에서 선언된 변수는 해당 함수에서만 사용가능하고.. 뭐 이런거 )

* 연결 (linkage)
	변수를 사용할 수 있는 파일의 접근 가능 여부를 의미
	- 외부 연결 
		외부 연결을 가지는 변수는 -> 여러 파일에서 사용가능
	- 내부 연결
		내부 연결을 가지는 변수는 -> 하나의 파일에서만 사용가능
	- 함수 내에 선언된 변수
		함수 내에 선언된 변수는 -> 함수 밖에서는 사용 불가능 

* 변수의 종류
	- [ 자동 변수 ]		(automatic variable)
			- local variable
			- 블록({}) 내에 선언된 변수. 
			- (함수의 매개변수가 여기에 속한다) 
			- 선언된 블록 안에서만 
			- stack영역에 저장됨
			- 초기화 하지 않으면 쓰레기값으로 초기화됨 -> 프린트 하려고 하면 에러남 
			- 해당 블록이 끝나면 -> 자동변수는 메모리에서 사라짐

	- [ 레지스터 변수] 	(register variable)
			-  register 키워드를 붙여서 선언한 변수
			- C++11 이전에는 의미가 있었음 ( CPU의 레지스터 메모리 영역에 저장되는 변수였다. 그럼 빠르게 접근이 가능함. )
										  ( 그러나 레지스터는 아주 작아서 이거 선언 못할 수 도 있는 상황이 있기도함 -> 그럼 걍 자동변수 취급됨)
			- C++11 부터는 그냥 자동변수랑 같은거임. 

	- [ 정적 번수 ]		(static variable)
			- 프로그램이 실행되는 내내 유지되는 변수. 
			- 메모리 상의 data영역에 저장됨.
			- 초기화 안하면 0으로 초기화됨

			유형 3가지 
				- [ 연결을 가지지 않는 정적변수 ]
						- '블록 내부에 선언된' 변수에 -> static 키워드 
						- 단 한번만 초기화 됨						 (전역변수 특징)
						- 프로그램이 종료되어야 메모리상에서 사라짐 (전역변수 특징) >> 함수안에서 선언했어도 static붙으면, 함수 끝나도 해제안됨 
							void func(){
								static int a = 100;
								cout << ++a <<endl;
							}

							func()을 세번부르면 100 101 102가 나옴. a가 static이라서 함수가 끝나도 바로 반환하지 않음. 
							static은 data영역에 할당되니까! (stack영역이 아니라) 

						- 해당 블록 내에서만 접근 가능				 (지역변수 특징)

				- [ 내부 연결을 가지는 정적변수 ]
						- '유효 범위를 변환 단위(파일)로 가지는' 변수에 -> static 키워드 
						- 해당 파일(.pp파일말하는 거임. 다른 말로는 변환 단위) 에서만 사용 가능 (블록 보다는 좀더 넒은 범위에서 가능한것)
						
				- [ 외부 연결을 가지는 정적변수 ]
						- 유효 볌위를 변환 단위로 가지는 변수 자체 (static 안붙임!! > 이게 내부 연결을 가지는 정적변수와의 차이임)
						- 외부 파일에서도 사용가능. -> 물론! 외부 파일에서 해당 변수를 쓰려면 extern 키워드를 써서 자기 파일에 재선언 하긴해야함. 


* 정리!
	 변수의 종류
		- 자동 변수 ( == 로컬변수)			[키워드 :        / 선언위치 : 블록 밖에]	
		- 레지스터 변수 ( 지금은 == 자동변수)	[키워드 : register / 선언위치 : 블록 안에]
		- 연결을 가지지 않는 정적변수			[키워드 : static / 선언위치 : 블록 안에]
		- 내부 연결 가지는 정적변수			[키워드 : static / 선언위치 : 블록 밖에]
		- 외부 연결 가지는 정적변수			[키워드 :        / 선언위치 : 블록 밖에 재선언시 extern]

	변수 값 변경 가능 불가능
		- 불가능 -> const
		- 가능 -> (const안쓰기)
						
*/



#include <iostream>

using namespace std;

static int staticVariable_internal_linkage;	// 내부 연결 가지는 정적변수
int staticVariable_external_linkage;		// 외부 연결 가지는 정적변수
												// 얘의 경우 만약 test.cpp파일에서 얘를 사용하고 싶으면 
												// test.cpp파일에서 -> #include <study_42.cpp>
												//				   ->  extern int staticVariable_external_linkage;
												// 이렇게 두개 써준다음에 사용가능. 

int main() {
	int automaticVariable;					// 자동 변수 ( == 로컬(지역) 변수)
	static int staticVariable_no_likage;    // 연결 가지지 않는 정적변수

	cout << "[ 초기화 상태 확인 ]" << endl;
	cout << "외부연결 정적변수 초기화 안했을 때 값: " << staticVariable_external_linkage << endl;  // 0으로 나올거임
	cout << "내부연결 정적변수 초기화 안했을 때 값: " << staticVariable_internal_linkage << endl;  // 0으로 나올거임
	cout << "연결없는 정적변수 초기화 안했을 때 값: " << staticVariable_no_likage << endl;			// 0으로 나올거임
	//cout << "자동변수 초기화 안했을 때 값: " << automaticVariable << endl;						// 지역변수는 초기화 안하면 디버깅 에러남. 
	

	cout << "main 블록 안에서 값 수정해보기 " << endl;	// 모두 const는 아니라서 다 수정됨
	staticVariable_internal_linkage = 5;
	staticVariable_external_linkage = 10;
	staticVariable_no_likage = 15;
	automaticVariable = 20;
	cout << "외부연결 정적변수 main에서 값 바꿈: " << staticVariable_external_linkage << endl; 
	cout << "내부연결 정적변수 main에서 값 바꿈: " << staticVariable_internal_linkage << endl;  
	cout << "연결없는 정적변수 main에서 값 바꿈: " << staticVariable_no_likage << endl;			
	cout << "자동변수 main에서 값 바꿈: " << automaticVariable << endl;						

}