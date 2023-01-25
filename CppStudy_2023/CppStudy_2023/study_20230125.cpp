#include <iostream>
using namespace std;

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

	{

	}
}