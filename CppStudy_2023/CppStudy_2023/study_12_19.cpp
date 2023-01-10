/* [ C++ study with TCP school 12~19part ]
topic : 연산자(헷갈리는 것만 정리함)

!! 기본적으로 동급의 연산자들은 오른쪽에서 -> 왼쪽 순서로 진행됨 !!

*/

#include <iostream>

using namespace std;

int main() {
	// [대입연산자 +=와 =+ 차이]
	{
		int num1 = 1;
		int num2 = 5;
		num1 += num2;
		cout << "num1: " << num1 << " / num2: " << num2 << endl;

		num1 = 1;
		num2 = 5;
		num1 = +num2; // 이건 =먼저 실행이라 num1에 num2를 넣고나서, num1 + num2를 한것. 그결과가 10인데 이걸 어디에 저장하지는 않음
		cout << "num1: " << num1 << " / num2: " << num2 << endl;

		num1 = 1;
		num2 = 5;
		int num3 = num1 = +num2; // 순서: = > = > +  
		cout << "num1: " << num1 << " / num2: " << num2 << " / num3: " << num3 << endl;
	}

	//[증감 연산자]
	{
		// 증감연산자를 쓰면 변수의 값이 바뀌는거임! a = b-1 은 b값이 안바뀌는데 a = --b는 b값도 바뀜! 
		int num1 = 5;
		int num2 = 10;
		int result1, result2;
		result1 = --num1 + num2; // -- >> +
		
		num1 = 5;
        num2 = 10;
		result2 = num1-- + num2; // + >> -- 

		cout << "result1: " << result1 << " / result2: " << result2 << endl;
	}

	//[비트 연산자]
	{
		/* & = 두수의 대응되는 두 비트가 모두 1이면 true
		   | = 하나라도 1이면 true
		   ~ = 반전 (NOT연산)
		   ^ = 싹다 다르면 true
		   >> = 오른쪽으로 이동 ( 2배 감소 )
		   << = 왼쪽으로 이동 ( 2배 증가 )
		
		*/
	}

	// [sizeof 연산자]
	{
		//변수의 메모리 크기 알려줌 (바이트 단위)
		cout << "char: " << sizeof(char) << endl;

		int num1 = 1;
		int arr[2];
		cout << "int: " << sizeof(num1) << " / int[2]: " <<  sizeof(arr) << endl;
	}

	//[범위지정 연산자 scope resolution operator]
	{
		/* 특정 범위 내에 있는 식별자(함수, 변수, 열거체 등)를 구분하는것.
			- 클래스 이름::식별자
			- 네임스페이스 :: 식별자
			- 열거체 :: 식별자 
		*/
	}

	//[ 맴버 포인터 연산자 pointer-to-member operation]
	{
		// 포인터 쪽에서 다룰거임. 
	}
}