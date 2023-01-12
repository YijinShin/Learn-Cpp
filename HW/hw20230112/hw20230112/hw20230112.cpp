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
		cout << "국어 점수를 입력하세요: ";
		cin >> iK_Score;
		cin.ignore();
		
		if (iK_Score >= 0 && iK_Score <= 100) break;
		cout << "0점에서 100점 사이의 점수를 입력해야합니다. " << endl;
	}

	while (1) {
		cout << "영어 점수를 입력하세요: ";
		cin >> iE_Score;
		cin.ignore();

		if (iE_Score >= 0 && iE_Score <= 100) break;
		cout << "0점에서 100점 사이의 점수를 입력해야합니다. " << endl;
	}

	while (1) {
		cout << "수학 점수를 입력하세요: ";
		cin >> iM_Score;
		cin.ignore();

		if (iM_Score >= 0 && iM_Score <= 100) break;
		cout << "0점에서 100점 사이의 점수를 입력해야합니다. " << endl;
	}


	//Calc avg
	iTotal = iK_Score + iE_Score + iM_Score;
	iAvg = iTotal / 3.0f;
	

	// output
	cout << endl << "당신의 총점은 " << iTotal << "점 입니다. " << endl;
	cout << "당신의 평균은 " << iAvg << "점 으로,  ";
	if (iAvg >= 90 && iAvg <= 100) {
		cout << "A 학점입니다." << endl;
	}
	else if (iAvg >= 80 && iAvg < 90) {
		cout << "B 학점입니다." << endl;
	}
	else if (iAvg >= 70 && iAvg < 80) {
		cout << "C 학점입니다." << endl;
	}
	else if (iAvg < 70 ) {
		cout << "D 학점입니다." << endl;
	}

}