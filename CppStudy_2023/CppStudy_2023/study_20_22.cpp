/* [ C++ study with TCP school 20~22part]
topic : switch 문 / 범위기반의 반복문 (조건문, 루프문 헷갈리는 것만 복습함)
	
	- break가 없는 스위치문
	- 범위기반의 반복문
*/

#include <iostream>

using namespace std;

int main() {
	// [ break ]
	// break는 '루프문' 또는 '스위치문' 안에만 쓸 수 있다. 이 둘을 끝낸다. 

	
	// [ break가 있는 switch문 ] -> 3만 출력하고 break되어서 해당 스위치문 자체가 끝남. 
	{
		int num = 3;

		switch (num)
		{
		case 1:
			cout << "1입니다." << endl;
			break;
		case 2:
			cout << "2입니다." << endl;
			break;
		case 3:
			cout << "3입니다." << endl;
			break;
		case 4:
			cout << "4입니다." << endl;
			break;
		default:
			break;
		}
	}
	// [ break가 없는 switch문 ] -> case 3에 걸리면, 그 뒤로 break가 안되서 3,4를 다 출력함. 
	{
		int num = 3;

		switch (num)
		{
		case 1:
			cout << "1입니다." << endl;
		case 2:
			cout << "2입니다." << endl;
		case 3:
			cout << "3입니다." << endl;
		case 4:
			cout << "4입니다." << endl;
		default:
			break;
		}
	}

	// [ break가 없는 switch문 응용하는 경우 ]
	{
		// 대소문자 관계 없이 인식하고싶을때 
		char score = 'c';

		switch (score)
		{
		case 'a':
		case 'A':
			cout << "성적이 A입니다." << endl;
			break;
		case 'b':
		case 'B':
			cout << "성적이 B입니다." << endl;
			break;
		case 'c': // 여기에 해당되지만 break가 없어서 다음 case를 자동으로 실행함. 
		case 'C': 
			cout << "성적이 C입니다." << endl;
			break; //여기서 break가 걸려서 스위치문 끝남. 
		default:
			break;
		}
	}

	// [범위기반의 for문]
	{
		// 배열을 자동으로 인식함 -> 배열 내의 모든 값에 대해 한번씩 루프 실행해줌 
		int arr[5] = { 1,7,2,4,9 };
		cout << "arr값들: ";
		for (int element : arr) {
			cout << element << ", ";
		}
		
	}
}