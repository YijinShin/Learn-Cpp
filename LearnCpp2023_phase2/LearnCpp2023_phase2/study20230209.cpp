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
/*
template <typename T>
template <typename U>
A<T>::class B {
public:
	U m_iData;
	void Display(U);
};*/


int main() {
	A<int> a1;
	A<int>::B<char> b1;

	a1.Display(10);
	b1.Display2(20,'A');
	
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
