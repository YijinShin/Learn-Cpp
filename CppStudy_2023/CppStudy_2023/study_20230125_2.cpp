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

// ����Ʈ �����ڿ� �������̵� �����ڸ� ��� ������ ���
class Test4 {
public:
	int iData;
	Test4() { iData = 10; };
	Test4(int iSrc) { iData = iSrc; };
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
}