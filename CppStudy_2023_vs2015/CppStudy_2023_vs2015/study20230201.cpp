#include <iostream>

using namespace std;

int main() {
	char szString1[10];
	char szString2[10];

	gets_s(szString1, sizeof(szString1));	// ������ ����. ���ʹ� ������. ������ �ʰ��� ������
	puts(szString1);

	fgets(szString2, sizeof(szString2), stdin);	// ������ �����ŭ�� ����. NULL���� �����
	fputs(szString2, stdout);
}