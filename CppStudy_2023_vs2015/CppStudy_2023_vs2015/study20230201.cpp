#include <iostream>

using namespace std;

int main() {
	char szString1[10];
	char szString2[10];

	gets_s(szString1, sizeof(szString1));	// 공백을 읽음. 엔터는 안읽음. 사이즈 초과시 오류남
	puts(szString1);

	fgets(szString2, sizeof(szString2), stdin);	// 설정한 사이즈만큼만 읽음. NULL문자 고려함
	fputs(szString2, stdout);
}