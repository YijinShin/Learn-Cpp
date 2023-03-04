/* 복사 생성자를 깊은 복사를 수행하도록 오버로딩 하지 않고
그냥 디폴트 (얕은복사) 복사 생성자를 사용할 경우 발생하는 문제 */

#include "stdafx.h"
using namespace std;


class CTest{
private:
	char* szName;
public:
	CTest(const char* _szName) {
		int iLength = strlen(_szName);
		szName = new char(iLength +1);
		strcpy_s(szName, iLength+1,_szName );
	}

	~CTest() { delete[] szName; }

	char* GetName() const { return szName; }
};

void Func(CTest _t) {						// _t로 t1을 얕은 복사 해버리는바람에, _t의 szName과 t1의 szName이 같다. 
											// 이 함수 호출이 끝나는 시점에서 _t의 소멸자가 호출되면서 _t와 t1의 szName이 다 해제됨. 
	cout << _t.GetName() << endl;
}


int main() {

	CTest t1("hello");

	Func(t1);

	//이제 프로그램이 끝났으니 t1을 소멸시키려고 하는데, Func(t1)에서 이미 _t를 소멸시키면서 _t와 t1이 공유하던 szName을 소멸시킴. 
	// 그래서 '이미 소멸시킨 메모리를 또 해제하려고 한다"는 에러가 남.  
	// 에러는 Heap Corruption detected : 잘못된 힙메모리 해제시 
}