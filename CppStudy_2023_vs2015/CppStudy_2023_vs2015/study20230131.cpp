#include <iostream>

using namespace std;

// ����ü 
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
		cout << " �ʱⰪ�� �������� �ʾ��� ���: " << *iData << endl;

		int* iData2 = new int(5);
		cout << " �ʱⰪ�� �������� �ʾ��� ���: " << *iData2 << endl;

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

		cout << "szData ũ��: " << sizeof(szData) << " / szSrc ũ��: " << sizeof(szSrc) << endl;

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

	//����ü
	cout << endl;
	{
		unPosition unPos;

		unPos.x = 10;
		cout << " x��: " << unPos.x << " y��: " << unPos.y << endl;

		unPos.y = 20;
		cout << " x��: " << unPos.x << " y��: " << unPos.y << endl;
	}
	cout << endl;
	{
		unPosition unPos;

		cout << " x�� �ּ�: " << &unPos.x << endl;
		cout << " y�� �ּ�: " << &unPos.x << endl;
		
		cout << endl;
		unInfo unI;
		cout << " unInfo�� ũ��: " << sizeof(unI) << endl;
	}

	cout << endl;
	{
		unPosition unPos1;
		unPosition unPos2;
		
		unPos1.x = 10;
		cout << " [unPos1] x��: " << unPos1.x << " y��: " << unPos1.y << endl;
		unPos2.x = 20;
		cout << " [unPos2] x��: " << unPos2.x << " y��: " << unPos2.y << endl;
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