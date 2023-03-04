#include "stdafx.h"

using namespace std;


class CTest {
private:
	int m_iData;
public:
	//CTest() {}
	CTest(int _iData) { cout << "������ �����ε�" << endl; };

	
	CTest& operator= (int _iData) {
		cout << "���� ������ �����ε�2" << endl;
		return *this;
	}

	CTest& operator= (CTest& refCTest) {
		cout << "���� ������ �����ε�1" << endl;
		return *this;
	}
	
	CTest(const CTest& _refCTest) {
		cout << "���� ������ �����ε�" << endl;
	}
	
};


class CTest_defult {
public:
	CTest_defult(int _iData) {};
};

class CTest_2 {
private:
	int m_iData;
public:
	CTest_2(int _iData):m_iData(_iData) {};

	void Rander() { cout << m_iData << endl; }

	CTest_2(const CTest_2& _ct) {
		cout << "���� ������ �����ε�" << endl;
	}

	CTest_2& operator= (int iData) { cout << "���� �����ε�" << endl; }
	CTest_2& operator= (const CTest_2& iData) { cout << "���� �����ε�" << endl; return *this; }
	
	void Set(int _iData) { m_iData = _iData; }
};

class CTest_3 {
public:
	explicit CTest_3(int i) { cout << "explicit ������ " << endl; }

	//CTest_3& operator= (int a) { cout << "����Ʈ ������ �����ε� " << endl; }
};

class CTest_4 {
public:
	CTest_4(int i) { cout << "������ " << endl; }

	//CTest_4& operator = (const CTest_4& _t) { cout << "���Կ�����" << endl; return *this; }

	CTest_4(const CTest_4& _t) { cout << "���� ������" << endl; }
};

int main(){

	{
		cout << " [1]" << endl;
		CTest a = { 200 };
		CTest t(a);
		//CTest c = 100;
		t = 200;
		
	}

	
	/* ����Ʈ ���� �����ڿ� ����Ʈ ���Կ����� */
	{
		cout << " [2]" << endl;
		// ���������, ���Կ����� ��� �����ε��� 
		CTest x1 = 100;		// ���Կ�����
		CTest x2 = { 100 };	// ���Կ�����
		CTest x3 = x2;		// ���� ������
		CTest x4(x3);		// ���� ������
			
		x1 = x2;			// ���Կ�����
	}


	/* ����Ʈ ���� �����ڿ� ����Ʈ ���Կ����� */
	{
		cout << " [3]" << endl;
		// ���������, ���Կ����� ��� ����Ʈ�� ���� ��ü���� 
		CTest_defult x1 = 100;	// ����Ʈ ���Կ�����
		CTest_defult x2 = { 100 };	//����Ʈ ���Կ�����
		CTest_defult x3 = x2;	//����Ʈ ���� ������
		CTest_defult x4(x3);	// ����Ʈ ���� ������

		x1 = x2;				// ����Ʈ ���� ������ 
	}

	/* �����ε� ���� �����ڿ� ����Ʈ ���Կ����� */
	{
		cout << " [4]" << endl;
		// ���������, ���Կ����� ��� ����Ʈ�� ���� ��ü���� 
		CTest_2 x1 = 100;		// ����Ʈ ���Կ�����
		CTest_2 x2 = { 100 };	//����Ʈ ���Կ�����
		CTest_2 x3 = x2;		//����Ʈ ���� ������
		CTest_2 x4(x3);			// ����Ʈ ���� ������
		
		//- -----------------------------------------------------

		x1 = x2;	// ����Ʈ ���� ������	(��ü�� ���׿� ������ �̰� ���� �����ڰ� �Ҹ�!)
		
		// x1, x2�� ��� ��ü �����Ͱ� �ƴ� �׳� ��ü�ϱ� ���� ���簡 �Ͼ�� ������. 
		x1.Rander();
		x2.Rander();
		x1.Set(200);
		x1.Rander();
		x2.Rander();
		cout << endl;
		//- -----------------------------------------------------
		
		CTest_2* xp1 = new CTest_2(100);
		CTest_2* xp2 = new CTest_2(100);
		
		xp1 = xp2; // ����Ʈ ���� ������	(��ü�� ���׿� ������ �̰� ���� �����ڰ� �Ҹ�!)

		// xp1, xp2�� ��ü �������̹Ƿ� ����Ʈ ���� �������� ��������� ���� ��ġ �ʴ°���� ���´�. 
		xp1->Rander();
		xp2->Rander();
		xp1->Set(200);
		xp1->Rander();
		xp2->Rander();
	}

	/* explicit */
	{
		cout << "[7]" << endl;
		//CTest_3 a = 100;	// explicit������ ����Ʈ ���Կ����� ���� 
		CTest_3 a(100);
		//a = 100;
	}

	// ����Ʈ ���� ������, const CTest_4& �� ���ڷ� �޴� ���� ������ �����ε� ��
	{
		cout << "[6]" << endl;
		CTest_4 a = 100;
		CTest_4 b = 200;

		a = b;

	}
	
}