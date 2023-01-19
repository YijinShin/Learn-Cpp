/* 
Topic: 정적 맴버 / 상수 맴버

*주의 : static 맴버 변수 와 다르게 static변수는 외부 연결 차단됨!
* (static 변수에 대해서는 study_staticVariablePlus.cpp 참고 하기 

----------------------------------------------------------------------------------------------

* static 변수
	- 외부 연결 차단됨
	- 전역 static변수
		- 해당 파일내의 모든 함수가 접근 가능
	- 로컬 static 변수
		- 해당 파일내의 해당 함수안에서만 접근 가능


* static 맴버 변수
	- 선언은 클래스 내에서 하지만 / 정의(초기화)는 파일에서 한다. 
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

https://ansohxxn.github.io/cpp/chapter4-2/ 참고 

----------------------------------------------------------------------------------------------

* constant 맴버 변수
	- 선언할때 초기화 시키잖아 -> 그 뒤로 값 못바꿈

* constant 맴버 함수
	-  호출한 객체의 데이터를 변경할 수 없는 멤버 함수
*/


#include <iostream>
#include "study_56_2.cpp"

using namespace std;


class A {
private:
	int private_v_;							// private 맴버 변수			-> 외부연결(X) / 같은 파일 내의, 해당 클래스의 퍼블릭 함수, 프랜즈 함수, 프랜즈 클래스의 퍼블릭함수 로만 접근 가능
	static int A_private_static_v_;			// private, 정적 맴버 변수	-> 외부연결(O) / 모든 파일 내의, 해당 클래스의 퍼블릭 함수, 프랜즈 함수, 프랜즈 클래스의 퍼블릭함수 로만 접근 가능

	void private_func();					// private 맴버 함수			-> 
	static void A_private_static_func();	// private, 정적 맴버 함수   ->	

public:
	A(int private_v = 100, int A_private_static_v=101, int public_v = 102, int A_public_static_v = 103);

	int public_v_;							// public 맴버 변수			-> 외부연결(X) / 같은 파일 내에서 접근 가능
	static int A_public_static_v_;			// public, 정적 맴버 변수		-> 외부연결(O) / 모든 파일 내에서 접근 가능

	void public_func();						// public 맴버 함수			
	static void A_public_static_func();		// public, 정적 맴버 함수 
	
	void A_public_func_linkToPrivate();
	static void A_public_static_func_linkToPrivate();
};

int A::A_private_static_v_ = 1;				// 정적 맴버 변수의 정의 및 초기화
int A::A_public_static_v_ = 2;				// 정적 맴버 변수의 정의 및 초기화



int main() {
	int local_v(1);							// local 변수				-> 외부연결(X) / 함수 종료시 소멸
	static int local_static_v(2);			// local, 정적 변수			-> 외부연결(X) / 프로그램 종료시 소멸

	{
		cout << "[함수1] world + static / world 변수 : " << world_static_v <<" , " << world_v << endl << endl;

		// 둘다 data영역에 저장된 애들이라 이 함수가(블록) 끝나도 값이 계속 유지될 것이다. 
		++world_static_v;
		++world_v;
	}

	{
		// 앞에서 출력한 world_static_v , world_v 보다 1씩 증가한 수가 나온다. 
		cout << "[함수1] world + static / world 변수 : " << world_static_v << ", " << world_v << endl << endl;
	}


	// 접근에 관하여 
	{
		A a;
		B b1;

		// 같은 파일에서 -> public / public static 함수 접근
		a.public_func();						// 같은 파일 내에서 , 해당 클래스 객체로 -> public맴버 함수 접근 
		a.A_public_static_func();				// 같은 파일 내에서 , 해당 클래스 객체로 -> public, static 맴버 함수 접근 
		A::A_public_static_func();				// 같은 파일 내에서 , 해당 클래스 이름으로 -> public, static 맴버 함수 접근

		// 같은 파일에서 -> public / public static 변수 접근
		cout << "[ A의 public 변수: " << a.A_public_static_v_ << ", " << a.public_v_ << "]" << endl;

		// 다른 파일에서 -> public / public static 함수 접근
		b1.public_func();						// 다른 파일 내에서 , 해당 클래스 객체로 -> public맴버 함수 접근 
		b1.B_public_static_func();				// 다른 파일 내에서 , 해당 클래스 객체로 -> public, static 맴버 함수 접근 
		B::B_public_static_func();				// 다른 파일 내에서 , 해당 클래스 이름으로 -> public, static 맴버 함수 접근
		
		// 다른 파일에서 -> public / public static 변수 접근
		cout << "[ B의 public 변수: " << b1.B_public_static_v_ << ", " << b1.public_v_ << "]" << endl;

	}
	cout << endl;

	{
		B b1, b2;

		// [ public static 변수는 객체간 공유함(하나뿐임) ]
			cout << "b1, b2의 B_public_static_v_ : " << b1.B_public_static_v_ << " / " << b2.B_public_static_v_ << endl;		// 둘다 103이 나옴

			++b1.B_public_static_v_;	// B_public_static_v_는 static이기 떄문에 모든 B 객체가 오직 하나의 B_public_static_v_ 를 공유한다. 
										// 따라서 b1의 B_public_static_v_를 1 올리면 b2의 B_public_static_v_도 같이 올라감 

			cout << "b1, b2의 B_public_static_v_ : " << b1.B_public_static_v_ << " / " << b2.B_public_static_v_ << endl;		// 둘다 104가 나옴
			cout << endl;

		// [ public 변수는 객체간 공유하지 않음 ]
			cout << "[전] b1, b2의 public_v_ : " << b1.public_v_ << " / " << b2.public_v_ << endl;		// 둘다 103이 나옴

			++b1.public_v_;	// 그냥 public은 같은 클래스의 객체라도, 모든 객체가 따로 가지고 있기 때문에 b1을 수정해도 b2는 안바뀜

			cout << "[후] b1, b2의 public_v_ : " << b1.public_v_ << " / " << b2.public_v_ << endl;		// 둘다 104가 나옴
			cout << endl;
		
		// -----------------------------------[여기서 부터는 private 맴버 변수를 손댈거라 다 public함수 호출 형식으로 되어있음]-----------------------------------------//

		// [ public static 함수는 객체간 공유함 ->  함수 사용시 객체이름이 아닌 클래스 이름으로 호출함]
			cout << "[전] b1, b2의 B_private_static_v_ : " << b1.B_public_static_func_printPrivateStatic() << " / " << b2.B_public_static_func_printPrivateStatic() << endl;		// 둘다 101이 나옴
														// 어차피 static 변수를 출력하는거니까 B::B_public_static_func_printPrivateStatic()로 한번만 해도 되는데 ㅋㅋ 그냥.. 그걸 두 객체가 공유하고있다는걸 보여주기위해 이렇게 따로 출력함.. 
			B::B_public_static_func_linkToPrivate();

			cout << "[후] b1, b2의 B_private_static_v_ : " << b1.B_public_static_func_printPrivateStatic() << " / " << b2.B_public_static_func_printPrivateStatic() << endl;		// 둘다 102가 나옴
			cout << endl;

		// 
			cout << "[전] b1, b2의 B_private_static_v_ : " << b1.B_public_static_func_printPrivateStatic() << " / " << b2.B_public_static_func_printPrivateStatic() << endl;
			cout << "[전] b1, b2의 private_v_ : " << b1.B_public_func_printPrivateStatic() << " / " << b2.B_public_func_printPrivateStatic() << endl;

			b1.B_public_func_linkToPrivate(); // b1의 private변수와, privat static변수를 1씩 올림  ==> static은 공용이니까 다같이 1 올라가는것처럼 보일거고, 그냥 private는 b1꺼만 올라갈거임

			cout << "[후] b1, b2의 B_private_static_v_ : " << b1.B_public_static_func_printPrivateStatic() << " / " << b2.B_public_static_func_printPrivateStatic() << endl;
			cout << "[후] b1, b2의 private_v_ : " << b1.B_public_func_printPrivateStatic() << " / " << b2.B_public_func_printPrivateStatic() << endl;


	}

}

A::A(int private_v, int A_private_static_v, int public_v, int A_public_static_v) {
	private_v_ = private_v;
	A_private_static_v_ = A_private_static_v;
	public_v_ = public_v;
	A_public_static_v_ = A_public_static_v;
}

void A::private_func() {
	cout << "[A's private func]" << endl;
}

void A::A_private_static_func() {
	cout << "[A's private_static func]" << endl;
}

void A::public_func() {
	cout << "[A's public func]" << endl;
}

void A::A_public_static_func() {
	cout << "[A's public_static func]" << endl;
}

void A::A_public_func_linkToPrivate() {

}
void A::A_public_static_func_linkToPrivate() {

}