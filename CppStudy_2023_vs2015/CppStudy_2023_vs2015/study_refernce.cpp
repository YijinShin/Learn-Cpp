#include <iostream>
using namespace std;

int main() {

	// 레퍼런스는 원래 초기화 후 다른 값으로 못바꿈 const마냥. 

	{
		int iData = 10;
		int iTemp = 20;

		int& iRef = iData;

		cout << iData << endl;
		iRef = iRef + 10;
		cout << iData << endl;
	}

	// 상수
	{
		//int& iRef2 = 7	//ERROR
		const int& iRef2 = 7;	// OK

		cout << iRef2 << endl;
		//iRef2 = 10;		//ERROR
	}

	//const상수 / const 레퍼런스
	{
		int iData = 10;
		const int& iRef= iData;
		//iRef = 20;	//ERROR	: 이것도 포인터마냥 읽기전용상수레퍼런스가 되는듯. 

		const int iData2 = 20;
		//int& iRef2 = iData2;	//ERROR
		const int& iRef2 = iData2;	//OK

	}
}