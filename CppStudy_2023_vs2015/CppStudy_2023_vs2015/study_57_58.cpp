/* [ TCP school C++ study 57 ~ 58 part ]
TOPIC:  ��� / �Ļ� Ŭ���� / �ɹ� �Լ� Overriding

* ���(inheritance) 
	- �ڵ� ��Ȱ�뼺�� ������. 
	- Ŭ���� ���� ������ ���� ������ ���� -> [������] �� ������ ��븦 ���� 
										  ( ������ = �ϳ��� ��ü�� �������� Ÿ���� ���� �� �ֵ��� �ϴ� ��) 

* Ŭ���� ��� 
	- ���� Ŭ������ ��� ���� �����޾Ƽ� ���ο� Ŭ���� �ۼ��ϴ� ��. 
	- ��Ī
		- ���� Ŭ����	 : �θ� Ŭ���� = base Ŭ���� = ����(super)Ŭ���� 
		- �������� Ŭ���� : �Ļ�(derived) Ŭ���� = �ڽ� Ŭ���� = ����(sub)Ŭ���� 
	
	- ���� ��� / ���� ��� ��� ���� 

	- �Ļ� Ŭ���� ����:
		class [class�̸�] : [�������� ������(public/ private)] [�θ�Ŭ���� �̸�] { ... }

	- �Ļ� Ŭ���� ������:
		[class �̸�]::[class �̸�] ([�Ű����� (��ӹ����� + ���ο� �ɹ� ��ο� ���� �� �޾ƾ���)]) : [�θ�class�̸�]() { ... } 

	- ������, �Ҹ��� ȣ�� ���� 
		1. �θ� Ŭ���� ������
		2. �ڽ� Ŭ���� ������ 
		3. �ڽ� Ŭ���� �Ҹ���
		4. �θ� Ŭ���� �Ҹ��� 

* �ɹ� �Լ� Overriding 
	
	�������̵� �ϴ� ��� 2���� 
		
		1. �Ļ� Ŭ�������� ���� �������̵��ϱ�
				: �� �Ļ� Ŭ������ �Ȱ��� �Լ��� �����ϰ�, ���븸 �ٲٸ��. 4
				-> ��ü�� ������ ������ : �ڽ��� Ÿ���� �������� �ɹ� �Լ��� ȣ���� 
			
		2. ���� �Լ��� �̿��� �������̵��ϱ� 
				: virtual Ű���� ����ϱ� 
				-> ��ü�� ������ ������ : �ڽ��� ����Ű�� �ִ� ��ü�� Ÿ���� �������� �ɹ� �Լ��� ȣ����
				  
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

	void Overriding_TestFunc_ver1();	// �̰Ÿ� �θ��� ������ ::����ؾ��� 
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
	
	void Overriding_TestFunc_ver1();			// �̷��� �ڳడ �θ� �ɹ��� �̸��� �Ȱ��� �ɹ��� �����ϸ�, �Լ� �������̵��Ѱ�. 
	virtual void Overriding_TestFunc_ver2();	// �����Լ� �̿��� �ɹ� �Լ� �������̵�
												  
	
};



int main() {

	{
		Child c1(1, 2, 3, 4);

		c1.Display_Parent();
		c1.Display_Child();

		// child���� �������̵��� �Լ� ȣ�� 
		c1.Overriding_TestFunc_ver1();
		// �������̵� ������ �θ� Ŭ������ �Լ��� ȣ���ϱ� 
		c1.Parent::Overriding_TestFunc_ver1();
	}

	cout << endl;

	// �Ļ�Ŭ������ ���� �������̵� �� ��� �߻��� �� �ִ� ����  ==> �̰� �����Ϸ��� ���� �Լ��� ����� �������̵���. 
	{
		Parent* p_ptr;
		Parent p1(1, 2);
		Child c1(10, 11, 12, 13);

		p_ptr = &p1;	// Parent* �� Parent* ���� 
		p_ptr->Overriding_TestFunc_ver1();		// Parent�� Overriding_TestFunc()�� ȣ��� ���̴�. 

		p_ptr = &c1;	// Parent* �� Child* ���� (���ʿ� �̷��� ���°� ��.. �߸��Ǳ���. �ٵ� ��ư �ڵ尡 ���ƴ� ��) 
		p_ptr->Overriding_TestFunc_ver1();		/* Parent�� Overriding_TestFunc()�� ȣ��� ���̴�. (Child�� �ƴ϶�)
											       ���� -> Ŭ���� �����ʹ� ����Ű�� ��ü�� Ÿ���� �ƴ϶� �ڽ��� 'ȣ���' Ÿ���� �������� �Լ��� ȣ���Ѵ�. Parent Ŭ������ Overriding_TestFunc()�� �ν��� ���̴�.*/
	}

	cout << endl;

	// �����Լ� �̿��� �ɹ� �Լ� �������̵� 
	{
		Parent* p_ptr;
		Parent p1(1, 2);
		Child c1(10, 11, 12, 13);

		p_ptr = &p1;	// Parent* �� Parent* ���� 
		p_ptr->Overriding_TestFunc_ver2();		// Parent�� Overriding_TestFunc()�� ȣ��� ���̴�. 

		p_ptr = &c1;	// Parent* �� Child* ����
		p_ptr->Overriding_TestFunc_ver2();		/* child�� Overriding_TestFunc()�� ȣ��� ���̴�.
												   ���� -> �̰� �����Լ��� �������̵� �ѰŶ� -> �����Ͱ� ����Ű�� ��ü�� Ÿ���� �������� �Լ��� ȣ���Ѵ�. */
	}

}


// Parent�� ������
Parent::Parent(int P_private_v, int P_public_v) {
	cout << "** Parent������ ȣ��" << endl;
	P_private_v_ = P_private_v;
	P_public_v_ = P_public_v;
}

// Child�� ������
Child::Child(int P_private_v, int P_public_v, int C_private_v, int C_public_v) 
	:Parent(P_private_v, P_public_v)	// �θ� Ŭ������ �����ڿ��� �� �Ѱ��ֱ� -> ��ӹ��� �ɹ��� ���ؼ��� ���⼭ �ʱ�ȭ��. 
{
	cout << "** Child������ ȣ��" << endl;
	C_private_v_ = C_private_v;
	C_public_v_ = C_public_v;
}

Parent::~Parent() { cout << "**Parent �Ҹ��� ȣ��" << endl; }
Child::~Child() { cout << "**Child �Ҹ��� ȣ��" << endl; }


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