/* [ map, multimap 컨테이너 맴버 함수 공부 ]

2023.03.02
stl종류: vector, list, deque, set, multiset, map, multimap, 
		unordered_map,set,multimap, multiset

개념정리
	[map]======================================================
	* stl컨테이너기 때문에 당연히 클래스 탬플릿으로 구현되어있음.
	* key, value 한쌍으로 데이터를 저장함
	* 레드블랙트리로 구현되어있음
	* key값 기준 자동 정렬됨. 
		* key값이 문자열일 경우, 기억해야할 몇가지가 있다. 
			* char(wchar_t, TCHAR)인 경우: 아스키코드 기준 key값이기 때문에 알파벳순 정렬됨
			* char*(wchar_t*, TCHAR*)인 경우: 문자열 시작주소순으로 정렬됨.(알파벳순이 아님)
			* string(wstring)인 경우: 문자열 대소 비교가 연산자 오버로딩 되어있어서 알파벳 정렬됨.
	* 중복 key값 허용안함.
	* 연관, 노드 기반 컨테이너
	* 양방향 반복자 사용. 하지만 임의 접근 가능함([]가 오버로딩 되어있음).
		양방향이니까 당연히 iter+=3 이런건 안되고, ++, --만 사용해야함
	* 삽입삭제 : 삽입, 삭제 동작 자체는 배열기반보다 간단함. 상수시간복잡도
				그러나 삽입, 삭제시 자동정렬을 실행하기 때문에 삽입, 삭제하는데 시간이 걸리는 편이다. (자동정렬은 트리 길이에 비례함. log n )
	* 노드 기반 컨테이너 중 유일하게 임의 접근이 되기 때문에 탐색용으로 많이 사용함. (주로 리소스 탐색용으로 많이 사용함)

	[multimap]======================================================
	map과 다 똑같은데 다른점이 딱 2개 있다.
	* 중복 key값 허용함. 
	* 임의접근 안됨 ([] 오버로딩 안되어있음).

사용방법
	- map 컨테이너 객체 생성
		map컨테이너는 다항탬플릿이다. 항목이 4개 들어감. 
		1.key 자료형, 2.value자료형, 3.정렬조건자, 4.할당자(allocator)
			3. 정렬조건자: 딱히 안정해주면 기본적으로 오름차순 
			4. allocator: 유연한 메모리 관리를 위한 클래스 탬플릿. 
					   메모리 할당, 해제 동작을 하는 맴버 함수를 가지고 있다. 
					   보통 new, delete로 메모리 할당, 해제를 하는데 stl컨테이너에서는 좀 더 효율적인 메모리 할당, 해제를 하기 위해 allocator라는 클래스 탬플릿을 사용한다.
					   new는 메모리 할당과 동시에 초기화를 진행하는데 allocator에서는 할당만 함. => 불필요한 오버헤드 줄일 수 있음. 
	- 삽입
		- .insert()
			- pair
			- make_pair()
			- map::value_type
			- {} (유니폼 초기화)
		- [] (대입연산자)
		map은 연관 컨테이너이기때문에 push_back, front이런게 없음. 방향이 없음.
		map은 key, value가 한쌍이기 때문에 그냥 값을 넣는게 아니라 pair같은 객체를 넣어야함.
		중간 삽입은 의미가 없다. 어차피 자동정렬되어버리기 때문에
	
	- 삭제
		- .erase()
		erase는 다른 컨테이너에서와 마찬가지로 erase후, 삭제한 iter의 다음 iter를 반환함. 
		key값으로도 특정 값 지울수있고, iter로 지울 수 있음. 
	
	- 탐색
		- .find()
		- find_if()	
		key값으로찾거나 iter로 찾을 수 있다. 
		만약 key가 char*(문자열)라면 조건자를 직접 정의해서 find_if를 사용하는 것이 좋다. 
			char	:	정수값을 가지고 
			char*	:	주소값을 가지고 
						map<char*, int> mymap 이런경우는
						mymap.find("dd") 이러헥하면 "dd"라는 문자열의 주소값을 찾는거임. 그래서 그냥 쓰면 일단 문제 안됨. 
						근데 이게 안되는 경우가 있다는거임. 멀티쓰레드 사용시, 다중 프로젝트를 만드는 경우 등등
						여튼, 지금은 문제 없어도 나중에 문제 생기기 때문에 이것도 안전하지는 않음. 
			string	:	문자열 탐색함. (string내에 대소비교 오버로딩되어있음) 그래서 주소기반이 아니라 문자열 대 문자열 비교함.	
						근데 문자열 상수를 넣으면 그건 문제가 된는거임. 
						얘쓰면 find 문제는 안됨. 
						key주제에 용량이 좀 큰게 단점. 
						unicode기반이면 8글자 이상이 안됨
						
*/

#include "stdafx.h"
#include <map>
using namespace std;

inline void Rander(map<int, int>& map1) {
	for (map<int, int>::iterator iter = map1.begin(); iter != map1.end(); iter++)
		cout << iter->first << ", " << iter->second << endl;
}

inline void Initialize(map<int,int>& map1) {
	for (int i = 0; i < 6; i++) 
		map1.insert(map<int,int>::value_type(i, i*100));
}

struct tagFinder {
private:
	const char* m_pTag;
public: 
	tagFinder(const char* _pTag) :m_pTag(_pTag) {}	// 외부에서 char*를 받아와야하기 때문에 맴버 변수도 있고, 생성자를 쓰는 것. 

	template<typename T>
	bool operator()(T& MyPair) {
		if (!strcmp(MyPair.first, m_pTag)) return true;
		else return false;
	}
};

int main() {
	
	/* 생성 */
	{
		map<int, int> map1;
		map<char*, int, greater<int>> map2;	// 정렬 조건자까지 써줌. 정렬조건자에는 key의 자료형이 들어가야함.
	}

	/* 삽입 */
	{
		map<int, int> map1;
		
		/* 방법1: pair 객체 선언 */
		pair<int, int> myPair1(1, 100);
		map1.insert(myPair1);

		/* 방법2: pair 임시 객체 사용 */
		map1.insert(pair<int, int>(2, 200));

		/* 방법3: make_pair함수 사용 
		   make_pair는 함수 템플릿으로, pair객체를 만들어준다. 
		   함수 템플릿이니까 사실 make_pair<key, value>이렇게 타입을 다 전달해야맞는건데, 안쓰면 컴파일러가 알아서 판단해준다.
		   문제는 컴파일러가 뭔가 판단하도록 두는 것 자체가 시간을 잡아먹기 때문에 make_pair쓸바엔 그냥 2번처럼 임시객체를 쓰는게 좋다.*/
		map1.insert(make_pair(3, 300));	

		/* 방법4: value_type 사용 
			map컨테이너가 소유하고 있는, 문법.
			일반 pair와 다르게 .first나 .second로 접근이 불가능하다.*/
		map<int, int>::value_type myValue_type1(4, 400);
		map1.insert(myValue_type1);

		/* 방법5: value_type 임시 객체 사용 */
		map1.insert(map<int, int>::value_type(5, 500));

		/* 방법6: []대입연산자 사용 
			insert는 메모리 할당+초기화 
			[]로 대입은 말그대로 대입임. 
			[key]를 하면, key가 있는 경우 -> 해당 노드의 value에 값 대입, 
						 key가 없는 경우 -> 새로 메모리공간 할당 후, 값 대입함. 
			즉, 처음 값을 넣으려고 하는 경우, 일반적인 insert보다는 느림. */
		map1[5] = 5000;	// 이미 있으니, 값만 바꿈
		map1[6] = 600;	// 새로 메모리 할당 후, 값 대입

		/* 방법7: emplace함수 사용
			c++11에서 나온 새로운 문법
			map컨테이너의 맴버 함수. 
			컴파일러가 자료형 알아서 파악해줌. */
		map1.emplace(7, 700);

		/* 방법8: 유니폼 초기화
			c++11에서 나온 새로운 문법 */
		map1.insert({8,800});

		Rander(map1);

		// 추천: 5번, 8번 추천. 
		cout << endl;
	}

	/* iterator값 접근 */
	{
		map<int, int> map1;
		map1.insert(map<int, int>::value_type(1, 100));

		cout << map1.begin()->first << endl;	//key값 접근
		cout << map1.begin()->second << endl;	//value값 접근 
	}


	/* 삭제 */
	{
		map<int, int> map1;
		Initialize(map1);

		Rander(map1);

		map1.erase(map1.begin());	// iterator로 삭제
		map1.erase(5);				//key값으로 삭제

		Rander(map1);
		cout << endl;
	}

	/* 찾기 */
	{	
		/* key가 문자열이 아닌 경우 */
		{
			map<int, int> map1;
			Initialize(map1);

			map<int, int>::iterator iter = map1.find(3);
			if (iter == map1.end()) cout << "찾지 못했습니다." << endl;					// 못찾으면 end()를 반환함. 
			else cout << "찾았습니다. " << iter->first << ", " << iter->second << endl;

			iter = map1.find(10);
			if (iter == map1.end()) cout << "찾지 못했습니다." << endl;					// 못찾으면 end()를 반환함. 
			else cout << "찾았습니다. " << iter->first << ", " << iter->second << endl;
		}

		/* key가 문자열인 경우 */
		{
			/* char*인 경우 */
			map<const char*, int> map1;
			map1.insert({ "AA", 100 });
			map1.insert({ "BB", 200 });
			map1.insert({ "CC", 300 });
			map1.insert({ "DD", 400 });

			auto iter = map1.find("AA");
			if (iter == map1.end()) cout << "찾지 못했습니다." << endl;					// 못찾으면 end()를 반환함. 
			else cout << "찾았습니다. " << iter->first << ", " << iter->second << endl;
			
			/* 위에서는 문제가 없지만 char*은 그냥 find함수로 찾으면 문제가 생길 수 있다. 
			* 문제가 발생하는 경우: 파일에서 데이터를 읽어오는 경우, 멀티쓰레드 등.. 
			* 원인: char*을 key로 하면 주소값을 비교해서 찾게 됨. 
				
			* 해결: 그래서 find가 아니라 find_if라는 algorithm함수를 써야함. find_if의 마지막에는 조건자가 들어가야한다. 
					이 조건자는 char* 끼리 비교해서, 같으면 true, 다르면 false를 반환하는 함수 객체나, 함수 템플릿이 들어가야한다.*/

			iter = find_if(map1.begin(), map1.end(), tagFinder("AA"));
			if (iter == map1.end()) cout << "찾지 못했습니다." << endl;					// 못찾으면 end()를 반환함. 
			else cout << "찾았습니다. " << iter->first << ", " << iter->second << endl;

		}

		/* map의 크기 */
		{
			/* map은 size만 있다. 
			   배열기반이 아니라 그런지 capasity가 없음. 
			   어차피 노드기반이라 하나추가, 하나삭제하면 끝인걸. 백터처럼 재할당 이슈를 신경쓸 필요가 없는듯.*/
			
			map<const char*, int> map1;
			cout << map1.size() << endl;
			cout << sizeof(map1) << endl;

			map1.insert({ "AA", 100 });
			map1.insert({ "BB", 200 });
			map1.insert({ "CC", 300 });
			map1.insert({ "DD", 400 });
			
			cout << sizeof(map1) << endl;
			cout << map1.size() << endl;
		}
		
	}
}




