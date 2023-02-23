#include "stdafx.h"
#include "GradeCard.h"
#include <vector>
using namespace std;

enum { ADD = 1, SEARCH, DELETE, SHOWALL, QUIT };

void Add(vector<GradeCard*>& vecGrade);
int Search(const vector<GradeCard*>& vecGrade);
void Delete(vector<GradeCard*>& vecGrade);
void ShowAll(const vector<GradeCard*>& vecGrade) {
	cout << "[시스템] 전체 학생 성적을 출력합니다." << endl;
	for (int i = 0; i < vecGrade.size(); i++) vecGrade[i]->Draw();
}

int main() {

	vector<GradeCard*> vecGrade;
	int iMenu(0);
	bool isEnd(false);

	while (1) {
		system("cls");

		cout << "[시스템] 무엇을 하시겠습니까? (1.성적입력, 2.조회, 3.성적삭제, 4.전체출력, 5.종료): ";
		cin >> iMenu;

		switch (iMenu)
		{
		case ADD:
			Add(vecGrade);
			break;
		case SEARCH:
			Search(vecGrade);
			break;
		case DELETE:
			Delete(vecGrade);
			break;
		case SHOWALL:
			ShowAll(vecGrade);
			break;
		case QUIT:
			isEnd = true;
			break;
		default:
			break;
		}

		if (isEnd) break;
		system("pause");
	}

}

void Add(vector<GradeCard*>& vecGrade) {
	int iSize(0);
	
	cout << "몇개를 추가하시겠습니까? : ";
	cin >> iSize;

	for (int i = 0; i < iSize; i++) {
		vecGrade.push_back(new GradeCard);
		vecGrade.back()->SetScore();
	}
}

int Search(const vector<GradeCard*>& vecGrade) {
	char szName[20];
	bool isFound(false);
	int iIndex(-1);

	cout << "학생 이름을 입력하세요: ";
	cin >> szName;

	for (int i = 0; i < vecGrade.size(); i++) {
		if (!strcmp(vecGrade[i]->GetName(), szName)) {
			vecGrade[i]->Draw();
			isFound = true;
			iIndex = i;
			break;
		}
	}

	if (!isFound) {
		cout << "학생 정보가 없습니다. " << endl;
	}
	return iIndex;
}


void Delete(vector<GradeCard*>& vecGrade) {
	char szName[20];
	bool isFound(false);
	int iIndex(-1);

	iIndex = Search(vecGrade);
	if (iIndex >= 0) {
		vecGrade.erase(vecGrade.begin() + iIndex);
		cout << "학생 정보를 삭제했습니다. " << endl;
	}

}