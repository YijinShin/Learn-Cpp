/*
연산자 오버로딩 part2

topic: ++, -- 오버로딩(전위, 후위 전부) 
(만들어보기!) 보통 복사하고, 거기에 ++해서 반환하는식임. 

stl에서는 stl컨테이너가 사용할 수 잇는 알고리즘이라는것을 지원한다. 
이때 어떤 알고리즘을 실행시킬지, 알고리즘을 어떤 형식으로 실행할지 
조건자(반환타입이 bool이면서 ..)

---------------------------------------------------------------------------------
함수 객체 : ()연산자를 오버로딩하여 객체를 함수처럼 쓰도록 만드는 문법

int Add(int a, int b){return a+b;}	//이렇게 하면 함수 

class CPlus{
public:
	int operator()(int a, int b){return a+b;}
	int operator()(int a, int b){return a+b;}
}

int main(){
	cout << Add(10,20)<<endl;
	CPlus plus;
	cout << plus(20,30)<<endl;	// 이렇게 객체를 함수처럼 쓰는게 함수 객체
}
함수 객체 쓰는 이유 = 알고리즘에서 조건자로서 사용하기 위해 
장점 : 함수 객체는 같은 호출 문장이라도 실체 어떤 객체냐에 따라 각기 다른 상태를 지니게 해주는 이점이 있다. 
클래스 선언부에 맴버 함수의 몸체까지 정의되어 있다면 자동으로 inline화가 적용되어 일반 함수 호출속도에 비해 빠르다. 


---------------------------------------------------------------------------------
------------------------------------------------------------------------------
임시 객체
int iNumber = 1+2;   // 이 코드는 총 12바이트를 소비함. iNumber 4, 1=4 ,2=4 합쳐서 12.
객체도 이런 임시 메모리 공간을 순간적을 사용할수 있다.

class Cobj{
public:
   Cobj(char* pString){
	  strcpy_s(m_szString, sizeof(m_szString), pString);
	  out << m_szString<<"생성자"<<endl;
   }
   ~Cobj(){
	  out << m_szString<<"소멸자"<<endl;
   }
private:
   char m_szString;
}

Cobj obj("일반객체);      // 일반 객체 생성
Cobj("임시객체");      // 임시 객체 생성

이렇게 하면 결과가
   일반 객체 생성자
   임시 객체 생성자
   임시 객체 소멸자
   일반 객체 소멸자
이렇게 나옴.
이건 임시 메모리 특성이 그즉시 생성, 소멸이라서 그렇다.
아까 연산자 오버로딩을 해서 (함수객체)조건자를 만들었는데, 실질적으로 활용할떄 임시객체로 호출할수도있다는거임.
*/

#include "stdafx.h"
using namespace std;

class CSortRule {
public:
	virtual bool operator()(int _iA, int _iB) const = 0;
	//virtual bool operator()(int _iA, int _iB) const { return true; };
};

// 오름차순 
class CAsendingSort :public CSortRule {
public:
	virtual bool operator()(int _iA, int _iB) const {
		if (_iA > _iB) return true;
		else return false;
	}
};

class CDesendingSort :public CSortRule {
public:
	virtual bool operator()(int _iA, int _iB) const {
		if (_iA < _iB) return true;
		else return false;
	}
};

void Bubble_sort_functor(int iArray[], int iSize, const CSortRule& Functor) {	//정렬의 조건이 오름차순, 내림차순이 있을 수 있음. 
	for (int i = 0; i < iSize; i++) {
		for (int j = 0; j < iSize-1; j++) {
			if (Functor(iArray[j], iArray[j + 1])) {
				int iTemp = iArray[j];
				iArray[j] = iArray[j+1];
				iArray[j + 1] = iTemp;
			}
		}
	}
	for (int i = 0; i < iSize; i++) cout << iArray[i] << ",";
	cout << endl;
}

bool DesendingSort(int _iA, int _iB) {
	if (_iA <= _iB) return true;
	else return false;
}


void Bubble_sort_function(int iArray[], int iSize, bool(*DesendingSort)(int _iA, int _iB)) {	//정렬의 조건이 오름차순, 내림차순이 있을 수 있음. 
	for (int i = 0; i < iSize; i++) {
		for (int j = 0; j < iSize - 1; j++) {
			if (DesendingSort(iArray[j], iArray[j + 1])) {
				int iTemp = iArray[j];
				iArray[j] = iArray[j+1];
				iArray[j+1] = iTemp;
			}
		}
	}
	for (int i = 0; i < iSize; i++) cout << iArray[i] << ",";
	cout << endl;
}

int main() {
	int iArray[5] = { 1,4,3,6,7 };

	// 조건자로 일반 함수 사용
	{
		Bubble_sort_function(iArray, sizeof(iArray) / sizeof(int), DesendingSort);
	}

	// 조건자로 함수 객체 사용 
	{
		// 그냥 함수 객체사용
		CAsendingSort Asend;
		CDesendingSort Dsend;
		Bubble_sort_functor(iArray, sizeof(iArray) / sizeof(int), Asend);	// 오름차순으로 하겠다. 

		// 임시 객체 사용 
		Bubble_sort_functor(iArray, sizeof(iArray) / sizeof(int), CDesendingSort()); // 근데 이것도 캐스팅인가? 매개변수는 부모의 레퍼로 되어있는데 자녀임시 객체를 넘겨주잖아. 
			// 이렇게 조건자(함수 객체)를 그냥 임시 객체로 부르기도함. 
			// 어차피 이건 우리가 조건자로서의 객체를 원하는거지 이걸 객채 생성해서 뭘 쓰겠다는게 아니기 떄문이다. 
	}
}
	

// 지금 예시에서는 함수 객체를 상속한 형태로 보여줘서 가상함수를 쓰긴했는데 보통 조건자로 쓰는 함수 객체는 상속형태로 구현하는 일이 많이 없다. 
// 조건자로 쓰는 함수들은 거의다 인라인되도록 구현해서 속도에서 이득을 보겠다는 편인데 가상함수를 써버리면 인라인이 안되기 때문이다. 