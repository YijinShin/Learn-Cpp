#include <iostream>

using namespace std;

// �׳� �ڳ� struct�� �ɹ������� ���ϰ�, ���Ŀ� �θ� ����ü ���ϸ��

struct tagInfo0 {	// 12byte
	char cData;
	short sData;
	// 4
};

struct tagInfo1 {	// 12byte
	char cData;	
	int iData1;
	int iData2;
	// 12
};

struct tagInfo2 {
	char cData;	// 1
	short sData;	//2	 
	// ��������� �ϸ� 4
	tagInfo0 tInfo0;	// 4 + 4
	tagInfo1 tInfo1;	// 4 + 4 + 12
	tagInfo1 tInfo2;	// 4 + 4 + 12 + 12
	// �� 28
};

struct tagInfo3 {
	int iData;

	void Display() { cout << "hello" << endl; }	//  �Լ� �ɹ��� byte�� ����
	int Func1() { return 10; }	// �Լ� �ɹ��� byte�� ����
	// ����� 4����Ʈ. iData�����ش�.
};

struct tagInfo4 {
	// �ƹ��͵� ������ 1����Ʈ
};

int main() {
	tagInfo1 t1;
	tagInfo2 t2;

	tagInfo3 t3;
	tagInfo4 t4;

	cout << sizeof(t2) << endl;
	cout << sizeof(t3) << endl;
	cout << sizeof(t4) << endl;
}