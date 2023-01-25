#include <iostream>
#include <string>
using namespace std;



class Cat {
private:
	const int iData1;

public:
	int const iData2;
	int a;
	Cat() :iData1(10), iData2(20) {
		a = 0;
	}
	void Display() const;
	void Display2();
};


int main() {
	{
		int a(1), b(1), c(1);
		int* ptr_arr[3] = { &a,&b,&c };
		int* ptr;
		cout << sizeof(ptr_arr) << "," << sizeof(ptr) << endl;

		int arr[3] = { 1,2,3 };
		int(*arr_ptr)[3] = &arr;
		cout << sizeof(arr_ptr) << endl;

		char* ptr2;
		cout << sizeof(ptr2) << endl;
	}

	cout << endl;

	{
		int iData(0), iSrc(1);

		const int* const ptr = &iData;
		//ptr = &iSrc;
		//*ptr = 10;
		cout << *ptr << endl;

		
	}
	cout << endl;
	{
		Cat c1;
		c1.Display();
		c1.Display2();

		const Cat c2;
		c2.Display();
		//c2.Display2();

		cout << c2.iData2 << "," << c2.a << endl;
		cout << c1.iData2 << "," << c1.a << endl;
	}
}

const void func(int* a) {
	cout << *a << endl;
	*a = 10;
}
/*
Cat::Cat() : iData1(10), iData2(20) {
	a = 10;
	//iData1 = 10; // 상수 맴버 변수는 이렇게 초기화 못함. 이건 어쨌든 선언 이후에 초기화하게 되는 거라
}*/

void Cat::Display() const {
	cout << iData1 << "," << a << endl;

	//iData1 = 100;
	//a = 200;
}


void Cat::Display2()  {
	cout << iData1 << endl;
	cout << a << endl;

	//iData1 = 100;
	a = 200;
}