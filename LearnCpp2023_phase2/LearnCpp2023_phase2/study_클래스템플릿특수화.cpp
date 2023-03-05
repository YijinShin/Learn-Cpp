/**/

#include "stdafx.h"
using namespace std;

// 원본
template <typename T1, typename T2, typename T3, int iData>
class CTest {
public:
	void Func(T1 t1, T2 t2, T3 t3) {
		cout << "특수화 안한 CTest의 Func ("<<iData<<")" << endl;
	}
};

// 부분 특수화
template <typename T3, int iData>
class CTest<int, char, T3, iData> {
public:
	// 함수 템플릿은 부분 특수화를 할 수 없지만 클래스 템플릿의 맴버로 작성하여 부분 특수화를 흉내낼수 있다. 
	void Func(int t1, char t2, T3 t3) {	
		cout << "부분 특수화 한 CTest의 Func(" << iData << ")" << endl;
	}
};

// 완전 특수화
template <>
class CTest<int, char, float, 300> {
public:
	void Func(int t1, char t2, float t3) {
		cout << "완전 특수화 한 CTest의 Func( 고정 300 )" << endl;
	}
};


int main() {
	// 특수화 안함 
	CTest<int, int, float, 100> t1;
	t1.Func(1,11, 3.14f);

	// 부분 특수화 함 
	CTest<int, char, float, 200> t2;
	t2.Func(2, 'B', 3.14f);

	// 특수화 안함 
	CTest<int, char, float, 300> t3;
	t3.Func(3, 'B', 3.14f);
}