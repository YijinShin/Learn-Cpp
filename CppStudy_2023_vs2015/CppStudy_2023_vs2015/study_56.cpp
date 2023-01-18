/* 
Topic: 정적 맴버 / 상수 맴버

*주의 : static 맴버 변수 와 다르게 static변수는 외부 연결 차단됨!

----------------------------------------------------------------------------------------------

* static 변수
	- 외부 연결 차단됨
	- 전역 static변수
		- 해당 파일내의 모든 함수가 접근 가능
	- 로컬 static 변수
		- 해당 파일내의 해당 함수안에서만 접근 가능


* static 맴버 변수
	- 외부 연결을 가진다. 
		- private static인 경우
			- 모든 파일에 있는 , 해당 클래스 맴버 함수나, 프랜드 함수, 프랜드 클래스의 맴버 함수가 접근 할 수 있음
		- public static인 경우
			- 모든 파일에 있는, 누구나 접근 가능. 
	- 해당 클래스의 모든 객체가 공유함. 

* static 맴버 함수 
	- 해당 클래스 객체를 생성하지 않아도, 클래스 이름만으로 호출
	- this포인터 가지지 않음 ( 객체 생성을 안해도 쓸수있으니까 this랄게 없음)
	- 정적 맴버 변수만 사용할 수 있음 ( 함수의 정의 안에 ) 

----------------------------------------------------------------------------------------------

* constant 맴버 변수
	- 선언할때 초기화 시키잖아 -> 그 뒤로 값 못바꿈

* constant 맴버 함수
	-  호출한 객체의 데이터를 변경할 수 없는 멤버 함수
*/

#include <iostream>


using namespace std;


int world_v(10);							// 전역 변수					-> 외부연결(O) / 프로그램 종료시 소멸
static int world_static_v(11);				// 전역, 정적 변수			-> 외부연결(X) / 프로그램 종료시 소멸


class A {
private:
	int private_v_;							// private 맴버 변수			-> 외부연결(X) / 같은 파일 내의, 해당 클래스의 퍼블릭 함수, 프랜즈 함수, 프랜즈 클래스의 퍼블릭함수 로만 접근 가능
	//static int private_static_v_;			// private, 정적 맴버 변수	-> 외부연결(O) / 모든 파일 내의, 해당 클래스의 퍼블릭 함수, 프랜즈 함수, 프랜즈 클래스의 퍼블릭함수 로만 접근 가능

	void private_func();					// private 맴버 함수			-> 
	//static void private_static_func();		// private, 정적 맴버 함수   ->	

public:
	A(int private_v = 100, int public_v = 102, int public_static_v = 103);

	int public_v_;							// public 맴버 변수			-> 외부연결(X) / 같은 파일 내에서 접근 가능
	static int public_static_v_;				// public, 정적 맴버 변수	-> 외부연결(O) / 모든 파일 내에서 접근 가능

	void public_func();						// public 맴버 함수
	static void public_static_func();		// public, 정적 맴버 함수 
};



int main() {
	int local_v(1);							// local 변수				-> 외부연결(X) / 함수 종료시 소멸
	static int local_static_v(2);			// local, 정적 변수			-> 외부연결(X) / 프로그램 종료시 소멸

	A a;
	//B b;

}

A::A(int private_v, int public_v, int public_static_v) {
	private_v_ = private_v;
	//private_static_v_ = private_static_v;
	public_v_ = public_v;
	public_static_v_ = public_static_v;
}

void A::private_func() {
	cout << "[A's private func]" << endl;
}
/*
void A::private_static_func() {
	cout << "[A's private_static func]" << endl;
}*/

void A::public_func() {
	cout << "[A's public func]" << endl;
}

void A::public_static_func() {
	cout << "[A's public_static func]" << endl;
}
