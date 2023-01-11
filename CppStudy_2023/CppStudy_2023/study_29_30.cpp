/* [ C++ study with TCP school ]
topic : sting Ŭ���� 

- C++ ���� �߰��� Ŭ����
- std namespace�� ����
- 'Ŭ����'�̴�. �ڷ����� �ƴ϶�

* �Է� : getline(cin, [string �����̸�])

* ��� : �Ȱ��� cout ��� ����

* �ε����� ������ ���� ���� ���� 
 
* ���� ������ : = ���� ���� 
				������ �迭�� ���, ���� �迭���� �ٸ� �� �迭�� ���縦 �ϴ� ���̶� strcpy() ������ ����ؾ��ߴ�.
* ���� ���� ���� : str + str2 �̷��� ����. 
 
* string �޼ҵ�	
	- length()	: ���ڿ��� ���� ( ���� ������ ���� )
	- size()	: string������ ���� �޸� ������ 
	- append()	: ���ڿ� �߰� 
	- find()	: ���� �Ǵ� ���ڿ� ã�� 
	- compare()	: �� ���ڿ��� �� 
	- replace()
	- capacity() : 
	- max_size() : ���ڿ��� �ִ��� ���Թ����� ���� �� �ִ� �ִ� ���ڿ����� 

*/

#include <iostream>
#include <String>

using namespace std;

int main() {
	{
		string str;				// ����
		cout << "�̸� �Է�: ";
		getline(cin, str);		// �Է� 
		cout << str << "�� �ݰ����ϴ�." << endl; // ���
	}

	cout << "------------------------------------------" << endl;

	{
		string str = "hello";
		char ch_str[] = "hello";

		// [length(), size()]
		cout << "1-1. str�� ����: " << str.length() << endl;
		cout << "1-2. str�� �޸𸮿��� ���� ����ϰ� �ִ� ũ��(������ ����, �迭�� size) : " << str.size() << endl;	// char ������ 5�� ���� �����ϱ� ����� 5
		cout << "1-3. str�� �޸� ������ �����ϴ� byte�� : " << sizeof(str) << endl;
		cout << "1-4. ���� hello�� �������ִ� ������ �迭�� �޸� ������ �����ϴ� byte�� : " << sizeof(ch_str) << endl;
		cout << endl;


		// [append()]
		str.append(" world");
		cout << "2-1. append�� world �߰� :" << str << endl;
		str = "hello";
		str.append(" world", 3, 5); // �ڿ� ld�� �߰��� 
		cout << "2-2. append�� world �߰� :" << str << endl;
		str = "hello";
		str.append(" world", 3); // �տ��� 3���� �߰���. " wo"���� �߰���.  
		cout << "2-3. append�� world �߰� :" << str << endl;
		str = "hello";
		str.append(3, 'X'); // X�� 3�� �߰���.
		cout << "2-4. append�� world �߰� :" << str << endl;
		cout << endl;

		// [find()]
		cout << "3-1. ���ڿ� ã��, ���� ��ġ ��ȯ: " << str.find("lo") << endl;
		cout << "3-2. ���� ã��, ���� ��ġ ��ȯ: " << str.find('l') << endl;
		cout << "3-3. ������ ��ġ���� ���� ã��, ���� ��ġ ��ȯ: " << str.find('l', 3) << endl;
		if (str.find("wr") == string::npos) cout << "�ش� ���ڿ��� ��ã�ҽ��ϴ�. \n";			// string::npos : string Ŭ������ ���ǵ� static const size_type �̴�. -1 ��, ������ ����Ǿ��ִ�. 
		cout << endl;

		// [compare()]
		string s1 = "ABC";
		string s2 = "ABD";
		if (s1.compare(s2) == 0) { cout << "4. s1�� s2�� ����. " << endl; }
		else if(s1.compare(s2) < 0) { cout << "4. s1�� s2���� ���� ���� ������ �տ� �ִ�. " << endl; }
		else if(s1.compare(s2) > 0) { cout << "4. s1�� s2���� ���� ���� ������ �ڿ� �ִ�. " << endl; }
		cout << endl;

		// [replace()]
		string test1 = "my name is yijin";
		string test2 = "junsu";
		test1.replace(11, test2.length(), test2);	// 11�� �ٲٴ� ������ġ
		cout << "5. �ٲ� test1: " << test1 << endl;
		cout << endl;

		// [capacity()]



	}

}