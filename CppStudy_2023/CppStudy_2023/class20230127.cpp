/*
1. 문자열 관련 함수들 
2. 구조체 


*/

#include <iostream>
using namespace std;


typedef struct tagInfo
{
	int iMath;
	int iEng;

	// C는 구조체가 맴버 함수를 가질 수 없었는데, cPP부터는 가능해짐. 
	void Display() {
		cout << iMath << "," << iEng << endl;
	}
	

}INFO, *PINFO; // 여거도 알아보기 


struct tagTemp {
	char sData;
	short iData;
	int sData2;
	float dData;
};

// 이거 위, 아래 두개는 구조체 크기가 다름. 위에기 12, 밑이 16. 왜 -> 맴버 위에서 부터 채우거든? 그럼 
// 위에는 ) 8할당 > -1-2-4-float 이렇게 감
// 아래는 ) 
struct tagTemp2 {
	char sData2;
	int sData;
	short iData;
	float dData;
};

struct tagTemp3 {
	char sData2[20];	// 이런경우라고해서 기준이 20바이트가 아니다! 무조건 자료형 중에 제일 큰바이트 기준으로 할당이라 여기서도 역시 float기준으로 할당하 
	int sData;
	short iData;
	float dData;
};

struct tagTT {
	long long ll1;
	long long ll1;
};

// 이런 경우에도 무조건 기본 자료형 기준으로 가장 큰 메모리 타입을 기준으로 삼는다. 
struct tagTemp3 {
	// +4
	short iData;	//2
	//+4
	int sData;	//4
	//+4

	float fData;	//4
	//long long dData;	// 8	// 얘지우면 32인데 why?

	tagTT  tt;	// 16
};

struct tagTemp3 {
	// +8
	short iData;	//2

	int sData;	//4
	//+8

	float fData;	//4
	//+8
	long long dData;	// 8	// 얘지우면 32인데 why?

	tagTT  tt;	// 16
};


/*

typedef struct tagInfo
{
	int iMath;
	int iEng;
}INFO, MONSTER, *PINFO;	// 이따구로도 가능함 

*/



int main(){


	/* 문자 배열과 문자열 상수의 차이점
	- 공통점: 둘 다 문자열의 시작 주소를 갖고있다.
	- 문자 배열은 문자 하나하나를 배열의 원소에 저장하는 방식
	- 문자 배열은 char const* 형태와 동작 동일하다.
		주소값의 변경은 불가능해도, 저장하는 데이터는 변경가능
	- 문자열 상수는 데이터 영역에 등록된 문자열의 시작 주소를 담는다.
	- 문자열 상수는 const char* 형태와 동작이 동일하다.
	지금 const 위치가 다르지, 이거 포인터니까 읽기 쓰기 가능한것에 대한 문제임. 
	문자열 상수는 읽기 전용! 위에서 const가 중간에 붙은거는 주소를 변경할 수 없다는 의미의 const!
	*/

	//------------------------------------------------------------------------------------------------------
	//문자열 복사 함수 
	{
		char szTemp[6] = "jusin";
		char szArray[16] = "serewerwrewr";
		// 바이트 옵션안준경우 -> 알아서 전체 바이트 복사함, 그리고 나머지는 다 지워버림
		strcpy_s(szArray, szTemp);
		cout << szTemp << endl;
	}
	cout << endl;


	{
		char szTemp[6] = "jusin";
		char szArray[16] = "serewerwrewr";
		// 정확히 몇 바이트까지 복사할지 정해주는 옵션을 쓴 경우
		strcpy_s(szArray,6, szTemp);
		cout << szTemp << endl;

		for (int i = 0; i < 16; i++) {
			cout << szArray[i];	// 앞에 8바이트 이후는 원래 szArray가 들어있다.
		}
	}

	{
		//복사를 받는 대상이 복사 해오는 대상보다 더 작은 경우 -> 실행하면 에러남
		char szTemp[6] = "jusin";
		char szArray[16] = "serewerwrewr";
		//strcpy_s(szTemp, szArray);	// ERROR
		cout << szTemp << endl;

		for (int i = 0; i < 16; i++) {
			cout << szArray[i];	// 앞에 8바이트 이후는 원래 szArray가 들어있다.
		}
		cout << endl;
	}

	/* 문자열 상수를 복사해오는건 가능하지만 문자열 상수끼리 서로 복사하는건 불가능. 
	쓰는 측도 문자열 상수라는 것이니까 -> 당연히 쓰기가 불가능. 읽기 전용임*/

	//------------------------------------------------------------------------------------------------------
	// 문자열 길이 계산 함수
	cout << endl;
	{
		//이거는 문자열의 순수한 길이임. 
		//size_t strlen(char const* _Str);

		char szName[32] = "hello";	// 32만큼의 크기를 확보했어도, 문자열의 길이가 5니까 이건 5 (널문자는 카운팅 안함)

		cout << strlen(szName) << endl;					// 순수하게 문자가 들어가있는, 문자열의 길이
		cout << strlen("hello") << endl;					// 문자열 상수도 넣을 수 있음. 
		cout << sizeof(szName) << endl;	// 이건 메모리 크기를 통해 구한것.
		cout << sizeof("hello") << endl;	// 이건 메모리 크기를 통해 구한것. => char 타입 문자 5개 + 널 1개  = 6개
	}
	//------------------------------------------------------------------------------------------------------
	//문자열 비교함수
	cout << endl;
	{
		//int strcmp(char const* _str1, char const* _str2)
		// 일치하면 => 0반환! 1이 아님!


		char szName[32] = "홍길동";
		cout << sizeof("홍길동") << endl;	 // 홍길동은 2바이트, 널은 1 => 총 2*3 +1 = 7임. (홍, 길, 동 이것들은 유니코드임)
		if (strcmp(szName, "홍길동")) {
			cout << "불일치" << endl;
		}
		else cout << "일치" << endl;
	}
	//------------------------------------------------------------------------------------------------------
	//문자열 결합 함수
	cout << endl;
	{
		// erron_t strcat_s(char* _dest, rsize_t _sizeinbyte, char const* str)
		// 인수: 결합 겨로가를 저장할 최종 문자열, 첫번쨰 매개변수의 버퍼사이즈, 결합할 문자열 

		char szTemp[32] = "jusin";
		char szDest[32] = "academy";

		strcat_s(szTemp, sizeof(szTemp), szDest);
		cout << szTemp << endl;	// 이 목적지가 메모리가 부족하면 실행시 에러남
		cout << szDest << endl;	// 걍복사해다가 temp쪽에 붙인거니까 당연히 얘는 그대로 남아있음 

		cout << sizeof(szTemp) << endl;
		cout << sizeof(szDest) << endl;
		cout << strlen(szTemp) << endl;	// 얘는 결합 후 5에서 12로 늘어남
		cout << sizeof("jusinacademy") << endl;	//이렇게 보면 널문자 떄문에 당연히 12가 아니라 13이 나옴. 
		cout << strlen(szDest) << endl;
	}
	/*
	숙제
	문자열길이구하는 함수 직접 만들기 (strlen말하는거임. null제외)

	숙제
	입력받은 문자열을 뒤집는 함수 만들기
	
	*/
	// 만들어쓰는 자료형 ~ 구조체~!
	cout << endl;

	{
		// 구초체 쓰는법..알지..? 그거 복습하기 
		// 나 노느라 필기 못함 고양이의 요정 그렸음 
		// 구조체 + typedef로 구조체 이름 쓰는거 그거도 복습하기 

		// 구조체 포인터 변수 선언하면 초기화 하는거랑 -> 이거 쓰는것도 같이 정리하기 

		// 구조체간 상속, 
		// 구조체와 클래스 간의 상속 이것도 정리하기 

		tagTemp t1;
		cout << sizeof(t1) << endl;
		// 구조체는 블록단위 데이터  => 이거 할당하는거 알지? 
		//제일 큰거를 할당하고, 그거 공유해서 쓰는거 그리고 부족하면 +해서 쓰는 그 거임 
		// 어쨌든 그래서 같은 맴버라도 무조건 메모리 크기가 작은 변수부터 쓰는게 좋음. 

		tagTemp2 t21;
		tagTemp t11;

		cout << sizeof(t1) << endl;

		cout << sizeof(t21) << endl;


	}
	cout << endl;

	/*
	숙제
	구조체를 이용하여 세 명의 학생 성적표 입출력 프로긂 만들기
	함수 만들어서 입출력해 
	- 1. 입력, 2. 출력, 3. 검색출력(이름으로 검색) 4. 종료 
	
	*/
}