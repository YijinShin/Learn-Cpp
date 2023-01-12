/* class 2023.01.12*/

#include <iostream>
#include <bitset>

using namespace std;

int main() {
	
	// [ NOT연산 ]
	{
		int iTest = 10;				// 숫자 10의 2의 보수 상태
		int not_iTest = ~(iTest); // 숫자 10의 1의 보수 상태
		cout << bitset<8>(iTest) << " -> " << bitset<8>(not_iTest) << endl;
		cout << iTest<<"의 NOT연산: " << ~(iTest) << endl;					//음수가 되는 것은 제일 왼쪽 부호 비트가 1로 바뀌었기 떄문 
	}

	// [ 쉬프트 연산 ]
	{
		int iTest = 10;
		cout << bitset<8>(iTest >> 2) << endl;
		cout << bitset<8>(iTest << 2) << endl;
	}
	

	{
		int iTest = 10;

		++(++iTest); // 가능
		//(iTest++)++; // 불가능. R-value가 없으니까 
	}
	
}