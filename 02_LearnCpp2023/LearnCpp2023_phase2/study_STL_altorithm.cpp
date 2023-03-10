/* [ STL algorithm 함수 ]

- sort()
	- 구조체 템플릿이다. 
		구조체인 이유는.. 구조체는 디폴트가 public이라.. class로하면 public:써야하니까 ㅋㅋㅋ
		저거 한단어 안쓰기 위해..
	- ()를 오버로딩 하고 있다. 
	- 퀵소트 기반
	- 배열기반 
		- 
		따라서 vector, deque는 사용 가능하지만 노드기반인 list는 사용할 수 없다. 
		list는 컨테이너안에 맴버 함수로 독자적인 sort를 가지고 있다. 
		연관컨테이너는 자동정렬하기 때문에 이걸 쓰지 않는다.

- count_t
	- 범위의 원소를 하나씩 순회하면서 조건자에 집어넣고 true를 반환한 원소의 개수를 리턴함.

- for_each
	- 범위의 원소를 하나씩 순회하면서 조건자에 집어넣는다.

*/

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

template <typename T>
bool Less(T a, T b) {
	return a < b;
}

template <typename T>
class Greater {
public:
	bool operator ()(T a, T b) {
		return a < b;
	}
};

template <typename T>
bool isOdd(T a) {
	if (a % 2 == 0) return false;
	else return true;
}

template <typename T>
bool isEven(T a) {
	if (a % 2 == 0) return true;
	else return false;
}

template <typename T>
void power(T& a) {
	a = a * a;
}

struct Delete {
	template<typename T>
	void operator ()(T& a) {
		delete a;
		a = nullptr;
	}
};


template<typename T>
struct Delete2 {
	void operator ()(T& a) {
		delete a;
		a = nullptr;
	}
};

class CTest {
private:
	int m_iData;
public:
	CTest() :m_iData(0) {}
};

void Rander(vector<int>& vec) {
	for (auto i : vec) cout << i << ", ";
	cout << endl;
}

int main() {

	/* sort */
	{
		// 인자:  1. 시작 iter, 끝 iter, 정렬 조건자 
		
		vector<int> vec{ 100,60,20,50,30 };
		
		/* 조건자로 함수 템플릿 사용, 부분 정렬 */
		sort(++vec.begin(), vec.end(), Less<int>);
		Rander(vec);

		/* 조건자로 함수 객체 사용, 전체 정렬 */
		sort(vec.begin(), vec.end(), Greater<int>());
		Rander(vec);

		/* 조건자로 이미 만들어진 조건자 사용 (<functional>) */
			// less<T>()		함수 객체이다. 	
			// greater<T>()		함수 객체이다. 
		sort(vec.begin(), vec.end(), less<int>());
		Rander(vec);
	}

	/* count_t */
	{
		// 인자: 1.시작iter, 2.끝iter, 3.조건자 
		// 리턴값: 조건자에 넣어서 true를 반환한 원소 개수를 카운트해서 리턴함. 
		
		vector<int> vec{ 1,2,3,4,5 };
		int iOddCnt = count_if(vec.begin(), vec.end(), isOdd<int>);
		int iEvenCnt = count_if(vec.begin(), vec.end(), isEven<int>);

		cout << "OddCnt: " << iOddCnt << "\tEvenCnt: " << iEvenCnt << endl;
	}

	/* for_each */
	{
		vector<int> vecI{ 1,2,3,4,5 };

		for_each(vecI.begin(), vecI.end(), power<int>);
		Rander(vecI);

		/* 메모리 해제할때 이렇게 쓸 수 있다. */
		vector<CTest*> vec(5);
		cout << "for_each전: " << vec.size() << ", " << vec.capacity() << endl;
		for_each(vec.begin(), vec.end(), Delete());
		//for_each(vec.begin(), vec.end(), Delete2<CTest>());	
					/* 이거는 안되는게, 조건자로 우리는 iter를 넘겨주고있음.근데
					Delete2타입 T는 CTest로 넘겨줘야함. 이거 두개가 호환이 안되서 오류남.
					그래서 타입을 여기서 써줄필요없도록 Delete()처럼 만드는것임. */
		cout << "for_each후: " << vec.size() << ", " << vec.capacity() << endl;

	}
}