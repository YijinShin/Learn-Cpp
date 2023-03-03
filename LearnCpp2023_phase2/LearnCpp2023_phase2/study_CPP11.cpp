/* [ C++11부터 나온 문법들 ] 

- auto 키워드
- 범위 기반 for문 
- 유니폼 초기화
	유니폼 초기화 ({} 를 이용한 생성자 호출) 를 통해서 인자 없는 생성자가 함수의 정의로 오해되는 일을 막을 수 있으며 
	initializer_list 를 만들어 전달할 수 있습니다. 
	initializer_list 를 통해서 객체를 간단하게 생성할 수 있습니다.

*/

#include "stdafx.h"
#include <vector>
#include <list>
using namespace std;

class CTest {
public:
	CTest() { cout << "CTest생성자" << endl; };
};

class CTest2 {
public:
	CTest2() { cout << "인자가 없는 생성자" << endl; }
	CTest2(int _i, double _d) { cout << "int, double을 받는 생성자 " << endl; }
	CTest2(std::initializer_list<int> _list) { cout << "list<int>를 받는 생성자 " << endl; }
};

int main() {

	/* auto 키워드 */
	{
		vector<int> vec(5, 2);

		vector<int>::iterator iter = vec.begin();

		auto iter2 = vec.begin();	// 타입을 컴파일러가 알아서 처리해준다. 
	}

	/* 범위 기반 for문 */
	{
		int iArray[]{1,2,3,4,5};
		for (int i : iArray) cout << iArray[i] << ", ";	
		cout << endl;

		vector<int> vec{ 1,2,3,4,5 };
		//for (auto i : vec) cout << vec[i] << ",";
		cout << endl;
	}

	/* 유니폼 초기화 */
	{
		// {}로 인자 없는 생성자 호출하기
		CTest ct{};

		// {}가 컴파일되는 경우의수 
		CTest2 t1{};
		CTest2 t2(10, 10.4);
		//CTest2 t3{ 10, 10.4 };	// initializer_list를 인자로 받는 생성자가 있고, initializer_list의 타입이 int라서 초기화 리스트로 인식됨.
									// 근데 {}는 부동소수점타입 <-> 정수 타입간의 암시적 형변환을 막기 때문에 에러가 남. 
									// (int, double) 생성자를 부르려면 1. initializer_list의 타입을 아예 string이렇게 바꿔버리거나(암시적 변환이 아예 안되는 타입으로) 
									//								  2. initializer_list 를 인자로 가지는 생성자를 없애면됨. 
	}
}