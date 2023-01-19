/* [ TCP school C++ study 57 ~ 58 part ]
TOPIC: 다중상속 (multiple inheritance)

!!!  이왕이면 피하는게 좋음 !!!
	- 코드가 복잡해지고, 실용적이지는 않음

	- 발생 가능한 문제점
		- 상속받은 여러개의 기초클래스들 끼리 겹치는 이름의 맴버를 가지고 있을 수 있음 
		- 막 상속을 받다보면 같은 클래스를 두번이나 상속받게 되는 상황이 있을 수 있음
		
*/



#include <iostream>

using namespace std;




class Parent1 {
private:
	int P1_private_v_;
public:
	Parent1(int P1_private_v);
	~Parent1();

};

class Parent2 {
private:
	int P2_private_v_;
public:
	Parent2(int P2_private_v);
	~Parent2();

};

class Child : public Parent1, public Parent2 {
private:
	int C_private_v_;
public:
	Child(int P1_private_v,int P2_private_v, int C_private_v);
	~Child();
};




int main() {
	Child c(1, 2, 3);

}

// Parent의 생성자
Parent1::Parent1(int P_private_v) {
	cout << "** Parent1생성자 호출" << endl;
	P1_private_v_ = P_private_v;
}
Parent2::Parent2(int P_private_v) {
	cout << "** Parent2생성자 호출" << endl;
	P2_private_v_ = P_private_v;
}

// Child의 생성자
Child::Child(int P1_private_v, int P2_private_v, int C_private_v)
	:Parent1(P1_private_v),Parent2(P2_private_v)	// 부모 클래스의 생성자에게 값 넘겨주기 -> 상속받은 맴버에 대해서는 여기서 초기화함. 
{
	cout << "** Child생성자 호출" << endl;
	C_private_v_ = C_private_v;
}

Parent1::~Parent1() { cout << "**Parent1 소멸자 호출" << endl; }
Parent2::~Parent2() { cout << "**Parent2 소멸자 호출" << endl; }
Child::~Child() { cout << "**Child 소멸자 호출" << endl; }