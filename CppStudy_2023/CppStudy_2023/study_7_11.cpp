/* [ C++ study with TCP school ]
topic : 변수의 종류 / 변수의 타입 / 타입 변환 




* Variable와 Constant 
 - Variable (코드 돌아가는동안 값 변할 수 있음)

 - Constant ( 값 변할 수 없음)
	- literal :  메모리 공간에 대한 '이름이 없다'. (정수, 변수, 문자형있음) > 6, 1.2, 'a' 이런거 
	- 변수 선언, 초기화 시 [변수타입][변수명] = [리터럴 상수][접미사(선택)] 이렇게 넣음. 
			[타입] [상수 종류]
			정수형 리터럴 상수 : 기본적으로 int로 저장됨 
							   -  직접 앞에 타입을 붙이는 경우, 너무 커서 int에 안담기는 경우가 아니면 int
							   - 상수의 타입을 지정 -> 상수의 끝에 접미사를 붙임. 
										- 접미사 없음: signed int
										- u, U: unsigned int 
										- l,L: signed long
										- ul, uL, Ul, UL : unsinged long 
										- ull, Ull, uLL, ULL: unsigned longlong
			실수형 리터럴 상수 : 기본 double 형
								- 상수의 타입을 지정 -> 상수의 끝에 접미사를 붙임.
										- 접미사 없음: double
										- f, F: float 
										- l,L: long double
			포인터 리터럴 상수 : null pointer = 아무것도 가리키고 있지 않은 포인터
							   표현 -> nullptr, 0으로 표현가능.(nullptr이 안전함)  
							   (nullptr == 0 은 true를 반환함. 둘이 같은 얘기니까)
							   정수형 변환 불가능 

	- Symbolic: 변수와 마찬가지로 '이름'을 가지고 있는 상수 
			선언한 심볼릭 상수를 특정 함수, 파일에서만 사용가능하도록 제한 가능 
			선언과 동시에 초기화 해야함 must. 
			선언 방법 
				- 메크로 이용 (C에서 쓰는 문법)
				- const 키워드 이용 (C++에서는 이걸 더 추천함) 


* 변수와 메모리 주소
	변수 = 메모리 addres를 기억하는 역할
	변수를 참조 = 주소가 아니라 주소에 있는 "데이터"를 참조

* 변수 타입과 할당 메모리 크기
 	- 정수형 : short(2), int(4), long(8), longlong(16) 
	- 실수형 : float(4), double(8)	
			  float = 소수점 6자리까지 오차없이 
			  double = 소수점 15자리까지 오차없이 
	- 문자형 : char(1) 
			  문자형도 엄연히 정수형타입이라서 un/signed 지정 가능.  
	- bool형 : bool
	- 사용자 정의 구조체 변수 

* auto 선언
  C+11 부터는 변수 선언시 [auto] [변수명] 이렇게 가능. 
  그러면 변수에 들어가는 '초기값'에 맞춰서 타입이 정해짐 

 * 타입 변환 종류
	- 묵시적 타입 변환 (자동 변환)
		묵시적 변환은 "손실이 최소화 되는 방향으로" 이루어진다. 
		당연히 char -> short -> int -> long -> float -> double 방향으로 이뤄짐 
	- 명시적 타입 변환 (강제 변환)

*/



#include <iostream>

using namespace std;

int main() {
	// [ 변수 선언 + 초기화 ]
	{
		int num1; //선언
		int num2 = 10; // 선언 + 초기화
		int num3(10); // 선언 + 초기화
		int num4 = 10, num5 = 10;
		int num6(10), num7(10);
	}

	// [ 출력시, 진법 선택 ]
	{
		int num = 10;
		cout << "10진수 표현: " << num << endl; // 기본적으로 10진수(dec)
		cout << oct; // 8진법 선택 > 다음에 다시 진법 선택이 있기 전까지는 8진수로 출력됨
		cout << "8진수 표현: " << num << endl;
		cout << hex; // 16진법 선택 > 다음에 다시 진법 선택이 있기 전까지는 8진수로 출력됨
		cout << "16진수 표현: " << num << endl;
		cout << dec; // 이 뒤를 위해 다시 10진수로 바꿔주기.. 
	}

	// [ 변수와 상수 ]
	{
		//변수 + 정수형 리터럴 상수 
		short i1 = 65535; // signed int 니까 범위가 -32,768~32,767. 따라서 65535을 넣으면 -1이 나옴. 순환이라 끝까지 가면 다시 제일 작은수로 바뀜 
		unsigned short i2 = 65535;
		cout << "signed int 65535 : " << i1 << " / unsigned int 65535 : " << i2;
		//변수 + 실수형 리터럴 상수 
		float f1 = 10.17f; // f1 = 변수, 10.17f = 실수형 리터럴 상수(f안붙이면 double로 저장됨),
		float f2 = 10.17; // 상수 타입지정 안했으니까 10.17은 double로 저장됨.(상수에 마우스 대보셈)
		// 심볼릭 상수 
		const int ages = 30;
	}
	
	// [ 타입 변환 ] 
	{
		// 묵시적
		int i3 = 3.14f; // 문제됨 > f에서 int로 변경되어버림 
		double d1 = 5; // 문제 안됨 > 변형안일어남
		cout << "i3은 묵시적 변환됨: " << i3 << " d1은 안변함: " << d1 << endl;
		float result1 = 5 + 3.1f; // 5가 묵시적으로 float가 됨
		double result2 = 5.0f + 3.14; // 5.0f가 묵시적으로 double이 됨 
		// 명시적 
		int num1 = 1;
		int num2 = 4;
		double result3 = num1 / num2;// int, int 의 계산이니까 결과는 0(int). int를 double변수에 넣어도 아무 손실이 없으니 결과는 0 
		double result4 = (double)num1 / num2; // 명시적으로 num1을 변환함. double과 int의 계산이니까 결과는 double(묵시적) > 결과는 double
		double result5 = num1 / (double)num2; // 위와 마찬가지 
		cout << "result3: " << result3 << " - result4: " << result4 << " - result5: " << result5 << endl;
	}
	

}