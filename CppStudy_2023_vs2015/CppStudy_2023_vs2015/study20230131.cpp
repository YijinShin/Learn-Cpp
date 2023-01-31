#include <iostream>

using namespace std;

// 공용체 
union	unPosition
{
	int		x;
	int		y;
	//float	y;
};

union unInfo {
	char cData;
	int iData;
	double dData;
};

union unInfo2 {
	int age;
	float weight;
};

int main() {
	{
		cout << endl;
		int* iData = new int;
		cout << " 초기값을 지정하지 않았을 경우: " << *iData << endl;

		int* iData2 = new int(5);
		cout << " 초기값을 지정하지 않았을 경우: " << *iData2 << endl;

		const char* cArr_ptr = "hello";
		cArr_ptr = "wrld";

		const char cArr[30] = "hello";

		cout << cArr_ptr << endl;
		cout << cArr << endl;
		cout << endl;
	}
	
	{
		//int* arr = new int[4];
		int arr[4];
			memset(arr, 1, sizeof(arr));
			
			for(int i=0;i<4;i++)cout <<" "<< arr[i] << endl;
	}
	cout << endl;
	{
		char szData[10] = "hello";
		char szSrc[20] = "bye bye";

		cout << "szData 크기: " << sizeof(szData) << " / szSrc 크기: " << sizeof(szSrc) << endl;

		memcpy(szData, szSrc, 3);
		cout << " " << szData << endl;

		memcpy(szData, szSrc, 5);
		cout << " " << szData << endl;
	}

	cout << endl;
	{
		char szData[10] = "hello";
		char szSrc[20] = "bye bye";

		memmove(szData, szSrc, 3); // ERROR
		cout << szData << endl;
	}

	//공용체
	cout << endl;
	{
		unPosition unPos;

		unPos.x = 10;
		cout << " x값: " << unPos.x << " y값: " << unPos.y << endl;

		unPos.y = 20;
		cout << " x값: " << unPos.x << " y값: " << unPos.y << endl;
	}
	cout << endl;
	{
		unPosition unPos;

		cout << " x의 주소: " << &unPos.x << endl;
		cout << " y의 주소: " << &unPos.x << endl;
		
		cout << endl;
		unInfo unI;
		cout << " unInfo의 크기: " << sizeof(unI) << endl;
	}

	cout << endl;
	{
		unPosition unPos1;
		unPosition unPos2;
		
		unPos1.x = 10;
		cout << " [unPos1] x값: " << unPos1.x << " y값: " << unPos1.y << endl;
		unPos2.x = 20;
		cout << " [unPos2] x값: " << unPos2.x << " y값: " << unPos2.y << endl;
	}

	cout << endl;
	{

			unInfo2 unI;

			unI.age = 10;
			cout << " age: " << unI.age << ", weight: " << unI.weight << endl;
			unI.weight = 10.f;
			cout << " age: " << unI.age << ", weight: " << unI.weight << endl;

			cout << (float)10 << endl;
	}
}