/* [ Vector ] 

- stdl�� �����̳�
- vector������ -> heap�޸𸮿� �����Ҵ��. 
- array�� ���� �ӵ��� �� ������
- array�� ���� �޸𸮸� ȿ�������� �����ϰ�, ����ó���� ����


*/

#include "stdafx.h"
#include <vector>
#include <string>

using namespace std;


struct stTest {
	int iData;
	string iSrc;
};

struct stTest2 {
	stTest fuck;
};


typedef struct stItemINFO {
	int iId;
	char szName[20];
	string strInfo;
	int iPrice;
	int iResellPrice;
	int iEffect_OffencePower;
	int iEffect_DefencePower;
	int iEffect_HillHP;
	int iEffect_DamageHP;
}ITEMINFO;


typedef struct stInventoryItemINFO {
	ITEMINFO stItemInfo;
	int iCnt;
}INVENITEMINFO;

class CTest {
public:
	int iA;
	CTest operator + (CTest& ct) {
		CTest newCTest;
		newCTest.iA = iA + ct.iA;
		return newCTest;
	}
};

int main() {
	// ���� ����, �ʱ�ȭ 
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

	// vector �ݺ��� ��� �Լ� 
	{

	}

	// ���� �����Ҵ�� �迭
	{
		vector<int>* vPtr = new vector<int>(5, 0);
		vector<int> v(5, 0);


		//for (int i = 0; i < 5; i++) 
		cout << sizeof(vPtr) << endl;
		cout << &vPtr[0] << "," << &vPtr[1] << endl;
		//for (int i = 0; i < 5; i++) 
		cout << &v[0] << "," << &v[1] << endl;
	}
	cout << endl;

	// ����ü ���� pop���� �ִ��� ���� 
	{
		vector<INVENITEMINFO> v1;

		INVENITEMINFO t[2] = {{ 0 }, {0}};
		for (int i = 0; i < 2; i++) v1.push_back(t[i]);

		//v1.pop_back();
		cout << "before:" << v1.size() << endl;
		v1.erase(v1.begin() + 1);
		cout << "after:" << v1.size() << endl;
	}

	{
		CTest t1 = { 10 };
		CTest t2 = { 20 };
		CTest t3 = t1 + t2;
		cout << t3.iA << endl;
	}
}