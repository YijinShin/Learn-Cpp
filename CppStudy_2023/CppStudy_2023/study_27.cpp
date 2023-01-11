/* [ C++ study with TCP school 12~19part ]
topic : �޸� ���� �Ҵ�

* �޸� ����
	������ ���� / ���� ���� / �� ���� 
	- ������ ����, ���� ������ �Ҵ�Ǵ� �޸��� ũ�� ->  ������ Ÿ��(compile time)�� �̸� ������
	- �� ������ �޸𸮰� �Ҵ�Ǵ� �޸��� ũ�� ->  ���α׷��� ����Ǵ� ������ �� Ÿ��(run time)�� ����ڰ� ���� ���� ���� 

* �޸� ���� �Ҵ�(dynamic allocation)
	��Ÿ�ӿ� �޸𸮸� �Ҵ� �޴� ��. 
	��, �̶� �Ҵ�޴� �޸𸮴� ���� ���� �� ������ �Ҵ�޴� ��. 

* ���� �Ҵ� ������ 
	- C ���
		- malloc()
		- calloc()
	- C++
		- new : �����Ϳ� �޸� �Ҵ� ( �� �� �Ҵ��ϴ� �޸𸮴� ���� �������̶�� �Ҹ��� �޸� ����(memory pool)�� �Ҵ�޴´�.)
				���� �Ҵ����� �޸� ������ ������ null �����͸� ��ȯ�Ѵ�. 
		- delete : �Ҵ���� �޸𸮸� �ٽ� �ü���� ��ȯ
*/

#include <iostream>

using namespace std;

int main() {
	// [ �����Ҵ� ������ ] 
	{
		// [new]
		int* ptr_int = new int; // �����Ϳ� �޸� �Ҵ� (4byte)
		*ptr_int = 10; // *�� ���� �����ڴϱ� .. �����Ͱ� ������ �ִ� �ּҰ��� -> 10�̶�� �����͸� �� ��.

		double* ptr_double = new double;
		*ptr_double = 3.14;

		cout << "int�� �Ҵ���� ptr_int�� ũ��: " << sizeof(ptr_int) << endl; // ��·�� ������ �����ϱ� �翬�� 8����Ʈ
		cout << "* ptr_int�� ũ��: " << sizeof(*ptr_int) << endl; // �ȿ� ����ִ� �����Ͱ� int�ϱ� 4����Ʈ
		cout << "double�� �Ҵ���� ptr_double�� ũ��: " << sizeof(ptr_int) << endl; // ��·�� ������ �����ϱ� �翬�� 8����Ʈ
		cout << "* ptr_int�� ũ��: " << sizeof(*ptr_double) << endl; // �ȿ� ����ִ� �����Ͱ� double�̴ϱ� 8����Ʈ

		// [delete]
		// ���� �Ҵ��� ���� �����ߴ� �����͵��� �� ������ delete�� �������ֱ� 
		delete ptr_int;
		delete ptr_double;
	}
}