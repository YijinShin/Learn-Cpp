/* [ Vector ] 

- stdl의 컨테이너
- vector생성시 -> heap메모리에 동적할당됨. 
- array에 비해 속도가 좀 떨어짐
- array에 비해 메모리를 효율적으로 관리하고, 예외처리가 쉬움


*/

#include "stdafx.h"
#include <vector>

using namespace std;

int main() {
	// 백터 생성, 초기화 
	{
		vector<int> iVec1;	// 생성. 
		vector<int> iVec2(5);	// 길이가 5인 vector생성 후, 다 0으로 초기화
			int iArr[10] = { 10 };	//이렇게 하면 0번 인덱스는 10이고, 나머지는 다 0으로 초기화 
		vector<int> iVec3 = { 1,2,3 };	//길이가 3인 vector생성 후, 초기화 
		vector<int> iVec4[] = { {1,2},{3,4} }; // 백터 배열생성. 행 가변, 열 고정 
		vector<vector<int>> iVec5;	//행,열 모두 가변 
		vector<int> iVec6(5);
		iVec6.assign(5, 10);	// 범위 5까지를 모두 10으로 초기화 
	}

	// vector 반복자 사용 함수 
	{

	}

	// 백터 동적할당시 배열
	{
		vector<int>* vPtr = new vector<int>(5, 0);
		vector<int> v(5, 0);


		//for (int i = 0; i < 5; i++) 
		cout << sizeof(vPtr) << endl;
		cout << &vPtr[0] << "," << &vPtr[1] << endl;
		//for (int i = 0; i < 5; i++) 
		cout << &v[0] << "," << &v[1] << endl;
	}
}