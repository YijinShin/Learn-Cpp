/*
 �Լ� ���ø� Ư��ȭ
	* �Լ� ���ø��� ���� Ư��ȭ�� �����ϰ� �κ� Ư��ȭ�� �Ұ����ϴ�


*/

#include "stdafx.h"
using namespace std;

// [1]
template <typename T, typename X, typename Y, int iData>
void Function(T t, X x, Y y) {
	cout << "[1] Ư��ȭ ���� Function ("<<iData<<")" << endl;
}

/* // [1]�� �κ� Ư��ȭ => �Ұ���!
template <typename Y, int iData>
void Function<float, char, Y, iData>(float t, char x, Y y) {
	cout << "[1] �κ� Ư��ȭ �� Function (" << iData << ")" << endl;
}
*/

// [1]�� ���� Ư��ȭ
template <>
void Function<float, char, double, 300>(float t, char x, double y) {	// iData���� ��������� 300���� �����߱� ������ iData�� 300�� �ƴ� �ٸ� �� ������ Ư��ȭ ���Ѱɷ� �Ҹ�
	cout << "[1] ���� Ư��ȭ �� Function (" << 300 << ")" << endl;
}

int main() {

	/* Ư��ȭ ����. */
	Function<int, char, double, 100>(1, 'a', 3.14);

	/* �κ� Ư��ȭ => �Ұ���! */
	//Function<float, char, double, 200>(2.0f, 'b', 3.14);

	/* ���� Ư��ȭ */
	Function<float, char, double, 300>(3.0f, 'c', 3.14);	// ���� Ư��ȭ �Ҹ�
	Function<float, char, double, 400>(3.0f, 'c', 3.14);	// iData�� Ư��ȭ�� ���� �ƴ϶� Ư��ȭ ���Ѱŷ� �Ҹ�

}