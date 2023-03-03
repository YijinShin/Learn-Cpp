/* [ C++11���� ���� ������ ] 

- auto Ű����
- ���� ��� for�� 
- ������ �ʱ�ȭ
	������ �ʱ�ȭ ({} �� �̿��� ������ ȣ��) �� ���ؼ� ���� ���� �����ڰ� �Լ��� ���Ƿ� ���صǴ� ���� ���� �� ������ 
	initializer_list �� ����� ������ �� �ֽ��ϴ�. 
	initializer_list �� ���ؼ� ��ü�� �����ϰ� ������ �� �ֽ��ϴ�.

*/

#include "stdafx.h"
#include <vector>
#include <list>
using namespace std;

class CTest {
public:
	CTest() { cout << "CTest������" << endl; };
};

class CTest2 {
public:
	CTest2() { cout << "���ڰ� ���� ������" << endl; }
	CTest2(int _i, double _d) { cout << "int, double�� �޴� ������ " << endl; }
	CTest2(std::initializer_list<int> _list) { cout << "list<int>�� �޴� ������ " << endl; }
};

int main() {

	/* auto Ű���� */
	{
		vector<int> vec(5, 2);

		vector<int>::iterator iter = vec.begin();

		auto iter2 = vec.begin();	// Ÿ���� �����Ϸ��� �˾Ƽ� ó�����ش�. 
	}

	/* ���� ��� for�� */
	{
		int iArray[]{1,2,3,4,5};
		for (int i : iArray) cout << iArray[i] << ", ";	
		cout << endl;

		vector<int> vec{ 1,2,3,4,5 };
		//for (auto i : vec) cout << vec[i] << ",";
		cout << endl;
	}

	/* ������ �ʱ�ȭ */
	{
		// {}�� ���� ���� ������ ȣ���ϱ�
		CTest ct{};

		// {}�� �����ϵǴ� ����Ǽ� 
		CTest2 t1{};
		CTest2 t2(10, 10.4);
		//CTest2 t3{ 10, 10.4 };	// initializer_list�� ���ڷ� �޴� �����ڰ� �ְ�, initializer_list�� Ÿ���� int�� �ʱ�ȭ ����Ʈ�� �νĵ�.
									// �ٵ� {}�� �ε��Ҽ���Ÿ�� <-> ���� Ÿ�԰��� �Ͻ��� ����ȯ�� ���� ������ ������ ��. 
									// (int, double) �����ڸ� �θ����� 1. initializer_list�� Ÿ���� �ƿ� string�̷��� �ٲ�����ų�(�Ͻ��� ��ȯ�� �ƿ� �ȵǴ� Ÿ������) 
									//								  2. initializer_list �� ���ڷ� ������ �����ڸ� ���ָ��. 
	}
}