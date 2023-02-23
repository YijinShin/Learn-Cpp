/*
vector 

*/


#include "stdafx.h"
#include <vector>
using namespace std;

int main() {
	
	vector<int> vecInt;	//vec가 백터의 헝가리안 표기법
	
	/* push_back
		모든 시퀀스 컨테이너는 pushback을가지고있음. 연관컨테이너는 없고*/
	for(int i=0;i<3;i++)vecInt.push_back(i);

	/* [] 인덱스 접근 */
	for (int i = 0; i < 3; i++) cout << vecInt[i];	// 여기서의 []는 오버로딩된 연산자임. 원래 백터==배열은 아니니까 (클래스템플릿임) 리얼[]는 못씀

	/* pop_back
		맨뒤의 원소 삭제
	*/
	
	/* size 
		컨테이너 내의 원소 갯수 반환함.모든 stl컨테이너에 있음.
		얘는 반환값이 unsigned int임. 갯수는 음수가 될 수 없으니까 그래서 size_t i=0;i<vec.size()이런식으로 해야함. 
	*/
		
	/* capacity
		백터 내부에 할당된 메모리 공간 개수 반환(메모리 크기가 아니라 원소가 들어가는 메모리 공간의 개수 
		5번쨰 푸쉬하는순ㄱ나 2개 더 늘려버림 이후도 원소는 1개를 넣어도 공간은 1개 이상씩 확보함 >> 재할당 최소화하기위함
		이거 컴파일러마다 얼마나 확보해주는지는 다름. 
		vs에서는 기존+ (n/2) 을함. 그래서 4 + (2/2) = 6이 되어버리는거임 
	*/

	/* clear
		컨테이너 안에 잇는 모든 원소를 삭제함. 카파시티는 그대로임. 
	*/

	/* empty
		원소가 아무것도 없으면 true, 있으면 false반환
		이거 모든 컨테이너가 가지고 있는가?
	*/

	/* swap
		두 백터를 스왑. 메모리까지 다 바꿈. 즉, 카파시티도 같이 바뀜
		모든 컨테이너가 가진 함수
	*/

	/* capacity 0으로 만들기 */
	vector<int> vec;
	vector<int>().swap(vec);	// 0개인 임시 객체랑 스왑하면 원래 vec의 메모리 0됨. 임시 객체는 바로 소멸하면서 메모리 반납하니까 

	/* shrink_to_fit
		이것도 카파시키까지 (메모리반환)0만들어주는건데 얘도 안에 까보면 결국 임시 객체랑 스왑하는 형태임 
	*/
	// 근데 사실 백터가 ㅏㅅ용다 하면 알아서 반납함. 그래서 capacity지우는거 엄청나게 막 중요하지는 않음. 

	/* front, back
		시퀀스 컨테이너에만 존재. (연관에는 앞, 뒤라는 개념이 없움)
		첫번쨰 원소의 레퍼런스 반환(이거 레퍼인지 반복자인지 확인해보기), 마지막 원소의 반복자 반환
		즉, 대입도 가능함. vec.front() = 200;, vec.back()=200; 이딴것도 됨. 
		읽기 쓰기 다 가능. cout << vec.front() 가능
		
		참고로 인덱스 접근도 쓰기 가능. 
	*/
	vector<int> v;
	//v.front() = 100;

	vector<int> v1(10);
	cout << endl;
	cout << v1.size() << "," << v1.capacity() << endl;
	cout << "before:";
	for (int i = 0; i < v1.size(); i++) cout << v1[i] << ", ";
	cout << endl;

	for (int i = 0; i < v1.size(); i++) v1.pop_back();
	
	cout << "after:";
	for (int i = 0; i < v1.size(); i++) cout << v1[i] << ", ";
	cout << endl;
	
	cout << v1.size() << "," << v1.capacity() << endl;
	v1[2] = 200;
	cout << "after:";
	for (int i = 0; i < v1.size(); i++) cout << v1[i] << ", ";
	
	/* end = 마지막원소 다음자리 */

	// 보통 백터쓸때 백터 안에 int나 float이런게 아니라 객체 포인터를 저장한다. 
	vector<CObj*> vecMonster;	//dlfjstlrdmfh 
	vecMonster.push_back(new CObj);	//이런식으로 
	// 몬스터가 몇마리, 총알이 몇발이 될지 모르니까 vector하는거임. 

}

/*
과제
- 백터 이용해서 성적표 만들기 
입력, 검색, 추가(추가인원물어봄), 삭제
*/


/*
text rpg 최종:
- 인벤토리, 아이템 사고팔기, 아이템 사용 
*/