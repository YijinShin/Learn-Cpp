/*
숙제
문자열길이구하는 함수 직접 만들기 (strlen말하는거임. null제외)

숙제
입력받은 문자열을 뒤집는 함수 만들기
*/

#include <iostream>
#define MAXSIZE 100

using namespace std;

typedef struct tagStudent {
	char szName[MAXSIZE];
	int iK_Score;
	int iE_Score;
	int iM_Score;
	int iTotal;
	float iAvg;
}STUDENT;

int GetStringLength(const char* szArr);
void FlipString(char* szArr);
const char* FlipString2(const char* szArr);
STUDENT GetStudentInfo();
void DisplayStudentInfo(const STUDENT* st);
void SearchStudent(const STUDENT* students, const char* szName);
void Swap(char* chData, char* chSrc);

int main() {
	
	//hw1
	{
		char szArr[MAXSIZE];
		cout << "[ 문자열 길이 구하는 함수 ]" << endl;
		cout << "문자열을 입력하세요: ";
		cin >> szArr;
		cin.ignore();
		cout <<  "문자열의 길이는" << GetStringLength(szArr) << "입니다." << endl;
		cout << endl;
	}

	//hw2
	{
		char szArr[MAXSIZE];

		cout << "[ 문자열을 뒤집는 함수 ]" << endl;
		cout << "문자열을 입력하세요: ";
		cin >> szArr;
		cin.ignore();
		FlipString(szArr);
		cout << "문자열을 뒤집으면 " << szArr << "입니다." << endl;
		cout << endl;
	}

	//hw3
	{
		int iMenu;
		bool isEnd(false);
		STUDENT students[3];
		cout << "[ 구조체를 이용한 학생 성적표 ]" << endl;

		while (1) {
			cout << "메뉴를 입력해주세요 ( 1. 입력, 2. 출력, 3. 검색, 4. 종료): ";
			cin >> iMenu;

			switch (iMenu) {
			case 1:
				for (int i = 0; i < 3; i++) {
					students[i] = GetStudentInfo();
				}
				break;
			case 2:
				for (int i = 0; i < 3; i++) {
					DisplayStudentInfo(&students[i]);
				}
				break;
			case 3:
				char szName[MAXSIZE];
				cout << "학생 이름을 입력해주세요: ";
				cin >> szName;
				cin.ignore();
				SearchStudent(students, szName);
				break;
			case 4:
				isEnd = true;
				break;
			default:
				cout << "잘못된 입력입니다." << endl;
				break;
			}

			if (isEnd) break;
		}
		cout << endl;
	}
	cout <<endl;

	// Flipstring2() 테스트 
	{
		char szArray[MAXSIZE] = "hello";
		
		const char* szFlipedArr = FlipString2(szArray);
		cout << "뒤집기! : " << szFlipedArr << endl;
	}
}

int GetStringLength(const char* szArr) {
	int iLength(0);
	int iIndex(0);
	while (1) {
		if (szArr[iIndex] != NULL) iLength++;
		else break;

		iIndex++;
	}
	return iLength;
}

void FlipString(char* szArr) {
	int iSize = strlen(szArr);
	//cout << "size:" << iSize << endl;
	for (int i = 0; i < (iSize / 2); i++) {
		Swap(&szArr[i], &szArr[iSize - i-1]);
		//cout << "swap("<<i<<" - "<< iSize-i-1 << "): " << szArr[i] << ", " << szArr[iSize - i-1] << endl;
	}
	
}

const char* FlipString2(const char* szArr) {
	int iSize = strlen(szArr);	// 문제안됨
	const int const_iSize = strlen(szArr);
	//char szFlipedArr[iSize];	// 변수는 배열 크기로 쓸 수없음. 존나 당연함.. 변수잖아 값이 바뀔 수도 있는애잖아 ㅋㅋㅋㅋㅋㅋㅋ 배열의 길이는 무조건 상수여야함. 하고싶으면 const int 변수로 해야함.
	//char szFlipedArr[const_iSize];	//엥 const 변수도 안됨.. 엇째서 
	//char szFlipedArr[strlen(szArr)];	// 이것도 상수취급안됨. szArr이 바뀌면 자동으로 값이 달라져서그런듯 

	/* ... 뭐가 다 안된대.. 짜증남 걍 동적할당 ㄱ */
	char* szFlipedArr = new char[iSize+1];
	
	//cout << "size:" << iSize << endl;
	for (int i = 0; i < iSize; i++) {
		szFlipedArr[i] = szArr[iSize - i - 1];
		cout << "->" << i << "에 " << iSize - i - 1 << "대입" << endl;
	}

	// 마지막에 문자열이 끝났다는 NULL문자 넣어주기 -> 이거 안하면 뒤에 cout으로 szFlipedArr 프린트 할 때, 어디가 문자열의 끝인지 몰라서 쓰레기값까지 다나옴.
	szFlipedArr[iSize] = NULL;	

	//cout << "결과: " << szFlipedArr << endl;

	return szFlipedArr;
}

STUDENT GetStudentInfo() {
	STUDENT newStudent;
	cout << "이름: ";
	cin >> newStudent.szName;
	cout << "국어, 영어, 수학 점수 : ";
	cin >> newStudent.iK_Score >> newStudent.iE_Score >> newStudent.iM_Score;
	newStudent.iTotal = newStudent.iK_Score + newStudent.iE_Score + newStudent.iM_Score;
	newStudent.iAvg = newStudent.iTotal / 3.f;

	return newStudent;
}

void DisplayStudentInfo(const STUDENT* st) {
	cout << "--학생 정보를 출력합니다.--" << endl;
	cout << "이름: " << st->szName << endl
		<< "국어: " << st->iK_Score << "점, 영어: " << st->iE_Score << "점, 수학: " << st->iM_Score << endl
		<< "총점: " << st->iTotal << "점, 평균: " << st->iAvg << endl;
}

void SearchStudent(const STUDENT* students, const char* szName) {
	bool isExest(false);
	for (int i = 0; i < 3; i++) {
		if (!strcmp(students[i].szName, szName)) {
			STUDENT selectedSt = students[i];
			DisplayStudentInfo(&selectedSt);
			isExest = true;
		}
	}
	if (!isExest) cout << "해당 학생을 조회할 수 없습니다." << endl;
}

void Swap(char* chData, char* chSrc) {
	char chTemp;
	chTemp = *chData;
	*chData = *chSrc;
	*chSrc = chTemp;
}
/*

홀
5/2 = 2
0,1,2,3,4
-> 4,1,2,3,0
-> 4,3,2,1,0

짝
6/2=3
0,1,2,3,4,5
-> 5,1,2,3,4,0
-> 5,4,2,3,1,0
-> 5,4,3,2,1,0
*/