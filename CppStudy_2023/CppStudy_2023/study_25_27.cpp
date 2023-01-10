/* [ C++ study with TCP school 25~27part]
topic : ������ 

* �ּҰ� 
	�������� ù ���� �޸� �ּҷ�, ��� ������ ����� ���� �� 1byte�� �ش� ������ �ּҰ��� ������ �ִ�. 
	��, int�� 4����Ʈ��, ���� ù��° 1����Ʈ�� �ش� int �����Ǵ� ����� '�ּҰ�'�� �ǹ���


* �����Ͷ�
	�������� �ּҰ��� �����ϴ� ����

* ������ ������
	- * : ���� ������ 
		'������' �տ� ����
		'�����Ϳ� �����' �ּҰ��� ����� '��'�� ��ȯ
	- & : �ּ� ������ 
		'����' �տ� ����
		�ش� '����'�� �ּҰ��� ��ȯ

* ������ ������ ũ�� 
	�������� ũ��� �տ� ���̴� Ÿ�԰� �������. > ������ '�ּҰ�'�� �����ϴ� �ִϱ�

	���� ������ ���� ũ��� CPU�� ���� ������
		- ���� 32bit�� ������ ���� ũ�� = 4byte
		- ���� 64bit�� ������ ���� ũ�� = 8byte
*/
#include <iostream>

using namespace std;

int main() {
	// [ ������ ���� ]
	{
		int num = 100;
		int* ptr = &num; // ������ ���� ����

		int* ptr2, ptr3; // ptr2�� int* , ptr3�� int�� �����
		int* ptr4, * ptr5; // �Ѵ� int*�� �����

		int test = 100;
		int* ptr6 = &test;
		int** ptr7 = &ptr6; // ���� ������ 
	}

	// [ �������� ũ�� ]
	{
		// �������� ũ��� �տ� ���̴� Ÿ�԰� �������. > ������ '�ּҰ�'�� �����ϴ� �ִϱ�

		/* ���� ������ ���� ũ��� CPU�� ���� ������
			- ���� 32bit�� ������ ���� ũ�� = 4byte
			- ���� 64bit�� ������ ���� ũ�� = 8byte
		*/
		int num = 1;
		int* ptr = &num;
		int** ptrr = &ptr;

		cout << "int size(byte): " << sizeof(num) << endl;
		cout << "pointer size(byte): " << sizeof(ptr) << endl; //8����Ʈ
		cout << "���� pointer size(byte): " << sizeof(ptrr) << endl;//8����Ʈ
		cout << endl;
	}

	// [ ������ ���� ] 
	{
		int i1 = 100;
		double d1 = 3.14;

		int* int_ptr = &i1;
		double* double_ptr = &d1;
		
		int** int_ptrr = &int_ptr;

		cout << "i1�� �ּҰ�: " << &i1 << endl;
		cout << "int_ptr�� ������ �ִ� �ּҰ� : " << int_ptr << endl;
		cout << "int_ptr�� ������ �ִ� �ּҰ��� ����� ��: " << *int_ptr << endl;
		cout << endl;
		cout << "d1�� �ּҰ�: " << &d1 << endl;
		cout << "double_ptr�� ������ �ִ� �ּҰ� : " << double_ptr << endl;
		cout << "double_ptr�� ������ �ִ� �ּҰ��� ����� ��: " << *double_ptr << endl;
		cout << endl;
		cout << "int_ptr�� �ּҰ�: " << &int_ptr << endl;
		cout << "int_ptrr�� ������ �ִ� �ּҰ� : " << int_ptrr << endl;
		cout << "int_ptrr�� ������ �ִ� �ּҰ��� ����� �� : " << *int_ptrr << endl;
		cout << "int_ptrr�� ������ �ִ� �ּҰ��� ����� �ּҰ��� ����� �� : " << **int_ptrr << endl;

	}
}