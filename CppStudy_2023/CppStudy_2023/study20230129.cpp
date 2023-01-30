#include <iostream>

using namespace std;

int main() {
	{
		const char* str_ptr = "hello world";
		
		//char* str_ptr2 = "hello world";

		cout << str_ptr[5] <<","<<str_ptr[0] << endl;


		//	str_ptr[1] = "E";	//error

		str_ptr = "bye bye";
		cout << str_ptr << endl;

		const char* str_ptr1 = "hello world";
		const char* str_ptr2 = "hello world";

		//printf("%d,  %d\n", str_ptr1, str_ptr2);
		//std::cout << reinterpret_cast<void*>(a1) << "," << reinterpret_cast<void*>(a1) << std::endl;

		cout << endl;
		cout << endl;
	}


	{
		cout << endl;

		char str1[20] = "hello";
		char str2[30] = "world";

		//strcpy_s(str1,22, "world");
		
		cout << " " << sizeof(str1) << endl;
	}


	{
		char szDest[15] = "xxxxxxxxxxxxx";
		char szSrc[5] = "aa";

		strcpy_s(szDest,5, szSrc);

		//cout << " "<<szDest << endl;
		cout << " ";
		for (int i = 0; i < 15; i++) {
			cout << szDest[i];
		}
	}
	cout << endl << endl;

	{
		cout << " 문자열 길이: " << strlen("hello") << endl;
		cout << " 문자열 크기: " << sizeof("hello") << endl;

		cout << endl;

		char str_arr[20] = "hello";
		cout << " 문자열 길이: " << strlen(str_arr) << endl;
		cout << " 문자열 크기: " << sizeof(str_arr) << endl;

		cout << endl;
	}
	cout << endl;

	{
		char str_arr[20] = "oooooooooooo";
		strcpy_s(str_arr, 6, "aa\0aa");
		cout <<" " << str_arr << endl;
		cout << endl;
		cout << " 문자열 길이: " << strlen("aa\0aa") << endl;
		cout << " 문자열 크기: " << sizeof("aa\0aa") << endl;
	}
	cout << endl;
	{
		char str1[] = "hello\0world";
		char str2[] = "hello";

		cout << " 비교 결과: " << strcmp(str1, str2) << endl;

		cout << endl;

		/* str1 > str2 */
		char str3[] = "hello";
		char str4[] = "hello";
		cout << " 비교 결과: " << strcmp(str3, str4) << endl;	// 0 반환

		/* str1 > str2 */
		char str5[] = "a";
		char str6[] = "b";
		cout << " 비교 결과: " << strcmp(str5, str6) << endl;	// 0 반환

		/* str1 > str2 */
		char str7[] = "b";
		char str8[] = "a";
		cout << " 비교 결과: " << strcmp(str7, str8) << endl;	// 0 반환

	}
	cout << endl;
	{

		char str1[7] = "aaaa";
		char str2[30] = "bbbb";

		strcat_s(str1, str2);
		cout << " str1 :" << str1 << endl;
		cout << " str2 :" << str2 << endl;
	}

	{

	}
}