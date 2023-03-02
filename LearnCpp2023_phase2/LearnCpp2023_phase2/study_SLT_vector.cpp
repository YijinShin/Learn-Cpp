/* [ vector �����̳� �ɹ� �Լ� ���� ] 

2023.03.02
stl����: vector, list, deque, set, multiset, map, multimap,
		unordered_map,set,multimap, multiset

�������� 
* stl�����̳ʱ� ������ �翬�� Ŭ���� ���ø����� �����Ǿ�����
* ������, �迭 ��� �����̳�
* �迭 ����̴ϱ� ���� ���� �ݺ��ڸ� ����Ѵ�.
* �翬�� [] �������� ����. 
* ���� �迭�� ������� �Ѵ�.
* ����, ������ �Ҹ��ϴ�. 
	* �ϴ� �߰� ����, ������ ���� ��ҵ��� �ڷ� �аų� ������ ��ܾ���. 
	* ���Խ� ���Ҵ��� �߻��� �� ����. 
	  ���Ҵ� ������ [ �� ū ������ �迭 Ȯ�� -> ���� ������ ���� -> ���� �迭 ���� ] �̷��� ��. 
	  �翬�� ������ ���Ҵ��� �߻��ϸ� �ð��� ��Ƹ���. 
* Ž���� ������. ���������� �����ϱ� ������ 
* 

�������
	- ���� 
		- push_back()
		- insert()
	
	- ����
		- pop_back()
		- erase()
		- clear()
		- �� ���� �ӽð�ü���� swap()
		- shrink_to_fit() 
		���� ���� ��Ҹ� �����ؼ� size�� �پ capacity�� ���� �ʴ´�. 
		���Ҵ� �̽������� capa�� �� ��� �������� ���̴°� ������ �ƴϴ�.  
		������ Ÿ������ �����Ͱ� �ִ°��, �ش� �����͸� ���� �����ϰ�, ���� ��Ҹ� �����ؾ��Ѵ�.
	
	- ũ�� 
		- size()
		- capacity()
		- empty()
	
	- ��ü
		- swap()
	
	- ������ ����
		- resize()
		size�� �ٲٴ°��� capacity�� �ٲٴ°� �ƴϴ�. 
		size�� ���� capacity���� ũ�� �ٲ� ��� �翬�� ���Ҵ��� �߻��ϸ鼭 capacity�� �ٲ�����
		size�� ���� capa���� �۰� �ٲ۴ٰ��ؼ� capa�� ���� �ʴ´�. 
	- ����
		- reserve()
		capacity�� �̸� �����ϴ� ���̴�. ���Ҹ� ���� ����. size�� �״�ΰ� capa�� �þ��. 
		���࿡ � ���͸� �󸶳� ũ�⸣ ���� �̸� �˰��ִٸ�, 
			�翬�� ���Ҵ� �̽��� ���̱����� reserve�� �س��� ���°� ����. 

*/

#include "stdafx.h"
#include <vector>

using namespace std;

inline void Rander(vector<int>& vec) {
	for (auto iter = vec.begin(); iter != vec.end(); iter++) cout << *iter << endl;
	cout << endl;
}

inline void Initialize(vector<int>& vec) {
	for (int i = 0; i < 6; i++) vec.push_back(i * 10);
}

class CTest {
private: 
	int m_iData;
public:
	CTest():m_iData(0) {}
};

template <typename T>
void Safe_Delete(T& temp) {
	delete temp;
	temp = nullptr;
}

int main() {

	/* ����, �ʱ�ȭ */
	{
		vector<int> iVec1;	// ����. 
		vector<int> iVec2(5);	// ���̰� 5�� vector���� ��, �� 0���� �ʱ�ȭ
		int iArr[10] = { 10 };	//�̷��� �ϸ� 0�� �ε����� 10�̰�, �������� �� 0���� �ʱ�ȭ 
		vector<int> iVec3 = { 1,2,3 };	//���̰� 3�� vector���� ��, �ʱ�ȭ 
		vector<int> iVec4[] = { {1,2},{3,4} }; // ���� �迭����. �� ����, �� ���� 
		vector<vector<int>> iVec5;	//��,�� ��� ���� 
		vector<int> iVec6(5);
		iVec6.assign(5, 10);	// ���� 5������ ��� 10���� �ʱ�ȭ 
	}

	/* ���� */
	{
		vector<int> veciData;

		// �迭����̶� �ڿ����ۿ� ������. push_front�� ����. 
		veciData.push_back(10);
		veciData.push_back(20);
		veciData.push_back(30);
		veciData.push_back(40);

		// insert�� �߰��� �����ϱ� => �ٵ� ȿ�� ��û ������. �������� �� �ڷ� �о���ϴϱ� 
		vector<int>::iterator iter = veciData.begin();
		iter += 2;
		veciData.insert(iter, 1000);

		Rander(veciData);
	
	}

	/* ���� */
	{
		vector<int> veciData;
		Initialize(veciData);

		// ���� �ڿ��ִ°� ���� pop_front�� ����. 
			veciData.pop_back();		

		// �߰� ��� ���� => �ٵ� ȿ�� ��û ������. �������� �� ������ �о���ϴϱ�
			veciData.erase(veciData.begin() + 3);	// erase�� iter�� ���� iter�� ��ȯ��. 
			cout << veciData.size() << ", " << veciData.capacity() << endl;
			Rander(veciData);

		// ���� ��ü ����
			veciData.clear();
			cout << veciData.size() << ", " << veciData.capacity() << endl;


		/* ������ ���Ұ� �������ΰ�� �ܼ��� ��Ҹ� �����ϸ�ȵȴ�. 
			1. safe_delete (*iter)
			2. vec.erase(iter) 
			�̷��� �ؾ�, �� ������ ��ҵ� �����޸� �����ϰ�, ������ ��ҵ� ���� �� �ִ�. 
			1�� ���ϰ� erase���ϸ� �����Ͷ�, �� �����Ͱ� ����Ű�� heap�޸𸮴� ���ֹ̾ư� �ȴ�.*/
			vector<CTest*> vecCTest(5);
			for (auto iter = vecCTest.begin(); iter != vecCTest.end();) {
				Safe_Delete(*iter);
				iter = vecCTest.erase(iter);	// ������ iter�� ���� iter�� ��ȯ��. 
			}

			cout << vecCTest.size()<< ", "<<vecCTest.capacity() << endl;
			cout << endl;
					
		/* �� capacity�� ���̰� �ʹٸ� �� ���� �ӽð�ü�� ����ϴ� ����� �ִ�. */
			vector<int> veciData2;
			Initialize(veciData2);
			cout << "swap��: ";
			cout << veciData2.size() << ", " << veciData2.capacity() << endl;
			Rander(veciData2);
		
			vector<int>().swap(veciData2);	/* vector<int>()�� �ӽð�ü�̱� ������ swap�ϸ�
											vector<int>()�� veciData2�� ������ �� ������� ������ �����. */
			cout << "swap��: ";
			cout << veciData2.size() << ", " << veciData2.capacity() << endl;
			Rander(veciData2);

		// shrink_to_fit() ���� capacity�� ���ҿ� �� �°� ���̱� 
			vector<int> veciData3;
			for(int i=0;i<5;i++) veciData3.push_back(i*10);
			cout << "shrink_to_fit��: " << veciData3.size() << ", " << veciData3.capacity() << endl;
			veciData3.shrink_to_fit();
			cout << "shrink_to_fit��: " << veciData3.size() << ", " << veciData3.capacity() << endl;
	}

	/* ũ�� */
	{
		/* capacity�� 1���� �þ�°� �ƴ϶� ���Ҵ� �̽��� ���̱� ���� 
			�ѹ� �߰��� �� n���� �߰��ȴ�. 
			�����Ϸ����� ��å�� �ٸ����� vs�� ���Ҵ�� currCapa + currCapa*0.5 �� �ø���.*/
		vector<int> vec;

		for (int i = 1; i <= 7; i++) {
			vec.push_back(i * 10);
			/* size: ������ ���� */
			cout <<"size: " << vec.size() << ",";
			/* capacity: ������ �� �ִ� ������ ���� */
			cout <<"capacity: "<< vec.capacity() << endl;
		}
		cout << endl;

		// empty() ���Ұ� �ִ��� Ȯ�� 
		if (vec.empty()) cout << "�����." << endl;
		else cout << "��������" << endl;
	}

	/* ��ü */
	{
		vector<int> vec1(5,3);
		vector<int> vec2(5,2);
		vec2.swap(vec1);		// vec1.swap(vec2)�� ����. ������̵� �������.

		Rander(vec1);
		Rander(vec2);
	}

	/* ������ ���� */
	{
		vector<int> vec(5, 0);

		cout << "resize��: " << vec.size() << ", " << vec.capacity() << endl;

		vec.resize(3);	// capa���� �۰� ����

		cout << "resize��: " << vec.size() << ", " << vec.capacity() << endl;

		vec.resize(11);	// capa���� ũ�� ���� (capa�� ������ 11�� �þ��. 11�� ���Ҵ���.)

		cout << "resize��: " << vec.size() << ", " << vec.capacity() << endl;
	}

	/* ���� */
	{
		vector<int> vec;
	
		cout << "reserve��: " << vec.size() << ", " << vec.capacity() << endl;

		vec.reserve(5);

		cout << "reserve��: " << vec.size() << ", " << vec.capacity() << endl;
	}
}

