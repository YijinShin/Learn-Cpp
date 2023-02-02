/*
TOPIC : 파일 함수 / 상수 매크로(매크로 상수) / 함수 매크로 / 조건부 컴파일

*/

#include <iostream>

// 메크로 함수 : 괄호의 중요성
#define		MUL1(X)		((X) * (X))	// 괄호로 묶는것과 아닌것의 차이를 잘 알아야함! 
#define		MUL2(X)		X * X

// 메크로 함수 : 여러줄 함수
#define		FUNC(X)		cout << "1. "<< X<< endl;\
cout << "2. " << X << endl;\
cout << "3. " << X << endl;							//마지막줄은 역슬래쉬 생략가능
	/* 주의할 점!역슬래쉬 뒤에는 아무것도 없어야함! 공백도, 주석도 다 없어야함!
	   역슬래쉬뒤에있는 것까지 전부다 메크로 사용시 코드로들어가버림*/

// 조건부 컴파일 예시에 쓸 매크로들 
#define AAA 10



using namespace std;



int main() {
	// 파일 
	{
		FILE* pFile = nullptr;
		fopen_s(&pFile, "../Data/Test.txt", "wb");
		int iArr[5] = { 1,2,3,4,5 };
		fwrite(iArr, sizeof(int), sizeof(iArr) / sizeof(int), pFile);

		fseek(pFile, 0, SEEK_END);
	}

	// 메크로 함수 사용 
	{
		//메크로 함수의 코드는 단순 치환을 해주는거임! 
		int result1 = MUL1(2+2);	// 이거는 (2+2) * (2+2) 를 실행하는거고
		int result2 = MUL2(2+2);	// 이거는 2 + 2 * 2 + 2 를 실행해서, 연산지 우선순위땜에 => 2 + (2*2) + 2를 실행한다.

		cout << result1 << " / " << result2 << endl;

		FUNC("hello");
	}

	// 조건부 컴파일:  if, elif, else, endif
	{
		/* 당연하게도 이건 전처리기 단계에서 실행되기 때문에 프로그램 실행 후에 사용자가 뭔갈 입력한 값을 조건으로 걸 수 없고
		   그냥 선언한 일반 변수들도 쓸 수 없다. */
		int iData = 10;
#if iData>0	// 당연하게도.. 오류는 안남. 전처리기 단계에서 문제가 발생한거니까 컴파일에서 오류를 알수없다. 이거 그냥 "상수 메크로중에 iData는 없네.."하고 넘어가버림. 
		cout << "일반변수는 조건으로 못씀" << endl;
#endif
		
#if AAA > 0
		cout << "AAA는 0보다 크다." << endl;
#elif AAA < 0
		cout << "AAA는 0보다 작다." << endl;
#else
		cout << "AAA는 0입니다." << endl;
#endif
	}

	// 조건부 컴파일: ifdef, elif, else, endif
	{
#ifdef BBB
		cout << "BBB define되어있습니다." << endl;
#elif AAA
		cout << "AAA는 define되어있습니다." << endl;
#else
		cout << "AAA, BBB 모두 define 되어있지 않습니다." << endl;
#endif
	}

	// 조건부 컴파일: ifndef, elif, else, endif
	{
#ifndef BBB
		cout << "BBB define되어있지 않습니다." << endl;
#elif AAA
		cout << "AAA는 define되어있지 않습니다." << endl;
#else
		cout << "AAA, BBB 모두 define 되어있습니다." << endl;
#endif
	}

	{
		cout << endl;

	}
}