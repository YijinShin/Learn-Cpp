#pragma once		// ������Ͽ��� �̰� �� �־����

#include <iostream>	
using namespace std;

namespace Test
{
	string name;
	
	void Display() {
		cout << "Test1) ����� �̸��� " << name << "�Դϴ�." << endl;
	}

}

namespace Test2	// �� ������Ͼȿ� �翬�� ���� namespace�����ص� ����. 
{
	string name;
	
	void Display() {
		cout << "Test2) ����� �̸��� " << name << "�Դϴ�." << endl;
	}
}

