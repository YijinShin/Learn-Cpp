#include <iostream>
using namespace std;

int main() {

	// ���۷����� ���� �ʱ�ȭ �� �ٸ� ������ ���ٲ� const����. 

	{
		int iData = 10;
		int iTemp = 20;

		int& iRef = iData;

		cout << iData << endl;
		iRef = iRef + 10;
		cout << iData << endl;
	}

	// ���
	{
		//int& iRef2 = 7	//ERROR
		const int& iRef2 = 7;	// OK

		cout << iRef2 << endl;
		//iRef2 = 10;		//ERROR
	}

	//const��� / const ���۷���
	{
		int iData = 10;
		const int& iRef= iData;
		//iRef = 20;	//ERROR	: �̰͵� �����͸��� �б����������۷����� �Ǵµ�. 

		const int iData2 = 20;
		//int& iRef2 = iData2;	//ERROR
		const int& iRef2 = iData2;	//OK

	}
}