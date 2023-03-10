/**/

#include "stdafx.h"
using namespace std;

// ����
template <typename T1, typename T2, typename T3, int iData>
class CTest {
public:
	void Func(T1 t1, T2 t2, T3 t3) {
		cout << "Ư��ȭ ���� CTest�� Func ("<<iData<<")" << endl;
	}
};

// �κ� Ư��ȭ
template <typename T3, int iData>
class CTest<int, char, T3, iData> {
public:
	// �Լ� ���ø��� �κ� Ư��ȭ�� �� �� ������ Ŭ���� ���ø��� �ɹ��� �ۼ��Ͽ� �κ� Ư��ȭ�� �䳻���� �ִ�. 
	void Func(int t1, char t2, T3 t3) {	
		cout << "�κ� Ư��ȭ �� CTest�� Func(" << iData << ")" << endl;
	}
};

// ���� Ư��ȭ
template <>
class CTest<int, char, float, 300> {
public:
	void Func(int t1, char t2, float t3) {
		cout << "���� Ư��ȭ �� CTest�� Func( ���� 300 )" << endl;
	}
};


int main() {
	// Ư��ȭ ���� 
	CTest<int, int, float, 100> t1;
	t1.Func(1,11, 3.14f);

	// �κ� Ư��ȭ �� 
	CTest<int, char, float, 200> t2;
	t2.Func(2, 'B', 3.14f);

	// Ư��ȭ ���� 
	CTest<int, char, float, 300> t3;
	t3.Func(3, 'B', 3.14f);
}