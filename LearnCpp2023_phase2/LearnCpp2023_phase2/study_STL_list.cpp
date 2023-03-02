/* [ list 컨테이너 맴버 함수 공부 ] 

2023.03.02
stl종류: vector, list, deque, set, multiset, map, multimap,
		unordered_map,set,multimap, multiset

개념정리
	* 시퀀스, 노드 기반 컨테이너
	* 더블 링크드 리스트 기반
	* 노드 기반이니까 당연히 양방향 반복자를 사용함. 
		* 즉, 임의접근 안되고, iter+=3이런것도 안됨. ++, --만 사용가능
	* 삽입, 삭제는 용의함. 노드기반이고, map처럼 정렬을 하는 것도 아니기 때문
	* 탐색은 불리함. 임의접근이 안되고, 한번에 1노드씩만 이동가능해서(++,--).
		시간복잡도는 O(n) 

 사용방법
	기본적으로 vector와 거의 유사함. 

	- 삽입
		- push_back()
		- push_front()
		- insert()
	- 삭제 
		- pop_back()
		- pop_front()
		- erase()
		- clear()
	- 크기 
		-size()
	- 정렬
		-sort()
		여기서의 sort는 stl <algorithm>의 sort가 아니다. 
		list 컨테이너내의 맴버 함수임. 
		stl <algotiyhm> sort()는 퀵소트이고 배열기반이다. list는 노드기반이라 적용이 안된다.
		조건자는 당연히 function에 있는거 사용가능하다. 
	- 역순 
		-reverse()
	- 잘래내기, 이어붙이기
		- splice()
		- merge()
		vector, deque와 다르게 잘라내기, 이어붙이기가 가능하다.
		이것도 배열이 아니라 노드기반이기 때문에 가능한 것이다. 
		참고로 merge는 합병정렬이라 정렬이된다.

*/

#include "stdafx.h"
#include <list>
#include <functional>

using namespace std;

inline void Rander(list<int> _list) {
	for (auto iter = _list.begin(); iter != _list.end(); iter++)
		cout << *iter << ", ";
	cout << endl;
}

int main() {

	/* 생성 + 초기화 */
	{
		list<int> iDataList1;

		list<int> iDataList2(5);
		Rander(iDataList2);

		list<int> iDataList3(5,2);
		Rander(iDataList3);

		list<int> iDataList4{1,2,3,4};
		Rander(iDataList4);

		list<int> iDataList5(5);
		iDataList5.assign(3,100);
		Rander(iDataList5);
	}
	
	/* 삽입 */
	{
		list<int> iDataList;

		iDataList.push_back(1);
		iDataList.push_back(2);
		iDataList.push_front(0);
		iDataList.insert(++iDataList.begin(), 100);

		Rander(iDataList);
	}

	/* 삭제 */
	{
		list<int> iDataList{1,2,3,4,5};
		
		iDataList.pop_back();
		iDataList.pop_front();
		Rander(iDataList);

		list<int> iDataList2{ 1,2,3,4,5 };
		cout << "삭제 전: ";
		Rander(iDataList2);
		
		for (list<int>::iterator iter = iDataList2.begin(); iter != iDataList2.end();)
			iter = iDataList2.erase(iter);
		
		cout << "삭제 후: ";
		Rander(iDataList2); 
	}

	/* 정렬 */
	{
		list<int> iDataList{ 10,60,50,20,30 };
		cout << "정렬 전:";
		Rander(iDataList);
		
		iDataList.sort();
		
		cout << "정렬 후:";
		Rander(iDataList);
	}

	/* 역순 */
	{
		list<int> iDataList{ 10,20,30,40,50 };
		cout << "역순 전:";
		Rander(iDataList);

		iDataList.reverse();

		cout << "역순 후:";
		Rander(iDataList);
	}

	/* 잘라내기, 붙여넣기 */
	{
		/* vec1.splice(vec2) 
			vec2를 잘라내어, vec1에 붙인다. 둘다 원본 데이터가 바뀐다.*/

		list<int> iDataList1{ 10,20,30,40,50 };
		list<int> iDataList2{ 100,200,300,400,500 };
		
		auto iter1 = iDataList1.begin();
		auto iter2 = iDataList2.begin();
		iter2++;
		
		iDataList2.splice(iter2, iDataList1,iter1);	// iDataList2의 2번째에 iDataList1의 1번을 붙여넣기

		Rander(iDataList1);
		Rander(iDataList2);

		iDataList2.splice(iter2, iDataList1);	// iDataList 전체를 붙여넣기

		Rander(iDataList1);
		Rander(iDataList2);
		cout << endl;

		/* vec1.merge(vec2)
			merge는 합병정렬이다. 정렬이된다. 
			vec1쪽으로 값을 다 모아서 정렬하기 때문에 vec2는 비어진다. */

		list<int> iDataList3{ 10,20,30,40,50 };
		list<int> iDataList4{ 100,200,300,400,500 };
		iDataList3.merge(iDataList4);

		cout << "iDataList3: "; Rander(iDataList3);
		cout << "iDataList4: "; Rander(iDataList4);
	}
}