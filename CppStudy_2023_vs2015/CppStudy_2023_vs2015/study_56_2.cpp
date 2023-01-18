
#include <iostream>

using namespace std;

int world_v(10);							// ���� ����					-> �ܺο���(O) / ���α׷� ����� �Ҹ�
static int world_static_v(11);				// ����, ���� ����			-> �ܺο���(X) / ���α׷� ����� �Ҹ�

class B {
private:
	int private_v_;							// private �ɹ� ����			-> �ܺο���(X) / ���� ���� ����, �ش� Ŭ������ �ۺ� �Լ�, ������ �Լ�, ������ Ŭ������ �ۺ��Լ� �θ� ���� ����
	static int B_private_static_v_;			// private, ���� �ɹ� ����	-> �ܺο���(O) / ��� ���� ����, �ش� Ŭ������ �ۺ� �Լ�, ������ �Լ�, ������ Ŭ������ �ۺ��Լ� �θ� ���� ����

	int private_func();						// private �ɹ� �Լ�			-> 
	static int B_private_static_func();		// private, ���� �ɹ� �Լ�   ->	

public:

	int public_v_;							// public �ɹ� ����			-> �ܺο���(X) / ���� ���� ������ ���� ����
	static int B_public_static_v_;			// public, ���� �ɹ� ����		-> �ܺο���(O) / ��� ���� ������ ���� ����

	int public_func();						// public �ɹ� �Լ�
	static int B_public_static_func();		// public, ���� �ɹ� �Լ� 


	void B_public_func_linkToPrivate();
	int B_public_func_printPrivateStatic();
	static int B_public_static_func_printPrivateStatic();
	static void B_public_static_func_linkToPrivate();


	B(int private_v = 100, int B_private_static_v = 101, int public_v = 102, int public_static_v = 103);
};

int B::B_private_static_v_ = 1;				// ���� �ɹ� ������ ���� �� �ʱ�ȭ
int B::B_public_static_v_ = 2;				// ���� �ɹ� ������ ���� �� �ʱ�ȭ

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
	//++private_v_;								-> !!!!!static �ɹ� �Լ��� static �ɹ� ������ ��밡��!!!! 
	++B_private_static_v_;
}

int B::B_public_func_printPrivateStatic() {
	return private_v_;
}

int B::B_public_static_func_printPrivateStatic() {
	return B_private_static_v_;
}