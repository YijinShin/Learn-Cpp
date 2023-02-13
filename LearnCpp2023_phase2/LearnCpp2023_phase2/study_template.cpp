/*  ���ø� 

*/

#include "stdafx.h"

using namespace std;


/* class templete*/

template <typename T>
class A {
private:
	T m_iData;

public:
	template <typename U>
	class B {
	public:
		U m_iData;
		void Display(U _para);
		void Display2(T _para2, U _para);	// �̰� �ɹ� ���ø��̴ϱ� �翬�� �θ��� typename(T)�� ��밡���ϴ�. 
	};


	void Display(T _para);
};

template <typename A, typename B>
class CTest1 {
private:
public:
	A Data;
	B Src;
	void Display() { cout << "CTest1: " << Data << ", " << Src << endl; }
};

template <typename T,int i>
class CTest2 {
private:
public:
	T Data;
	void Display() { cout << "CTest2: " << Data << ", " << i << endl; }
};

/* CTest2 Ŭ���� ���ø��� ��ӹ��� CTest2 Ŭ���� ���ø�*/
template <typename U>
class CTest3 :public CTest2 <char, 20> {
private:
public:
	U uData;
	void Display() { CTest2::Display(); cout << "CTest3: " << uData << endl; }
};

/* ����� Ư��ȭ = Ư�� Ÿ�Կ� ���ؼ��� Ŭ���� ������ �ɹ� �Լ� ���� ���� �ٲ�. */
template <typename T>
class CTest4 {
public:
	T data;
	void Display() { cout << "CTest4: " << data << endl; }
};
	// CTest4�� char Ÿ�Կ� ���� ����� Ư��ȭ 
template <> 
class CTest4<char>
{
private:
	int a;	// ���� �ɹ��� �߰��� ���� �ִ�. 
public:
	char data;
	void Display() { cout << "CTest4 <char> : " << data << endl; }	// �ɹ� �Լ��� ������ �ٲ� �� �ִ�. 
};

/* �κ� Ư��ȭ = �����Ư��ȭ�ε�, Ÿ���� 2�� �̻��϶�, ���߿� �ϳ��� Ư��ȭ�� �ϴ� ��� */



int main() {
	// ��ø Ŭ���� ���ø�
	{
		A<int> a1;
		A<int>::B<char> b1;

		a1.Display(10);
		b1.Display2(20, 'A');
	}
	cout << endl;
	// �ϳ� �̻��� ���ø� �μ��� ������ Ŭ���� ���ø�
	{
		CTest1<int, char> t1;
		t1.Data = 10;
		t1.Src = 'A';
		t1.Display();

		CTest2<char, 10> t2;
		t2.Data = 'A';
		t2.Display();

		CTest3<int> t3;
		t3.Data = 300;
		t3.uData = 200;
		t3.Display();
	}
	cout << endl;
	// ����� Ư��ȭ
	{
		CTest4<int> t4;
		CTest4<char> t5;

		t4.data = 10;
		t5.data = 'A';
		
		t4.Display();
		t5.Display();
	}


	
}


template <typename T>
void A<T>::Display(T _para) {
	cout << "A: " << _para << endl;
}


template <typename T>
template <typename U>
void A<T>::B<U>::Display( U _para) {
	cout << "B: " << _para << endl;
}


template <typename T>
template <typename U>
void A<T>::B<U>::Display2(T _para2, U _para) {
	cout << "B: " << _para << endl;
	cout << "B_A typename: " << _para<<", " << _para2 << endl;
}
