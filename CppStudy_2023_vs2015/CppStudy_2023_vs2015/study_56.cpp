/* 
Topic: ���� �ɹ� / ��� �ɹ�

*���� : static �ɹ� ���� �� �ٸ��� static������ �ܺ� ���� ���ܵ�!
* (static ������ ���ؼ��� study_staticVariablePlus.cpp ���� �ϱ� 

----------------------------------------------------------------------------------------------

* static ����
	- �ܺ� ���� ���ܵ�
	- ���� static����
		- �ش� ���ϳ��� ��� �Լ��� ���� ����
	- ���� static ����
		- �ش� ���ϳ��� �ش� �Լ��ȿ����� ���� ����


* static �ɹ� ����
	- ������ Ŭ���� ������ ������ / ����(�ʱ�ȭ)�� ���Ͽ��� �Ѵ�. 
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

https://ansohxxn.github.io/cpp/chapter4-2/ ���� 

----------------------------------------------------------------------------------------------

* constant �ɹ� ����
	- �����Ҷ� �ʱ�ȭ ��Ű�ݾ� -> �� �ڷ� �� ���ٲ�

* constant �ɹ� �Լ�
	-  ȣ���� ��ü�� �����͸� ������ �� ���� ��� �Լ�
*/


#include <iostream>
#include "study_56_2.cpp"

using namespace std;


class A {
private:
	int private_v_;							// private �ɹ� ����			-> �ܺο���(X) / ���� ���� ����, �ش� Ŭ������ �ۺ� �Լ�, ������ �Լ�, ������ Ŭ������ �ۺ��Լ� �θ� ���� ����
	static int A_private_static_v_;			// private, ���� �ɹ� ����	-> �ܺο���(O) / ��� ���� ����, �ش� Ŭ������ �ۺ� �Լ�, ������ �Լ�, ������ Ŭ������ �ۺ��Լ� �θ� ���� ����

	void private_func();					// private �ɹ� �Լ�			-> 
	static void A_private_static_func();	// private, ���� �ɹ� �Լ�   ->	

public:
	A(int private_v = 100, int A_private_static_v=101, int public_v = 102, int A_public_static_v = 103);

	int public_v_;							// public �ɹ� ����			-> �ܺο���(X) / ���� ���� ������ ���� ����
	static int A_public_static_v_;			// public, ���� �ɹ� ����		-> �ܺο���(O) / ��� ���� ������ ���� ����

	void public_func();						// public �ɹ� �Լ�			
	static void A_public_static_func();		// public, ���� �ɹ� �Լ� 
	
	void A_public_func_linkToPrivate();
	static void A_public_static_func_linkToPrivate();
};

int A::A_private_static_v_ = 1;				// ���� �ɹ� ������ ���� �� �ʱ�ȭ
int A::A_public_static_v_ = 2;				// ���� �ɹ� ������ ���� �� �ʱ�ȭ



int main() {
	int local_v(1);							// local ����				-> �ܺο���(X) / �Լ� ����� �Ҹ�
	static int local_static_v(2);			// local, ���� ����			-> �ܺο���(X) / ���α׷� ����� �Ҹ�

	{
		cout << "[�Լ�1] world + static / world ���� : " << world_static_v <<" , " << world_v << endl << endl;

		// �Ѵ� data������ ����� �ֵ��̶� �� �Լ���(���) ������ ���� ��� ������ ���̴�. 
		++world_static_v;
		++world_v;
	}

	{
		// �տ��� ����� world_static_v , world_v ���� 1�� ������ ���� ���´�. 
		cout << "[�Լ�1] world + static / world ���� : " << world_static_v << ", " << world_v << endl << endl;
	}


	// ���ٿ� ���Ͽ� 
	{
		A a;
		B b1;

		// ���� ���Ͽ��� -> public / public static �Լ� ����
		a.public_func();						// ���� ���� ������ , �ش� Ŭ���� ��ü�� -> public�ɹ� �Լ� ���� 
		a.A_public_static_func();				// ���� ���� ������ , �ش� Ŭ���� ��ü�� -> public, static �ɹ� �Լ� ���� 
		A::A_public_static_func();				// ���� ���� ������ , �ش� Ŭ���� �̸����� -> public, static �ɹ� �Լ� ����

		// ���� ���Ͽ��� -> public / public static ���� ����
		cout << "[ A�� public ����: " << a.A_public_static_v_ << ", " << a.public_v_ << "]" << endl;

		// �ٸ� ���Ͽ��� -> public / public static �Լ� ����
		b1.public_func();						// �ٸ� ���� ������ , �ش� Ŭ���� ��ü�� -> public�ɹ� �Լ� ���� 
		b1.B_public_static_func();				// �ٸ� ���� ������ , �ش� Ŭ���� ��ü�� -> public, static �ɹ� �Լ� ���� 
		B::B_public_static_func();				// �ٸ� ���� ������ , �ش� Ŭ���� �̸����� -> public, static �ɹ� �Լ� ����
		
		// �ٸ� ���Ͽ��� -> public / public static ���� ����
		cout << "[ B�� public ����: " << b1.B_public_static_v_ << ", " << b1.public_v_ << "]" << endl;

	}
	cout << endl;

	{
		B b1, b2;

		// [ public static ������ ��ü�� ������(�ϳ�����) ]
			cout << "b1, b2�� B_public_static_v_ : " << b1.B_public_static_v_ << " / " << b2.B_public_static_v_ << endl;		// �Ѵ� 103�� ����

			++b1.B_public_static_v_;	// B_public_static_v_�� static�̱� ������ ��� B ��ü�� ���� �ϳ��� B_public_static_v_ �� �����Ѵ�. 
										// ���� b1�� B_public_static_v_�� 1 �ø��� b2�� B_public_static_v_�� ���� �ö� 

			cout << "b1, b2�� B_public_static_v_ : " << b1.B_public_static_v_ << " / " << b2.B_public_static_v_ << endl;		// �Ѵ� 104�� ����
			cout << endl;

		// [ public ������ ��ü�� �������� ���� ]
			cout << "[��] b1, b2�� public_v_ : " << b1.public_v_ << " / " << b2.public_v_ << endl;		// �Ѵ� 103�� ����

			++b1.public_v_;	// �׳� public�� ���� Ŭ������ ��ü��, ��� ��ü�� ���� ������ �ֱ� ������ b1�� �����ص� b2�� �ȹٲ�

			cout << "[��] b1, b2�� public_v_ : " << b1.public_v_ << " / " << b2.public_v_ << endl;		// �Ѵ� 104�� ����
			cout << endl;
		
		// -----------------------------------[���⼭ ���ʹ� private �ɹ� ������ �մ�Ŷ� �� public�Լ� ȣ�� �������� �Ǿ�����]-----------------------------------------//

		// [ public static �Լ��� ��ü�� ������ ->  �Լ� ���� ��ü�̸��� �ƴ� Ŭ���� �̸����� ȣ����]
			cout << "[��] b1, b2�� B_private_static_v_ : " << b1.B_public_static_func_printPrivateStatic() << " / " << b2.B_public_static_func_printPrivateStatic() << endl;		// �Ѵ� 101�� ����
														// ������ static ������ ����ϴ°Ŵϱ� B::B_public_static_func_printPrivateStatic()�� �ѹ��� �ص� �Ǵµ� ���� �׳�.. �װ� �� ��ü�� �����ϰ��ִٴ°� �����ֱ����� �̷��� ���� �����.. 
			B::B_public_static_func_linkToPrivate();

			cout << "[��] b1, b2�� B_private_static_v_ : " << b1.B_public_static_func_printPrivateStatic() << " / " << b2.B_public_static_func_printPrivateStatic() << endl;		// �Ѵ� 102�� ����
			cout << endl;

		// 
			cout << "[��] b1, b2�� B_private_static_v_ : " << b1.B_public_static_func_printPrivateStatic() << " / " << b2.B_public_static_func_printPrivateStatic() << endl;
			cout << "[��] b1, b2�� private_v_ : " << b1.B_public_func_printPrivateStatic() << " / " << b2.B_public_func_printPrivateStatic() << endl;

			b1.B_public_func_linkToPrivate(); // b1�� private������, privat static������ 1�� �ø�  ==> static�� �����̴ϱ� �ٰ��� 1 �ö󰡴°�ó�� ���ϰŰ�, �׳� private�� b1���� �ö󰥰���

			cout << "[��] b1, b2�� B_private_static_v_ : " << b1.B_public_static_func_printPrivateStatic() << " / " << b2.B_public_static_func_printPrivateStatic() << endl;
			cout << "[��] b1, b2�� private_v_ : " << b1.B_public_func_printPrivateStatic() << " / " << b2.B_public_func_printPrivateStatic() << endl;


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