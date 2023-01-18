/* 
Topic: ���� �ɹ� / ��� �ɹ�

*���� : static �ɹ� ���� �� �ٸ��� static������ �ܺ� ���� ���ܵ�!

----------------------------------------------------------------------------------------------

* static ����
	- �ܺ� ���� ���ܵ�
	- ���� static����
		- �ش� ���ϳ��� ��� �Լ��� ���� ����
	- ���� static ����
		- �ش� ���ϳ��� �ش� �Լ��ȿ����� ���� ����


* static �ɹ� ����
	- �ܺ� ������ ������. 
		- private static�� ���
			- ��� ���Ͽ� �ִ� , �ش� Ŭ���� �ɹ� �Լ���, ������ �Լ�, ������ Ŭ������ �ɹ� �Լ��� ���� �� �� ����
		- public static�� ���
			- ��� ���Ͽ� �ִ�, ������ ���� ����. 
	- �ش� Ŭ������ ��� ��ü�� ������. 

* static �ɹ� �Լ� 
	- �ش� Ŭ���� ��ü�� �������� �ʾƵ�, Ŭ���� �̸������� ȣ��
	- this������ ������ ���� ( ��ü ������ ���ص� ���������ϱ� this���� ����)
	- ���� �ɹ� ������ ����� �� ���� ( �Լ��� ���� �ȿ� ) 

----------------------------------------------------------------------------------------------

* constant �ɹ� ����
	- �����Ҷ� �ʱ�ȭ ��Ű�ݾ� -> �� �ڷ� �� ���ٲ�

* constant �ɹ� �Լ�
	-  ȣ���� ��ü�� �����͸� ������ �� ���� ��� �Լ�
*/

#include <iostream>


using namespace std;


int world_v(10);							// ���� ����					-> �ܺο���(O) / ���α׷� ����� �Ҹ�
static int world_static_v(11);				// ����, ���� ����			-> �ܺο���(X) / ���α׷� ����� �Ҹ�


class A {
private:
	int private_v_;							// private �ɹ� ����			-> �ܺο���(X) / ���� ���� ����, �ش� Ŭ������ �ۺ� �Լ�, ������ �Լ�, ������ Ŭ������ �ۺ��Լ� �θ� ���� ����
	//static int private_static_v_;			// private, ���� �ɹ� ����	-> �ܺο���(O) / ��� ���� ����, �ش� Ŭ������ �ۺ� �Լ�, ������ �Լ�, ������ Ŭ������ �ۺ��Լ� �θ� ���� ����

	void private_func();					// private �ɹ� �Լ�			-> 
	//static void private_static_func();		// private, ���� �ɹ� �Լ�   ->	

public:
	A(int private_v = 100, int public_v = 102, int public_static_v = 103);

	int public_v_;							// public �ɹ� ����			-> �ܺο���(X) / ���� ���� ������ ���� ����
	static int public_static_v_;				// public, ���� �ɹ� ����	-> �ܺο���(O) / ��� ���� ������ ���� ����

	void public_func();						// public �ɹ� �Լ�
	static void public_static_func();		// public, ���� �ɹ� �Լ� 
};



int main() {
	int local_v(1);							// local ����				-> �ܺο���(X) / �Լ� ����� �Ҹ�
	static int local_static_v(2);			// local, ���� ����			-> �ܺο���(X) / ���α׷� ����� �Ҹ�

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
