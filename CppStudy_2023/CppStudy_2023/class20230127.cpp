/*
1. ���ڿ� ���� �Լ��� 
2. ����ü 


*/

#include <iostream>
using namespace std;


typedef struct tagInfo
{
	int iMath;
	int iEng;

	// C�� ����ü�� �ɹ� �Լ��� ���� �� �����µ�, cPP���ʹ� ��������. 
	void Display() {
		cout << iMath << "," << iEng << endl;
	}
	

}INFO, *PINFO; // ���ŵ� �˾ƺ��� 


struct tagTemp {
	char sData;
	short iData;
	int sData2;
	float dData;
};

// �̰� ��, �Ʒ� �ΰ��� ����ü ũ�Ⱑ �ٸ�. ������ 12, ���� 16. �� -> �ɹ� ������ ���� ä��ŵ�? �׷� 
// ������ ) 8�Ҵ� > -1-2-4-float �̷��� ��
// �Ʒ��� ) 
struct tagTemp2 {
	char sData2;
	int sData;
	short iData;
	float dData;
};

struct tagTemp3 {
	char sData2[20];	// �̷�������ؼ� ������ 20����Ʈ�� �ƴϴ�! ������ �ڷ��� �߿� ���� ū����Ʈ �������� �Ҵ��̶� ���⼭�� ���� float�������� �Ҵ��� 
	int sData;
	short iData;
	float dData;
};

struct tagTT {
	long long ll1;
	long long ll1;
};

// �̷� ��쿡�� ������ �⺻ �ڷ��� �������� ���� ū �޸� Ÿ���� �������� ��´�. 
struct tagTemp3 {
	// +4
	short iData;	//2
	//+4
	int sData;	//4
	//+4

	float fData;	//4
	//long long dData;	// 8	// ������� 32�ε� why?

	tagTT  tt;	// 16
};

struct tagTemp3 {
	// +8
	short iData;	//2

	int sData;	//4
	//+8

	float fData;	//4
	//+8
	long long dData;	// 8	// ������� 32�ε� why?

	tagTT  tt;	// 16
};


/*

typedef struct tagInfo
{
	int iMath;
	int iEng;
}INFO, MONSTER, *PINFO;	// �̵����ε� ������ 

*/



int main(){


	/* ���� �迭�� ���ڿ� ����� ������
	- ������: �� �� ���ڿ��� ���� �ּҸ� �����ִ�.
	- ���� �迭�� ���� �ϳ��ϳ��� �迭�� ���ҿ� �����ϴ� ���
	- ���� �迭�� char const* ���¿� ���� �����ϴ�.
		�ּҰ��� ������ �Ұ����ص�, �����ϴ� �����ʹ� ���氡��
	- ���ڿ� ����� ������ ������ ��ϵ� ���ڿ��� ���� �ּҸ� ��´�.
	- ���ڿ� ����� const char* ���¿� ������ �����ϴ�.
	���� const ��ġ�� �ٸ���, �̰� �����ʹϱ� �б� ���� �����ѰͿ� ���� ������. 
	���ڿ� ����� �б� ����! ������ const�� �߰��� �����Ŵ� �ּҸ� ������ �� ���ٴ� �ǹ��� const!
	*/

	//------------------------------------------------------------------------------------------------------
	//���ڿ� ���� �Լ� 
	{
		char szTemp[6] = "jusin";
		char szArray[16] = "serewerwrewr";
		// ����Ʈ �ɼǾ��ذ�� -> �˾Ƽ� ��ü ����Ʈ ������, �׸��� �������� �� ��������
		strcpy_s(szArray, szTemp);
		cout << szTemp << endl;
	}
	cout << endl;


	{
		char szTemp[6] = "jusin";
		char szArray[16] = "serewerwrewr";
		// ��Ȯ�� �� ����Ʈ���� �������� �����ִ� �ɼ��� �� ���
		strcpy_s(szArray,6, szTemp);
		cout << szTemp << endl;

		for (int i = 0; i < 16; i++) {
			cout << szArray[i];	// �տ� 8����Ʈ ���Ĵ� ���� szArray�� ����ִ�.
		}
	}

	{
		//���縦 �޴� ����� ���� �ؿ��� ��󺸴� �� ���� ��� -> �����ϸ� ������
		char szTemp[6] = "jusin";
		char szArray[16] = "serewerwrewr";
		//strcpy_s(szTemp, szArray);	// ERROR
		cout << szTemp << endl;

		for (int i = 0; i < 16; i++) {
			cout << szArray[i];	// �տ� 8����Ʈ ���Ĵ� ���� szArray�� ����ִ�.
		}
		cout << endl;
	}

	/* ���ڿ� ����� �����ؿ��°� ���������� ���ڿ� ������� ���� �����ϴ°� �Ұ���. 
	���� ���� ���ڿ� ������ ���̴ϱ� -> �翬�� ���Ⱑ �Ұ���. �б� ������*/

	//------------------------------------------------------------------------------------------------------
	// ���ڿ� ���� ��� �Լ�
	cout << endl;
	{
		//�̰Ŵ� ���ڿ��� ������ ������. 
		//size_t strlen(char const* _Str);

		char szName[32] = "hello";	// 32��ŭ�� ũ�⸦ Ȯ���߾, ���ڿ��� ���̰� 5�ϱ� �̰� 5 (�ι��ڴ� ī���� ����)

		cout << strlen(szName) << endl;					// �����ϰ� ���ڰ� ���ִ�, ���ڿ��� ����
		cout << strlen("hello") << endl;					// ���ڿ� ����� ���� �� ����. 
		cout << sizeof(szName) << endl;	// �̰� �޸� ũ�⸦ ���� ���Ѱ�.
		cout << sizeof("hello") << endl;	// �̰� �޸� ũ�⸦ ���� ���Ѱ�. => char Ÿ�� ���� 5�� + �� 1��  = 6��
	}
	//------------------------------------------------------------------------------------------------------
	//���ڿ� ���Լ�
	cout << endl;
	{
		//int strcmp(char const* _str1, char const* _str2)
		// ��ġ�ϸ� => 0��ȯ! 1�� �ƴ�!


		char szName[32] = "ȫ�浿";
		cout << sizeof("ȫ�浿") << endl;	 // ȫ�浿�� 2����Ʈ, ���� 1 => �� 2*3 +1 = 7��. (ȫ, ��, �� �̰͵��� �����ڵ���)
		if (strcmp(szName, "ȫ�浿")) {
			cout << "����ġ" << endl;
		}
		else cout << "��ġ" << endl;
	}
	//------------------------------------------------------------------------------------------------------
	//���ڿ� ���� �Լ�
	cout << endl;
	{
		// erron_t strcat_s(char* _dest, rsize_t _sizeinbyte, char const* str)
		// �μ�: ���� �ܷΰ��� ������ ���� ���ڿ�, ù���� �Ű������� ���ۻ�����, ������ ���ڿ� 

		char szTemp[32] = "jusin";
		char szDest[32] = "academy";

		strcat_s(szTemp, sizeof(szTemp), szDest);
		cout << szTemp << endl;	// �� �������� �޸𸮰� �����ϸ� ����� ������
		cout << szDest << endl;	// �������شٰ� temp�ʿ� ���ΰŴϱ� �翬�� ��� �״�� �������� 

		cout << sizeof(szTemp) << endl;
		cout << sizeof(szDest) << endl;
		cout << strlen(szTemp) << endl;	// ��� ���� �� 5���� 12�� �þ
		cout << sizeof("jusinacademy") << endl;	//�̷��� ���� �ι��� ������ �翬�� 12�� �ƴ϶� 13�� ����. 
		cout << strlen(szDest) << endl;
	}
	/*
	����
	���ڿ����̱��ϴ� �Լ� ���� ����� (strlen���ϴ°���. null����)

	����
	�Է¹��� ���ڿ��� ������ �Լ� �����
	
	*/
	// ������ �ڷ��� ~ ����ü~!
	cout << endl;

	{
		// ����ü ���¹�..����..? �װ� �����ϱ� 
		// �� ����� �ʱ� ���� ������� ���� �׷��� 
		// ����ü + typedef�� ����ü �̸� ���°� �װŵ� �����ϱ� 

		// ����ü ������ ���� �����ϸ� �ʱ�ȭ �ϴ°Ŷ� -> �̰� ���°͵� ���� �����ϱ� 

		// ����ü�� ���, 
		// ����ü�� Ŭ���� ���� ��� �̰͵� �����ϱ� 

		tagTemp t1;
		cout << sizeof(t1) << endl;
		// ����ü�� ��ϴ��� ������  => �̰� �Ҵ��ϴ°� ����? 
		//���� ū�Ÿ� �Ҵ��ϰ�, �װ� �����ؼ� ���°� �׸��� �����ϸ� +�ؼ� ���� �� ���� 
		// ��·�� �׷��� ���� �ɹ��� ������ �޸� ũ�Ⱑ ���� �������� ���°� ����. 

		tagTemp2 t21;
		tagTemp t11;

		cout << sizeof(t1) << endl;

		cout << sizeof(t21) << endl;


	}
	cout << endl;

	/*
	����
	����ü�� �̿��Ͽ� �� ���� �л� ����ǥ ����� ���΃E �����
	�Լ� ���� ������� 
	- 1. �Է�, 2. ���, 3. �˻����(�̸����� �˻�) 4. ���� 
	
	*/
}