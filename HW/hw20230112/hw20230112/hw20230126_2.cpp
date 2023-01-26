#include <iostream>

using namespace std;

void Display(const int (*iArray)[5]);
void Swap(int* iData, int* iSrc);

struct Position {
	int iX;
	int iY;
};

int main() {
	int iArray[5][5];
	int iInput(0);
	
	Position zeroPosition;

	//init iArray
	for (int i = 0; i < 5; i++) {
		int iIndex = i * 5;
		for (int j = 0; j < 5; j++) {
			iArray[i][j] = iIndex + j;
		}
	}

	zeroPosition.iX = 0;
	zeroPosition.iY = 0;

	cout << "-------------�ѹ� �е��� 2,4,6,8�� 0�� �̵���ų �� �ֽ��ϴ�.-------------" << endl;
	Display(iArray);

	while (1) {

		//get input
		cout << "[ 0�� ������������! (2:��, 4:��, 6:��, 8:��, 0:����)] : ";
		cin >> iInput;
		
		// update array
		if (iInput == 0) {
			break;
		}
		else if (iInput == 2) {
			if (zeroPosition.iY != 4) {
				Swap(&iArray[zeroPosition.iY][zeroPosition.iX], &iArray[zeroPosition.iY + 1][zeroPosition.iX]);
				zeroPosition.iY = zeroPosition.iY + 1;
			}
			else cout << "���̻� �Ʒ��� �� �� �����ϴ�." << endl;
		}
		else if (iInput == 4) {
			if (zeroPosition.iX != 0) {
				Swap(&iArray[zeroPosition.iY][zeroPosition.iX], &iArray[zeroPosition.iY][zeroPosition.iX - 1]);
				zeroPosition.iX = zeroPosition.iX -1;
			}
			else cout << "���̻� �������� �� �� �����ϴ�." << endl;

		}
		else if (iInput == 6) {
			if (zeroPosition.iX != 4) {
				Swap(&iArray[zeroPosition.iY][zeroPosition.iX], &iArray[zeroPosition.iY][zeroPosition.iX + 1]);
				zeroPosition.iX = zeroPosition.iX + 1;
			}
			else cout << "���̻� �������� �� �� �����ϴ�." << endl;

		}
		else if (iInput == 8) {
			if (zeroPosition.iY != 0) {
				Swap(&iArray[zeroPosition.iY][zeroPosition.iX], &iArray[zeroPosition.iY-1][zeroPosition.iX]);
				zeroPosition.iY = zeroPosition.iY - 1;
			}
			else cout << "���̻� ���� �� �� �����ϴ�." << endl;

		}

		// display result
		Display(iArray);
	}
}

void Display(const int(*iArray)[5]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << iArray[i][j] << "\t";
		}
		cout << endl;
	}
}

void Swap(int* iData, int* iSrc) {
	int iTemp;
	iTemp = *iData;
	*iData = *iSrc;
	*iSrc = iTemp;
}
