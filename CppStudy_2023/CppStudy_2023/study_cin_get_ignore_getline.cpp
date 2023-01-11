/*
	cin, get, getline �� ignore�� �ڼ��ϰ� �˾ƺ���.

	cin.ignore()�� ���ۿ� �����ִ� ���� �ϳ��� �����.
	cin.ignore(10) �̸� 10���� ����� ��.

	
	cin() : ����, ���� ������ '����'���ڱ����� �о�´�. 
			���� ����ڰ� �Է��� 'ù��° ���� ���� ����'�� '������ ����'�� ���ۿ� ���´�.
			��, ignore()�� �Ἥ ���۸� ��� �ʿ䰡 �ִ�. 

	get() : ����, ���� ���ڱ��� �о�´�. 
			���� ����ڰ� �Է��ϰ� ģ ������ ���ʹ� ���ۿ� ���� �ʴ´�.
			��, get()�������� ignore()�Ἥ ���� ��� �ʿ䰡 ����. 
	
	getlie() : get�� ���������� ����, ���� ���ڱ��� �о�´�. 
	
	
	��� 
		- cin ������ cin ����		-> ���ۿ� �����ִ� ����, ���๮�� ������ -> ignore�ʿ����. 
		- cin ������ get ����		-> ���ۿ� �����ִ� ����, ���๮�� ���� �о�� -> ignore�ʿ���
		- cin ������ getline ����	-> ���ۿ� �����ִ� ����, ���๮�� ���� �о�� -> ignore�ʿ���
		- get/getline ������ get/getline ����	-> ���ʿ� ���� get/getline�� ���ۿ� ����, ������ �ȳ��ܼ� -> ignore�ʿ����


*/

#include <iostream>
#include <string>

using namespace std;

int main() {
	
	// [case1:	cin ������ cin ]
	{
		char str[10];
		char test[10];

		cin >> str;
		cin >> test;
		cout << "str: " << str << " / test: " << test << endl;
	}
	
	// [case2:	cin ������ get ]
	{
		char str[10];
		char test[10];

		cin >> str;
		cin.ignore(); // �̰� ������ ���� �Է� �� ���ۿ� �����ִ� ���鹮�� ������
		cin.get(test, 10).get();
		cout << "str: " << str << " / test: " << test << endl;
	}
	
	// [case3:	cin ������ getline ]
	{
		char arr_str[10];
		string str_str;

		cin >> arr_str;
		cin.ignore(); // �̰� ������ ���� �Է� �� ���ۿ� �����ִ� ���鹮�� ������
		getline(cin,str_str);
		cout << "arr_str: " << arr_str << " / str_str: " << str_str << endl;
	}
	
	// [case4:	cin ������ getline ]
	{
		char arr_str[10];
		string str_str;

		cin.get(arr_str,10).get();
		getline(cin, str_str);
		cout << "arr_str: " << arr_str << " / str_str: " << str_str << endl;
	}
}