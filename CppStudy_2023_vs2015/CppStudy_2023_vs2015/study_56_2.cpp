#include <iostream>

using namespace std;

class B {
private:
	int private_v_;							// private 맴버 변수			-> 외부연결(X) / 같은 파일 내의, 해당 클래스의 퍼블릭 함수, 프랜즈 함수, 프랜즈 클래스의 퍼블릭함수 로만 접근 가능
	//static int private_static_v_;			// private, 정적 맴버 변수	-> 외부연결(O) / 모든 파일 내의, 해당 클래스의 퍼블릭 함수, 프랜즈 함수, 프랜즈 클래스의 퍼블릭함수 로만 접근 가능

	void Bprivate_func();					// private 맴버 함수			-> 
	//static void Bprivate_static_func();		// private, 정적 맴버 함수   ->	

public:
	B(int private_v = 100, int public_v = 102, int public_static_v = 103);

	int public_v_;							// public 맴버 변수			-> 외부연결(X) / 같은 파일 내에서 접근 가능
	static int public_static_v_;				// public, 정적 맴버 변수	-> 외부연결(O) / 모든 파일 내에서 접근 가능

	void Bpublic_func();						// public 맴버 함수
	static void Bpublic_static_func();		// public, 정적 맴버 함수 
};

B::B(int private_v, int public_v, int public_static_v) {
	private_v_ = private_v;
	//private_static_v_ = private_static_v;
	public_v_ = public_v;
	public_static_v_ = public_static_v;
}

void B::Bprivate_func() {
	cout << "[B's private func]" << endl;
}

/*
void B::Bprivate_static_func() {
	cout << "[B's private_static func]" << endl;
}*/

void B::Bpublic_func() {
	cout << "[B's public func]" << endl;
}

void B::Bpublic_static_func() {
	cout << "[B's public_static func]" << endl;
}