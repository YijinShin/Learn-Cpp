/* [ C++11부터 나온 문법들 ] 

- auto 키워드
- 범위 기반 for문 
- 유니폼 초기화

*/

#include "stdafx.h"
#include <vector>
using namespace std;

class CTest {
public:
	CTest() { cout << "CTest생성자" << endl; };
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
		// {}로 초기화 하는 방법
		CTest ct{};
	}
}