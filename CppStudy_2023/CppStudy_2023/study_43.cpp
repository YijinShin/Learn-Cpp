/* [ C++ study with TCP school 43part]
topic: ���� �����̽�

* ���� �ĺ���(identifier)
		����, �Լ�, ����ü, Ŭ���� �� 


* ���ӽ����̽� 
		- �ĺ��� ���� �浹���ɼ��� �ִ�(�̸��� ��ģ�ٰų�) => ���νĺ��ڿ� ��ȿ ������ �����ϱ� ���� ���ӽ����̽� ���
		- ��� �������� ���� �Ұ���. 
		- �ܺ� ���� ������ ��
		- �Ϲ������δ� ������Ͽ� ������. 


*/

#include <iostream>
#include <string>

#include "study_43.h"	// ���� ������ ���ӽ����̽� ���� ���� ���� ���� ������� include �ϱ�

using namespace std;
using namespace Test;	// Test2�� using�������ϱ� ���Ÿ� Test2:: �ٿ��� ȣ���ؾ���

int main() {
	cout << "�̸��� �Է��ϼ���: ";
	getline(cin, name);		// �տ� ::(��������������)�����ϱ� �翬�� Test ���ӽ����̽��� name������ ����� ���̴�. 
	Display();				//	�տ� ::(��������������)�����ϱ� �翬�� Test ���ӽ����̽��� Display()�� ����� ���̴�. 
	
	
	cout << "�̸��� �Է��ϼ���: ";
	getline(cin, Test2::name);
	Test2::Display();
}