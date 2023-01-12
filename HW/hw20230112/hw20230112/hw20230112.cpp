#include <iostream>

using namespace std;

int main() {

	int iK_Score = 0; // korean score
	int iE_Score = 0; // english score
	int iM_Score = 0; // math score
	int iTotal = 0;
	float iAvg = 0;

	//get input
	while (1){
		cout << "���� ������ �Է��ϼ���: ";
		cin >> iK_Score;
		cin.ignore();
		
		if (iK_Score >= 0 && iK_Score <= 100) break;
		cout << "0������ 100�� ������ ������ �Է��ؾ��մϴ�. " << endl;
	}

	while (1) {
		cout << "���� ������ �Է��ϼ���: ";
		cin >> iE_Score;
		cin.ignore();

		if (iE_Score >= 0 && iE_Score <= 100) break;
		cout << "0������ 100�� ������ ������ �Է��ؾ��մϴ�. " << endl;
	}

	while (1) {
		cout << "���� ������ �Է��ϼ���: ";
		cin >> iM_Score;
		cin.ignore();

		if (iM_Score >= 0 && iM_Score <= 100) break;
		cout << "0������ 100�� ������ ������ �Է��ؾ��մϴ�. " << endl;
	}


	//Calc avg
	iTotal = iK_Score + iE_Score + iM_Score;
	iAvg = iTotal / 3.0f;
	

	// output
	cout << endl << "����� ������ " << iTotal << "�� �Դϴ�. " << endl;
	cout << "����� ����� " << iAvg << "�� ����,  ";
	if (iAvg >= 90 && iAvg <= 100) {
		cout << "A �����Դϴ�." << endl;
	}
	else if (iAvg >= 80 && iAvg < 90) {
		cout << "B �����Դϴ�." << endl;
	}
	else if (iAvg >= 70 && iAvg < 80) {
		cout << "C �����Դϴ�." << endl;
	}
	else if (iAvg < 70 ) {
		cout << "D �����Դϴ�." << endl;
	}

}