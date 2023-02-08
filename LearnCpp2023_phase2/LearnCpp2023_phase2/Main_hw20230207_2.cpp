/*
 ����ǥ linked list�� ����
 + ���̳ʸ� ��ġ
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

		cout << "������ �Ͻðڽ��ϱ� (1.Add new reports, 2.Remove report 3.Show all reports, 4. Search report, 5.Sort(avg), 6.Clear, 7.Quit):";
		cin >> iMenu;

		switch (iMenu)
		{
		case ADD:
			cout << "[ADD] ��� �߰��� �����Ͻðڽ��ϱ�: ";
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
		cout << "������ �Է��ϼ���." << endl;
		cout << "�̸�: ";
		cin >> szName;
		cout << "����, ����, ����: ";
		for (int i = 0; i < 3; i++) cin >> iScore[i];
		Linkedlist::AddNode(pList, iScore[0], iScore[1], iScore[2], szName);
	}
}

void SearchReport(const LIST* pList) {
	char szName[20];
	cout << " [SEARCH] �̸����� ��ȸ���ּ���: ";
	cin >> szName;
	Linkedlist::ShowSearchInfo(pList, szName);
}

void RemoveReport(PLIST pList) {
	char szName[20];
	cout << " [REMOVE] ������ �л� �̸��� �Է����ּ���: ";
	cin >> szName;
	Linkedlist::RemoveNode(pList, szName);
}