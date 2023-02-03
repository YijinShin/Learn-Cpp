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

struct tagInfo5 {
	int& iRef;
};

struct tagInfo6 {
	char szName[20];
	int iData;

};

int main() {
	tagInfo1 t1;
	tagInfo2 t2;

	tagInfo3 t3;
	tagInfo4 t4;

	tagInfo6 t6;

	int iData = 10;
	tagInfo5 t5{iData};	// 이건 ref변수가 있어서 무조건 초기화 해야함. 
						// 초기화는 매개변수가 아니다. 그러니까 상수는 안됨! 

	cout << sizeof(t2) << endl;
	cout << sizeof(t3) << endl;
	cout << sizeof(t4) << endl;
	cout << sizeof(t5) << endl;	// int Ref라서 4byte나옴. 
	cout << sizeof(t6) << endl;


	{
		char szDest[15] = "xxxxxxxxxxxxx";
		char szSrc[5] = "aa";
		strcpy_s(szDest, 3, szSrc);

		cout << szDest << endl;		// 문자열을 인식해서 출력하므로 "aa"까지만 나옴

		for (int i = 0; i < 15; i++) {	// 문자열을 떠나서 그냥 메모리 공간에 접근해서 값 조회해보기
			cout << szDest[i];
		}
	}

	{
		char szData[20] = "hellohellohello";
		char szSrc[20] = "bye bye";
		cout << endl;
		memcpy(szData, szSrc, 3); // 결과는 byelo
		cout << szData << endl;
		memcpy(szData, szSrc, 20); // 결과는 bye b
		cout << szData << endl;
	}

	{
		char szName[5] = { 'C' };
		cout << szName[3] << endl;
	}

	{
		short* sPtr = new short[2] {1,2};

		cout << sPtr << " == "<< &sPtr[0]<<  endl;
		cout << sPtr + 1 << " == " << &sPtr[1] << endl;

	}
}