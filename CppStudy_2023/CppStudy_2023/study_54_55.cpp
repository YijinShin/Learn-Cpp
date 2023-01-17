/* [ C++ study with TCP school 39 ~ 41part]
topic: friend 접근제어 지시자 ( friend 함수 / friend 클래스 )


* friend 함수 사용법 >> (study_52_53에서 사용하는거 예시 나옴 )

	함수의 원형에서만 사용  -> 이 함수의 원형은 일단 클래스 맴버 선언하는 곳에 있어야함. 
	함수의 정의에서는 안써도됨.

	friend [클래스 이름] [함수이름] ([매개변수])



* friend 함수 특징
	- 일반적인 함수 말고 연산자 오버로딩 함수에 많이 씀 
	- friend 함수는 해당 클래스의 맴버 함수인 것은 아니다. 
	- 그러나 해당 클래스 안의 private 맴버에 접근할 권한은 있다. (마치 public맴버처럼) 

----------------------------------------------------------------------------------------------------

* friend 클래스 
	A가 B의 friend클래스로 선언되어있으면, 
	B클래스의 모든 맴버들은 A클래스의 private 맴버까지 접근이 가능하다. 

* 전방선언
	순환 참조를 막기 위해 씀 
*/


#include <iostream>

using namespace std;

void DisplayTest();

//-----------------------------------[ 전방선언 사용 x => 순환참조인 상황 (알아서 클래스 선언 순서 맞춘경우) ]----------------------------------------
	// 순환선언 : 두클래스가 서로를 참조하고있는 상황 
class A {
private:
	int ia_;
public:
	A(int ia = 10);
	friend class Display;	// 프랜드 클래스 생성
};

class Display {
private:

public:
	void Display_A(const A& a);
};
//------------------------------------[ 전방선언 사용 ]----------------------------------------

// 클래스 B 전방 선언
class B;	//	 이게 없으면 Display_2의 함수에서 오류남 

class Display_2 {
private:

public:
	void Display_B(const B& b);	//지금 Display_2 클래스의 맴버 함수가 B클래스의 맴버를 참고하고있다. 때문에 클래스 B가 Display_2클래스보다 더 앞에 선언이 되어야한다. 
								// 이 경우, B를 통째로 앞에서 선언해도 되는데, 그럴 필요없이 전방 선언을 사용해도 된다. 
};

class B {
private:
	int ib_;
public:
	B(int ib = 10);
	friend class Display_2;	// 프랜드 클래스 생성
};



//----------------------------------------------------------------------------


int main() {
	//---------------------
	{
		A a;
		Display dis;
		dis.Display_A(a);
	}
	//---------------------
	{
		B b;
		Display_2 dis;
		dis.Display_B(b);
	}
}

//A class의 생성자
A::A(int ia) {
	ia_ = ia;
}

//B class의 생성자
B::B(int ib) {
	ib_ = ib;
}



void Display::Display_A(const A& a) {
	cout << "A클래스 정보: " << a.ia_ << endl;	// A클래스에 Display 클래스를 프랜즈 클래스로 선언했기 때문에 A클래스의 private까지 접근 가능. 
												// 그러나 매개변수를 const로 선언했기 때문에 원본값을 수정하지는 못함 
}

void Display_2::Display_B(const B& b) {
	cout << "B클래스 정보: " << b.ib_ << endl;	// Di
}

