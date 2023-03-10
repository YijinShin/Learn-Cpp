#include "stdafx.h"
using namespace std;


class Parent {
public:
	//int iParent;
	//char cParent;
	virtual void Func() {}
};

class Child:public Parent {
public:
	char iChild;
};

int main() {
	Child c;
	Parent p;

	cout << sizeof(p) << endl;

	cout << sizeof(c) << endl;
}