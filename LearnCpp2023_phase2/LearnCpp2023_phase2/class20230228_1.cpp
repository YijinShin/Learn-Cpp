/*
[ deque ]
���ͺ��� ���Ի��� �� ����
vector�� �޸� push front, pop front ����
�ɹ��Լ��� ���Ͷ� ���� �����

��ϴ��� �޸��Ҵ� -> ���Ҵ� Ƚ�� ���̱� 
------------------------------------------------------------------------------------
[ map ]
key, value�� �ѽ�
�����Ʈ���� �����Ǿ�����. 
key�� ���� �ڵ����ĵ�

���Ի����� �������ϱ� ������ ���Ի����� �Ҹ��� ( ���Ի��� ��ü�� �����ΰǾƴϰ�(������� ���Ի����� �迭��ݺ��� ����) �������ؾ��ϴϱ� �������°�.)
�ݺ��� ���ؼ� Ž�� ����, ���� ���ٵ� ���� ([]�� �����ε� �Ǿ��ֱ� ����)

���������� �ȴٰ��ؼ� �迭����� �ƴϴ�. ������ ����������̳���
���������� key������ ����. 

������߿� ���������� �����ؼ� Ž�������� ���� ��. (�ַ� ���ҽ� Ž�������� ���̾�)
�ߺ� Ű��������

-------------------------------------------------------------------------------------

[ multimap ]
[]�� �����ε� �ȵǾ��־  ���������� �Ұ�����. 
�ߺ� key����

map, multimap��� ����� <map>
-------------------------------------------------------------------------------------
*/

#include "stdafx.h"
#include <map>
#include <functional>
using namespace std;

struct tagFinder {
public:
	char* 

	tagFinder(char* _pTag):m_;
	template<typename T>
	bool operator()(T& myPair) {
		if (!strcmp(myPair.first)) return true;

	}
};

int main() {
	
	//map �����̳ʴ� �������ø��̴�. �׸��� 4���� ��. 
	// 1.key �ڷ���, 2.value�ڷ���, 3.���� ������(����, ����), //�ٵ� ������ �տ� 1,2�� ��
	//map<int, int> map1;
	/* key�����δ� �ַ� ���ڿ�(char*, string)�� ���� ��.
		char*�� ���������, �츮���忡���� ���ڿ������ �ִ°����� �����Ϸ����忡���� �ּҰ��̶�� ��������. 
		�ٵ� ���α׷��ӵ��� char*�� ���� ��ȣ��. string�����̳ʴ� (�����Ϸ����� �� �ٸ�����) 28����Ʈ�̴�. ũ�Ⱑ ŭ
		�׷��� char* �� ���� �����(���� 4�Ǵ�8����Ʈ�ۿ� ����)
		�׸��� stl�����̳ʷ� key���� �������, �ִ� 8���ڱ����ۿ� ������ ����. ��Ȯ�� ������ �� ��. �Ƹ� string���� key�� ����ϸ� �����Ҵ��� �Ͼ�� �ʴ°�찡 �ִ� �� ���ٰ� �Ѵ�. �׷��� �⺻������ �Ҵ�� �޸𸮱����� �� �� �ִ�..
		�� �̷� �̽��� �ִ�. ��ο��� �Ͼ�� �� �ƴѵ� �����ִٰ� �Ѵ�. */

	
	// ����
	{
		map<int, int> mapInt;

		/*��� 1*/
				/* ��� ��, �� �̷� ������ ��� push back, push front�� ���� �� insert�� �ִ�. 
				pair ��ü�� �ʿ��ϴ�. pair���� Ŭ���� ���ø�*/
			pair<int, int> myPair(1, 100);
			mapInt.insert(myPair);

			pair<int, int> myPair2;
			myPair2.first = 2;			//pair�� �� �̷��� ���Ե� ����
			myPair2.second = 200;
			mapInt.insert(myPair2);
	
		/*���2*/
			mapInt.insert(pair<int, int>(3, 300));	//pair�ӽ� ��ü�� ���� ���

		/*���3*/
				/* make_pair�Լ� �̿��ϱ�. ��� �Լ� ���ø�. ��� �ӽð�ü�� ������ִ� �Լ� .
				����� �������� ������ ����. �̰� ���ٿ� �׳� 2��������� ���°� ����. 
				�Լ� ���ø��̴ϱ� ��� make_pair<int,int>(4,400) �̷��� ���°� �´�. 
				int,int�� �Ƚ��ָ� �����Ϸ��� Ÿ���� �Ǵ��ؾ��ϴµ�, �ϴ� �����Ϸ� ������ ���Ǵ��� �ؾ��ϴ� ������ �ִٴ°� ��ü�� �ð��� �� �ɸ�. 
				�׷��� �׳� 3��������ٿ� 2�� ��*/
			mapInt.insert(make_pair(4, 400));	

		/*���4*/
				/* �� �����̳� ��ü�� ������ pair��ü ����� ����*/
			map<int, int>::value_type myValueType(5,500);
			//myValueType.first = 5;	// ���� ����� �ȵ�. �Ϲ� pair��ü���� ����
			mapInt.insert(myValueType);

		/*���5*/
			/* value_type�� �ӽð�ü�� ����ϱ�
			stl�� �̰� ���� ����. ������ map�� �� ������ �̰� ����1!!!!*/
			mapInt.insert(map<int, int>::value_type(6, 600));

		/*���6*/
			/* []���Կ����ڷ� ���� �߰�. 
			�̰� �����ؾ��� ������ �ִ�.
				���Կ����ڷ� �� �ֱ�� insert�� ������ �ٸ���. 
				�������� ���ο� ��带 �ִ°��� "���ο� ������ �Ŀ�" >> �� ���� �� �����̴�. 
				insert�� ���ο� ��� ������ ���ÿ� ���� �ִ°Ű�
			�̰� �� �Ⱦ��� ����
				�ϴ� []�� �����ε��̴�.
				eky���� �ִ��� ������ �Ǵ��ϰ�
					������ �޸𸮰����� �Ҵ���. >> �ٸ� insert ������� ��û ����
					������ �ű⿡ �ִ� value�� ��. 

			*/
			mapInt[7] = 700;	
	
		/*���7*/
			/* c++11���� ���� ���ο� ���
			map �����̳��� ���ο� Inplace�Լ� 
			�� �� ������ �������. �����Ϸ��� �ڷ��� �˾Ƽ� �ľ���
			*/
			mapInt.emplace(8, 800);	

		/*���8*/
			/* ������ �ʱ�ȭ
			�����Ϸ��� �˾Ƽ� �ڷ��� �Ǵ���*/
			mapInt.insert({9,900});

		/* 5�� ���ų�
		7,8���Ÿ� ���� 8�� ���°� ����. ���� ū �ӵ����̴� �����ѵ� ���⿡ �� �������̶�.(pair�� ����������� ������) 
		������ ū ����� ���µ�

		����(6��)�� insert�� �ٸ���. �̰͸� �������. 
		*/

		// ���
		for (map<int, int>::iterator iter = mapInt.begin(); iter != mapInt.end();) {
			//cout << (*iter) << endl;	// �̷��Դ� �ȵ�. key���� value���� ������ �Ȱ��ϱ�. 
			cout << iter->first << ", ";	//key
			cout << iter->second << endl;	//value
		}
	}

	// ã��
	{
		map<int, int> mapInt;
		for(int i=0;i<5;i++) mapInt.insert({i,i*100});
		

		map<int, int>::iterator iter = mapInt.begin();

		//iter += 3;	//	map�� �����ݺ����� iter+=3 �̷��� �ȵ�. ������ ++�� --�����
		iter++;
		iter++;
		cout << iter->first << "," << iter->second << endl;

		// �ڵ������̶� ���۶����� �߰������� �ǹ̰� ����. �߰��� �־ �˾Ƽ� �����ع���
		mapInt.insert(iter, map<int, int>::value_type(4, 4000));

		for (map<int, int>::iterator iter = mapInt.begin(); iter != mapInt.end();) {
			//cout << (*iter) << endl;	// �̷��Դ� �ȵ�. key���� value���� ������ �Ȱ��ϱ�. 
			cout << iter->first << ", ";	//key
			cout << iter->second << endl;	//value
		}


		mapInt.erase(iter);	

		for (map<int, int>::iterator iter2 = mapInt.begin(); iter2 != mapInt.end();) {
			//cout << (*iter) << endl;	// �̷��Դ� �ȵ�. key���� value���� ������ �Ȱ��ϱ�. 
			cout << iter2->first << ", ";	//key
			cout << iter2->second << endl;	//value
		}

		mapInt.erase(4);	// key������ �����ϱ� 

		/*erase ���� ������ ���� ������ ����Ű�� ������ ������
			iter = mapInt.erase(iter); �̷������� �ؾ���. 
			�̰Ŵ� ��.. �ٸ� �����̳ʿ����� �������� */

	}
	
	// ������ 
	{
		map<int, int, greater<int>> mapInt;	// greater���� key���� �ڷ����� �־�����Ѵ�. �װ� �����̴ϱ�. 
		for (int i = 0; i < 5; i++) mapInt.insert({ i,i * 100 });
	}

	//find �Լ� 
	{
		map<int, int> mapInt;
		for (int i = 0; i < 5; i++) mapInt.insert({ i,i * 100 });

		map<int, int>::iterator iterTarget = mapInt.find(3);	//key���� 3�ξָ� ã�ڴ�. 
																//���࿡ 3�̶�� key���� ���ٸ� mapInt.end()�� ��ȯ�ȴ�. 
		if (iterTarget == mapInt.end()) cout << "ã�� �����Ͱ� �����ϴ�." << endl;
		else cout << iterTarget->second << endl;

	}

	{
		map<const char*, int> mapInt;
		mapInt.insert({ "AA", 100 });
		mapInt.insert({ "BB", 200 });
		mapInt.insert({ "CC", 300 });

		map<const char*, int>::iterator iter = mapInt.find("BB");
		
		/*
		�̷��� ã�°� ���� ����� ��찡 �ִ�.
		1. ���� ����½�, 2.��Ƽ������ 3.���� ��..? 

		�̰� char*�� �ּҰ��̱� ������ Ž���Ҷ� ������ �� �� �ִ�. 
		�ذ����� find�Լ��� �ƴ� �˰������� Ž���ϴ°��̴�. 

		stl�˰����߿� find_if�� �ִ�. 
		
		*/

		map<const char*, int>::iterator iter = find_if(mapInt.begin(), mapInt.end(), );	//�������� ������
		/* �����ڸ� �Լ������ͷ� ����ٸ� => �Լ� �����ʹ� �Ű������� ���� �� ����. �׷��� �ܺ� �����͸� ��� �Լ� �ȿ��� �����Ҽ��ִ°�. ���Ѵ�. 
		�׷��� �Լ� ��ü�� �����ڷ� ����Ѵ�. 
		����) �ܺ� �����͸� ������ �ȿ��� �����ִٸ� �Լ� ��ü�� �������Ѵ�. (���� ����� ���ҿ�)*/

	}


	{
		map<const char*, int> mapInt;
		mapInt.insert({ "AA", 100 });
		mapInt.insert({ "BB", 200 });
		mapInt.insert({ "CC", 300 });

		/*
		key������ ���ڿ��� ���� ���µ�
		
		char(wchar_t, TCHAR)�ΰ��
			- �ƽ�Ű �ڵ� �����̴ϱ� ���ĺ� �� ������ �����ϴ�.

		char*(wchar_t*, TCHAR*)�� ���
			- ���ڿ��� ���� �ּҸ� ��Һ��Ͽ� ������ �Ͼ. ���ĺ����� �ƴ϶�

		string(wstring)�� ��� 
			- ���ڿ� ��� �񱳰� ������ �����ε� �Ǿ��־ ���ĺ� �� ������ ����. 
		*/

	}

}