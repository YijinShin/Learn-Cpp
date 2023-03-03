/*
[array]
stl 컨테이너
stl에서 제공하는 배열 

대입이 가능함.
기존 배열은 배열 전체를 옮기려면 memcpy를 써야했잖아. 근데 그냥 = 로 대입 가능 

.data()	= array의 첫번째 주소. 
기존 배열은 배열의 이름이 그냥 첫번째 주소였음. stl array는 .data를 통해서 가져올수있음. 

.fill(999);	//	모든 원소들의 값을 999로 초기화. 

iterator가 당연히 있다. 양반향 반복자인듯 

얘는 정적배열이라 중간삽입이 안된다. 정적배열이라 하나를중간에 넣고, 그 뒤 애들을 뒤로 미는게 불가능하다.
마찬가지로 erase도 안된다.(중간 삭제) 정적배열이라 애들을 앞으로 당길 수 없다. 
------------------------------------------------------------------

[c++11 문법]

* 람다식
	람다식이란 
		- stl알고리즘의 조건자를 생성하는 방식으로 함수 객체의 단점을 보완하기 위해 등장

	함수 객체의 단점
		- 작성이 용이하지 못하고 
		- 일반함수와의 구분이 어렵다.
		- 함수 객체는 결국 객체다. 생성자 호출, 소멸자 호출이 다 발생한다. (함수 객체가 함수 포인터로 동작시키는것보다는 빠름. )
			람다식은 엄연히 말하면 인라인함수같은거라 객체 생성,소멸비용은 줄일수있다.람다식은 치환으로 동작함.

	람다식 문법
		[] : 람다 소개자. 컴파일러가 얘를 보고 람다식이라는 것을 인지
		() : 파라니머 지정자. 일반 함수의 매개변수와 같은 의미
		{} : 람다 몸체. 함수 몸체와 같은 의미

		[](){cout << " hello world";}	//이렇게 하면 람다 식을 만든거고, 함수로 호추출하려면 함수 호출 연산자 ()를 붙이면됨
		[](){cout << " hello world";}();	//이렇게하면쓰여짐

		밑에 조건자로 람다식 쓸때는 끝에 ()안붙이잖아. 
		그건 인라인함수..?함수 포인터..?로 쓴거래. 함수 포인터아니고 인라인함수 말하는듯..? 제대로 못들음

		반환타입은 묵시적으로도 가능. 그러나 명시적으로 할수있음 하는게 좋음. 
		-> 로 반환타입 명시적으로 지정가능
		[]()->int {}	//이렇게

		람다 소개자[] 를 다른말로 캡처절이라고도 부른다. 
		이 캡처절을 통해 외부데이터를 참조할 수 있다. 

		int iEvenSum(0);
		int iOddSum(0);
		for_each(vec.begin(), vec.end(), [iEvenSum, iOddSum](int n) {	// iEvenSum, iOddSum을 캡쳐하겠다는 말임.
				if (0 == n % 2) iEvenSum += n;
				else iOddSum += n;
		});	
		이렇게 캡처절에 넣으면 그냥 값복사를 해버림. 그래서 쓰기를하면 오류가남. 
		const로 변환되서 그러는데 그래서 mutable을 쓰면 쓸때 오류는 안남. 
		그러나 실제 iEvenSum, iOddSum의 원본에 써지지 않음. 

		그래서 &로 가져와야하는거다. 
		int iEvenSum(0);
		int iOddSum(0);
		for_each(vec.begin(), vec.end(), [&](int n) {	
				if (0 == n % 2) iEvenSum += n;
				else iOddSum += n;
		});
		이렇게 해야 원본값에 직접 쓰는게 됨. 

		이거 캡처절안에 들어갈수있는것과 없는게 잇음. (첨부 사진 참고) 
		[] : 아무것도 캡처 안함
		[&x]: 외부 변수중에 x라는 이름의 변수만 레퍼로 캡처 .. 
		... 

		static, 전역, class의 맴버 변수는 캡처가 불가능. 
		람다식은 인라인함수기 때문에 

		근데 람다식에서 맴버 변수를 캡처하려면, 일단 지역변수를 만들어서, 걔가 맴버 변수 값을 가지게 하고, 그 만들어놓은 지역변수를 람다가 참조하게 하기 


R-value레퍼런스
	원래 레퍼런스는 l-value만 참조가 가능하다.
	int& iref = 10;이건안된다고. 

	근데 정하고싶으면 const를 붙여서 읽기 전용 레퍼런스를 쓰면 가능함. 
	const int& r2 = 10;	
	대신 참조값에 쓸 수는 없다. r2 = 20;	이런건 말이 안됨
	이걸 어따쓰냐 => 이동생성자에서 씀 


이동생성자 
	밑에 있음

decltype
	auto를 대신할수있는 문법

	int x = 10;
	decltype(x) y = x;		//알아서 int로 인식함. 
		
	tag t;
	decltype(t.memver)	Test = 3.14; // 알아서 double로 인식함
	cout << Test<<endl;

	...근데 뭐.. auto쓰지 뭐 
	
*/

#include "stdafx.h"
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

void Swap(int& a, int& b) {
	int itemp = a;
	a = b;
	b = itemp;
}

class CTest {
public:
	CTest() :m_pArray(nullptr), m_iSize(0) {}
	CTest(int a) : m_pArray(new int[m_iSize]), m_iSize(a) {}
	CTest(const CTest& _t) {
		// 깊은 복사 하는 복사 생성자
	}

	// 이동생성자
	CTest(CTest&& rvr) {
		m_pArray = rvr.m_pArray;
		m_iSize = rvr.m_iSize;
		rvr.m_pArray = nullptr;	// 원본은 nullptr로 만들어버림. 원본 객체의 주소는 사용이 불가능하게 됨. 
								// 이걸 "이동 후, 소유권 이전"을 했다고 함. 
								// 이게 복사생성자와의 차이임
		// (면접) 이동생성자의 개념 설명하라. 
	}

	~CTest() {
		if (m_pArray) {
			delete m_pArray;
			m_pArray = nullptr;
		}
	}



private:
	int* m_pArray;
	int m_iSize;
};

int main() {
	
	/* Array */
	{
		int iArray[5] = { 1,2,3,4,5 };
		array<int, 5> arrEx = { 1,2,3 };
		array<int, 5> arrEx2 = arrEx;

		auto iter = arrEx.begin();
		iter += 2;

	}

	/* 람다식 */
	{
		vector<int> vec{ 10,20,30,40,50 };

		for_each(vec.begin(), vec.end(), [](int n) {cout << n << ","; });	//이게 조건자로 람다식을 넣은 것. 
		cout << endl;

		//for_each(vec.begin(), vec.end(), [](int n)->bool {return (n%2!=0) });	//이게 조건자로 람다식을 넣은 것. 

		int iEvenSum(0);
		int iOddSum(0);
		for_each(vec.begin(), vec.end(), [&](int n) {	// iEvenSum, iOddSum을 캡쳐하겠다는 말임. 
														/*	여기서 &가 없으면 에러가 나는데 
															iEvenSum, iOddSum은
															
														*/
			if (0 == n % 2) iEvenSum += n;
			else iOddSum += n;
		});	//이게 조건자로 람다식을 넣은 것. 
		cout << iEvenSum << ", " << iOddSum << endl;
		
		[](int i) {cout << i<<" hello world"<<endl; }(10);

		[](int i = 100) {cout << i << " hello world" << endl; }();	//디폴트 매개변수 가능 

		int iResult = [](int a, int b) {return a + b; }(10, 20);	// 리턴값 지정안해줘도 묵시적으로 컴파일러가 판단함. 근데 명시적으로하는게 보기도 좋고, 효율도 좋음. 
		cout << iResult << endl;
	}
	
	/* R - value 레퍼런스 */
	{
		int iA(10), iB(20);

		cout << iB << ", " << iA << endl;
		Swap(iA, iB);
		cout << iA << ", " << iB << endl;

		//Swap(10, 20);	//이건 안됨. r-value는 레퍼타입에 넣을 수없으니까.  

		// r-vlaue레퍼런스 
		int& r = iA;
		int&& rR = 999;	// r-value가 참조 가능 
		//int&& rR = iA // 대신 l-value는 참조 불가능 
		rR = iB;	//l-value를 대입도 가능 
		
	}

	/* 이동 생성자  */
	{
		// 깊은 복사 생성자 만들었다고 가정하자.. 
		CTest t(4);
		CTest temp(t);

		CTest t2(100000000);	// 동적배열이 100000000이만큼 생김
		CTest t3(t2);			// 이거 객체 생성하는데 시간이 얼마나 걸리냐 => 0.156sec 정도 나옴. 이거 되게 오래걸리는거임. 

		// 이렇게 복사해서 사는게 아니라 원본을 그대로 이동시키는 생성을하겠다는거임. 
	
		// 이동생성자 호출
		CTest MoveCon(std::move(t2));	//이동생성자 쓸려면 move()라는 함수 호출해야함. 
										// move(): 매개변수로 전달받은 대상을 R-value 레퍼런스로 캐스팅하는 함수 
										// 이렇게 해야지 이동생성자 호출이 가능해짐 
										// 이렇게 생성하는게 위에 t3복사 생성자불러서 생성하는것보다 훨씬 아주 많이 적은시간이 든다. 

		/* 백터가 클래스(포인터가 아닌) 를 가진다고 해. vec.push_back(CTest(10000000))이런식으로. 
		* 이게 과거에는 CTest(1000000000)를 임시객체로 만들고 -> 그걸 다시 복사함. 
		* 그러니까 1000000만큼 생성도하고, 그걸 복사까지 다 함. 
		* 그리고 10000000를 또 해제함. (임시객체니까 이 명령줄 긑나면 끝) 
		이게 엄청 오래걸림. 근데 이동생성자로 하니까 
		일단 복사가 일어나지 않고, 원본을 해제할 필요도 없는거임. 원본자체를 다 옮겨 넣은거니까 원본을 해제하면안되는거임. 
		엄청 시간이 줄어든다. 

		복사를 꼭 해야하는게 아니면 이동생성자 쓰는게 좋다. 

		*/
	}
}