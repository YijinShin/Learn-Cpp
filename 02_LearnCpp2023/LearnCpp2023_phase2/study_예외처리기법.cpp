/* [ c++ 예외처리 기법 ]

- mutable
	읽기 전용 함수 (funct() const) 에서 쓰기를 해야하는 경우, 맴버 변수 앞에 mutable붙이면 해당 변수는 
	읽기 전용함수에도 쓸 수 있음. 
	( const cast는 const가 붙은 pointer, ref타입의 참조값에 쓰기를 할 수 있게 해주는거임! 헷갈리지 말기 )  

- try catch
	throw에 의해 던져진 값과, catch가 받는 자료형이 같아야함. 안그럼 에러남. 
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
		//m_iSrc = _iData; ReadOnly()가 const함수라 mutable아닌 맴버는 못씀. 
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

		// 이런식으로 에러(?) 코드를 인식시킬수있다. 
		int i = 11;

		try
		{
			if (i == 10) throw 0;
			if (i == 11) throw 1;
		}
		catch (int iCode)
		{
			if (iCode == 0) cout << "iData가 10이라서 throw됨" << endl;
			else if (iCode == 1) cout << "iData가 11이라서 throw됨" << endl;

		}
		
	}

}