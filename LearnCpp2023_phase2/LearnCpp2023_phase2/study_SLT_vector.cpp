/* [ vector 컨테이너 맴버 함수 공부 ] 

2023.03.02
stl종류: vector, list, deque, set, multiset, map, multimap,
		unordered_map,set,multimap, multiset

개념정리 
* stl컨테이너기 때문에 당연히 클래스 템플릿으로 구현되어있음
* 시퀀스, 배열 기반 컨테이너
* 배열 기반이니까 임의 접근 반복자를 사용한다.
* 당연히 [] 임의접근 가능. 
* 동적 배열을 기반으로 한다.
* 삽입, 삭제에 불리하다. 
	* 일단 중간 삽입, 삭제시 기존 요소들을 뒤로 밀거나 앞으로 당겨야함. 
	* 삽입시 재할당이 발생할 수 있음. 
	  재할당 과정은 [ 더 큰 사이즈 배열 확보 -> 기존 데이터 복사 -> 기존 배열 삭제 ] 이렇게 됨. 
	  당연히 여러번 재할당이 발생하면 시간을 잡아먹음. 
* 탐색에 용이함. 임의접근이 가능하기 때문에 
* 

기능정리
	- 삽입 
		- push_back()
		- insert()
	
	- 삭제
		- pop_back()
		- erase()
		- clear()
		- 빈 백터 임시객체와의 swap()
		- shrink_to_fit() 
		위에 셋은 요소를 삭제해서 size는 줄어도 capacity는 줄지 않는다. 
		재할당 이슈때문에 capa를 매 요소 삭제마다 줄이는게 좋은건 아니다.  
		백터의 타입으로 포인터가 있는경우, 해당 포인터를 먼저 해제하고, 백터 요소를 삭제해야한다.
	
	- 크기 
		- size()
		- capacity()
		- empty()
	
	- 교체
		- swap()
	
	- 사이즈 변경
		- resize()
		size를 바꾸는거지 capacity를 바꾸는게 아니다. 
		size가 현재 capacity보다 크게 바꿀 경우 당연히 재할당이 발생하면서 capacity도 바뀌지만
		size를 현재 capa보다 작게 바꾼다고해서 capa가 줄지 않는다. 
	- 예약
		- reserve()
		capacity만 미리 예약하는 것이다. 원소를 넣지 않음. size는 그대로고 capa만 늘어난다. 
		만약에 어떤 백터를 얼마난 크기르 쓸지 미리 알고있다면, 
			당연히 재할당 이슈를 줄이기위해 reserve를 해놓고 쓰는게 좋다. 

*/

#include "stdafx.h"
#include <vector>

using namespace std;

inline void Rander(vector<int>& vec) {
	for (auto iter = vec.begin(); iter != vec.end(); iter++) cout << *iter << endl;
	cout << endl;
}

inline void Initialize(vector<int>& vec) {
	for (int i = 0; i < 6; i++) vec.push_back(i * 10);
}

class CTest {
private: 
	int m_iData;
public:
	CTest():m_iData(0) {}
};

template <typename T>
void Safe_Delete(T& temp) {
	delete temp;
	temp = nullptr;
}

int main() {

	/* 생성, 초기화 */
	{
		vector<int> iVec1;	// 생성. 
		vector<int> iVec2(5);	// 길이가 5인 vector생성 후, 다 0으로 초기화
		int iArr[10] = { 10 };	//이렇게 하면 0번 인덱스는 10이고, 나머지는 다 0으로 초기화 
		vector<int> iVec3 = { 1,2,3 };	//길이가 3인 vector생성 후, 초기화 
		vector<int> iVec4[] = { {1,2},{3,4} }; // 백터 배열생성. 행 가변, 열 고정 
		vector<vector<int>> iVec5;	//행,열 모두 가변 
		vector<int> iVec6(5);
		iVec6.assign(5, 10);	// 범위 5까지를 모두 10으로 초기화 
	}

	/* 삽입 */
	{
		vector<int> veciData;

		// 배열기반이라 뒤에서밖에 못넣음. push_front는 없음. 
		veciData.push_back(10);
		veciData.push_back(20);
		veciData.push_back(30);
		veciData.push_back(40);

		// insert로 중간에 삽입하기 => 근데 효율 엄청 안좋음. 나머지는 다 뒤로 밀어야하니까 
		vector<int>::iterator iter = veciData.begin();
		iter += 2;
		veciData.insert(iter, 1000);

		Rander(veciData);
	
	}

	/* 삭제 */
	{
		vector<int> veciData;
		Initialize(veciData);

		// 제일 뒤에있는거 삭제 pop_front는 없음. 
			veciData.pop_back();		

		// 중간 요소 삭제 => 근데 효율 엄청 안좋음. 나머지는 다 앞으로 밀어야하니까
			veciData.erase(veciData.begin() + 3);	// erase한 iter의 다음 iter를 반환함. 
			cout << veciData.size() << ", " << veciData.capacity() << endl;
			Rander(veciData);

		// 원소 전체 삭제
			veciData.clear();
			cout << veciData.size() << ", " << veciData.capacity() << endl;


		/* 백터의 원소가 포인터인경우 단순히 요소만 삭제하면안된다. 
			1. safe_delete (*iter)
			2. vec.erase(iter) 
			이렇게 해야, 그 백터의 요소도 동적메모리 해제하고, 백터의 요소도 지울 수 있다. 
			1을 안하고 erase만하면 포인터랑, 그 포인터가 가리키는 heap메모리는 우주미아가 된다.*/
			vector<CTest*> vecCTest(5);
			for (auto iter = vecCTest.begin(); iter != vecCTest.end();) {
				Safe_Delete(*iter);
				iter = vecCTest.erase(iter);	// 삭제한 iter의 다음 iter를 반환함. 
			}

			cout << vecCTest.size()<< ", "<<vecCTest.capacity() << endl;
			cout << endl;
					
		/* 정 capacity도 줄이고 싶다면 빈 백터 임시객체를 사용하는 방법도 있다. */
			vector<int> veciData2;
			Initialize(veciData2);
			cout << "swap전: ";
			cout << veciData2.size() << ", " << veciData2.capacity() << endl;
			Rander(veciData2);
		
			vector<int>().swap(veciData2);	/* vector<int>()가 임시객체이기 때문에 swap하면
											vector<int>()에 veciData2가 들어가지만 이 명령줄이 끝나면 사라짐. */
			cout << "swap후: ";
			cout << veciData2.size() << ", " << veciData2.capacity() << endl;
			Rander(veciData2);

		// shrink_to_fit() 으로 capacity를 원소에 딱 맞게 줄이기 
			vector<int> veciData3;
			for(int i=0;i<5;i++) veciData3.push_back(i*10);
			cout << "shrink_to_fit전: " << veciData3.size() << ", " << veciData3.capacity() << endl;
			veciData3.shrink_to_fit();
			cout << "shrink_to_fit후: " << veciData3.size() << ", " << veciData3.capacity() << endl;
	}

	/* 크기 */
	{
		/* capacity는 1개씩 늘어나는게 아니라 재할당 이슈를 줄이기 위해 
			한번 추가될 때 n개씩 추가된다. 
			컴파일러마다 정책은 다르지만 vs는 재할당시 currCapa + currCapa*0.5 로 늘린다.*/
		vector<int> vec;

		for (int i = 1; i <= 7; i++) {
			vec.push_back(i * 10);
			/* size: 원소의 개수 */
			cout <<"size: " << vec.size() << ",";
			/* capacity: 저장할 수 있는 원소의 개수 */
			cout <<"capacity: "<< vec.capacity() << endl;
		}
		cout << endl;

		// empty() 원소가 있는지 확인 
		if (vec.empty()) cout << "비었음." << endl;
		else cout << "원소있음" << endl;
	}

	/* 교체 */
	{
		vector<int> vec1(5,3);
		vector<int> vec2(5,2);
		vec2.swap(vec1);		// vec1.swap(vec2)와 같다. 어느쪽이든 상관없음.

		Rander(vec1);
		Rander(vec2);
	}

	/* 사이즈 변경 */
	{
		vector<int> vec(5, 0);

		cout << "resize전: " << vec.size() << ", " << vec.capacity() << endl;

		vec.resize(3);	// capa보다 작게 변경

		cout << "resize후: " << vec.size() << ", " << vec.capacity() << endl;

		vec.resize(11);	// capa보다 크게 변경 (capa도 지정한 11로 늘어난다. 11로 재할당함.)

		cout << "resize후: " << vec.size() << ", " << vec.capacity() << endl;
	}

	/* 예약 */
	{
		vector<int> vec;
	
		cout << "reserve전: " << vec.size() << ", " << vec.capacity() << endl;

		vec.reserve(5);

		cout << "reserve후: " << vec.size() << ", " << vec.capacity() << endl;
	}
}

