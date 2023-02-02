/*
TOPIC : ���� �Լ� / ��� ��ũ��(��ũ�� ���) / �Լ� ��ũ�� / ���Ǻ� ������

*/

#include <iostream>

// ��ũ�� �Լ� : ��ȣ�� �߿伺
#define		MUL1(X)		((X) * (X))	// ��ȣ�� ���°Ͱ� �ƴѰ��� ���̸� �� �˾ƾ���! 
#define		MUL2(X)		X * X

// ��ũ�� �Լ� : ������ �Լ�
#define		FUNC(X)		cout << "1. "<< X<< endl;\
cout << "2. " << X << endl;\
cout << "3. " << X << endl;							//���������� �������� ��������
	/* ������ ��!�������� �ڿ��� �ƹ��͵� �������! ���鵵, �ּ��� �� �������!
	   ���������ڿ��ִ� �ͱ��� ���δ� ��ũ�� ���� �ڵ�ε�����*/

// ���Ǻ� ������ ���ÿ� �� ��ũ�ε� 
#define AAA 10



using namespace std;



int main() {
	// ���� 
	{
		FILE* pFile = nullptr;
		fopen_s(&pFile, "../Data/Test.txt", "wb");
		int iArr[5] = { 1,2,3,4,5 };
		fwrite(iArr, sizeof(int), sizeof(iArr) / sizeof(int), pFile);

		fseek(pFile, 0, SEEK_END);
	}

	// ��ũ�� �Լ� ��� 
	{
		//��ũ�� �Լ��� �ڵ�� �ܼ� ġȯ�� ���ִ°���! 
		int result1 = MUL1(2+2);	// �̰Ŵ� (2+2) * (2+2) �� �����ϴ°Ű�
		int result2 = MUL2(2+2);	// �̰Ŵ� 2 + 2 * 2 + 2 �� �����ؼ�, ������ �켱�������� => 2 + (2*2) + 2�� �����Ѵ�.

		cout << result1 << " / " << result2 << endl;

		FUNC("hello");
	}

	// ���Ǻ� ������:  if, elif, else, endif
	{
		/* �翬�ϰԵ� �̰� ��ó���� �ܰ迡�� ����Ǳ� ������ ���α׷� ���� �Ŀ� ����ڰ� ���� �Է��� ���� �������� �� �� ����
		   �׳� ������ �Ϲ� �����鵵 �� �� ����. */
		int iData = 10;
#if iData>0	// �翬�ϰԵ�.. ������ �ȳ�. ��ó���� �ܰ迡�� ������ �߻��ѰŴϱ� �����Ͽ��� ������ �˼�����. �̰� �׳� "��� ��ũ���߿� iData�� ����.."�ϰ� �Ѿ����. 
		cout << "�Ϲݺ����� �������� ����" << endl;
#endif
		
#if AAA > 0
		cout << "AAA�� 0���� ũ��." << endl;
#elif AAA < 0
		cout << "AAA�� 0���� �۴�." << endl;
#else
		cout << "AAA�� 0�Դϴ�." << endl;
#endif
	}

	// ���Ǻ� ������: ifdef, elif, else, endif
	{
#ifdef BBB
		cout << "BBB define�Ǿ��ֽ��ϴ�." << endl;
#elif AAA
		cout << "AAA�� define�Ǿ��ֽ��ϴ�." << endl;
#else
		cout << "AAA, BBB ��� define �Ǿ����� �ʽ��ϴ�." << endl;
#endif
	}

	// ���Ǻ� ������: ifndef, elif, else, endif
	{
#ifndef BBB
		cout << "BBB define�Ǿ����� �ʽ��ϴ�." << endl;
#elif AAA
		cout << "AAA�� define�Ǿ����� �ʽ��ϴ�." << endl;
#else
		cout << "AAA, BBB ��� define �Ǿ��ֽ��ϴ�." << endl;
#endif
	}

	{
		cout << endl;

	}
}