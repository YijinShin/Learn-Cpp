/* [ C++ study with TCP school ]
topic: �Լ� / �����Լ��� ���� / ����Լ� / �Լ� ������

* ���� �Լ��� ���� 
	���� �Լ��� ���ڴ� 2���̴�.���� void�� �ص���.
		1. int argc
			�μ��� ���޵Ǵ� ���ڿ��� ����
		2. char *argv[]
			���޵� ������ ���ڿ��� ���ԵǴ� �迭 
-------------------------------------------------------------------------------------

* �Ϲ� �Լ��� ���� ����
	�Լ��� �μ��� �����ϴ� ���
	- ������ ����
		�̰Ŵ� ���� �����͸� �ִ°� �ƴ϶� �Ű������� ���� ������ �ѱ�� ��. 
		�Լ� ������ ���� �����͸� �ǵ帮�� ����. 
	- ������ ���� ����
		������ �ּҰ��� ���� �����Ѵ�. ��, ���� �����͸� ������� ��
	- �����͸� ����
		�̰ų� ������ ���� �����̳� ����. 
		���� �� &value �̷��� �Ұ���, &value�� ������ ������ �־� �����Ұ��� �� �����ϻ� 

	���: ����, ������ -> ���� �������� "�ּҰ�"�� �����ϴ� ��. 
-------------------------------------------------------------------------------------

* ����Լ�
	����Լ��� ������ ������ ������ �������� �Լ��� ����Ǹ鼭 ���ÿ����÷ο� ������ ���� ����� ���̴�. 
	
	* stackoverflow : stack ������ �ش� ���α׷��� ����� �� �ִ� �޸� ���� �̻��� ����Ϸ��� �Ѵٴ� ����
-------------------------------------------------------------------------------------

* �Լ� ������ (function pointer)
	�Լ��� �̸� = constant pointer(������ ���)�̴�. ( �Լ��� �̸� ��ü�� ������ ������ ��) 
				 ������ ����ϱ� �翬��, �� ������ ������ �������ִ� �ּҰ��� �츮�� �ٲ� �� ����. 
				 �޸𸮿� �ö� �Լ��� ���� �ּҸ� �ǹ���. 
	�Լ� ������(function pointer) = �Լ��� ���� �ּҸ� ����Ű�� ��� 

	* ��� ������ vs ������ ���
		��� ������(pointer of constant) = ����� ����Ű�� ������
		������ ��� (constant pointer) = ������ ������ ������ �ִ� �ּҰ��� ������ �� ���� ������

	* �Լ� �������� Ÿ�� 
		[ �Լ��� ����Ÿ�� + �Ű����� ]�� ���� �����ȴ�. 

	* ����ϴ� ���
		�Լ��� -> �� �ٸ� �Լ��� �μ��� ������ �� �����ϰ� ����. 
	
	* �Լ� ������ ǥ�⸦ �ܼ�ȭ �ϴ� �ΰ��� ���
		
		- typedef
				�Լ� �����Ϳ� ���ο� �̸��� ���δ�. 
				�Լ� �����͸� ���Ϸ��� [int (*Func)(int, int)] �̷��� �䵥 �̰� �׳� ���� ó�� �����ؼ� ���� ������ �̸����� ���
				Func ptr_func = [�Լ� �����Ϳ� ���� �Լ��̸�(������ ���)]
		- auto
				auto ptr_func = calc; 
				�̷��� �ϸ� �ڵ����� calc() �Լ��� ������ ������ ptr_func �Լ� �������� Ÿ���� �����ع���
*/

#include <iostream>

using namespace std;
	
void func_call_by_value(int data);		 // �Լ��� �μ��� -> ������ ����.
void func_call_by_reference(int& data);	 // �Լ��� �μ��� -> ������ ���� ����.
void func_call_by_pointer(int* data);	
int Sum(int num);
double Add(int i1, int i2);
double Min(int i1, int i2);
double Mul(int i1, int i2);
double Div(int i1, int i2);
double Calculator(int i1, int i2, double (*func)(int, int));

typedef double (*Operator)(int, int); // typedef�� [double�� ���ϰ��̰�, �ŰԺ����� (int, int) �� �Լ� ������ �̸��� Operator�� ������


int main( int argc ,char *argv[]) {
	
	// [ ���� �Լ��� ���� ] 
	{
		//cout << "(" << argc << ")";
		//cout << argv << endl;
	}

	// [ �Լ� ���ڿ� ���� ������ ]
	{	
		int iData = 10;
		func_call_by_value(iData);
		cout << "iData ������: " << iData << endl;
		func_call_by_reference(iData);
		cout << "iData ������: " << iData << endl;
		func_call_by_pointer(&iData);
		cout << "iData ������: " << iData << endl;
	}

	// [ ��� ȣ�� ] 
	{
		int result;
		result = Sum(10);
		cout << "1~10���� ���� ���: " << result << endl;
	}

	// [ �Լ� ������ ��� ����]
	{
		int i1, i2;
		double result;
		char type;
		cout << "����1: ";
		cin >> i1;
		cin.ignore();
		cout << "����2: ";
		cin >> i2;
		cin.ignore();
		cout << "���� ������ �ұ�? (+,-,*,/): ";
		cin >> type;
		cin.ignore();

		switch (type)
		{
		case '+':
			result = Calculator(i1, i2, Add);
			break;
		case '-':
			result = Calculator(i1, i2, Min);
			break;
		case '/':
			result = Calculator(i1, i2, Div);
			break;
		case '*':
			result = Calculator(i1, i2, Mul);
			break;
		default:
			cout << "������ �߸� �Է��߽��ϴ�.";
			break;
		}
		cout << "���: " << result << endl;

	}

}

// ---------------------------------------------���� ���� ���� �Լ�--------------------------------------------- 

void func_call_by_value(int data) {
	data = data + 10;
	cout << "[�Լ� ����] data: " << data << endl;
}

void func_call_by_reference(int& data) {
	data = data + 20;
	cout << "[�Լ� ����] data: " << data << endl;
}

void func_call_by_pointer(int* data) {
	*data = *data + 20;
	cout << "[�Լ� ����] data: " << *data << endl;
}

// ---------------------------------------------����Լ�--------------------------------------------- 
int Sum(int num) {

	if (num == 1) {
		return 1;
	}

	return num + Sum(num - 1);
}
// ---------------------------------------------�Լ� ������ ���� ���� �Լ�--------------------------------------------- 
double Calculator(int i1, int i2, double (*func)(int, int )) {	//	 �Լ� ������ ��� ��� 
	return func(i1, i2);
}

// ���� �Լ��� ����. �ٵ� typedef�� �������� �̸� Operator�� [double (*func)(int,int) ��� ���� ��. ]
double Calculator_using_typedef(int i1, int i2, Operator func) {	
	return func(i1, i2);
}

/* // typedef�� �ٸ��� auto�� �̷������� ��� ����. 
double Calculator_using_typedef(int i1, int i2, auto func) {
	return func(i1, i2);
}
*/

double Add(int i1, int i2) {return i1 + i2;}
double Min(int i1, int i2) { return i1 - i2; }
double Mul(int i1, int i2) { return i1 * i2; }
double Div(int i1, int i2) { return i1 / i2; }