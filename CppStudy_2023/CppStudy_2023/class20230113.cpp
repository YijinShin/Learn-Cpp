#include <iostream>

using namespace std;

int main() {

	// if
	{
		int i1 = 10, i2 = 20;

		if ((i1 < i2) && (i1 = 200))
			cout << "�̰� ����!" << endl; //����� 200 

		if ((i1 < i2) || (i1 = 200))
			cout << i1 << endl; // �̰Ŵ� 10��. �տ� ���̶� �ڿ� ���Ծ���
	}


	//switch
	{
		// case [���] >>������ ����� �;��� ( ���ͷ� ��� / �ɺ��� ��� ��� ����) 
		
		int iA = 10;
		const int ten = 10;
		
		switch (iA) {
			case ten:	// �ɺ��� ���

				break;

			case 11:	// ���ͷ� ���
				break;

			default:
				break;
		}
	}
	
}

/*while�� �̿��ؼ� ������ 2 ~ 9 �� ����ؿ��� */