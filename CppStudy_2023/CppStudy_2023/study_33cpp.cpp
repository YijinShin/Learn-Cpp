/* [ C++ study with TCP school 12~19part ]
topic : ����ü(Union) / ����ü (Enum)

* ����ü(Union)��?
	����ü�� �� �Ȱ����� �ɹ� �������� "�޸� ���"�� �ٸ� 
	1. ���� ū �ɹ� ������ ũ��� �޸� �Ҵ�ް� 
	2. ��� �ɹ� ������ �� �޸𸮸� ���� �� 

	EX) char, short, int �ɹ��� ������
		- ����ü : 1 + 2 + 4 + (1�и� ����Ʈ) => �� 8����Ʈ ����ü����

		- ����ü : 4����Ʈ ����ü����. �� �ȿ� �� ��ܳ��� 
	
	��, ����ü�� ���� "������"�� �پ��� ũ���� �����ͷ� ������ ������. �̰� �� ������
	char, short, int��� �ϸ� "a", 1, 3034 �̷��� �����ϱ� ������ �ƴ϶�
	"a"��� �����͸�, char, short, int���·� �����ϱ� ������. 
	�׷��� ����ü�� �ɹ��� �Ѹ����׸� ���� ������ �������� �� �����͸� ������

* ����ü


*/

#include <iostream>

using namespace std;

// [ ����ü ���� ]
union ShareData {
	unsigned char ch;
	unsigned short sh;
	unsigned int i;
};

// [ ����ü ���� ] 
enum Week { MON = 0, TUE = 1, WED = 2, THU = 3, FRI = 4, SAT = 5, SUN = 6};	 // �̶�, ������� ��� ���� ������ �ڵ����� 0���� 1�� �����ϴ°ɷ� ��

int main() {
	// [ ����ü ��� ]
	{
		ShareData sd1;
		
		sd1.ch = 'a';	// ch���� 'a'��� �����͸� �־ sh, i ��δ� �� 
		cout << "sd1: " << sd1.ch << " / " << sd1.sh << " / " << sd1.i << endl;
	
		sd1.ch = 'b';
		cout << "sd1: " << sd1.ch << " / " << sd1.sh << " / " << sd1.i << endl;
	}

	// [ ����ü ��� ] 
	{
		Week wk;

		int input;
		cout << "������ ���� �����Դϱ� (��=0, ȭ=1, ��=2, ��=3, ��=4, ��=5, ��=6): ";
		cin >> input; 

		wk = (Week)input; // �Է¹��� ���ڸ� ����ü�� ��ȯ 

		switch (wk) {
			case MON: 
				cout << "�������Դϴ�.";
				break;
			case TUE:
				cout << "ȭ�����Դϴ�.";
				break;
			case WED:
				cout << "�������Դϴ�.";
				break;
			case THU:
				cout << "������Դϴ�.";
				break;
			case FRI:
				cout << "�ݿ����Դϴ�.";
				break;
			case SAT:
				cout << "������Դϴ�.";
				break;
			case SUN:
				cout << "�Ͽ����Դϴ�.";
				break;
			default:
				break;
		}
	}

}