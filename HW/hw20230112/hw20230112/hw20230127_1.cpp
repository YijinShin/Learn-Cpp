/*
寿薦
庚切伸掩戚姥馬澗 敗呪 送羨 幻級奄 (strlen源馬澗暗績. null薦須)

寿薦
脊径閤精 庚切伸聖 及増澗 敗呪 幻級奄
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
		cout << "[ 庚切伸 掩戚 姥馬澗 敗呪 ]" << endl;
		cout << "庚切伸聖 脊径馬室推: ";
		cin >> szArr;
		cin.ignore();
		cout <<  "庚切伸税 掩戚澗" << GetStringLength(szArr) << "脊艦陥." << endl;
		cout << endl;
	}

	//hw2
	{
		char szArr[MAXSIZE];

		cout << "[ 庚切伸聖 及増澗 敗呪 ]" << endl;
		cout << "庚切伸聖 脊径馬室推: ";
		cin >> szArr;
		cin.ignore();
		FlipString(szArr);
		cout << "庚切伸聖 及増生檎 " << szArr << "脊艦陥." << endl;
		cout << endl;
	}

	//hw3
	{
		int iMenu;
		bool isEnd(false);
		STUDENT students[3];
		cout << "[ 姥繕端研 戚遂廃 俳持 失旋妊 ]" << endl;

		while (1) {
			cout << "五敢研 脊径背爽室推 ( 1. 脊径, 2. 窒径, 3. 伊事, 4. 曽戟): ";
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
				cout << "俳持 戚硯聖 脊径背爽室推: ";
				cin >> szName;
				cin.ignore();
				SearchStudent(students, szName);
				break;
			case 4:
				isEnd = true;
				break;
			default:
				cout << "設公吉 脊径脊艦陥." << endl;
				break;
			}

			if (isEnd) break;
		}
		cout << endl;
	}
	cout <<endl;

	// Flipstring2() 砺什闘 
	{
		char szArray[MAXSIZE] = "hello";
		
		const char* szFlipedArr = FlipString2(szArray);
		cout << "及増奄! : " << szFlipedArr << endl;
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
	int iSize = strlen(szArr);	// 庚薦照喫
	const int const_iSize = strlen(szArr);
	//char szFlipedArr[iSize];	// 痕呪澗 壕伸 滴奄稽 承 呪蒸製. 糎蟹 雁尻敗.. 痕呪摂焼 葵戚 郊介 呪亀 赤澗蕉摂焼 せせせせせせせ 壕伸税 掩戚澗 巷繕闇 雌呪食醤敗. 馬壱粛生檎 const int 痕呪稽 背醤敗.
	//char szFlipedArr[const_iSize];	//触 const 痕呪亀 照喫.. 譲属辞 
	//char szFlipedArr[strlen(szArr)];	// 戚依亀 雌呪昼厭照喫. szArr戚 郊餓檎 切疑生稽 葵戚 含虞閃辞益訓牛 

	/* ... 更亜 陥 照吉企.. 促装害 袷 疑旋拝雁 ぁ */
	char* szFlipedArr = new char[iSize+1];
	
	//cout << "size:" << iSize << endl;
	for (int i = 0; i < iSize; i++) {
		szFlipedArr[i] = szArr[iSize - i - 1];
		cout << "->" << i << "拭 " << iSize - i - 1 << "企脊" << endl;
	}

	// 原走厳拭 庚切伸戚 魁概陥澗 NULL庚切 隔嬢爽奄 -> 戚暗 照馬檎 及拭 cout生稽 szFlipedArr 覗鍵闘 拝 凶, 嬢巨亜 庚切伸税 魁昔走 侯虞辞 床傾奄葵猿走 陥蟹身.
	szFlipedArr[iSize] = NULL;	

	//cout << "衣引: " << szFlipedArr << endl;

	return szFlipedArr;
}

STUDENT GetStudentInfo() {
	STUDENT newStudent;
	cout << "戚硯: ";
	cin >> newStudent.szName;
	cout << "厩嬢, 慎嬢, 呪俳 繊呪 : ";
	cin >> newStudent.iK_Score >> newStudent.iE_Score >> newStudent.iM_Score;
	newStudent.iTotal = newStudent.iK_Score + newStudent.iE_Score + newStudent.iM_Score;
	newStudent.iAvg = newStudent.iTotal / 3.f;

	return newStudent;
}

void DisplayStudentInfo(const STUDENT* st) {
	cout << "--俳持 舛左研 窒径杯艦陥.--" << endl;
	cout << "戚硯: " << st->szName << endl
		<< "厩嬢: " << st->iK_Score << "繊, 慎嬢: " << st->iE_Score << "繊, 呪俳: " << st->iM_Score << endl
		<< "恥繊: " << st->iTotal << "繊, 汝液: " << st->iAvg << endl;
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
	if (!isExest) cout << "背雁 俳持聖 繕噺拝 呪 蒸柔艦陥." << endl;
}

void Swap(char* chData, char* chSrc) {
	char chTemp;
	chTemp = *chData;
	*chData = *chSrc;
	*chSrc = chTemp;
}
/*

筈
5/2 = 2
0,1,2,3,4
-> 4,1,2,3,0
-> 4,3,2,1,0

側
6/2=3
0,1,2,3,4,5
-> 5,1,2,3,4,0
-> 5,4,2,3,1,0
-> 5,4,3,2,1,0
*/