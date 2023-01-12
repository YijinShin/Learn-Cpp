#include <iostream>

using namespace std;

int main() {
	
	int iK_Score = 0; // korean score
	int iE_Score = 0; // english score
	int iM_Score = 0; // math score
	int iTotal = 0;
	float iAvg = 0;

	//get input
	cout << "국어 점수를 입력하세요: ";
	cin >> iK_Score;
	cin.ignore();
	cout << "영어 점수를 입력하세요: ";
	cin >> iE_Score;
	cin.ignore();
	cout << "수학 점수를 입력하세요: ";
	cin >> iM_Score;
	cin.ignore();

	//Calc avg
	iTotal = iK_Score + iE_Score + iM_Score;
	iAvg = iTotal / 3.0f;
	cout << endl << "당신의 총점은 " << iTotal << "점 입니다. " << endl;
	cout << "당신의 평균은 " << iAvg << "점 입니다. " << endl;



}