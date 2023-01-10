/* [ C++ study with TCP school 12~19part ]
topic : ������(�򰥸��� �͸� ������)

!! �⺻������ ������ �����ڵ��� �����ʿ��� -> ���� ������ ����� !!

*/

#include <iostream>

using namespace std;

int main() {
	// [���Կ����� +=�� =+ ����]
	{
		int num1 = 1;
		int num2 = 5;
		num1 += num2;
		cout << "num1: " << num1 << " / num2: " << num2 << endl;

		num1 = 1;
		num2 = 5;
		num1 = +num2; // �̰� =���� �����̶� num1�� num2�� �ְ���, num1 + num2�� �Ѱ�. �װ���� 10�ε� �̰� ��� ���������� ����
		cout << "num1: " << num1 << " / num2: " << num2 << endl;

		num1 = 1;
		num2 = 5;
		int num3 = num1 = +num2; // ����: = > = > +  
		cout << "num1: " << num1 << " / num2: " << num2 << " / num3: " << num3 << endl;
	}

	//[���� ������]
	{
		// ���������ڸ� ���� ������ ���� �ٲ�°���! a = b-1 �� b���� �ȹٲ�µ� a = --b�� b���� �ٲ�! 
		int num1 = 5;
		int num2 = 10;
		int result1, result2;
		result1 = --num1 + num2; // -- >> +
		
		num1 = 5;
        num2 = 10;
		result2 = num1-- + num2; // + >> -- 

		cout << "result1: " << result1 << " / result2: " << result2 << endl;
	}

	//[��Ʈ ������]
	{
		/* & = �μ��� �����Ǵ� �� ��Ʈ�� ��� 1�̸� true
		   | = �ϳ��� 1�̸� true
		   ~ = ���� (NOT����)
		   ^ = �ϴ� �ٸ��� true
		   >> = ���������� �̵� ( 2�� ���� )
		   << = �������� �̵� ( 2�� ���� )
		
		*/
	}

	// [sizeof ������]
	{
		//������ �޸� ũ�� �˷��� (����Ʈ ����)
		cout << "char: " << sizeof(char) << endl;

		int num1 = 1;
		int arr[2];
		cout << "int: " << sizeof(num1) << " / int[2]: " <<  sizeof(arr) << endl;
	}

	//[�������� ������ scope resolution operator]
	{
		/* Ư�� ���� ���� �ִ� �ĺ���(�Լ�, ����, ����ü ��)�� �����ϴ°�.
			- Ŭ���� �̸�::�ĺ���
			- ���ӽ����̽� :: �ĺ���
			- ����ü :: �ĺ��� 
		*/
	}

	//[ �ɹ� ������ ������ pointer-to-member operation]
	{
		// ������ �ʿ��� �ٷ����. 
	}
}