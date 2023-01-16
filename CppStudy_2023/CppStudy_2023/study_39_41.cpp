/* [ C++ study with TCP school 39 ~ 41part]
topic: ����Ʈ �μ� / �Լ� �����ε� / �ζ��� �Լ� / ��ũ�� �Լ�

--------------------------------------------------------------------------------------------------------------
* ����Ʈ �μ�
	����Ʈ �μ� = �⺻���� �̸� ���ǵǾ� �ִ� �μ� 
	�Լ��� ȣ���� �� �μ��� �������� ������, �Լ��� �ڵ����� �̸� ���ǵǾ� �ִ� ����Ʈ �μ����� ����� 

* ����Ʈ �μ� ���� ��Ģ
	1. �Լ��� ���������� ��������
	2. ���� ������ �Ű��������� ������� ��������
	   ��, ����� ���� ������ �����ϴ°� �Ұ���. �����ҰŸ� ���� �����ʺ��� �ؾ���. 

--------------------------------------------------------------------------------------------------------------

* �Լ� �����ε� (Function overloading)�̶�?
	: ���� �̸��� �Լ��� �ߺ��Ͽ� �����ϴ� ��

* �ַ� ����
	: ���� ����� �ϴ� �Լ��� , �پ��� �Ű����� ������ �ʿ��� ��

* "�Լ� �����ε�" �� -> ��ü ���� ���α׷����� Ư���� "������(polymorphism)�� �����̴�. 

	- ��ü ���� ���α׷����� 4���� Ư¡
		1. �߻�ȭ
		2. ĸ��ȭ
		3. ���
		4. ������
		
--------------------------------------------------------------------------------------------------------------

* C++���� �Լ��� ȣ���ϴ� ����
	�Լ��� ȣ���ϸ� 
	-> ���ؿ� �Լ��� ������ �Ű�����, ��ȯ �ּҰ��� ������
	-> �Լ� ���� ����� ���������� ���ÿ� ������
	-> ���ؿ� �����, ���ư� ��ȯ �ּҰ����� �̵��ؼ� -> ���ÿ� ����� �Լ� ȣ�� ������ ������
	
	�� ������ �Լ� ȣ��ø��� �߻��ϴµ�, �� '�Լ� ȣ���ϴµ� �ɸ��� �ð�' �� �� �����غ���
	- [ '�Լ��� �����ϴ� �ð�' > '�Լ� ȣ���ϴµ� �ɸ��� �ð�' ] : �̷� ���� ȣ���ϴµ� �ɸ��� �ð��� ���� �Ű澲���� ����. 
	- [ '�Լ��� �����ϴ� �ð�' < '�Լ� ȣ���ϴµ� �ɸ��� �ð�' ] : �ٵ� �� ���� �躸�� ����� ū����
	=> ��� ) ����ð��� ª�� �Լ����� �������� �Լ� ȣ������� ��ġ�⿡�� �ʹ� ���ҽ��� �Ʊ��. 
	=> �ذ��� ) �׷��� �ζ��� �Լ��� ����ϴ� ��. 
	
* �ζ��� �Լ�(inline function) 
	- �Ϲ����� �Լ� ȣ����� ��ġ��x
	- �Լ��� ��� �ڵ带 ȣ��� �ڸ��� �ٷ� ���� ( ������ �� �� > �ڵ�� �Լ� ȣ���� ���� �׳� ó������ �Լ� ������ �����Ŀ�, ������ �� �ϴ°���. '�Ϲ����� ȣ�����' ����) 
											  ( �״ϱ� �̰� �ڵ� ������ �� inline�� Ű���常 �߰��Ǵ� �� ���̰�, ������ �ڵ� ������ �߿� �߻��ϴ� �����ΰ�)  

	-inline Ű���� :  �Լ��� ���� / �Լ� ���� -> ���� �Ѱ����� ǥ���ص��� (�ٵ� ���ʴ� �ص� �������, �� ���� ���� ������)

--------------------------------------------------------------------------------------------------------------

* ��ũ�� �Լ� 
	�ַ� C���� ���� ��������, �ζ��� �Լ��� ���� ����ѱ��, ����� �뵵�� ����

	#define [��ũ�� �Լ� �̸�] ([�Ű�����]) [�Լ� ����]
	-> �̋�, �Լ� ����κп����� ��� �μ��� �� ��ȣ�� �������. 
		EX) x + x�� �ϰ�������
		   ((x) + (x)) �̷��� �����. 

*/

#include <iostream>
#define MECRO_FUNC(X) ((X)*(X))	 // ��ũ�� �Լ� 

using namespace std;



// [����Ʈ �μ� ���� �Լ� ]
	void TestFunc_DefaultArgument(int i1 = 1, int i2 = 1);	// �̰� �Լ��� �����̴�. 
	// void TestFunc_DefaultArgument(int i1 = 1, int i2 );  // �̰� �Ұ���. �����ʺ��� ����Ʈ �־����. 

// [�Լ� �����ε� ���� �Լ�]
	void Overloading_func(int i1);
	void Overloading_func(char ch1);
	void Overloading_func(int i1, string str1);

// [ �ζ��� �Լ� ���� �Լ�]
	inline void Inline_func1(int x) { cout << x << "�� �޾ҽ��ϴ�." << endl; }	  // ������ �����̴ϱ� �� �Լ��� �������� ���� ���� �Լ� ���� �ع����� ����
	inline void Inline_func2(int x);	// �ؿ� �Լ� �����ϰ� ���⼱ �Լ� ���� ���°�. (�Ϲ����� �Լ� ���� ����)



int main() {
	// [ ����Ʈ �μ� ]
	{
		TestFunc_DefaultArgument(10); //i1�� �����ϸ� i2�� �ڵ����� ����Ʈ �μ��� ��
		TestFunc_DefaultArgument(10, 20);	 // ��� �μ��� ���� ����������, ����Ʈ �μ������� ������ ���鸸 ���� 
	}

	// [ �Լ� �����ε� ]
	{
		Overloading_func(10);
		Overloading_func('A');
		Overloading_func(100, "hello world");
	}
	
	// [ �ζ��� �Լ� ]
	{
		Inline_func1(10);
		Inline_func2(20);
	}

	// [ ��ũ�� �Լ� ]
	{
		int result = MECRO_FUNC(10);
		cout << "��ũ�� �Լ� ���: " << result << endl;
		int x = 4;
		result = MECRO_FUNC(x+5);
		cout << "��ũ�� �Լ� ���: " << result << endl;
	}
	
}



void TestFunc_DefaultArgument(int i1, int i2) 	//�̰� �Լ� ����
{								// �̰� �Լ� ��ü
	cout << "i1: " << i1 << ", i2: " << i2 << endl;
}

void Overloading_func(int i1) { cout << "1. �����ε� �Լ� (int) : " << i1 << endl; }
void Overloading_func(char ch1) { cout << "2. �����ε� �Լ� (char) : " << ch1 << endl; }
void Overloading_func(int i1, string str1) { cout << "3. �����ε� �Լ� (int, string) : " << i1 << " / "<<str1 << endl; }

inline void Inline_func2(int x) { cout << x << "�� �޾ҽ��ϴ�." << endl; }