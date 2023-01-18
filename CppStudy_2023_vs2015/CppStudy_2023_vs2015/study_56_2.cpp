#include <iostream>

using namespace std;

class B {
private:
	int private_v_;							// private �ɹ� ����			-> �ܺο���(X) / ���� ���� ����, �ش� Ŭ������ �ۺ� �Լ�, ������ �Լ�, ������ Ŭ������ �ۺ��Լ� �θ� ���� ����
	//static int private_static_v_;			// private, ���� �ɹ� ����	-> �ܺο���(O) / ��� ���� ����, �ش� Ŭ������ �ۺ� �Լ�, ������ �Լ�, ������ Ŭ������ �ۺ��Լ� �θ� ���� ����

	void Bprivate_func();					// private �ɹ� �Լ�			-> 
	//static void Bprivate_static_func();		// private, ���� �ɹ� �Լ�   ->	

public:
	B(int private_v = 100, int public_v = 102, int public_static_v = 103);

	int public_v_;							// public �ɹ� ����			-> �ܺο���(X) / ���� ���� ������ ���� ����
	static int public_static_v_;				// public, ���� �ɹ� ����	-> �ܺο���(O) / ��� ���� ������ ���� ����

	void Bpublic_func();						// public �ɹ� �Լ�
	static void Bpublic_static_func();		// public, ���� �ɹ� �Լ� 
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