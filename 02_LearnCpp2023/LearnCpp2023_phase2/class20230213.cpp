/* class, const

- explicit ����

- const�ɹ� �ʱ�ȭ�ϱ� => �ʱ�ȭ ����Ʈ (initiailzer list)
		���޸� �Ҵ� ��, ������ ȣ������ ������
		�����ڰ� ������ �ʿ��Ѱ��� �ʱ�ȣ ������Ʈ ���°� ����

- const�Լ�(�б� �����Լ�) > ������ �������ϸ� const���̱�(�ظ��ϼ� ���̱� ���� ����)
	���⼭ �д°� �ɹ� �������ϴ°���. 
	�ش��Լ��� �Ķ���ʹ� �������. �Լ� �ȿ��� �����ϴ� ���������� �������

- const�ɹ� �Լ� �ȿ��� �ٸ� �Լ��� �θ����� �� �θ����Լ��� const������
Display() const{
	getHP()	// �굵 const������. 
}

getHP() const{...}

constŰ���常 �ٿ��� �����ε� ������. 

const INFO* Get_Info()const {return &m_tInfo;} �̷��� ¥�°� ����. 

���۷��� ������� = l-value�� ��������. 
�ٵ� �Լ��Ű������� ref�� �־���ϴµ� ����� �ְ���� �� ���ڳ�
�׷��� �Ű������� const int& _iTemp�� ������ �޾ƿü��ֿ�


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
	//func(300);	// ref�� r-value�ѱ�� ����. (l�� �¿��� �� �������ִ°Ű�, r�� ���׿��� �������ִ°���)
	//c C;
	//C.Draw(20);

	CTest2 ct2;
	ct2.Display1();
}