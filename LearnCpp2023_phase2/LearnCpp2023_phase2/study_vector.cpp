/* [ Vector ] 

- stdl�� �����̳�
- vector������ -> heap�޸𸮿� �����Ҵ��. 
- array�� ���� �ӵ��� �� ������
- array�� ���� �޸𸮸� ȿ�������� �����ϰ�, ����ó���� ����


*/

#include "stdafx.h"
#include <vector>

using namespace std;

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
}