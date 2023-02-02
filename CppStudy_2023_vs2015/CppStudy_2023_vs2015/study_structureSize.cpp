#include <iostream>

using namespace std;

// 그냥 자녀 struct의 맴버가지고 구하고, 이후에 부모 구조체 더하면됨

struct tagInfo0 {	// 12byte
	char cData;
	short sData;
	// 4
};

struct tagInfo1 {	// 12byte
	char cData;	
	int iData1;
	int iData2;
	// 12
};

struct tagInfo2 {
	char cData;	// 1
	short sData;	//2	 
	// 여기까지만 하면 4
	tagInfo0 tInfo0;	// 4 + 4
	tagInfo1 tInfo1;	// 4 + 4 + 12
	tagInfo1 tInfo2;	// 4 + 4 + 12 + 12
	// 총 28
};

struct tagInfo3 {
	int iData;

	void Display() { cout << "hello" << endl; }	//  함수 맴버는 byte로 안팀
	int Func1() { return 10; }	// 함수 맴버는 byte로 안팀
	// 결과는 4바이트. iData만쳐준다.
};

struct tagInfo4 {
	// 아무것도 없으면 1바이트
};

int main() {
	tagInfo1 t1;
	tagInfo2 t2;

	tagInfo3 t3;
	tagInfo4 t4;

	cout << sizeof(t2) << endl;
	cout << sizeof(t3) << endl;
	cout << sizeof(t4) << endl;
}