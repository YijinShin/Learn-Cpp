/* [ c++ ����ó�� ��� ]

- mutable
	�б� ���� �Լ� (funct() const) ���� ���⸦ �ؾ��ϴ� ���, �ɹ� ���� �տ� mutable���̸� �ش� ������ 
	�б� �����Լ����� �� �� ����. 
	( const cast�� const�� ���� pointer, refŸ���� �������� ���⸦ �� �� �ְ� ���ִ°���! �򰥸��� ���� )  

- try catch
	throw�� ���� ������ ����, catch�� �޴� �ڷ����� ���ƾ���. �ȱ׷� ������. 
*/

#include "stdafx.h"
using namespace std;

class CTest {
private:
	mutable int m_iData;
	int m_iSrc;
public:
	CTest() :m_iData(0), m_iSrc(0) {}
	void ReadOnly( int _iData) const {
		m_iData = _iData;
		//m_iSrc = _iData; ReadOnly()�� const�Լ��� mutable�ƴ� �ɹ��� ����. 
	}
	void Rander() { cout << "m_iData: " << m_iData << ", m_iSrc: " << m_iSrc << endl; }
};

int main() {

	/* mutable */
	{
		CTest t;

		t.ReadOnly(10);
		t.Rander();
	}

	/* try catch */
	{
		int iData = 0;
		int iSrc = 10;

		try {
			if (iData == 0) throw iData;
			cout << iSrc / iData << endl;
		}
		catch (int iNum) {
			cout << "divide by "<<iNum << endl;
		}

		// �̷������� ����(?) �ڵ带 �νĽ�ų���ִ�. 
		int i = 11;

		try
		{
			if (i == 10) throw 0;
			if (i == 11) throw 1;
		}
		catch (int iCode)
		{
			if (iCode == 0) cout << "iData�� 10�̶� throw��" << endl;
			else if (iCode == 1) cout << "iData�� 11�̶� throw��" << endl;

		}
		
	}

}