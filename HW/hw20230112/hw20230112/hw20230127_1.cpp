/*
����
���ڿ����̱��ϴ� �Լ� ���� ����� (strlen���ϴ°���. null����)

����
�Է¹��� ���ڿ��� ������ �Լ� �����
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
		cout << "[ ���ڿ� ���� ���ϴ� �Լ� ]" << endl;
		cout << "���ڿ��� �Է��ϼ���: ";
		cin >> szArr;
		cin.ignore();
		cout <<  "���ڿ��� ���̴�" << GetStringLength(szArr) << "�Դϴ�." << endl;
		cout << endl;
	}

	//hw2
	{
		char szArr[MAXSIZE];

		cout << "[ ���ڿ��� ������ �Լ� ]" << endl;
		cout << "���ڿ��� �Է��ϼ���: ";
		cin >> szArr;
		cin.ignore();
		FlipString(szArr);
		cout << "���ڿ��� �������� " << szArr << "�Դϴ�." << endl;
		cout << endl;
	}

	//hw3
	{
		int iMenu;
		bool isEnd(false);
		STUDENT students[3];
		cout << "[ ����ü�� �̿��� �л� ����ǥ ]" << endl;

		while (1) {
			cout << "�޴��� �Է����ּ��� ( 1. �Է�, 2. ���, 3. �˻�, 4. ����): ";
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
				cout << "�л� �̸��� �Է����ּ���: ";
				cin >> szName;
				cin.ignore();
				SearchStudent(students, szName);
				break;
			case 4:
				isEnd = true;
				break;
			default:
				cout << "�߸��� �Է��Դϴ�." << endl;
				break;
			}

			if (isEnd) break;
		}
		cout << endl;
	}
	cout <<endl;

	// Flipstring2() �׽�Ʈ 
	{
		char szArray[MAXSIZE] = "hello";
		
		const char* szFlipedArr = FlipString2(szArray);
		cout << "������! : " << szFlipedArr << endl;
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
	int iSize = strlen(szArr);	// �����ȵ�
	const int const_iSize = strlen(szArr);
	//char szFlipedArr[iSize];	// ������ �迭 ũ��� �� ������. ���� �翬��.. �����ݾ� ���� �ٲ� ���� �ִ¾��ݾ� �������������� �迭�� ���̴� ������ ���������. �ϰ������ const int ������ �ؾ���.
	//char szFlipedArr[const_iSize];	//�� const ������ �ȵ�.. ��°�� 
	//char szFlipedArr[strlen(szArr)];	// �̰͵� �����޾ȵ�. szArr�� �ٲ�� �ڵ����� ���� �޶������׷��� 

	/* ... ���� �� �ȵȴ�.. ¥���� �� �����Ҵ� �� */
	char* szFlipedArr = new char[iSize+1];
	
	//cout << "size:" << iSize << endl;
	for (int i = 0; i < iSize; i++) {
		szFlipedArr[i] = szArr[iSize - i - 1];
		cout << "->" << i << "�� " << iSize - i - 1 << "����" << endl;
	}

	// �������� ���ڿ��� �����ٴ� NULL���� �־��ֱ� -> �̰� ���ϸ� �ڿ� cout���� szFlipedArr ����Ʈ �� ��, ��� ���ڿ��� ������ ���� �����Ⱚ���� �ٳ���.
	szFlipedArr[iSize] = NULL;	

	//cout << "���: " << szFlipedArr << endl;

	return szFlipedArr;
}

STUDENT GetStudentInfo() {
	STUDENT newStudent;
	cout << "�̸�: ";
	cin >> newStudent.szName;
	cout << "����, ����, ���� ���� : ";
	cin >> newStudent.iK_Score >> newStudent.iE_Score >> newStudent.iM_Score;
	newStudent.iTotal = newStudent.iK_Score + newStudent.iE_Score + newStudent.iM_Score;
	newStudent.iAvg = newStudent.iTotal / 3.f;

	return newStudent;
}

void DisplayStudentInfo(const STUDENT* st) {
	cout << "--�л� ������ ����մϴ�.--" << endl;
	cout << "�̸�: " << st->szName << endl
		<< "����: " << st->iK_Score << "��, ����: " << st->iE_Score << "��, ����: " << st->iM_Score << endl
		<< "����: " << st->iTotal << "��, ���: " << st->iAvg << endl;
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
	if (!isExest) cout << "�ش� �л��� ��ȸ�� �� �����ϴ�." << endl;
}

void Swap(char* chData, char* chSrc) {
	char chTemp;
	chTemp = *chData;
	*chData = *chSrc;
	*chSrc = chTemp;
}
/*

Ȧ
5/2 = 2
0,1,2,3,4
-> 4,1,2,3,0
-> 4,3,2,1,0

¦
6/2=3
0,1,2,3,4,5
-> 5,1,2,3,4,0
-> 5,4,2,3,1,0
-> 5,4,3,2,1,0
*/