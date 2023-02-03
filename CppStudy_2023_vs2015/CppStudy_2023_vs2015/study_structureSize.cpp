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

struct tagInfo5 {
	int& iRef;
};

struct tagInfo6 {
	char szName[20];
	int iData;

};

int main() {
	tagInfo1 t1;
	tagInfo2 t2;

	tagInfo3 t3;
	tagInfo4 t4;

	tagInfo6 t6;

	int iData = 10;
	tagInfo5 t5{iData};	// �̰� ref������ �־ ������ �ʱ�ȭ �ؾ���. 
						// �ʱ�ȭ�� �Ű������� �ƴϴ�. �׷��ϱ� ����� �ȵ�! 

	cout << sizeof(t2) << endl;
	cout << sizeof(t3) << endl;
	cout << sizeof(t4) << endl;
	cout << sizeof(t5) << endl;	// int Ref�� 4byte����. 
	cout << sizeof(t6) << endl;


	{
		char szDest[15] = "xxxxxxxxxxxxx";
		char szSrc[5] = "aa";
		strcpy_s(szDest, 3, szSrc);

		cout << szDest << endl;		// ���ڿ��� �ν��ؼ� ����ϹǷ� "aa"������ ����

		for (int i = 0; i < 15; i++) {	// ���ڿ��� ������ �׳� �޸� ������ �����ؼ� �� ��ȸ�غ���
			cout << szDest[i];
		}
	}

	{
		char szData[20] = "hellohellohello";
		char szSrc[20] = "bye bye";
		cout << endl;
		memcpy(szData, szSrc, 3); // ����� byelo
		cout << szData << endl;
		memcpy(szData, szSrc, 20); // ����� bye b
		cout << szData << endl;
	}

	{
		char szName[5] = { 'C' };
		cout << szName[3] << endl;
	}

	{
		short* sPtr = new short[2] {1,2};

		cout << sPtr << " == "<< &sPtr[0]<<  endl;
		cout << sPtr + 1 << " == " << &sPtr[1] << endl;

	}
}