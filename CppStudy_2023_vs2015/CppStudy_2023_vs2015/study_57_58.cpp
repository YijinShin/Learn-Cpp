/* [ TCP school C++ study 57 ~ 58 part ]
TOPIC:  상속 / 파생 클래스 / 맴버 함수 Overriding

* 상속(inheritance) 
	- 코드 재활용성을 높여줌. 
	- 클래스 간의 계층적 관계 형성을 해줌 -> [다형성] 의 문법적 토대를 형성 
										  ( 다형성 = 하나의 객체가 여러가지 타입을 가질 수 있도록 하는 것) 

* 클래스 상속 
	- 기존 클래스의 모든 것을 물려받아서 새로운 클래스 작성하는 것. 
	- 명칭
		- 기존 클래스	 : 부모 클래스 = base 클래스 = 상위(super)클래스 
		- 물려받은 클래스 : 파생(derived) 클래스 = 자식 클래스 = 하위(sub)클래스 
	
	- 단일 상속 / 다중 상속 모두 가능 

	- 파생 클래스 선언:
		class [class이름] : [접근제어 지시자(public/ private)] [부모클래스 이름] { ... }

	- 파생 클래스 생산자:
		[class 이름]::[class 이름] ([매개변수 (상속받은거 + 새로운 맴버 모두에 대한 값 받아야함)]) : [부모class이름]() { ... } 

	- 생성자, 소멸자 호출 순서 
		1. 부모 클래스 생성자
		2. 자식 클래스 생성자 
		3. 자식 클래스 소멸자
		4. 부모 클래스 소멸자 

* 맴버 함수 Overriding 
	
	오버라이딩 하는 방법 2가지 
		
		1. 파생 클래스에서 직접 오버라이딩하기
				: 걍 파생 클래스에 똑같은 함수를 선언하고, 내용만 바꾸면됨. 4
				-> 객체의 포인터 변수가 : 자신의 타입을 기준으로 맴버 함수를 호출함 
			
		2. 가상 함수를 이용해 오버라이딩하기 
				: virtual 키워드 사용하기 
				-> 객체의 포인터 변수가 : 자신이 가리키고 있는 객체의 타입을 기준으로 맴버 함수를 호출함
				  
*/

#include <iostream>

using namespace std;




class Parent {
private: 
	int P_private_v_;
public:
	Parent(int P_private_v, int P_public_v);
	~Parent();
	int P_public_v_;

	void Display_Parent();

	void Overriding_TestFunc_ver1();	// 이거를 부르고 싶으면 ::사용해야함 
	void Overriding_TestFunc_ver2();

};

class Child : public Parent {
private:
	int C_private_v_;
public:
	Child(int P_private_v, int P_public_v, int C_private_v, int C_public_v);
	~Child();
	int C_public_v_;

	void Display_Child();
	
	void Overriding_TestFunc_ver1();			// 이렇게 자녀가 부모 맴버와 이름이 똑같은 맴버를 선언하면, 함수 오버라이딩한것. 
	virtual void Overriding_TestFunc_ver2();	// 가상함수 이용한 맴버 함수 오버라이딩
												  
	
};



int main() {

	{
		Child c1(1, 2, 3, 4);

		c1.Display_Parent();
		c1.Display_Child();

		// child에서 오버라이딩한 함수 호출 
		c1.Overriding_TestFunc_ver1();
		// 오버라이딩 했지만 부모 클래스의 함수를 호출하기 
		c1.Parent::Overriding_TestFunc_ver1();
	}

	cout << endl;

	// 파생클래스에 직접 오버라이딩 할 경우 발생할 수 있는 오류  ==> 이걸 방지하려고 가상 함수를 사용해 오버라이딩함. 
	{
		Parent* p_ptr;
		Parent p1(1, 2);
		Child c1(10, 11, 12, 13);

		p_ptr = &p1;	// Parent* 에 Parent* 대입 
		p_ptr->Overriding_TestFunc_ver1();		// Parent의 Overriding_TestFunc()이 호출될 것이다. 

		p_ptr = &c1;	// Parent* 에 Child* 대입 (애초에 이렇게 쓰는게 좀.. 잘못되긴함. 근데 여튼 코드가 돌아는 감) 
		p_ptr->Overriding_TestFunc_ver1();		/* Parent의 Overriding_TestFunc()이 호출될 것이다. (Child가 아니라)
											       이유 -> 클래스 포인터는 가리키는 객체의 타입이 아니라 자신이 '호출된' 타입을 기준으로 함수를 호출한다. Parent 클래스의 Overriding_TestFunc()로 인식할 것이다.*/
	}

	cout << endl;

	// 가상함수 이용한 맴버 함수 오버라이딩 
	{
		Parent* p_ptr;
		Parent p1(1, 2);
		Child c1(10, 11, 12, 13);

		p_ptr = &p1;	// Parent* 에 Parent* 대입 
		p_ptr->Overriding_TestFunc_ver2();		// Parent의 Overriding_TestFunc()이 호출될 것이다. 

		p_ptr = &c1;	// Parent* 에 Child* 대입
		p_ptr->Overriding_TestFunc_ver2();		/* child의 Overriding_TestFunc()이 호출될 것이다.
												   이유 -> 이게 가상함수로 오버라이딩 한거라서 -> 포인터가 가리키는 객체의 타입을 기준으로 함수를 호출한다. */
	}

}


// Parent의 생성자
Parent::Parent(int P_private_v, int P_public_v) {
	cout << "** Parent생성자 호출" << endl;
	P_private_v_ = P_private_v;
	P_public_v_ = P_public_v;
}

// Child의 생성자
Child::Child(int P_private_v, int P_public_v, int C_private_v, int C_public_v) 
	:Parent(P_private_v, P_public_v)	// 부모 클래스의 생성자에게 값 넘겨주기 -> 상속받은 맴버에 대해서는 여기서 초기화함. 
{
	cout << "** Child생성자 호출" << endl;
	C_private_v_ = C_private_v;
	C_public_v_ = C_public_v;
}

Parent::~Parent() { cout << "**Parent 소멸자 호출" << endl; }
Child::~Child() { cout << "**Child 소멸자 호출" << endl; }


void Child::Display_Child() {
	cout << "Child: " << C_private_v_ << " , " << C_public_v_ << endl;
}

void Parent::Display_Parent() {
	cout << "Parent: " << P_private_v_ << " , " << P_public_v_ << endl;
}

void Parent::Overriding_TestFunc_ver1() {
	cout << "[ver1] Overriding_TestFunc form Parent" << endl;
}

void Child::Overriding_TestFunc_ver1() {
	cout << "[ver1] Overriding_TestFunc form Child" << endl;
}

void Parent::Overriding_TestFunc_ver2() {
	cout << "[ver2] Overriding_TestFunc form Parent" << endl;
}

void Child::Overriding_TestFunc_ver2() {
	cout << "[ver2] Overriding_TestFunc form Child" << endl;
}