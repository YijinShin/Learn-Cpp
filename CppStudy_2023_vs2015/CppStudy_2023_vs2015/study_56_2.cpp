
#include <iostream>

using namespace std;

int world_v(10);							// 전역 변수					-> 외부연결(O) / 프로그램 종료시 소멸
static int world_static_v(11);				// 전역, 정적 변수			-> 외부연결(X) / 프로그램 종료시 소멸

class B {
private:
	int private_v_;							// private 맴버 변수			-> 외부연결(X) / 같은 파일 내의, 해당 클래스의 퍼블릭 함수, 프랜즈 함수, 프랜즈 클래스의 퍼블릭함수 로만 접근 가능
	static int B_private_static_v_;			// private, 정적 맴버 변수	-> 외부연결(O) / 모든 파일 내의, 해당 클래스의 퍼블릭 함수, 프랜즈 함수, 프랜즈 클래스의 퍼블릭함수 로만 접근 가능

	int private_func();						// private 맴버 함수			-> 
	static int B_private_static_func();		// private, 정적 맴버 함수   ->	

public:

	int public_v_;							// public 맴버 변수			-> 외부연결(X) / 같은 파일 내에서 접근 가능
	static int B_public_static_v_;			// public, 정적 맴버 변수		-> 외부연결(O) / 모든 파일 내에서 접근 가능

	int public_func();						// public 맴버 함수
	static int B_public_static_func();		// public, 정적 맴버 함수 


	void B_public_func_linkToPrivate();
	int B_public_func_printPrivateStatic();
	static int B_public_static_func_printPrivateStatic();
	static void B_public_static_func_linkToPrivate();


	B(int private_v = 100, int B_private_static_v = 101, int public_v = 102, int public_static_v = 103);
};

int B::B_private_static_v_ = 1;				// 정적 맴버 변수의 정의 및 초기화
int B::B_public_static_v_ = 2;				// 정적 맴버 변수의 정의 및 초기화

B::B(int private_v, int B_private_static_v, int public_v, int B_public_static_v) {
	private_v_ = private_v;
	B_private_static_v_ = B_private_static_v;
	public_v_ = public_v;
	B_public_static_v_ = B_public_static_v;
}

int B::private_func() {
	cout << "[B's private func]" << endl;
	return 10;
}


int B::B_private_static_func() {
	cout << "[B's private_static func]" << endl;
	return 10;
}

int B::public_func() {
	cout << "[B's public func]" << endl;
	return 10;
}

int B::B_public_static_func() {
	cout << "[B's public_static func]" << endl;
	return 10;
}


void B::B_public_func_linkToPrivate() {
	++private_v_;
	++B_private_static_v_;
}
void B::B_public_static_func_linkToPrivate() {
	//++private_v_;								-> !!!!!static 맴버 함수는 static 맴버 변수만 사용가능!!!! 
	++B_private_static_v_;
}

int B::B_public_func_printPrivateStatic() {
	return private_v_;
}

int B::B_public_static_func_printPrivateStatic() {
	return B_private_static_v_;
}