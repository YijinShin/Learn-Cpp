/* ���� �����ڸ� ���� ���縦 �����ϵ��� �����ε� ���� �ʰ�
�׳� ����Ʈ (��������) ���� �����ڸ� ����� ��� �߻��ϴ� ���� */

#include "stdafx.h"
using namespace std;


class CTest{
private:
	char* szName;
public:
	CTest(const char* _szName) {
		int iLength = strlen(_szName);
		szName = new char(iLength +1);
		strcpy_s(szName, iLength+1,_szName );
	}

	~CTest() { delete[] szName; }

	char* GetName() const { return szName; }
};

void Func(CTest _t) {						// _t�� t1�� ���� ���� �ع����¹ٶ���, _t�� szName�� t1�� szName�� ����. 
											// �� �Լ� ȣ���� ������ �������� _t�� �Ҹ��ڰ� ȣ��Ǹ鼭 _t�� t1�� szName�� �� ������. 
	cout << _t.GetName() << endl;
}


int main() {

	CTest t1("hello");

	Func(t1);

	//���� ���α׷��� �������� t1�� �Ҹ��Ű���� �ϴµ�, Func(t1)���� �̹� _t�� �Ҹ��Ű�鼭 _t�� t1�� �����ϴ� szName�� �Ҹ��Ŵ. 
	// �׷��� '�̹� �Ҹ��Ų �޸𸮸� �� �����Ϸ��� �Ѵ�"�� ������ ��.  
	// ������ Heap Corruption detected : �߸��� ���޸� ������ 
}