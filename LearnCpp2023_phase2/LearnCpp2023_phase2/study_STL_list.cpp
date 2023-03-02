/* [ list �����̳� �ɹ� �Լ� ���� ] 

2023.03.02
stl����: vector, list, deque, set, multiset, map, multimap,
		unordered_map,set,multimap, multiset

��������
	* ������, ��� ��� �����̳�
	* ���� ��ũ�� ����Ʈ ���
	* ��� ����̴ϱ� �翬�� ����� �ݺ��ڸ� �����. 
		* ��, �������� �ȵǰ�, iter+=3�̷��͵� �ȵ�. ++, --�� ��밡��
	* ����, ������ ������. ������̰�, mapó�� ������ �ϴ� �͵� �ƴϱ� ����
	* Ž���� �Ҹ���. ���������� �ȵǰ�, �ѹ��� 1��徿�� �̵������ؼ�(++,--).
		�ð����⵵�� O(n) 

 �����
	�⺻������ vector�� ���� ������. 

	- ����
		- push_back()
		- push_front()
		- insert()
	- ���� 
		- pop_back()
		- pop_front()
		- erase()
		- clear()
	- ũ�� 
		-size()
	- ����
		-sort()
		���⼭�� sort�� stl <algorithm>�� sort�� �ƴϴ�. 
		list �����̳ʳ��� �ɹ� �Լ���. 
		stl <algotiyhm> sort()�� ����Ʈ�̰� �迭����̴�. list�� ������̶� ������ �ȵȴ�.
		�����ڴ� �翬�� function�� �ִ°� ��밡���ϴ�. 
	- ���� 
		-reverse()
	- �߷�����, �̾���̱�
		- splice()
		- merge()
		vector, deque�� �ٸ��� �߶󳻱�, �̾���̱Ⱑ �����ϴ�.
		�̰͵� �迭�� �ƴ϶� ������̱� ������ ������ ���̴�. 
		����� merge�� �պ������̶� �����̵ȴ�.

*/

#include "stdafx.h"
#include <list>
#include <functional>

using namespace std;

inline void Rander(list<int> _list) {
	for (auto iter = _list.begin(); iter != _list.end(); iter++)
		cout << *iter << ", ";
	cout << endl;
}

int main() {

	/* ���� + �ʱ�ȭ */
	{
		list<int> iDataList1;

		list<int> iDataList2(5);
		Rander(iDataList2);

		list<int> iDataList3(5,2);
		Rander(iDataList3);

		list<int> iDataList4{1,2,3,4};
		Rander(iDataList4);

		list<int> iDataList5(5);
		iDataList5.assign(3,100);
		Rander(iDataList5);
	}
	
	/* ���� */
	{
		list<int> iDataList;

		iDataList.push_back(1);
		iDataList.push_back(2);
		iDataList.push_front(0);
		iDataList.insert(++iDataList.begin(), 100);

		Rander(iDataList);
	}

	/* ���� */
	{
		list<int> iDataList{1,2,3,4,5};
		
		iDataList.pop_back();
		iDataList.pop_front();
		Rander(iDataList);

		list<int> iDataList2{ 1,2,3,4,5 };
		cout << "���� ��: ";
		Rander(iDataList2);
		
		for (list<int>::iterator iter = iDataList2.begin(); iter != iDataList2.end();)
			iter = iDataList2.erase(iter);
		
		cout << "���� ��: ";
		Rander(iDataList2); 
	}

	/* ���� */
	{
		list<int> iDataList{ 10,60,50,20,30 };
		cout << "���� ��:";
		Rander(iDataList);
		
		iDataList.sort();
		
		cout << "���� ��:";
		Rander(iDataList);
	}

	/* ���� */
	{
		list<int> iDataList{ 10,20,30,40,50 };
		cout << "���� ��:";
		Rander(iDataList);

		iDataList.reverse();

		cout << "���� ��:";
		Rander(iDataList);
	}

	/* �߶󳻱�, �ٿ��ֱ� */
	{
		/* vec1.splice(vec2) 
			vec2�� �߶󳻾�, vec1�� ���δ�. �Ѵ� ���� �����Ͱ� �ٲ��.*/

		list<int> iDataList1{ 10,20,30,40,50 };
		list<int> iDataList2{ 100,200,300,400,500 };
		
		auto iter1 = iDataList1.begin();
		auto iter2 = iDataList2.begin();
		iter2++;
		
		iDataList2.splice(iter2, iDataList1,iter1);	// iDataList2�� 2��°�� iDataList1�� 1���� �ٿ��ֱ�

		Rander(iDataList1);
		Rander(iDataList2);

		iDataList2.splice(iter2, iDataList1);	// iDataList ��ü�� �ٿ��ֱ�

		Rander(iDataList1);
		Rander(iDataList2);
		cout << endl;

		/* vec1.merge(vec2)
			merge�� �պ������̴�. �����̵ȴ�. 
			vec1������ ���� �� ��Ƽ� �����ϱ� ������ vec2�� �������. */

		list<int> iDataList3{ 10,20,30,40,50 };
		list<int> iDataList4{ 100,200,300,400,500 };
		iDataList3.merge(iDataList4);

		cout << "iDataList3: "; Rander(iDataList3);
		cout << "iDataList4: "; Rander(iDataList4);
	}
}