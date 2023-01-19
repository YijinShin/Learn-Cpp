/* [ TCP school C++ study 57 ~ 58 part ]
TOPIC: ���߻�� (multiple inheritance)

!!!  �̿��̸� ���ϴ°� ���� !!!
	- �ڵ尡 ����������, �ǿ��������� ����

	- �߻� ������ ������
		- ��ӹ��� �������� ����Ŭ������ ���� ��ġ�� �̸��� �ɹ��� ������ ���� �� ���� 
		- �� ����� �޴ٺ��� ���� Ŭ������ �ι��̳� ��ӹް� �Ǵ� ��Ȳ�� ���� �� ����
		
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

// Parent�� ������
Parent1::Parent1(int P_private_v) {
	cout << "** Parent1������ ȣ��" << endl;
	P1_private_v_ = P_private_v;
}
Parent2::Parent2(int P_private_v) {
	cout << "** Parent2������ ȣ��" << endl;
	P2_private_v_ = P_private_v;
}

// Child�� ������
Child::Child(int P1_private_v, int P2_private_v, int C_private_v)
	:Parent1(P1_private_v),Parent2(P2_private_v)	// �θ� Ŭ������ �����ڿ��� �� �Ѱ��ֱ� -> ��ӹ��� �ɹ��� ���ؼ��� ���⼭ �ʱ�ȭ��. 
{
	cout << "** Child������ ȣ��" << endl;
	C_private_v_ = C_private_v;
}

Parent1::~Parent1() { cout << "**Parent1 �Ҹ��� ȣ��" << endl; }
Parent2::~Parent2() { cout << "**Parent2 �Ҹ��� ȣ��" << endl; }
Child::~Child() { cout << "**Child �Ҹ��� ȣ��" << endl; }