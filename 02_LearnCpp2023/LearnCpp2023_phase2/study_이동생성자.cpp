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

	// 복사 생성자 (깊은 복사)
	CTest3(const CTest3& rhs):m_iArray(new int[rhs.m_iSize]), m_iSize(rhs.m_iSize),m_iId(0) {
		cout << "깊은 복사 생성자 호출 " << endl;
		memcpy(m_iArray, rhs.m_iArray,sizeof(int)*rhs.m_iSize);
	}
	// 이동 생성자 
	CTest3(CTest3&& rvr):m_iId(0) {
		cout << "이동 생성자 호출 " << endl;
		m_iArray = rvr.m_iArray;
		rvr.m_iArray = nullptr;	// delete는 하면안됨!! 그 할당받은 heap을 그대로 생성되는 애한테 이전시키는 것임!
	}
	~CTest3() {
		cout << m_iId << "의 소멸자 호출" << endl;
		if (m_iArray) {
			cout << m_iId << "의 m_szName 삭제" << endl;
			delete[] m_iArray;
			m_iArray = nullptr;
		}
	}
	int* GetArray() { return m_iArray; }
	void Rander() { 
		//cout << m_szName << endl; }
		cout << m_iId << "의 rander" << endl;
	}
	void SetId(int _iId) { m_iId = _iId; }
};

/* 이동 생성자 */
int main(){
	CTest3 t1(5);
	t1.SetId(1);

	// 복사 생성자 
	cout << "* 복사생성자 후 * " << endl;
	CTest3 t2(t1);
	t2.SetId(2);
	cout << "t1: "; t1.Rander();
	cout << "t2: "; t2.Rander();

	// 이동 생성자 
	cout << "* 이동생성자 후 * " << endl;
	CTest3 t3(std::move(t1));
	t3.SetId(3);
	cout << "t1: "; if (t1.GetArray() != nullptr) t1.Rander(); else cout << "nullptr" << endl;
	cout << "t2: "; t2.Rander();
	cout << "t3: "; t3.Rander();
	}