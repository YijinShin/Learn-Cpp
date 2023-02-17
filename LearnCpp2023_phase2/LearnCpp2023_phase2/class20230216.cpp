/*
- text rpg 상속으로 만들기 시연
	 - 구조체 안에 생성자 만들어서 baseinfo의 struct는 그렇게 함. 
	 - 전방선언 활용해보기 >> 바꿈!
--------------------------------------------------------------------------
상속의 종류 
A is a B / A has a B

- uml 기호체계 복습하기 (flow 차트 그릴떄이거 정확히 쓰기)
- uml기호중에 어떤 것을 사용할거시고, 왜 그걸 사용할것인지(업무할때)

- 일반화 <-> 구체화 
- 다중상속은 전세계적으로 거의 쓰지 않는 추세. 
- 왼만한 상속은 is a 를 위해서 쓴다. has a 는 #include 를 통해 구현하는 경우가 대부분이다. 
	앞으로 뭘 상속시키고, 뭘 #include로 할지 잘 고민해보자. 
-------------------------------------------------------------------------
객체 포인터와 정적 바인딩 

CParent*  = new CParent
CParent* = new CChild
이렇게 된다. 

정적바인딩 (정적 = 컴파일 타임) 즉, 이건 이미 컴파일 타임에 결정되어져있는 문법이다. 
바인딩 = 함수를 부를 때, 실제 함수가 있는 그 주소와 링크 시키는것. 
정적바인딩의 판단 조건은 선언된 자료형 

주소값이 누구꺼인지가 중요한게 아니라 "컴파일 타임"에서, 어떤 자료형의 맴버 함수인가가 중요한것이다. 
이게 동적할당이잖아 그러니까 컴파일 타임에는 선언된그 자료형만 아는거고, 이후에 런타임에 자녀가 들어와버린거잖아 
그러니까 기준은 선언된 자료형인것. 

--------------------------------------------------------------------------
다형성

형태가 여러개 있다는 뜻으로, 부모 클래스의 접근 권한이 여러개로 증가하는 문법을 말한다. 

다형성의 문법
- 오버라이딩
	- 부모, 자식 간의 상속 관계일 떄 성립
	- 부모와 자식 클래스의 완전히 동일한 형태의 함수가 있어야 가능
	- virsual 키워드를 사용해야한다. 
		- 가상함수를 클래스에 생성하면, 그 클래스안에는 가상함수 포인터와 가상함수 테이블이 생성됨. 
			이거때문에 클래스에서 원래 함수는 용량을 차지하지 않는데, 가상함수가 있으면 포인터 변수만큼의 용량을 차지하게됨
			- 가상함수 테이블이란?
			  virtual키워드 붙으면 코드 영역에 생성이된대... 
			  정적 바인딩과 동적바인딩 (정적바인딩은 data영역에서 끄집어오는거고, 버추얼함수는 가당테이블에 등록하고, 일반 맴버들은 가상테이블에 등록하지 않는다. 
				그럼 가상함수 테이블은 크기가 몇일까? => 가상함수 테이블은 최소 4바이트. (64비트면 8바이트.) 최대는 모름
				가상함수 테이블에 등록하는거는 함수의이름, 즉, 함수의 주소다. 
				어쨌는 가상함수가 늘어나면 테이블도 늘어나는데
				클래스의 용량은 가상 테이블은 고려 안하고 가상함수 포인터만! 포함해서 계산한다. 
				그래서 4바이트(8바이트)나오는것. 가상함수 포인터를 통해 -> 가상 테이블 접근해서 가상함수를 가져오는 것이다. 
				일반적인 맴버함수보다 가상 함수 호출속도가 더 느린것. (과정이 더 있으니까)

				가상함수자체를 만드는것은 단점처럼보일순있다(용량소비를 하니까. 가상함수 포인터와 테이블 / 그리고 느리다)
				그래도 쓰는 이유는 오버라이딩을 통해 해결하는 것이 더 많으니까 쓰는것이다.(이게 장점)

				참고로 부모의 가상함수를 자식이 오버라이딩해도, 그 함수도 가상함수임. 
				그럼 부모의 가상함수 하나를 자식이 오버라이딩하면 자식은 4*2라서 8인가?
				가상함수 포인터와 가상함수 테이블은 완전히 독립적이다. 오버라이딩을 했다고 해서 부모의 가상함수 포인터와 자식의 가상함수 포인터(테이블도 마찬가지)가 같지 않다. 
				자식의 가상함수 테이블에는 부모의 가상함수와 자기가 오버라이딩한 가상함수 모두 들어있다. 그래도 우선권은 내가오버라이딩한 함수에게 있다. 
				동적바인딩 = 프로그램 실행중에 바인딩하는것. (가상 테이블에서 가상함수 바인딩하는것)
				CParent* b = new CParent
				CParent* a = new CChild
				// 이때, a.가상함수를 호출하면 "동적바인딩"이되면서 parent가 아닌 child의 오버라이딩 된 가상함수가 호출된다. 
				이게 정적바인딩과의 차이인거야

				오버라이딩 -> 재정의 기능이 있고, "은닉화"의 개념도 가지고 있다.
				CChild b;
				CParent* a = &b
				// 이래도 child의 가상함수를 호출하게됨

			

- 캐스팅



*/

#include "stdafx.h"
using namespace std;


/* 가상함수 사용하는 부모-자식 */
class CParent_virtual {
public:
	virtual ~CParent_virtual() { cout << "부모 소멸자" << endl; }
	virtual void Display() { cout << "부모 Display()" << endl; }
};

class CChild_virtual: public CParent_virtual {
public:
	~CChild_virtual() { cout << "자식 소멸자" << endl; }
	void Display() { cout << "자녀 Display()" << endl; }
};

/* 가상함수 안쓰는 부모-자식 */
class CParent_nonVirtual {
public:
	~CParent_nonVirtual() { cout << "부모 소멸자" << endl; }
	void Display() { cout << "부모 Display()" << endl; }
};

class CChild_nonVirtual : public CParent_nonVirtual {
public:
	~CChild_nonVirtual() { cout << "자녀 소멸자" << endl; }
	void Display() { cout << "자녀 Display()" << endl; }
};

int main() {
	/* 가상함수 사용하는 부모-자식*/
		{
			// 소멸자와 일반 맴버 함수가 정적 바인딩되었을 때
				/* 정적 할당 => 정적 바인딩만 발생함. */
				CParent_virtual pv1;	// 부모 소멸자
				CChild_virtual cv1;	// 자녀 소멸자 -> 부모 소멸자

				pv1.Display();						// 부모 함수	
				cv1.Display();						// 자녀 함수 
				cv1.CParent_virtual::Display();		// 부모 함수 

				/* 동적 할당 => virtual 함수 말고는 정적 바인딩 */
				CParent_virtual* pv2 = new CParent_virtual;
				CChild_virtual* cv2 = new CChild_virtual;
				CParent_virtual* cross2 = new CChild_virtual;

				pv2->Display();		//부모 함수 
				cv2->Display();		//자녀 함수		<<<<<<<<<<<<<<<<<<<<<<< 이게 정적 바인딩과의 차이
				cross2->Display();	//자녀 함수 

				delete pv2;		// 부모 소멸자 only
				delete cv2;		// 자녀 소멸자 -> 부모 소멸자
				delete cross2;	// 자녀 소멸자 -> 부모 소멸자		<<<<<<<<<<<<<<<<<<<<<<< 이게 정적 바인딩과의 차이
				cout << endl;
		}

	/* 가상함수 사용안하는 부모-자식 (정적 바인딩 확인하기 ) */
		{
			// 소멸자와 일반 맴버 함수가 정적 바인딩되었을 때
				/* 정적 할당 => 정적 바인딩만 발생함.  */
				CParent_nonVirtual pv1;	// 부모 소멸자
				CChild_nonVirtual cv1;	// 자녀 소멸자 -> 부모 소멸자

				pv1.Display();						// 부모 함수 
				cv1.Display();						// 자녀 함수 
				cv1.CParent_nonVirtual::Display();	//부모 함수 
		
				/* 동적 할당 => virtual 함수 말고는 정적 바인딩 */
				CParent_nonVirtual* pv2 = new CParent_nonVirtual;
				CChild_nonVirtual* cv2 = new CChild_nonVirtual;
				CParent_nonVirtual* cross2 = new CChild_nonVirtual;

				pv2->Display();		//부모 함수 
				cv2->Display();		//자녀 함수 
				cross2->Display();	//부모 함수 	<<<<<<<<<<<<<<<<<<<<<<< 이게 동적 바인딩과의 차이
		
				delete pv2;		// 부모 소멸자 only
				delete cv2;		// 자녀 소멸자 -> 부모 소멸자
				delete cross2;	// 부모 소멸자 only		<<<<<<<<<<<<<<<<<<<<<<< 이게 동적 바인딩과의 차이
				cout << endl;
		}
		
}