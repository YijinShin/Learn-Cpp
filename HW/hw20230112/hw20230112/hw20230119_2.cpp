#include <iostream>

using namespace std;

void Swap(int* iData, int* iSrc);

int main() {

	int iData(10), iSrc(20);

	cout << "[ swap �� ] iData: " << iData << ", iSrc: " << iSrc << endl;

	Swap(&iData, &iSrc);

	cout << "[ swap �� ] iData: " << iData << ", iSrc: " << iSrc << endl;


		 

}

void Swap(int* iData, int* iSrc) {
	int iTemp = *iData;

	*iData = *iSrc;
	*iSrc = iTemp;
}