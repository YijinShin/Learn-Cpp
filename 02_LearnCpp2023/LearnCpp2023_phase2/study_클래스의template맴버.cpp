#include "stdafx.h"
using namespace std;


class CTest {
public:
	template<typename T>
	void Func(T a) {
		cout << "�Լ� ���ø� ���: " << a << endl;
	}
};

int main() {

	CTest t;
	t.Func<int>(10);


}