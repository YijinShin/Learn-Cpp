#include <iostream>

using namespace std;

int main() {
	
	int iK_Score = 0; // korean score
	int iE_Score = 0; // english score
	int iM_Score = 0; // math score
	int iTotal = 0;
	float iAvg = 0;

	//get input
	cout << "���� ������ �Է��ϼ���: ";
	cin >> iK_Score;
	cin.ignore();
	cout << "���� ������ �Է��ϼ���: ";
	cin >> iE_Score;
	cin.ignore();
	cout << "���� ������ �Է��ϼ���: ";
	cin >> iM_Score;
	cin.ignore();

	//Calc avg
	iTotal = iK_Score + iE_Score + iM_Score;
	iAvg = iTotal / 3.0f;
	cout << endl << "����� ������ " << iTotal << "�� �Դϴ�. " << endl;
	cout << "����� ����� " << iAvg << "�� �Դϴ�. " << endl;



}