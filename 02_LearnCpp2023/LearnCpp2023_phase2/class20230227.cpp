/*
[ 과제 피드백 ]
그냥 나중에 코드만 한번 확인해보고 
케스팅 응용하는 것만 공부하기 나머지는 딱히 
------------------------------------------------------------------------------------

[ list ]
탐색하고자 하는 위치를 찾으려면 원소 개수만큼 선형적 시간 복잡도를 갖는다. 그래서 탐색 용도로는 불리다. 
리스트 헝가리안 표기법은 BulletList 뒤에 List붙이기

------------------------------------------------------------------------------------

[ list맴버 함수 공부하기 ]
 
=====
listMint> intList;
intList.push_back()
for(size_t i=0;i<list.size();i++)	// 이거 size_t로 치환하는게 size는 갯수니까 unsinged int여서 그런거임
====
노드기반이니까 임의 접근 안됨 -> 접근하려면 반복자를 통한 접근만 허용함 
list[1] 이거 안되니까 
list<int>::iterator iter = list.begin();	
	근데!!! iter+=3은 안됨!! 임의접근안되니까. ( 양방향반복자는이런거 안됨. 
	할거면 iter++를 3번 하든가 해야함.. 
	
====
백터는 불가능했던거 
intList.push_front()	// 노드 기반이라 앞에도 넣을수있음. 
intList.pop_front()		// 노드 기반이라 앞에꺼도 뺄수있음 
back은 당연히 가능하고 

====
begin, end, erase, size, clear, empty, swap 등등 이런건 다 맴버 함수로 가지고 있다.
기본적인건 다 있음. 직접해봐 ㅋㅋㅋ 뭐뭐있는지 

====
insert로 중간삽입 됨. 

====
earse로 중간노드 삭제 됨.
iter = erase()이렇게 안하고 그냥 erase()이렇게 하면 에러남

====
sort
stl알고리즘 sort사용안됨. 
이거 quick기반인데, 배열기반으로 만든함수라 노드기반은 이게 불가능. 
그래서 list는 자기 sort를 따로 가지고있음. 맴버함수임 . 그래서 list.sort()이런식으로 호출해야함.
마찬가지로 조건자 사용가능함.(오름, 내림) function의 제공되는 조건자 사용가능. less<int> greater<int>

====
reverse()
들어간 원소들을 역순으로 바꿔줌

====
splice()
잘라내기 붙여넣기 하는 함수 
구간지정도 가능. 

*/

#include "stdafx.h"
#include <vector>
using namespace std;

int main() {

}