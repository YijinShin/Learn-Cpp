/*
과제 피드백
이제 캐스팅 연산자배웠으니까 Player쓸때 다운캐스팅해서 씀 
item 클래스 따로 나누기 

-----------------------------------------------------------------------------------------
[const cast]

-포인터 또는 레퍼런스 자료형인 경우의 const만 제거가 가능. 
애초에 포인터에 const붙어있으면 읽기 전용 포인터인데, 너무 급하게.. 거기에 써야하는 일이 발생한다면
이걸 쓰는거임. 
- 상속관련된 그런조건은 없음. 애초에 그럴때 쓰는것도아니고

[ reinterpret_cast]

-이거 쓰는걸 c++은 싫어함. 
- const 포인터를 제외한 모든 포인터의형 변환을 허용함. 
- 핵심은 포인터 형의 형변환을 할때 쓰는거임. 근데 const붙어있으면 안되는.
- 논리적으로 맞지 않는 형변환이라도 허용하는것이 이새끼의 특징
- 왠만하면 안쓰는게 좋음. 

cast중에서 제일 중요한 내용은 static cast와 dynamic cast 차이임(면접)
-----------------------------------------------------------------------------------------
함수메크로는 "함수"는 아니다. 그냥 생김세가 함수처럼 생겨서 그렇게 말하는거고. 
[인라인 함수]
inline int func(int i){return i*i}	//이건 선언과 동시에 정의부까지 다 만들어주는거임. 따로 안나누고
옛날에는 인라인 키워드를 붙이나 안붙이나 최대 8줄까지는 컴파일러가 알아서 인라인화 해줬는데 지금은 더 기능이 좋아짐. 
이건 장점이 빨라 
대신 난발하면 은닉화, 캡슐화가 제대로 안이뤄질수있음. 

인라인함수가 일반함수로 바뀌는 경우
- 일반적인 함수는 메모리 공간에 바이너리 코드가 등록되어있으면, 그걸 호출하는거고
인라인은 그 즉시 생성+동작하게되는데, 
이게 어떤 경우에 일케 바뀌는가

1. 인라인 함수를 함수 포인터를 이용하여 활용할때 
	(인라인 함수 주소를 함수 포인터에 저장하려는 순간 인라인화가 풀림. 당연함. 주소라는걸 불러오려면 메모리공간에 저장된 주소가 있어야하니까/
2. 인라인 함수를 재귀 형태로 호출하고자 할때 
	stack 메모리와 가장 밀접한것이 함수인데, 

어쨌든 전반적으로 인라인함수는 컴파일러가 그렇게 해버리지 않으면 별수없기때문에 프로그래머의 권한이 절대적이지는 않지만..
그래도 인라인으로 의도하고 만들려면 인라인 키워드 꼭 붙이고, 선언+정의 같이 붙여서 구현하기
-------------------------------------------------------------------------------------
[연산자 오버로딩]
함수 오버로딩의 규칙을 연산자에 적용한 문법
연산자 오버로딩은 좌측 객체 기준으로 수행 10+class면 10이 상수니까 상수의 +가 실행되는거임

클래스 맴버로만 연산자 오버로딩이 가능한 것들: =, (), [], ->
	이 연산자들은 좌측 기주능로만 연산자 오버로딩을 수행하는 경우이다.

과제 - 이거 3개 연산자 오버라이딩으로 만들어오기
문자열 복사	strcpt(=)
문자열 결함	strcat(+)
문자열 비교	strcmp(==)

*/

#include "stdafx.h"
using namespace std;

class CTest {
public:
	void Dispaly() { cout << "Test" << endl; }
};
class CParent {
public:
	void Dispaly() { cout << "Parent" << endl; }
};
class CChild : public CParent {
public:
	void Dispaly() { cout << "Child" << endl; }
};


int main() {
	//const_cast
	{
		// example 1
		{
			const int iSrc = 20;	// 당연한 이야기지만 const가 int에 붙어버리면 무조건 못바꿈. 
			
			int iData = 10;
			const int* iPtr = &iData;

			//*iPtr = 10;	// ERROR
			int* iPtrCast = const_cast<int*>(iPtr);
			*iPtrCast = 20;

			cout << iData << endl;
		}
		// example 2
		{
			int iData = 10;
			const int& iRef = iData;
			//iRef = 20; // ERROR
			int* iPtr = const_cast<int*>(&iRef);
			*iPtr = 20;
			cout << iData << endl;
		}
	}

	// reinterpret_cast
	{
		// 정수형을 포인터로 캐스팅 => 가능
			// 이거는 정수를 주소값으로 인식해버려서 가능한 것 같다. 
		{
			int iData = 10;
			int* iPtr = reinterpret_cast<int*>(iData);	// iPtr에 &iData가 들어가는게 아니라, 진짜 주소값이 10이라는 뜻으로 들어간다. 
			int* iPtr2 = reinterpret_cast<int*>(10);
			int* iPtr3 = reinterpret_cast<int*>('a');

			cout <<"(int)iData: " << iData << " / (int*)iPtr: " << iPtr << endl;	// 10, : 000000000000000A (10의 16진수형태, 주소값 형태)
		}
		// 정수형이 아닌 다른 타입을 포인터로 캐스팅 => 아예 불가능
		{
			float fData = 10.f;
			//int* iPtr = reinterpret_cast<int*>(fData);	
		}

		// 포인터를 포인터로 캐스팅 => 전부 가능 
		{
			CTest* t = new CTest;
			int* iPtr = reinterpret_cast<int*>(t);	// 이딴것도됨

			CTest t1;
			CParent* p = reinterpret_cast<CParent*>(&t1);	// 상속아니어도됨

			char a = 'a';
			float* fPtr = reinterpret_cast<float*>(&a);	//이상한것도 됨
		}
	}
}