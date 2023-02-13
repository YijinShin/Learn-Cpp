#include <iostream>

using namespace std;

class CTest {
public:
	int data;
	CTest(int _idata) { data = _idata; }
};

int main() {
	CTest c1(10);
	CTest c2(10);

	c1 = c2;	//±íÀº º¹»ç
	c1.data = 20;
	cout << c1.data << " / " << c2.data << endl;
}