/* [ STL algorithm �Լ� ]

- sort()
	- ����ü ���ø��̴�. 
		����ü�� ������.. ����ü�� ����Ʈ�� public�̶�.. class���ϸ� public:����ϴϱ� ������
		���� �Ѵܾ� �Ⱦ��� ����..
	- ()�� �����ε� �ϰ� �ִ�. 
	- ����Ʈ ���
	- �迭��� 
		- 
		���� vector, deque�� ��� ���������� ������� list�� ����� �� ����. 
		list�� �����̳ʾȿ� �ɹ� �Լ��� �������� sort�� ������ �ִ�. 
		���������̳ʴ� �ڵ������ϱ� ������ �̰� ���� �ʴ´�.

- count_t
	- ������ ���Ҹ� �ϳ��� ��ȸ�ϸ鼭 �����ڿ� ����ְ� true�� ��ȯ�� ������ ������ ������.

- for_each
	- ������ ���Ҹ� �ϳ��� ��ȸ�ϸ鼭 �����ڿ� ����ִ´�.

*/

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

template <typename T>
bool Less(T a, T b) {
	return a < b;
}

template <typename T>
class Greater {
public:
	bool operator ()(T a, T b) {
		return a < b;
	}
};

template <typename T>
bool isOdd(T a) {
	if (a % 2 == 0) return false;
	else return true;
}

template <typename T>
bool isEven(T a) {
	if (a % 2 == 0) return true;
	else return false;
}

template <typename T>
void power(T& a) {
	a = a * a;
}

struct Delete {
	template<typename T>
	void operator ()(T& a) {
		delete a;
		a = nullptr;
	}
};


template<typename T>
struct Delete2 {
	void operator ()(T& a) {
		delete a;
		a = nullptr;
	}
};

class CTest {
private:
	int m_iData;
public:
	CTest() :m_iData(0) {}
};

void Rander(vector<int>& vec) {
	for (auto i : vec) cout << i << ", ";
	cout << endl;
}

int main() {

	/* sort */
	{
		// ����:  1. ���� iter, �� iter, ���� ������ 
		
		vector<int> vec{ 100,60,20,50,30 };
		
		/* �����ڷ� �Լ� ���ø� ���, �κ� ���� */
		sort(++vec.begin(), vec.end(), Less<int>);
		Rander(vec);

		/* �����ڷ� �Լ� ��ü ���, ��ü ���� */
		sort(vec.begin(), vec.end(), Greater<int>());
		Rander(vec);

		/* �����ڷ� �̹� ������� ������ ��� (<functional>) */
			// less<T>()		�Լ� ��ü�̴�. 	
			// greater<T>()		�Լ� ��ü�̴�. 
		sort(vec.begin(), vec.end(), less<int>());
		Rander(vec);
	}

	/* count_t */
	{
		// ����: 1.����iter, 2.��iter, 3.������ 
		// ���ϰ�: �����ڿ� �־ true�� ��ȯ�� ���� ������ ī��Ʈ�ؼ� ������. 
		
		vector<int> vec{ 1,2,3,4,5 };
		int iOddCnt = count_if(vec.begin(), vec.end(), isOdd<int>);
		int iEvenCnt = count_if(vec.begin(), vec.end(), isEven<int>);

		cout << "OddCnt: " << iOddCnt << "\tEvenCnt: " << iEvenCnt << endl;
	}

	/* for_each */
	{
		vector<int> vecI{ 1,2,3,4,5 };

		for_each(vecI.begin(), vecI.end(), power<int>);
		Rander(vecI);

		/* �޸� �����Ҷ� �̷��� �� �� �ִ�. */
		vector<CTest*> vec(5);
		cout << "for_each��: " << vec.size() << ", " << vec.capacity() << endl;
		for_each(vec.begin(), vec.end(), Delete());
		//for_each(vec.begin(), vec.end(), Delete2<CTest>());	
					/* �̰Ŵ� �ȵǴ°�, �����ڷ� �츮�� iter�� �Ѱ��ְ�����.�ٵ�
					Delete2Ÿ�� T�� CTest�� �Ѱ������. �̰� �ΰ��� ȣȯ�� �ȵǼ� ������.
					�׷��� Ÿ���� ���⼭ �����ʿ������ Delete()ó�� ����°���. */
		cout << "for_each��: " << vec.size() << ", " << vec.capacity() << endl;

	}
}