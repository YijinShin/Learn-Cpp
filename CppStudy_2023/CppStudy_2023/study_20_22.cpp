/* [ C++ study with TCP school 20~22part]
topic : switch �� / ��������� �ݺ��� (���ǹ�, ������ �򰥸��� �͸� ������)
	
	- break�� ���� ����ġ��
	- ��������� �ݺ���
*/

#include <iostream>

using namespace std;

int main() {
	// [ break ]
	// break�� '������' �Ǵ� '����ġ��' �ȿ��� �� �� �ִ�. �� ���� ������. 

	
	// [ break�� �ִ� switch�� ] -> 3�� ����ϰ� break�Ǿ �ش� ����ġ�� ��ü�� ����. 
	{
		int num = 3;

		switch (num)
		{
		case 1:
			cout << "1�Դϴ�." << endl;
			break;
		case 2:
			cout << "2�Դϴ�." << endl;
			break;
		case 3:
			cout << "3�Դϴ�." << endl;
			break;
		case 4:
			cout << "4�Դϴ�." << endl;
			break;
		default:
			break;
		}
	}
	// [ break�� ���� switch�� ] -> case 3�� �ɸ���, �� �ڷ� break�� �ȵǼ� 3,4�� �� �����. 
	{
		int num = 3;

		switch (num)
		{
		case 1:
			cout << "1�Դϴ�." << endl;
		case 2:
			cout << "2�Դϴ�." << endl;
		case 3:
			cout << "3�Դϴ�." << endl;
		case 4:
			cout << "4�Դϴ�." << endl;
		default:
			break;
		}
	}

	// [ break�� ���� switch�� �����ϴ� ��� ]
	{
		// ��ҹ��� ���� ���� �ν��ϰ������ 
		char score = 'c';

		switch (score)
		{
		case 'a':
		case 'A':
			cout << "������ A�Դϴ�." << endl;
			break;
		case 'b':
		case 'B':
			cout << "������ B�Դϴ�." << endl;
			break;
		case 'c': // ���⿡ �ش������ break�� ��� ���� case�� �ڵ����� ������. 
		case 'C': 
			cout << "������ C�Դϴ�." << endl;
			break; //���⼭ break�� �ɷ��� ����ġ�� ����. 
		default:
			break;
		}
	}

	// [��������� for��]
	{
		// �迭�� �ڵ����� �ν��� -> �迭 ���� ��� ���� ���� �ѹ��� ���� �������� 
		int arr[5] = { 1,7,2,4,9 };
		cout << "arr����: ";
		for (int element : arr) {
			cout << element << ", ";
		}
		
	}
}