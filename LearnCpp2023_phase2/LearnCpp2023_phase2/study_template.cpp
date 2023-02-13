/*  템플릿 

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
		void Display2(T _para2, U _para);	// 이게 맴버 탬플릿이니까 당연히 부모의 typename(T)도 사용가능하다. 
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

/* CTest2 클래스 탬플릿을 상속받은 CTest2 클래스 탬플릿*/
template <typename U>
class CTest3 :public CTest2 <char, 20> {
private:
public:
	U uData;
	void Display() { CTest2::Display(); cout << "CTest3: " << uData << endl; }
};

/* 명시적 특수화 = 특정 타입에 대해서는 클래스 구조나 맴버 함수 동작 등을 바꿈. */
template <typename T>
class CTest4 {
public:
	T data;
	void Display() { cout << "CTest4: " << data << endl; }
};
	// CTest4의 char 타입에 대한 명시적 특수화 
template <> 
class CTest4<char>
{
private:
	int a;	// 없던 맴버를 추가할 수도 있다. 
public:
	char data;
	void Display() { cout << "CTest4 <char> : " << data << endl; }	// 맴버 함수의 동작을 바꿀 수 있다. 
};

/* 부분 특수화 = 명시적특수화인데, 타입이 2개 이상일때, 그중에 하나만 특수화를 하는 경우 */



int main() {
	// 중첩 클래스 탬플릿
	{
		A<int> a1;
		A<int>::B<char> b1;

		a1.Display(10);
		b1.Display2(20, 'A');
	}
	cout << endl;
	// 하나 이상의 템플릿 인수를 가지는 클래스 탬플릿
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
	// 명시적 특수화
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
