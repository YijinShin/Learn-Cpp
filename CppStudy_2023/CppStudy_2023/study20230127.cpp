#include <iostream>

using namespace std;

int main() {
	
	{
		char str1[50] = "hello";	// ���⼭ "hello"�̰�!! �̰� ���ڿ� ����̴�. 
		
		const char* str = "hello";	// �ϴ� ���ڿ� ������ ���ϴ� Ÿ���� �̰� ���ϴ°� �´�.
		char* str2 = "hello";	// �̷��� �����ϸ� �ϴ� ������ ���µ�, Ÿ���� �ȸ���. 

	}

}