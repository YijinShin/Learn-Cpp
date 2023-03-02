/* [ C++11���� ���� ������ ] 

- auto Ű����
- ���� ��� for�� 
- ������ �ʱ�ȭ

*/

#include "stdafx.h"
#include <vector>
using namespace std;

class CTest {
public:
	CTest() { cout << "CTest������" << endl; };
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
		// {}�� �ʱ�ȭ �ϴ� ���
		CTest ct{};
	}
}