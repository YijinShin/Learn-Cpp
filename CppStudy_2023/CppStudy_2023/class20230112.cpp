/* class 2023.01.12*/

#include <iostream>
#include <bitset>

using namespace std;

int main() {
	
	// [ NOT���� ]
	{
		int iTest = 10;				// ���� 10�� 2�� ���� ����
		int not_iTest = ~(iTest); // ���� 10�� 1�� ���� ����
		cout << bitset<8>(iTest) << " -> " << bitset<8>(not_iTest) << endl;
		cout << iTest<<"�� NOT����: " << ~(iTest) << endl;					//������ �Ǵ� ���� ���� ���� ��ȣ ��Ʈ�� 1�� �ٲ���� ���� 
	}

	// [ ����Ʈ ���� ]
	{
		int iTest = 10;
		cout << bitset<8>(iTest >> 2) << endl;
		cout << bitset<8>(iTest << 2) << endl;
	}
	

	{
		int iTest = 10;

		++(++iTest); // ����
		//(iTest++)++; // �Ұ���. R-value�� �����ϱ� 
	}
	
}