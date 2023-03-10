/*
[ deque ]
백터보다 삽입삭제 더 느림
vector와 달리 push front, pop front 가능
맴버함수는 백터랑 거의 비슷함

블록단위 메모리할당 -> 재할당 횟수 줄이기 
------------------------------------------------------------------------------------
[ map ]
key, value가 한쌍
레드블랙트리로 구현되어있음. 
key값 기준 자동정렬됨

삽입삭제시 정렬을하기 때문에 삽입삭제에 불리함 ( 삽입삭제 자체가 문제인건아니고(노드기반은 삽입삭제가 배열기반보다 쉬움) 정렬을해야하니까 느려지는것.)
반복자 통해서 탐색 가능, 임의 접근도 가능 ([]가 오버로딩 되어있기 때문)

임의접근이 된다고해서 배열기반은 아니다. 엄연히 노드기반컨테이너임
임의접근은 key값으로 가능. 

노드기반중에 임의접근이 가능해서 탐색용으로 많이 씀. (주로 리소스 탐색용으로 많이씀)
중복 키값허용안함

-------------------------------------------------------------------------------------

[ multimap ]
[]가 오버로딩 안되어있어서  임의접근이 불가능함. 
중복 key가능

map, multimap모두 헤더는 <map>
-------------------------------------------------------------------------------------
*/

#include "stdafx.h"
#include <map>
#include <functional>
using namespace std;

struct tagFinder {
public:
	char* 

	tagFinder(char* _pTag):m_;
	template<typename T>
	bool operator()(T& myPair) {
		if (!strcmp(myPair.first)) return true;

	}
};

int main() {
	
	//map 컨테이너는 다항템플릿이다. 항목이 4개나 들어감. 
	// 1.key 자료형, 2.value자료형, 3.정렬 조건자(오름, 내림), //근데 보통은 앞에 1,2만 씀
	//map<int, int> map1;
	/* key값으로는 주로 문자열(char*, string)을 많이 씀.
		char*를 집어넣으면, 우리입장에서는 문자열상수를 넣는거지만 컴파일러입장에서는 주소값이라고 생각하지. 
		근데 프로그래머들은 char*를 좀더 선호함. string컨테이너는 (컴파일러마다 좀 다르지만) 28바이트이다. 크기가 큼
		그래서 char* 을 많이 사용함(보통 4또는8바이트밖에 안함)
		그리고 stl컨테이너로 key값을 써버리면, 최대 8글자까지밖에 저장을 못함. 정확한 이유는 잘 모름. 아마 string으로 key를 사용하면 동적할당이 일어나지 않는경우가 있는 것 같다고 한다. 그래서 기본적으로 할당된 메모리까지만 쓸 수 있는..
		뭐 이런 이슈가 있다. 모두에게 일어나는 건 아닌데 가끔있다고 한다. */

	
	// 삽입
	{
		map<int, int> mapInt;

		/*방법 1*/
				/* 얘는 앞, 뒤 이런 개념이 없어서 push back, push front는 없고 걍 insert만 있다. 
				pair 객체가 필요하다. pair역시 클래스 템플릿*/
			pair<int, int> myPair(1, 100);
			mapInt.insert(myPair);

			pair<int, int> myPair2;
			myPair2.first = 2;			//pair에 값 이렇게 삽입도 가능
			myPair2.second = 200;
			mapInt.insert(myPair2);
	
		/*방법2*/
			mapInt.insert(pair<int, int>(3, 300));	//pair임시 객체를 만들어서 사용

		/*방법3*/
				/* make_pair함수 이용하기. 얘는 함수 템플릿. 페어 임시객체를 만들어주는 함수 .
				사용은 편하지만 동작이 느림. 이걸 쓸바엔 그냥 2번방법으로 쓰는게 나음. 
				함수 템플릿이니까 사실 make_pair<int,int>(4,400) 이렇게 쓰는게 맞다. 
				int,int를 안써주면 컴파일러가 타입을 판단해야하는데, 일단 컴파일러 스스로 논리판단을 해야하는 과정이 있다는거 자체가 시간이 좀 걸림. 
				그래서 그냥 3번방법쓸바엔 2번 씀*/
			mapInt.insert(make_pair(4, 400));	

		/*방법4*/
				/* 맵 컨테이너 자체가 소유한 pair객체 만드는 문법*/
			map<int, int>::value_type myValueType(5,500);
			//myValueType.first = 5;	// 값이 상수라 안됨. 일반 pair객체와의 차이
			mapInt.insert(myValueType);

		/*방법5*/
			/* value_type의 임시객체를 사용하기
			stl은 이걸 제일 권함. 앞으로 map에 뭐 넣을때 이거 쓰기1!!!!*/
			mapInt.insert(map<int, int>::value_type(6, 600));

		/*방법6*/
			/* []대입연산자로 원소 추가. 
			이건 유의해야할 사항이 있다.
				대입연산자로 값 넣기와 insert는 동작이 다르다. 
				대입으로 새로운 노드를 넣는것은 "새로운 노드생성 후에" >> 값 대입 이 순서이다. 
				insert는 새로운 노드 생성과 동시에 값을 넣는거고
			이거 잘 안쓰는 이유
				일단 []는 오버로딩이다.
				eky값이 있는지 없는지 판단하고
					없으면 메모리공간을 할당함. >> 다른 insert 방법보다 엄청 느림
					있으면 거기에 있는 value에 씀. 

			*/
			mapInt[7] = 700;	
	
		/*방법7*/
			/* c++11에서 나온 새로운 방법
			map 컨테이너의 새로운 Inplace함수 
			걍 값 저렇게 넣으면됨. 컴파일러가 자료형 알아서 파악함
			*/
			mapInt.emplace(8, 800);	

		/*방법8*/
			/* 유니폼 초기화
			컴파일러가 알아서 자료형 판단함*/
			mapInt.insert({9,900});

		/* 5번 쓰거나
		7,8쓸거면 차라리 8을 쓰는게 좋음. 둘의 큰 속도차이는 없긴한데 보기에 더 직관적이라.(pair를 만들고있음을 보여줌) 
		뭘쓰든 큰 상관은 없는데

		대입(6번)과 insert는 다르다. 이것만 기억하자. 
		*/

		// 출력
		for (map<int, int>::iterator iter = mapInt.begin(); iter != mapInt.end();) {
			//cout << (*iter) << endl;	// 이렇게는 안됨. key인지 value인지 구별이 안가니까. 
			cout << iter->first << ", ";	//key
			cout << iter->second << endl;	//value
		}
	}

	// 찾기
	{
		map<int, int> mapInt;
		for(int i=0;i<5;i++) mapInt.insert({i,i*100});
		

		map<int, int>::iterator iter = mapInt.begin();

		//iter += 3;	//	map도 양방향반복자임 iter+=3 이런거 안됨. 무조건 ++나 --써야함
		iter++;
		iter++;
		cout << iter->first << "," << iter->second << endl;

		// 자동정렬이란 동작때문에 중간삽입의 의미가 없다. 중간에 넣어도 알아서 정렬해버림
		mapInt.insert(iter, map<int, int>::value_type(4, 4000));

		for (map<int, int>::iterator iter = mapInt.begin(); iter != mapInt.end();) {
			//cout << (*iter) << endl;	// 이렇게는 안됨. key인지 value인지 구별이 안가니까. 
			cout << iter->first << ", ";	//key
			cout << iter->second << endl;	//value
		}


		mapInt.erase(iter);	

		for (map<int, int>::iterator iter2 = mapInt.begin(); iter2 != mapInt.end();) {
			//cout << (*iter) << endl;	// 이렇게는 안됨. key인지 value인지 구별이 안가니까. 
			cout << iter2->first << ", ";	//key
			cout << iter2->second << endl;	//value
		}

		mapInt.erase(4);	// key값으로 삭제하기 

		/*erase 다음 삭제한 원소 다음을 가리키기 때문에 무조건
			iter = mapInt.erase(iter); 이런식으로 해야함. 
			이거는 뭐.. 다른 컨테이너에서도 마찬가지 */

	}
	
	// 조건자 
	{
		map<int, int, greater<int>> mapInt;	// greater에는 key값의 자료형을 넣어줘야한다. 그게 기준이니까. 
		for (int i = 0; i < 5; i++) mapInt.insert({ i,i * 100 });
	}

	//find 함수 
	{
		map<int, int> mapInt;
		for (int i = 0; i < 5; i++) mapInt.insert({ i,i * 100 });

		map<int, int>::iterator iterTarget = mapInt.find(3);	//key값이 3인애를 찾겠다. 
																//만약에 3이라는 key값이 없다면 mapInt.end()가 반환된다. 
		if (iterTarget == mapInt.end()) cout << "찾는 데이터가 없습니다." << endl;
		else cout << iterTarget->second << endl;

	}

	{
		map<const char*, int> mapInt;
		mapInt.insert({ "AA", 100 });
		mapInt.insert({ "BB", 200 });
		mapInt.insert({ "CC", 300 });

		map<const char*, int>::iterator iter = mapInt.find("BB");
		
		/*
		이렇게 찾는게 문제 생기는 경우가 있다.
		1. 파일 입출력시, 2.멀티쓰레드 3.다중 뭐..? 

		이거 char*는 주소값이기 때문에 탐색할때 문제가 될 수 있다. 
		해결방법은 find함수가 아닌 알고리즘으로 탐색하는것이다. 

		stl알고리즘중에 find_if가 있다. 
		
		*/

		map<const char*, int>::iterator iter = find_if(mapInt.begin(), mapInt.end(), );	//마지막은 조건자
		/* 조건자를 함수포인터로 만든다면 => 함수 포인터는 매개변수를 받을 수 없다. 그러면 외부 데이터를 어떻게 함수 안에서 가공할수있는가. 못한다. 
		그래서 함수 객체를 조건자로 써야한다. 
		정리) 외부 데이터를 조건자 안에서 쓸일있다면 함수 객체를 만들어야한다. (위에 만들다 말았움)*/

	}


	{
		map<const char*, int> mapInt;
		mapInt.insert({ "AA", 100 });
		mapInt.insert({ "BB", 200 });
		mapInt.insert({ "CC", 300 });

		/*
		key값으로 문자열을 많이 쓰는데
		
		char(wchar_t, TCHAR)인경우
			- 아스키 코드 기준이니까 알파벳 순 정렬이 가능하다.

		char*(wchar_t*, TCHAR*)인 경우
			- 문자열의 시작 주소를 대소비교하여 정렬이 일어남. 알파벳순이 아니라

		string(wstring)인 경우 
			- 문자열 대소 비교가 연산자 오버로딩 되어있어서 알파벳 순 정렬이 가능. 
		*/

	}

}