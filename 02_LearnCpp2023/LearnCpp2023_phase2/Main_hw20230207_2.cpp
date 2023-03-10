/*
 성적표 linked list로 구현
 + 바이너리 서치
*/

#include "stdafx.h"
#include "hw20230207_2.h"

using namespace std;
using namespace hw20230207_2;

enum Menu { ADD = 1, REMOVE, SHOW, SEARCH, SORT, CLEAR, QUIT };

void AddNewReports(PLIST pList, int iNewReportCnt);
void SearchReport(const LIST* pList);
void RemoveReport(PLIST pList);

int main() {
	int iMenu(0);
	int iNewReportCnt(0);
	bool isEnd(false);
	
	LIST list = Linkedlist::CreateLinkedList();
	
	while (1) {

		cout << "무엇을 하시겠습니까 (1.Add new reports, 2.Remove report 3.Show all reports, 4. Search report, 5.Sort(avg), 6.Clear, 7.Quit):";
		cin >> iMenu;

		switch (iMenu)
		{
		case ADD:
			cout << "[ADD] 몇개를 추가로 생성하시겠습니까: ";
			cin >> iNewReportCnt;
			AddNewReports(&list, iNewReportCnt);
			break;
		case REMOVE:
			RemoveReport(&list);
			break;
		case SHOW:
			Linkedlist::ShowList(&list);
			break;
		case SEARCH:
			SearchReport(&list);
			break;
		case SORT:
			Linkedlist::SortList(&list);
			break;
		case CLEAR:
			system("cls");
			break;
		case QUIT:
			isEnd = true;
			Linkedlist::DeleteList(&list);
			cout << " [END]" << endl;
			break;
		default:
			break;
		}

		if (isEnd) break;
		
	}
}

void AddNewReports(PLIST pList, int iNewReportCnt) {
	int iScore[3]{ 0 };
	char szName[20];

	for (int i = 0; i < iNewReportCnt; i++) {
		cout << "정보를 입력하세요." << endl;
		cout << "이름: ";
		cin >> szName;
		cout << "국어, 영어, 수학: ";
		for (int i = 0; i < 3; i++) cin >> iScore[i];
		Linkedlist::AddNode(pList, iScore[0], iScore[1], iScore[2], szName);
	}
}

void SearchReport(const LIST* pList) {
	char szName[20];
	cout << " [SEARCH] 이름으로 조회해주세요: ";
	cin >> szName;
	Linkedlist::ShowSearchInfo(pList, szName);
}

void RemoveReport(PLIST pList) {
	char szName[20];
	cout << " [REMOVE] 삭제할 학생 이름을 입력해주세요: ";
	cin >> szName;
	Linkedlist::RemoveNode(pList, szName);
}