#include "stdafx.h"
#include "GradeCard.h"
#include <vector>
using namespace std;

enum { ADD = 1, SEARCH, DELETE, SHOWALL, QUIT };

void Add(vector<GradeCard*>& vecGrade);
int Search(const vector<GradeCard*>& vecGrade);
void Delete(vector<GradeCard*>& vecGrade);
void ShowAll(const vector<GradeCard*>& vecGrade) {
	cout << "[�ý���] ��ü �л� ������ ����մϴ�." << endl;
	for (int i = 0; i < vecGrade.size(); i++) vecGrade[i]->Draw();
}

int main() {

	vector<GradeCard*> vecGrade;
	int iMenu(0);
	bool isEnd(false);

	while (1) {
		system("cls");

		cout << "[�ý���] ������ �Ͻðڽ��ϱ�? (1.�����Է�, 2.��ȸ, 3.��������, 4.��ü���, 5.����): ";
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
	
	cout << "��� �߰��Ͻðڽ��ϱ�? : ";
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

	cout << "�л� �̸��� �Է��ϼ���: ";
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
		cout << "�л� ������ �����ϴ�. " << endl;
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
		cout << "�л� ������ �����߽��ϴ�. " << endl;
	}

}