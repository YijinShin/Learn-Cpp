/* ���� ������ */

#include "stdafx.h"
using namespace std;

/* ����Ʈ ���� ������ ��� */
class CTest1 {
private:
	int m_iData;
	int m_iSrc;
public:

};

/* ����� ���� ���� ������ ��� */
class CTest2 {
private:
	int m_iData;
	int m_iSrc;
public:

};

class CTest3 {
private:
	int m_iData;
	int m_iSrc;
public:
	

};

static int iSrc;		//�ʱ�ȭ ���� ���� ���� static ���� 

class CTest {
public:
	static int m_iData;		// class ���� static �ɹ� ���� 
};

class CTest4 {
public:
	 static int m_iA;
	static  int m_iB;

	 static int* m_iptrA;
	static int* m_iptrB;
};

int num = 10;
static int* const iptrB = &num;
static const int* iptrA = &num;

int CTest4::m_iA = 0;
int CTest4::m_iB = 0;
//int CTest4::m_iptrA = nullptr;
//int CTest4::m_iptrB = &num;

static const int* const iptrC = &num;

void AddCnt() {
	static int iCnt;
	iCnt++;
	cout << iCnt;
}

int main() {
	{
		for (int i = 0; i < 5; i++) AddCnt();
		cout << endl << endl;
	}

	/* ���� static const int* ������, static int* const ������*/
	{
		int num2 = 20;
		iptrA = &num2;
		//iptrB = &num2 //  ERROR const �� ���ٲ�
		//*iptrA = 20;	// ERROR �б� ���� �����Ͷ� ������ ���ٲ�

		cout << *iptrC << endl;
		//iptrC = &num2;
		//*iptrC = 20;
		
	}

	/*  */
	{
		int num = 10;

		//CTest4::m_iA = 10;
		//CTest4::m_iB = 10;
		//CTest4::m_iptrA = &num;
		//CTest4::m_iptrB = &num;
	}

	/* static �ʱ�ȭ �Ǵ°� Ȯ�� */
	{
	/* �Ϲ� ���� */

	/* static ���� */
	static int iNum;		// �ʱ�ȭ ���� ����, �Լ� ������ ������ static ���� 
	cout << iNum << endl;	// 0�� �������. 
	cout << iSrc << endl;	// 0�� �������. 
	//cout << CTest::m_iData << endl;	//ERROR!
	}
}
