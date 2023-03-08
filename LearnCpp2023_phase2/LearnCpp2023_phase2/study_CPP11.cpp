/* [ C++11���� ���� ������ ] 

- auto Ű����
- ���� ��� for�� 
- ������ �ʱ�ȭ
	������ �ʱ�ȭ ({} �� �̿��� ������ ȣ��) �� ���ؼ� ���� ���� �����ڰ� �Լ��� ���Ƿ� ���صǴ� ���� ���� �� ������ 
	initializer_list �� ����� ������ �� �ֽ��ϴ�. 
	initializer_list �� ���ؼ� ��ü�� �����ϰ� ������ �� �ֽ��ϴ�.

- ���ٽ� 
	stl�˰����� �����ڸ� �����ϴ� ���. 
	�Լ� ��ü�� ������ �����ϱ� ���� �����ߴ�. 

	�Լ� ��ü�� ����
		- �Ϲ��Լ��� ������ �����
		- �Լ� ��ü�� ��·�� ��ü��. 
		  �Ҹ���, ������ ȣ���� �� �߻��Ѵ�. 
		  ���� �����ڷ� �Լ� ������(�Ϲ��Լ���)�� ����ϴ� �� ���ٴ� �Լ� ��ü�� &�� �޴°� �� ������.
		  �׷��� �� �Լ� ��ü�� �����ڷ� ���°� ���� ���ٽ��� ���°� �� ������. (���ٽ��� ������ �ζ��� �Լ��̱⋚��) 

	���ٽ� ���� ���� : �Լ� ��ü�� �����ڷ� ���� �� ���� ������. 

	���ٽ� ����
		[]: ���� �Ұ���(ĸó��)	�����Ϸ��� �긦 ���� ���ٽ��̶�� ������
								�ܺ� �����͸� ������ �� �ֵ��� ���ش�. 
		(): �Ķ���� ������		�Ϲ� �Լ��� �Ű������� ���� �ǹ�
		->: ��ȯŸ��				��ȯ Ÿ���� ������. �Ⱦ��� �����Ϸ��� �˾Ƽ� ������ ����ȯ����. �׷��� ������ ������ΰ� �������� �� ���ٴ� ����. 
		{}: ���� ��ü			�Ϲ� �Լ��� ��ü 

		[](){ cout << "hello world"<<endl; }	// �̰� ���ٽ��� ���� ��. 
		[](){ cout << "hello world"<<endl; }();	// �̰� ���ٽ��� �����, ȣ���� ��.

		// ��ȯŸ���� �ִ� ���ٽ�
		[](int i)->bool{ if(i == 0) return false;}	

		// �ܺ� ������ ���� + ��ȯŸ�Ե� �ִ� ���ٽ� 
		int iSrc(0);
		[&](int iData)->bool { if(iData==0) {iSrc++; return true;}
								  else { iSrc--; return false;}     }();

		�ܺ� ������ ����(ĸó)�� �ȵǴ� �͵鵵 �ִ�. 
			- ��ǥ���ΰ� static, ����, class�� �ɹ� ���� 

- R-value reference
	���� R-value�� ���۷��� Ÿ�� ������ �ȵȴ�. 
		ex_ int& iRef = 10;
	�ٵ� �� �ϰ�ʹٸ� ������ ���� Ÿ���� �� �� �ִ�. 
		- const &
		- &&	(�̰� �츮�� ���ϴ� R-value ���۷���)

- �̵� ������ 
	�̵� �����ڴ� �������ε� param���� &&�� ����. 
	���� �����ڰ� -> A�� �����ϱ� ���� B�� �����͸� �״�� ���� �ؼ� ���� �̸�
	�̵� �����ڴ� -> A�� �����ϱ� ���� B�� �����͸� �״�� �Űܿ���, B�� �����̴�. 

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

class CTest3 {
private:
	int m_iId;
	char* m_szName;
public:
	CTest3(const char* _szName){
		int iSize = strlen(_szName)+1;
		m_szName = new char(iSize);
		strcpy_s(m_szName, iSize, _szName);
	}
	// ���� ������ (���� ����)
	CTest3(const CTest3& rhs) {
		cout << "���� ���� ������ ȣ�� " << endl;
		int iSize = strlen(rhs.m_szName) + 1;
		m_szName = new char(iSize);
		strcpy_s(m_szName, iSize, rhs.m_szName);
	}
	// �̵� ������ 
	CTest3(CTest3&& rvr) {
		cout << "�̵� ������ ȣ�� " << endl;
		m_szName = rvr.m_szName;
		rvr.m_szName = nullptr;	// delete�� �ϸ�ȵ�!! �� �Ҵ���� heap�� �״�� �����Ǵ� ������ ������Ű�� ����!
	}
	~CTest3() {
		cout << m_iId << "�� �Ҹ��� ȣ��" << endl;
		if(m_szName){
			cout << m_iId << "�� m_szName ����" << endl;
			delete[] m_szName;
			m_szName = nullptr;
		}
	}

	void Rander() { cout << m_szName << endl; }
	char* GetName() { return m_szName; }
	void SetId(int _iId) { m_iId = _iId; }
};


int main() {

	/* auto Ű���� */
	{
		cout << "[ auto ]" << endl;
		vector<int> vec(5, 2);

		vector<int>::iterator iter = vec.begin();

		auto iter2 = vec.begin();	// Ÿ���� �����Ϸ��� �˾Ƽ� ó�����ش�. 
	}

	/* ���� ��� for�� */
	{
		cout <<"\n\n[���� ��� for��]" << endl;
		int iArray[]{1,2,3,4,5};
		for (int i : iArray) cout << iArray[i] << ", ";	
		cout << endl;

		vector<int> vec{ 1,2,3,4,5 };
		//for (auto i : vec) cout << vec[i] << ",";
		cout << endl;
	}

	/* ������ �ʱ�ȭ */
	{
		cout << "\n\n[ ������ �ʱ�ȭ ]" << endl;
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

	/* ���ٽ� */
	{
		cout << "\n\n[ ���ٽ� ]" << endl;

		// ���ٽ� ȣ�� 
		[](){cout << "hello world" << endl; }();

		// �Ķ����, ���ϰ� �ִ� ���ٽ� ȣ��
		if ([](int iData)->bool { if (iData % 2 == 0) return true; else return false; }(10)) cout << "Even" << endl;
		else cout << "Odd" << endl;

		// �ܺ� ������ �����ϴ� ���ٽ� (&�� �ؾ� �������ȴ�.)
		{
			int iEvenCnt(0);
			int iArray[] = { 1,2,3,4,5 };
			for (int i : iArray) [&iEvenCnt](int iData) {if (iData % 2 == 0) iEvenCnt++; }(iArray[i]);
				// �׳� &�� ���൵�ȴ�. ���� �̸� �Ⱦ��� 
				//for (int i : iArray) [&](int iData) {if (iData % 2 == 0) iEvenCnt++; }(iArray[i]);
			cout << "Even number cnt: " << iEvenCnt << endl;
		}
		// �ܺ� �����͸� �߸� �����ϴ� ��� 1
		{
			int iEvenCnt(0);
			int iArray[] = { 1,2,3,4,5 };
			// �̷��� �ܺ� ������ �״�� ���� �Լ��� const�� �ڵ����� �پ ���Ⱑ �Ұ����ϴ�. (�б�� ����)
			//for (int i : iArray) [iEvenCnt](int iData) {if (iData % 2 == 0) iEvenCnt++; }(iArray[i]);
			cout << "Even number cnt: " << iEvenCnt << endl;
		}
		// �ܺ� �����͸� �߸� �����ϴ� ��� 2
		{
			int iEvenCnt(0);
			int iArray[] = { 1,2,3,4,5 };
			// const �Լ��� �Ǿ�����ϱ� mutableŰ����� ���ٽ��� ����� => �� ���� �ְ� �ȴ�. 
			// �׷��� ���ʿ� �ܺ� ������ ������ �ؼ� ������ ���̱� ������ ���ٽĿ��� ����� ���� �����Ͱ� ������ �ʴ´�. 
			for (int i : iArray) [iEvenCnt](int iData)mutable {if (iData % 2 == 0) iEvenCnt++; }(iArray[i]);
			cout << "Even number cnt: " << iEvenCnt << endl;
		}
	}

	/* R-value ���۷��� */
	{
		int iData(10);
		
		/* && */
		//int&& iR_ref1 = iData;	// l-value ���� �Ұ� 
		int&& iR_ref2 = 10;			// r-value ���� ���� 
		iR_ref2 = iData;			// l-vlaue ���� ����
		iR_ref2 = 20;				// r-value ���� ���� 
		
		/* const & */
		const int& i_Const_ref1 = iData;	// l-value ���� ���� 
		const int& i_Const_ref2 = 10;		// r-value ���� ���� 
		// i_Const_ref1 = iData;			// const�� �� ���� �Ұ���
		// i_Const_ref2 = iData;			// const�� �� ���� �Ұ���
		// i_Const_ref1 = 20;				// const�� �� ���� �Ұ���
		// i_Const_ref2 = 20;				// const�� �� ���� �Ұ���

		/* ����� & const�� �ƿ� �ٸ� �̾߱���. 
			��Ȯ���� �𸣰ڴ°� �׳� �Ϲ� &�� ���� ����. */
		int& const i_Ref_const1 = iData;
		//int& const i_Ref_const2 = 10;
		i_Ref_const1 = 20;	
	}

	/* �̵� ������ */
	{
		CTest3 t1("hello");
		t1.SetId(1);
	
		// ���� ������ 
		cout << "* ��������� �� * " << endl;
		CTest3 t2(t1);
		t2.SetId(2);
		cout << "t1: "; t1.Rander();
		cout << "t2: "; t2.Rander();

		// �̵� ������ 
		cout << "* �̵������� �� * " << endl;
		CTest3 t3(std::move(t1));
		t3.SetId(3);
		cout << "t1: "; if (t1.GetName() != nullptr) t1.Rander(); else cout << "nullptr" << endl;
		cout << "t2: "; t2.Rander();
		cout << "t3: "; t3.Rander();

		// ERROR: �̰� t3�� ���� ���� �Ҹ��Ű�µ� �Ҹ��Ҷ� �������ŵ�? ������ ��Ȯ�� �𸣰ڴµ� �Ƹ� �޸� �Ҵ��Ҷ� ������ �ִ� �� ����. 
		//		  study_�̵�������.cpp���� char*�� �ƴ϶� int*�� �Ȱ��� �����Ѱ� �ִµ�, �װŴ� �ƹ� ���� ���� �� ���ư�
	}
}