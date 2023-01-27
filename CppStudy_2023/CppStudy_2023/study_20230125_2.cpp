/*
Ŭ���� �����ڿ� ���Ͽ�. (��α� class �ʱ�ȭ ����鿡 ÷���� �ڵ�)

*/


#include <iostream>

using namespace std;


// �� ��� �����ڵ� �������� ���� ���
class Test1 {
public:
	int iData;
};

// ����Ʈ �����ڸ� ������ ���
class Test2 {
public:
	int iData;
	Test2() { iData = 10; };
};

// ����Ʈ ������ ���� �����ڸ� ������ ���
class Test3 {
public:
	int iData;
	Test3(int iSrc) { iData = iSrc; };
};

// ����Ʈ �����ڿ� �����ε� �����ڸ� ��� ������ ���
class Test4 {
public:
	int iData;
	Test4() { iData = 10; };
	Test4(int iSrc) { iData = iSrc; };
};

// ���� �����ڸ� �������� ���� ���
class Test5 {
private:
	int private_mem;
public:
	int public_mem;	
	int* public_ptr_mem;
	Test5(int iData, int iSrc, int* iPtr) {
		public_ptr_mem = iPtr;
		private_mem = iData;
		public_mem = iSrc;
	}
	void Display() {
		cout << private_mem << "," << public_mem <<"," <<*public_ptr_mem<< endl;
	}
};
// ���� �����ڸ� �����ε��� ���
class Test6 {
private:
	int private_mem;
public:
	int public_mem;
	int* public_ptr_mem;
	Test6(int iData, int iSrc, int* iPtr) {
		public_ptr_mem = iPtr;
		private_mem = iData;
		public_mem = iSrc;
	}
	Test6(const Test6& t) {
		
		//public_ptr_mem �ɹ� ������ ���� �Ҵ��� �޴� �ɹ� �����̴�. ���� �׳� ����Ʈ ���� ������ ���ο��� ���� ���簡 �Ͼ���� ������Ѵ�.
		public_ptr_mem = new int;				
		*public_ptr_mem = *t.public_ptr_mem;
		// 	public_ptr_mem = t.public_ptr_mem;	// �̷��� �ϸ� ����������. �� ����Ʈ ���� ������ ���°Ŷ� �ٸ��� x
		
		private_mem = t.private_mem;
		public_mem = t.public_mem;
	}
	void Display() {
		cout << private_mem << "," << public_mem << "," << *public_ptr_mem << endl;
	}
};


// reference �ɹ��� �������ִ� ��� 
class Test7 {
public:
	int mem;
	int& ref_mem;
	Test7(int iData, int& iValue):ref_mem(iValue), mem(0){
		cout << "member1: " << mem << ", "
			<< "member2: " << ref_mem << endl;

		mem = iData;
		ref_mem = iValue;

		cout << "member1: " << mem << ", "
			<< "member2: " << ref_mem << endl;
	}

};

// �ʱ�ȭ ����Ʈ ���� �����ڿ��� "����" �� ���� �ʱ�ȭ �ϴ� ���
class Test8 {
private:
public:
	int member1;
	int member2;
	Test8(int iData, int iSrc) :member1(10), member2(10) {
		cout << "member1: " << member1 << ", "
			<< "member2: " << member2 << endl;

		member1 = iData;
		member2 = iSrc;

		cout << "member1: " << member1 <<  ", "
			<< "member2: " << member2 << endl;
	}

};




int main() {

	// �� ��� �����ڵ� �������� ���� ���
	{
		Test1 t1;
		Test1 t2 = Test1();

		//cout << t1.iData << endl;	//ERROR
		cout << t2.iData << endl;
	}

	// ����Ʈ �����ڸ� ������ ���
	{
		Test2 t1;
		Test2 t2 = Test2();

		cout << t1.iData << endl;	//ERROR
		cout << t2.iData << endl;
	}

	// ����Ʈ ������ ���� �����ڸ� ������ ���
	{
		//Test3 t1;					//ERROR
		//Test3 t2 = Test3();		//ERROR
		Test3 t3 = Test3(4);

		cout << t3.iData << endl;
	}

	// ����Ʈ �����ڿ� �������̵� �����ڸ� ��� ������ ���
	{

		Test4 t1;				
		Test4 t2 = Test4();		
		Test4 t3 = Test4(4);

		cout << t1.iData << endl;
		cout << t2.iData << endl;
		cout << t3.iData << endl;

	}
	cout << endl;

	//���������
	{
		int iA = 100;
		Test5 t1(10, 20, &iA);
		Test5 t2(t1);	// ����Ʈ ��������� ���
		t1.Display();
		t2.Display();

		// �׳� public �� ����
		t1.public_mem = 22;
		t2.public_mem = 25;
		t1.Display();
		t2.Display();

		//����Ʈ ��������ڸ� ����߱� ������(���� ���縦 �߱⶧����) t1�� ���� �����ص� t2�� ���� ����ȴ�.
		*t1.public_ptr_mem = 200;	
		t1.Display();
		t2.Display();
	}
	cout << endl;

	{
		int iA = 100;
		Test6 t1(10, 20, &iA);
		Test6 t2(t1);	// ����Ʈ ��������� ���
		t1.Display();
		t2.Display();

		// �׳� public �� ����
		t1.public_mem = 22;
		t2.public_mem = 25;
		t1.Display();
		t2.Display();

		//���� ������ ���� �����ڸ� ����߰�, �� ���� ������ �ȿ��� ���� ���簡 �Ͼ���� �����߱� ������ t1�� t2�� public_ptr_mem�� ������ �ִ� �ּҰ� �ٸ���.
		*t1.public_ptr_mem = 200;
		t1.Display();
		t2.Display();

	}
	cout << endl;
	
	// �ʱ�ȭ ����Ʈ ����� ������ 
	{
		Test8 t1(100,100);

		int ia = 5;
		int& k = ia;

		Test7 t(100, k);

	}
}