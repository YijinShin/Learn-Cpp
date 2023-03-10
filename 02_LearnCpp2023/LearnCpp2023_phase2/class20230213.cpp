/* class, const

- explicit 복습

- const맴버 초기화하기 => 초기화 리스트 (initiailzer list)
		ㄱ메모리 할당 후, 생성자 호출전에 동작함
		생성자가 여러개 필요한경우는 초기호 ㅏ리스트 쓰는걸 권장

- const함수(읽기 전용함수) > 데이터 가공안하면 const붙이기(왠만하선 붙이기 보기 쉽게)
	여기서 읽는건 맴버 변수말하는거임. 
	해당함수의 파라미터는 상관없음. 함수 안에서 선언하는 지역변수도 상관없음

- const맴버 함수 안에서 다른 함수를 부를려면 그 부르는함수도 const여야함
Display() const{
	getHP()	// 얘도 const여야함. 
}

getHP() const{...}

const키워드만 붙여도 오버로딩 가능함. 

const INFO* Get_Info()const {return &m_tInfo;} 이렇게 짜는게 좋다. 

레퍼런스 참조대상 = l-value만 참조가능. 
근데 함수매개변수로 ref를 넣어야하는데 상수를 넣고싶을 수 잇자나
그럴때 매개변수로 const int& _iTemp로 받으면 받아올수있움


*/

#include "stdafx.h"
using namespace std;

void func(const int& a) {
	cout << a << endl;
}

class c {
private:
	int i_data;
public:
	void Draw(const int& _temp) const {
		
		//i_data = _temp;
		cout << i_data << endl;
	}
};

const char* Func1() {
	return "hello";
}
/*
char* Func2() {
	//return "hello";
}*/


class CTest2{
public:
void Func1() const { cout << "const func" << endl; }
void Func1() { cout << "not const func" << endl; }

void Display1() const {
	Func1();	// OK!
	//Func2(); 	// ERROR!
}

void Display2() {
	Func1();	// OK!
	Func1(); 	// ERROR!
}

};


int main() {
	//func(300);	// ref에 r-value넘기기 가능. (l은 좌우항 다 놓을수있는거고, r은 우항에만 놓을수있는거임)
	//c C;
	//C.Draw(20);

	CTest2 ct2;
	ct2.Display1();
}