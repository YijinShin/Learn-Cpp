#include "stdafx.h"
using namespace std;


class CTest3 {
private:
	int m_iId;
	int m_iSize;
	int* m_iArray;
public:
	CTest3(int _iSize):m_iArray(new int[_iSize]), m_iSize(_iSize), m_iId(0) {
	}

	// ���� ������ (���� ����)
	CTest3(const CTest3& rhs):m_iArray(new int[rhs.m_iSize]), m_iSize(rhs.m_iSize),m_iId(0) {
		cout << "���� ���� ������ ȣ�� " << endl;
		memcpy(m_iArray, rhs.m_iArray,sizeof(int)*rhs.m_iSize);
	}
	// �̵� ������ 
	CTest3(CTest3&& rvr):m_iId(0) {
		cout << "�̵� ������ ȣ�� " << endl;
		m_iArray = rvr.m_iArray;
		rvr.m_iArray = nullptr;	// delete�� �ϸ�ȵ�!! �� �Ҵ���� heap�� �״�� �����Ǵ� ������ ������Ű�� ����!
	}
	~CTest3() {
		cout << m_iId << "�� �Ҹ��� ȣ��" << endl;
		if (m_iArray) {
			cout << m_iId << "�� m_szName ����" << endl;
			delete[] m_iArray;
			m_iArray = nullptr;
		}
	}
	int* GetArray() { return m_iArray; }
	void Rander() { 
		//cout << m_szName << endl; }
		cout << m_iId << "�� rander" << endl;
	}
	void SetId(int _iId) { m_iId = _iId; }
};

/* �̵� ������ */
int main(){
	CTest3 t1(5);
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
	cout << "t1: "; if (t1.GetArray() != nullptr) t1.Rander(); else cout << "nullptr" << endl;
	cout << "t2: "; t2.Rander();
	cout << "t3: "; t3.Rander();
	}