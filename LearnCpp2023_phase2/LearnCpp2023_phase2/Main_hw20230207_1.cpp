/*
 ����ǥ Ŭ���� �迭 (�����Ҵ�)���� ���� 
*/


#include "stdafx.h"
#include "hw20230207_1.h"

using namespace std;
using namespace hw20230207_1;

enum Menu{ ADD = 1, SHOW, CLEAR, QUIT };

void InitReport(Report* pReport);
void AddNewReport(Report** pReport, int iReportCnt, int iNewReportCnt);

int main() {
	int iReportCnt(0);
	int iMenu(0);
	bool isEnd(false);
	int iNewReportCnt(0);
	Report* reports;

	// create reports
	cout << "����ǥ�� � �����Ͻðڽ��ϱ�: " << endl;
	cin >> iReportCnt;
	reports = new Report[iReportCnt];
	cout << " �ּ�:" << reports << endl;
	for (int i = 0; i < iReportCnt; i++) InitReport(&reports[i]);

	// menu
	while (1) {
		system("cls");

		cout << " ������ �Ͻðڽ��ϱ� (1.Add, 2.Show, 3.Clear, 4.Quit): ";
		cin >> iMenu;

		switch (iMenu) {
		case ADD:
			cout << " [Add new reports] ��� �߰��Ͻðڽ��ϱ�: ";
			cin >> iNewReportCnt;
			iReportCnt = iReportCnt + iNewReportCnt;
			AddNewReport(&reports, iReportCnt, iNewReportCnt);
			break;
		case SHOW:
			for (int i = 0; i < iReportCnt; i++) reports[i].ShowReport();
			break;
		case CLEAR:
			system("cls");
			break;
		case QUIT:
			cout << " [QUIT]" << endl;
			delete[] reports;
			isEnd = true;
			break;
		default:
			break;
		}

		if (isEnd) break;
		system("pause");
	}
	
}

void InitReport(Report* pReport) {
	cout << "���ּ�:" << pReport << endl;
	char szName[20];
	int iScores[3];
	
	cout << "[������ �Է����մϴ�.]" << endl;
	// name
	cout << "�̸�: ";
	cin >> szName;
	pReport->SetszName(szName);
	// score
	cout << "����, ����, ����: ";
	for (int i = 0; i < 3; i++) cin >> iScores[i];

	pReport->InitReport(iScores[0], iScores[1], iScores[2], szName);
}

void AddNewReport(Report** pReport, int iReportCnt, int iNewReportCnt) {
	Report *newpReports = new Report[iReportCnt];
	cout << iReportCnt << " / " << iNewReportCnt << endl;

	//copy already exists
	for (int i = 0; i < iReportCnt - iNewReportCnt; i++) {
		cout << "Index(copy):" << i << endl;
		newpReports[i].CopyReport((*pReport)[i]);
	} 
	// new reports
	for (int i = iReportCnt-iNewReportCnt; i < iReportCnt; i++) {
		cout << "Index(new):" << i << endl;
		InitReport(&newpReports[i]);
	}
	delete[] *pReport;
	*pReport = nullptr;
	*pReport = newpReports;	// nullptr�� ��۸��� ���ִ� ��� ���ο� �迭�� ù�ּҷ� �ٲ��ֱ� 
}