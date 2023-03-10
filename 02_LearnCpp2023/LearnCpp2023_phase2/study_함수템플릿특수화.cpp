/*
 함수 템플릿 특수화
	* 함수 템플릿은 완전 특수화만 가능하고 부분 특수화는 불가능하다


*/

#include "stdafx.h"
using namespace std;

// [1]
template <typename T, typename X, typename Y, int iData>
void Function(T t, X x, Y y) {
	cout << "[1] 특수화 안한 Function ("<<iData<<")" << endl;
}

/* // [1]의 부분 특수화 => 불가능!
template <typename Y, int iData>
void Function<float, char, Y, iData>(float t, char x, Y y) {
	cout << "[1] 부분 특수화 한 Function (" << iData << ")" << endl;
}
*/

// [1]의 완전 특수화
template <>
void Function<float, char, double, 300>(float t, char x, double y) {	// iData까지 명시적으로 300으로 고정했기 때문에 iData에 300이 아닌 다른 값 넣으면 특수화 안한걸로 불림
	cout << "[1] 완전 특수화 한 Function (" << 300 << ")" << endl;
}

int main() {

	/* 특수화 안함. */
	Function<int, char, double, 100>(1, 'a', 3.14);

	/* 부분 특수화 => 불가능! */
	//Function<float, char, double, 200>(2.0f, 'b', 3.14);

	/* 완전 특수화 */
	Function<float, char, double, 300>(3.0f, 'c', 3.14);	// 완전 특수화 불림
	Function<float, char, double, 400>(3.0f, 'c', 3.14);	// iData가 특수화한 값이 아니라 특수화 안한거로 불림

}