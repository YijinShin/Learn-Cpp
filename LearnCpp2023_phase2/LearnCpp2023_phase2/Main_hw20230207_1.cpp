/*
 성적표 클래스 배열 (동적할당)으로 구현 
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
	cout << "성적표를 몇개 생성하시겠습니까: " << endl;
	cin >> iReportCnt;
	reports = new Report[iReportCnt];
	cout << " 주소:" << reports << endl;
	for (int i = 0; i < iReportCnt; i++) InitReport(&reports[i]);

	// menu
	while (1) {
		system("cls");

		cout << " 무엇을 하시겠습니까 (1.Add, 2.Show, 3.Clear, 4.Quit): ";
		cin >> iMenu;

		switch (iMenu) {
		case ADD:
			cout << " [Add new reports] 몇개를 추가하시겠습니까: ";
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
	cout << "내주소:" << pReport << endl;
	char szName[20];
	int iScores[3];
	
	cout << "[성적을 입력해합니다.]" << endl;
	// name
	cout << "이름: ";
	cin >> szName;
	pReport->SetszName(szName);
	// score
	cout << "국어, 영어, 수학: ";
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
	*pReport = newpReports;	// nullptr로 댕글링을 없애는 대신 새로운 배열의 첫주소로 바꿔주기 
}