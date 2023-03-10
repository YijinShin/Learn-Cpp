/* [ map, multimap �����̳� �ɹ� �Լ� ���� ]

2023.03.02
stl����: vector, list, deque, set, multiset, map, multimap, 
		unordered_map,set,multimap, multiset

��������
	[map]======================================================
	* stl�����̳ʱ� ������ �翬�� Ŭ���� ���ø����� �����Ǿ�����.
	* key, value �ѽ����� �����͸� ������
	* �����Ʈ���� �����Ǿ�����
	* key�� ���� �ڵ� ���ĵ�. 
		* key���� ���ڿ��� ���, ����ؾ��� ����� �ִ�. 
			* char(wchar_t, TCHAR)�� ���: �ƽ�Ű�ڵ� ���� key���̱� ������ ���ĺ��� ���ĵ�
			* char*(wchar_t*, TCHAR*)�� ���: ���ڿ� �����ּҼ����� ���ĵ�.(���ĺ����� �ƴ�)
			* string(wstring)�� ���: ���ڿ� ��� �񱳰� ������ �����ε� �Ǿ��־ ���ĺ� ���ĵ�.
	* �ߺ� key�� ������.
	* ����, ��� ��� �����̳�
	* ����� �ݺ��� ���. ������ ���� ���� ������([]�� �����ε� �Ǿ�����).
		������̴ϱ� �翬�� iter+=3 �̷��� �ȵǰ�, ++, --�� ����ؾ���
	* ���Ի��� : ����, ���� ���� ��ü�� �迭��ݺ��� ������. ����ð����⵵
				�׷��� ����, ������ �ڵ������� �����ϱ� ������ ����, �����ϴµ� �ð��� �ɸ��� ���̴�. (�ڵ������� Ʈ�� ���̿� �����. log n )
	* ��� ��� �����̳� �� �����ϰ� ���� ������ �Ǳ� ������ Ž�������� ���� �����. (�ַ� ���ҽ� Ž�������� ���� �����)

	[multimap]======================================================
	map�� �� �Ȱ����� �ٸ����� �� 2�� �ִ�.
	* �ߺ� key�� �����. 
	* �������� �ȵ� ([] �����ε� �ȵǾ�����).

�����
	- map �����̳� ��ü ����
		map�����̳ʴ� �������ø��̴�. �׸��� 4�� ��. 
		1.key �ڷ���, 2.value�ڷ���, 3.����������, 4.�Ҵ���(allocator)
			3. ����������: ���� �������ָ� �⺻������ �������� 
			4. allocator: ������ �޸� ������ ���� Ŭ���� ���ø�. 
					   �޸� �Ҵ�, ���� ������ �ϴ� �ɹ� �Լ��� ������ �ִ�. 
					   ���� new, delete�� �޸� �Ҵ�, ������ �ϴµ� stl�����̳ʿ����� �� �� ȿ������ �޸� �Ҵ�, ������ �ϱ� ���� allocator��� Ŭ���� ���ø��� ����Ѵ�.
					   new�� �޸� �Ҵ�� ���ÿ� �ʱ�ȭ�� �����ϴµ� allocator������ �Ҵ縸 ��. => ���ʿ��� ������� ���� �� ����. 
	- ����
		- .insert()
			- pair
			- make_pair()
			- map::value_type
			- {} (������ �ʱ�ȭ)
		- [] (���Կ�����)
		map�� ���� �����̳��̱⶧���� push_back, front�̷��� ����. ������ ����.
		map�� key, value�� �ѽ��̱� ������ �׳� ���� �ִ°� �ƴ϶� pair���� ��ü�� �־����.
		�߰� ������ �ǹ̰� ����. ������ �ڵ����ĵǾ������ ������
	
	- ����
		- .erase()
		erase�� �ٸ� �����̳ʿ����� ���������� erase��, ������ iter�� ���� iter�� ��ȯ��. 
		key�����ε� Ư�� �� ������ְ�, iter�� ���� �� ����. 
	
	- Ž��
		- .find()
		- find_if()	
		key������ã�ų� iter�� ã�� �� �ִ�. 
		���� key�� char*(���ڿ�)��� �����ڸ� ���� �����ؼ� find_if�� ����ϴ� ���� ����. 
			char	:	�������� ������ 
			char*	:	�ּҰ��� ������ 
						map<char*, int> mymap �̷�����
						mymap.find("dd") �̷����ϸ� "dd"��� ���ڿ��� �ּҰ��� ã�°���. �׷��� �׳� ���� �ϴ� ���� �ȵ�. 
						�ٵ� �̰� �ȵǴ� ��찡 �ִٴ°���. ��Ƽ������ ����, ���� ������Ʈ�� ����� ��� ���
						��ư, ������ ���� ��� ���߿� ���� ����� ������ �̰͵� ���������� ����. 
			string	:	���ڿ� Ž����. (string���� ��Һ� �����ε��Ǿ�����) �׷��� �ּұ���� �ƴ϶� ���ڿ� �� ���ڿ� ����.	
						�ٵ� ���ڿ� ����� ������ �װ� ������ �ȴ°���. 
						�꾲�� find ������ �ȵ�. 
						key������ �뷮�� �� ū�� ����. 
						unicode����̸� 8���� �̻��� �ȵ�
						
*/

#include "stdafx.h"
#include <map>
using namespace std;

inline void Rander(map<int, int>& map1) {
	for (map<int, int>::iterator iter = map1.begin(); iter != map1.end(); iter++)
		cout << iter->first << ", " << iter->second << endl;
}

inline void Initialize(map<int,int>& map1) {
	for (int i = 0; i < 6; i++) 
		map1.insert(map<int,int>::value_type(i, i*100));
}

struct tagFinder {
private:
	const char* m_pTag;
public: 
	tagFinder(const char* _pTag) :m_pTag(_pTag) {}	// �ܺο��� char*�� �޾ƿ;��ϱ� ������ �ɹ� ������ �ְ�, �����ڸ� ���� ��. 

	template<typename T>
	bool operator()(T& MyPair) {
		if (!strcmp(MyPair.first, m_pTag)) return true;
		else return false;
	}
};

int main() {
	
	/* ���� */
	{
		map<int, int> map1;
		map<char*, int, greater<int>> map2;	// ���� �����ڱ��� ����. ���������ڿ��� key�� �ڷ����� ������.
	}

	/* ���� */
	{
		map<int, int> map1;
		
		/* ���1: pair ��ü ���� */
		pair<int, int> myPair1(1, 100);
		map1.insert(myPair1);

		/* ���2: pair �ӽ� ��ü ��� */
		map1.insert(pair<int, int>(2, 200));

		/* ���3: make_pair�Լ� ��� 
		   make_pair�� �Լ� ���ø�����, pair��ü�� ������ش�. 
		   �Լ� ���ø��̴ϱ� ��� make_pair<key, value>�̷��� Ÿ���� �� �����ؾ߸´°ǵ�, �Ⱦ��� �����Ϸ��� �˾Ƽ� �Ǵ����ش�.
		   ������ �����Ϸ��� ���� �Ǵ��ϵ��� �δ� �� ��ü�� �ð��� ��ƸԱ� ������ make_pair���ٿ� �׳� 2��ó�� �ӽð�ü�� ���°� ����.*/
		map1.insert(make_pair(3, 300));	

		/* ���4: value_type ��� 
			map�����̳ʰ� �����ϰ� �ִ�, ����.
			�Ϲ� pair�� �ٸ��� .first�� .second�� ������ �Ұ����ϴ�.*/
		map<int, int>::value_type myValue_type1(4, 400);
		map1.insert(myValue_type1);

		/* ���5: value_type �ӽ� ��ü ��� */
		map1.insert(map<int, int>::value_type(5, 500));

		/* ���6: []���Կ����� ��� 
			insert�� �޸� �Ҵ�+�ʱ�ȭ 
			[]�� ������ ���״�� ������. 
			[key]�� �ϸ�, key�� �ִ� ��� -> �ش� ����� value�� �� ����, 
						 key�� ���� ��� -> ���� �޸𸮰��� �Ҵ� ��, �� ������. 
			��, ó�� ���� �������� �ϴ� ���, �Ϲ����� insert���ٴ� ����. */
		map1[5] = 5000;	// �̹� ������, ���� �ٲ�
		map1[6] = 600;	// ���� �޸� �Ҵ� ��, �� ����

		/* ���7: emplace�Լ� ���
			c++11���� ���� ���ο� ����
			map�����̳��� �ɹ� �Լ�. 
			�����Ϸ��� �ڷ��� �˾Ƽ� �ľ�����. */
		map1.emplace(7, 700);

		/* ���8: ������ �ʱ�ȭ
			c++11���� ���� ���ο� ���� */
		map1.insert({8,800});

		Rander(map1);

		// ��õ: 5��, 8�� ��õ. 
		cout << endl;
	}

	/* iterator�� ���� */
	{
		map<int, int> map1;
		map1.insert(map<int, int>::value_type(1, 100));

		cout << map1.begin()->first << endl;	//key�� ����
		cout << map1.begin()->second << endl;	//value�� ���� 
	}


	/* ���� */
	{
		map<int, int> map1;
		Initialize(map1);

		Rander(map1);

		map1.erase(map1.begin());	// iterator�� ����
		map1.erase(5);				//key������ ����

		Rander(map1);
		cout << endl;
	}

	/* ã�� */
	{	
		/* key�� ���ڿ��� �ƴ� ��� */
		{
			map<int, int> map1;
			Initialize(map1);

			map<int, int>::iterator iter = map1.find(3);
			if (iter == map1.end()) cout << "ã�� ���߽��ϴ�." << endl;					// ��ã���� end()�� ��ȯ��. 
			else cout << "ã�ҽ��ϴ�. " << iter->first << ", " << iter->second << endl;

			iter = map1.find(10);
			if (iter == map1.end()) cout << "ã�� ���߽��ϴ�." << endl;					// ��ã���� end()�� ��ȯ��. 
			else cout << "ã�ҽ��ϴ�. " << iter->first << ", " << iter->second << endl;
		}

		/* key�� ���ڿ��� ��� */
		{
			/* char*�� ��� */
			map<const char*, int> map1;
			map1.insert({ "AA", 100 });
			map1.insert({ "BB", 200 });
			map1.insert({ "CC", 300 });
			map1.insert({ "DD", 400 });

			auto iter = map1.find("AA");
			if (iter == map1.end()) cout << "ã�� ���߽��ϴ�." << endl;					// ��ã���� end()�� ��ȯ��. 
			else cout << "ã�ҽ��ϴ�. " << iter->first << ", " << iter->second << endl;
			
			/* �������� ������ ������ char*�� �׳� find�Լ��� ã���� ������ ���� �� �ִ�. 
			* ������ �߻��ϴ� ���: ���Ͽ��� �����͸� �о���� ���, ��Ƽ������ ��.. 
			* ����: char*�� key�� �ϸ� �ּҰ��� ���ؼ� ã�� ��. 
				
			* �ذ�: �׷��� find�� �ƴ϶� find_if��� algorithm�Լ��� �����. find_if�� ���������� �����ڰ� �����Ѵ�. 
					�� �����ڴ� char* ���� ���ؼ�, ������ true, �ٸ��� false�� ��ȯ�ϴ� �Լ� ��ü��, �Լ� ���ø��� �����Ѵ�.*/

			iter = find_if(map1.begin(), map1.end(), tagFinder("AA"));
			if (iter == map1.end()) cout << "ã�� ���߽��ϴ�." << endl;					// ��ã���� end()�� ��ȯ��. 
			else cout << "ã�ҽ��ϴ�. " << iter->first << ", " << iter->second << endl;

		}

		/* map�� ũ�� */
		{
			/* map�� size�� �ִ�. 
			   �迭����� �ƴ϶� �׷��� capasity�� ����. 
			   ������ ������̶� �ϳ��߰�, �ϳ������ϸ� ���ΰ�. ����ó�� ���Ҵ� �̽��� �Ű澵 �ʿ䰡 ���µ�.*/
			
			map<const char*, int> map1;
			cout << map1.size() << endl;
			cout << sizeof(map1) << endl;

			map1.insert({ "AA", 100 });
			map1.insert({ "BB", 200 });
			map1.insert({ "CC", 300 });
			map1.insert({ "DD", 400 });
			
			cout << sizeof(map1) << endl;
			cout << map1.size() << endl;
		}
		
	}
}




