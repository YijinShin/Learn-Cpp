/* 동적할당2 new

- new는 내부적으로는 malloc으로 만들어져있어서 쓰면 쓰레기로 초기화됨
- 그치만 초기화 값을 할당시에 넣을 수 있도록 가능

int* p = new int(10)// 이렇게 초기화값 넣어줄 수있음




*/

#include < iostream>
using namespace std;

int main() {

	{
		int* p = new int(10);

		cout << p << endl;	// delete전 p 주소(의미있는주소)
		delete p;	// delete는 free와는 다르게 기존 주소를 가지고있도록하지는 않음. 그래도 p에 원치 않는 주소를 가지게 되므로 역시나 댕글링 포인터임. 그래서 nullptr넣어줘야함 
		cout << p << endl;	// delete후 p 주소(이전의 주소를 그대로 가지고 있지는 않지만 여전히 의미없는주소)
		p = nullptr; // 댕글링 포인터 처리를 위해 이렇게 해주는거 습관들이기

		int* p_arr = new int[4];
		int* p_arr2 = new int[4] {1,2,3,4};	// 유니폼 초기화! {}를 딱 붙여서 쓰는거 이거 c++11이후부터 가능한거임. 이거 유니폼 초기화 자체가 원래 c++11이후부터 나와서 그전꺼는 안될껄 
		
		// 애초에 보통 일일히 초기화 안함
		int* iArr = new int[5];
		delete[] iArr;	// 배열할당받으면 delete이렇게 함
		iArr = nullptr;

	}
	//그럼 동적할당한 공간 0으로 어케 채움? => 메모리함수

		/*memset: 메모리 공간의 값을 원하는 값으로 체우는 함수. 대체적으로 블록 단위 데이터를

		매개변수
		memset[초기화할 공간의 주소값], [바이트단위로 채우고자하는 값] [값을 채우고자하는 메모리]
		*/

	cout << endl;
	{
		int iArr[5] = { 1,2,3,4,5 };
		memset(iArr, 0, sizeof(iArr));	// 이거 두번째꺼는 바이트 단위라서 1라고 쓴다고 1로 초기화되는거 아님! 근데 대분 0으로 많이 씀 
		for(int i=0;i<5;i++) cout << iArr[i]<<endl;
	}

	/*memcpy: 메모리대 메모리 복사를 수행하는 함수 
	 [복사받을 사본데이터의 주소][원본 데이터 주소][사본 메모리 크기]

	*/
	cout << endl;
	{
		int iArr1[5] = { 1,2,3,4,5 };
		int iArr2[6];

		memcpy(iArr2, iArr1, sizeof(iArr2));
		for (int i = 0; i < 5; i++) cout << iArr2[i] << endl;
	}
	/* memmove: 메모리 대 메모리로 값을 복사 이동 (원본값 역시 사라지지 않음)
	memcpy와 걷으로는 차이가 없음.
	근데 동작과정에서 좀 차이가 잇다. 
	memcpy는 직접적으로 바이트 단위로, 바로 복사해오는데
	memmove는 원본데이터 만큼의 임시 버퍼를 만들고, 원본 -> 임시버퍼 -> 목적지 이렇게 값을 이동시켜서 복사한다.
	그래서 사실 memcpy가 더 빠름. 
	근데 왜 memmove가 있는가 -> 제공되는 환경땜에그렇다. memcpy는 리눅스 운영체제에서는 사용불가능. memmove는 리눇에서도 사용가능 
	
	*/
	cout << endl;
	{
		int iArr1[5] = { 1,2,3,4,5 };
		int iArr2[6];

		memmove(iArr2, iArr1, sizeof(iArr2));
		for (int i = 0; i < 5; i++) cout << iArr2[i] << endl;
	}


	/* 할당받은 메모리 해제 안하면 메모리 누수가 발생함.
	메모리 누수가 나는지 컴파일러가 알려주는거 -> 디버깅 모드 F5로 실행해야함. 이거 프로그램다 돌리고 밑에 누수되는게 있다 이런식으로 알림 뜸. 
		delete안쓰고 한번해봐
	컨트롤 F5: 콘솔에 실행
	F5는 디버그 모드에서 계속 검사하겠다는것.
	
	참고로 메모리 누수 잡는거 완전 필수적임 */
	{
		
	}
}

/*
과제 : test rpg를 new, delete사용해서 구현하기 

*/