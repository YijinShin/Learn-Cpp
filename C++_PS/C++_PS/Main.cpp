#include <iostream>
#include <vector>
using namespace std;


class CHoneycomb {
private:
	int** m_iArray;
	int m_iN;
	int m_iSize;
	int m_iXMax;
	int m_iYMax;
public:
	CHoneycomb() : m_iArray(nullptr), m_iN(0), m_iSize(0), m_iXMax(0), m_iYMax(0){}
	CHoneycomb(int _iN) : m_iArray(nullptr), m_iN(_iN), m_iSize(0), m_iXMax(0), m_iYMax(0) {}

	void Initialize() {
		m_iSize = 1+ (6*(m_iN - 1) * (m_iN-1));
		m_iYMax = 5 + ((m_iN - 2) * 4);
		m_iXMax = m_iN;

		m_iArray = new int*[m_iYMax+1];
		for (int i = 0; i < m_iYMax+1; i++) m_iArray[i] = new int(m_iXMax+1);

		Fill();
	}

	void Fill() {
		int x(1);
		int y(1);
		int iData(1);
		int iRepet = m_iN - 1;

		// 일반적인 규칙으로 레이어 체우기
		for (int i = 0; i < m_iN - 2;) {
			// 레이어 첫 시작
			m_iArray[x][y] = iData;
			iData++;
			
			// 우측 하향 
			for (int j = 0; j < iRepet; j++) {
				x++;
				y++;
				m_iArray[x][y] = iData;
				iData++;
			}
			// 하향
			for (int j = 0; j < iRepet; j++) {
				y+=2;
				m_iArray[x][y] = iData;
				iData++;
			}
			// 좌측 하향
			for (int j = 0; j < iRepet; j++) {
				x--;
				y++;
				m_iArray[x][y] = iData;
				iData++;
			}
			// 좌측 상향
			for (int j = 0; j < iRepet; j++) {
				y--;
				m_iArray[x][y] = iData;
				iData++;
			}
			// 상향
			for (int j = 0; j < iRepet; j++) {
				y-=2;
				m_iArray[x][y] = iData;
				iData++;
			}
			// 우측 상향
			for (int j = 0; j < iRepet; j++) {
				y--;
				m_iArray[x][y] = iData;
				iData++;
			}
			
		}
	}

	
};

int main() {
	int iInput(0);
	cout << "size: ";
	cin >> iInput;

	CHoneycomb cHoneycomb(iInput);
	cHoneycomb.Initialize();
}