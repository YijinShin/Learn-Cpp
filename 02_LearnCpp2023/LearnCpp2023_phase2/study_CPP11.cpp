/* [ C++11부터 나온 문법들 ] 

- auto 키워드
- 범위 기반 for문 
- 유니폼 초기화
	유니폼 초기화 ({} 를 이용한 생성자 호출) 를 통해서 인자 없는 생성자가 함수의 정의로 오해되는 일을 막을 수 있으며 
	initializer_list 를 만들어 전달할 수 있습니다. 
	initializer_list 를 통해서 객체를 간단하게 생성할 수 있습니다.

- 람다식 
	stl알고리즘의 조건자를 생성하는 방식. 
	함수 객체의 단점을 보완하기 위해 등장했다. 

	함수 객체의 단점
		- 일반함수와 구분이 힘들고
		- 함수 객체는 어쨌든 객체다. 
		  소멸자, 생성자 호출이 다 발생한다. 
		  물론 조건자로 함수 포인터(일반함수를)를 사용하는 것 보다는 함수 객체를 &로 받는게 더 빠르다.
		  그러나 그 함수 객체를 조건자로 쓰는것 보다 람다식을 쓰는게 더 빠르다. (람다식은 일종의 인라인 함수이기떄문) 

	람다식 쓰는 이유 : 함수 객체를 조건자로 쓰는 것 보다 빠르다. 

	람다식 문법
		[]: 람다 소개자(캡처절)	컴파일러가 얘를 보고 람다식이라고 인지함
								외부 데이터를 참조할 수 있도록 해준다. 
		(): 파라미터 지정자		일반 함수의 매개변수와 같은 의미
		->: 반환타입				반환 타입을 지정함. 안쓰면 컴파일러가 알아서 묵시적 형변환해줌. 그러나 언제나 명시적인게 묵시적인 것 보다는 좋음. 
		{}: 람다 몸체			일반 함수의 몸체 

		[](){ cout << "hello world"<<endl; }	// 이게 람다식을 만든 것. 
		[](){ cout << "hello world"<<endl; }();	// 이게 람다식을 만들고, 호출한 것.

		// 반환타입이 있는 람다식
		[](int i)->bool{ if(i == 0) return false;}	

		// 외부 데이터 참조 + 반환타입도 있는 람다식 
		int iSrc(0);
		[&](int iData)->bool { if(iData==0) {iSrc++; return true;}
								  else { iSrc--; return false;}     }();

		외부 데이터 참조(캡처)는 안되는 것들도 있다. 
			- 대표적인게 static, 전역, class의 맴버 변수 

- R-value reference
	원래 R-value는 레퍼런스 타입 저장이 안된다. 
		ex_ int& iRef = 10;
	근데 꼭 하고싶다면 다음과 같은 타입을 쓸 수 있다. 
		- const &
		- &&	(이게 우리가 말하는 R-value 레퍼런스)

- 이동 생성자 
	이동 생성자는 생성자인데 param으로 &&를 받음. 
	복사 생성자가 -> A를 생성하기 위해 B의 데이터를 그대로 복사 해서 생성 이면
	이동 생성자는 -> A를 생성하기 위해 B의 데이터를 그대로 옮겨오고, B는 없앰이다. 

*/

#include "stdafx.h"
#include <vector>
#include <list>
using namespace std;

class CTest {
public:
	CTest() { cout << "CTest생성자" << endl; };
};

class CTest2 {
public:
	CTest2() { cout << "인자가 없는 생성자" << endl; }
	CTest2(int _i, double _d) { cout << "int, double을 받는 생성자 " << endl; }
	CTest2(std::initializer_list<int> _list) { cout << "list<int>를 받는 생성자 " << endl; }
};

class CTest3 {
private:
	int m_iId;
	char* m_szName;
public:
	CTest3(const char* _szName){
		int iSize = strlen(_szName)+1;
		m_szName = new char(iSize);
		strcpy_s(m_szName, iSize, _szName);
	}
	// 복사 생성자 (깊은 복사)
	CTest3(const CTest3& rhs) {
		cout << "깊은 복사 생성자 호출 " << endl;
		int iSize = strlen(rhs.m_szName) + 1;
		m_szName = new char(iSize);
		strcpy_s(m_szName, iSize, rhs.m_szName);
	}
	// 이동 생성자 
	CTest3(CTest3&& rvr) {
		cout << "이동 생성자 호출 " << endl;
		m_szName = rvr.m_szName;
		rvr.m_szName = nullptr;	// delete는 하면안됨!! 그 할당받은 heap을 그대로 생성되는 애한테 이전시키는 것임!
	}
	~CTest3() {
		cout << m_iId << "의 소멸자 호출" << endl;
		if(m_szName){
			cout << m_iId << "의 m_szName 삭제" << endl;
			delete[] m_szName;
			m_szName = nullptr;
		}
	}

	void Rander() { cout << m_szName << endl; }
	char* GetName() { return m_szName; }
	void SetId(int _iId) { m_iId = _iId; }
};


int main() {

	/* auto 키워드 */
	{
		cout << "[ auto ]" << endl;
		vector<int> vec(5, 2);

		vector<int>::iterator iter = vec.begin();

		auto iter2 = vec.begin();	// 타입을 컴파일러가 알아서 처리해준다. 
	}

	/* 범위 기반 for문 */
	{
		cout <<"\n\n[범위 기반 for문]" << endl;
		int iArray[]{1,2,3,4,5};
		for (int i : iArray) cout << iArray[i] << ", ";	
		cout << endl;

		vector<int> vec{ 1,2,3,4,5 };
		//for (auto i : vec) cout << vec[i] << ",";
		cout << endl;
	}

	/* 유니폼 초기화 */
	{
		cout << "\n\n[ 유니폼 초기화 ]" << endl;
		// {}로 인자 없는 생성자 호출하기
		CTest ct{};

		// {}가 컴파일되는 경우의수 
		CTest2 t1{};
		CTest2 t2(10, 10.4);
		//CTest2 t3{ 10, 10.4 };	// initializer_list를 인자로 받는 생성자가 있고, initializer_list의 타입이 int라서 초기화 리스트로 인식됨.
									// 근데 {}는 부동소수점타입 <-> 정수 타입간의 암시적 형변환을 막기 때문에 에러가 남. 
									// (int, double) 생성자를 부르려면 1. initializer_list의 타입을 아예 string이렇게 바꿔버리거나(암시적 변환이 아예 안되는 타입으로) 
									//								  2. initializer_list 를 인자로 가지는 생성자를 없애면됨. 
	}

	/* 람다식 */
	{
		cout << "\n\n[ 람다식 ]" << endl;

		// 람다식 호출 
		[](){cout << "hello world" << endl; }();

		// 파라미터, 리턴값 있는 람다식 호출
		if ([](int iData)->bool { if (iData % 2 == 0) return true; else return false; }(10)) cout << "Even" << endl;
		else cout << "Odd" << endl;

		// 외부 데이터 참조하는 람다식 (&로 해야 참조가된다.)
		{
			int iEvenCnt(0);
			int iArray[] = { 1,2,3,4,5 };
			for (int i : iArray) [&iEvenCnt](int iData) {if (iData % 2 == 0) iEvenCnt++; }(iArray[i]);
				// 그냥 &만 해줘도된다. 변수 이름 안쓰고 
				//for (int i : iArray) [&](int iData) {if (iData % 2 == 0) iEvenCnt++; }(iArray[i]);
			cout << "Even number cnt: " << iEvenCnt << endl;
		}
		// 외부 데이터를 잘못 참조하는 경우 1
		{
			int iEvenCnt(0);
			int iArray[] = { 1,2,3,4,5 };
			// 이렇게 외부 변수를 그대로 쓰면 함수에 const가 자동으로 붙어서 쓰기가 불가능하다. (읽기는 가능)
			//for (int i : iArray) [iEvenCnt](int iData) {if (iData % 2 == 0) iEvenCnt++; }(iArray[i]);
			cout << "Even number cnt: " << iEvenCnt << endl;
		}
		// 외부 데이터를 잘못 참조하는 경우 2
		{
			int iEvenCnt(0);
			int iArray[] = { 1,2,3,4,5 };
			// const 함수가 되어버리니까 mutable키워드로 람다식을 만들면 => 쓸 수는 있게 된다. 
			// 그러나 애초에 외부 변수를 값복사 해서 가져온 것이기 때문에 람다식에서 써봤자 원본 데이터가 변하지 않는다. 
			for (int i : iArray) [iEvenCnt](int iData)mutable {if (iData % 2 == 0) iEvenCnt++; }(iArray[i]);
			cout << "Even number cnt: " << iEvenCnt << endl;
		}
	}

	/* R-value 레퍼런스 */
	{
		int iData(10);
		
		/* && */
		//int&& iR_ref1 = iData;	// l-value 참조 불가 
		int&& iR_ref2 = 10;			// r-value 참조 가능 
		iR_ref2 = iData;			// l-vlaue 대입 가능
		iR_ref2 = 20;				// r-value 대입 가능 
		
		/* const & */
		const int& i_Const_ref1 = iData;	// l-value 참조 가능 
		const int& i_Const_ref2 = 10;		// r-value 참조 가능 
		// i_Const_ref1 = iData;			// const라 값 변경 불가능
		// i_Const_ref2 = iData;			// const라 값 변경 불가능
		// i_Const_ref1 = 20;				// const라 값 변경 불가능
		// i_Const_ref2 = 20;				// const라 값 변경 불가능

		/* 참고로 & const는 아예 다른 이야기임. 
			정확히는 모르겠는게 그냥 일반 &와 거의 같음. */
		int& const i_Ref_const1 = iData;
		//int& const i_Ref_const2 = 10;
		i_Ref_const1 = 20;	
	}

	/* 이동 생성자 */
	{
		CTest3 t1("hello");
		t1.SetId(1);
	
		// 복사 생성자 
		cout << "* 복사생성자 후 * " << endl;
		CTest3 t2(t1);
		t2.SetId(2);
		cout << "t1: "; t1.Rander();
		cout << "t2: "; t2.Rander();

		// 이동 생성자 
		cout << "* 이동생성자 후 * " << endl;
		CTest3 t3(std::move(t1));
		t3.SetId(3);
		cout << "t1: "; if (t1.GetName() != nullptr) t1.Rander(); else cout << "nullptr" << endl;
		cout << "t2: "; t2.Rander();
		cout << "t3: "; t3.Rander();

		// ERROR: 이거 t3을 제일 먼저 소멸시키는데 소멸할때 에러나거든? 이유는 정확히 모르겠는데 아마 메모리 할당할때 문제가 있는 것 같음. 
		//		  study_이동생성자.cpp에서 char*가 아니라 int*로 똑같이 구현한게 있는데, 그거는 아무 문제 없이 잘 돌아감
	}
}