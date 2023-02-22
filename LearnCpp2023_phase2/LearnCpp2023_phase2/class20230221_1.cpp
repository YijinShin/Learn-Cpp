/*
������ �����ε� part2

topic: ++, -- �����ε�(����, ���� ����) 
(������!) ���� �����ϰ�, �ű⿡ ++�ؼ� ��ȯ�ϴ½���. 

stl������ stl�����̳ʰ� ����� �� �մ� �˰����̶�°��� �����Ѵ�. 
�̶� � �˰����� �����ų��, �˰����� � �������� �������� 
������(��ȯŸ���� bool�̸鼭 ..)

---------------------------------------------------------------------------------
�Լ� ��ü : ()�����ڸ� �����ε��Ͽ� ��ü�� �Լ�ó�� ������ ����� ����

int Add(int a, int b){return a+b;}	//�̷��� �ϸ� �Լ� 

class CPlus{
public:
	int operator()(int a, int b){return a+b;}
	int operator()(int a, int b){return a+b;}
}

int main(){
	cout << Add(10,20)<<endl;
	CPlus plus;
	cout << plus(20,30)<<endl;	// �̷��� ��ü�� �Լ�ó�� ���°� �Լ� ��ü
}
�Լ� ��ü ���� ���� = �˰��򿡼� �����ڷμ� ����ϱ� ���� 
���� : �Լ� ��ü�� ���� ȣ�� �����̶� ��ü � ��ü�Ŀ� ���� ���� �ٸ� ���¸� ���ϰ� ���ִ� ������ �ִ�. 
Ŭ���� ����ο� �ɹ� �Լ��� ��ü���� ���ǵǾ� �ִٸ� �ڵ����� inlineȭ�� ����Ǿ� �Ϲ� �Լ� ȣ��ӵ��� ���� ������. 


---------------------------------------------------------------------------------
------------------------------------------------------------------------------
�ӽ� ��ü
int iNumber = 1+2;   // �� �ڵ�� �� 12����Ʈ�� �Һ���. iNumber 4, 1=4 ,2=4 ���ļ� 12.
��ü�� �̷� �ӽ� �޸� ������ �������� ����Ҽ� �ִ�.

class Cobj{
public:
   Cobj(char* pString){
	  strcpy_s(m_szString, sizeof(m_szString), pString);
	  out << m_szString<<"������"<<endl;
   }
   ~Cobj(){
	  out << m_szString<<"�Ҹ���"<<endl;
   }
private:
   char m_szString;
}

Cobj obj("�Ϲݰ�ü);      // �Ϲ� ��ü ����
Cobj("�ӽð�ü");      // �ӽ� ��ü ����

�̷��� �ϸ� �����
   �Ϲ� ��ü ������
   �ӽ� ��ü ������
   �ӽ� ��ü �Ҹ���
   �Ϲ� ��ü �Ҹ���
�̷��� ����.
�̰� �ӽ� �޸� Ư���� ����� ����, �Ҹ��̶� �׷���.
�Ʊ� ������ �����ε��� �ؼ� (�Լ���ü)�����ڸ� ������µ�, ���������� Ȱ���ҋ� �ӽð�ü�� ȣ���Ҽ����ִٴ°���.
*/

#include "stdafx.h"
using namespace std;

class CSortRule {
public:
	virtual bool operator()(int _iA, int _iB) const = 0;
	//virtual bool operator()(int _iA, int _iB) const { return true; };
};

// �������� 
class CAsendingSort :public CSortRule {
public:
	virtual bool operator()(int _iA, int _iB) const {
		if (_iA > _iB) return true;
		else return false;
	}
};

class CDesendingSort :public CSortRule {
public:
	virtual bool operator()(int _iA, int _iB) const {
		if (_iA < _iB) return true;
		else return false;
	}
};

void Bubble_sort_functor(int iArray[], int iSize, const CSortRule& Functor) {	//������ ������ ��������, ���������� ���� �� ����. 
	for (int i = 0; i < iSize; i++) {
		for (int j = 0; j < iSize-1; j++) {
			if (Functor(iArray[j], iArray[j + 1])) {
				int iTemp = iArray[j];
				iArray[j] = iArray[j+1];
				iArray[j + 1] = iTemp;
			}
		}
	}
	for (int i = 0; i < iSize; i++) cout << iArray[i] << ",";
	cout << endl;
}

bool DesendingSort(int _iA, int _iB) {
	if (_iA <= _iB) return true;
	else return false;
}


void Bubble_sort_function(int iArray[], int iSize, bool(*DesendingSort)(int _iA, int _iB)) {	//������ ������ ��������, ���������� ���� �� ����. 
	for (int i = 0; i < iSize; i++) {
		for (int j = 0; j < iSize - 1; j++) {
			if (DesendingSort(iArray[j], iArray[j + 1])) {
				int iTemp = iArray[j];
				iArray[j] = iArray[j+1];
				iArray[j+1] = iTemp;
			}
		}
	}
	for (int i = 0; i < iSize; i++) cout << iArray[i] << ",";
	cout << endl;
}

int main() {
	int iArray[5] = { 1,4,3,6,7 };

	// �����ڷ� �Ϲ� �Լ� ���
	{
		Bubble_sort_function(iArray, sizeof(iArray) / sizeof(int), DesendingSort);
	}

	// �����ڷ� �Լ� ��ü ��� 
	{
		// �׳� �Լ� ��ü���
		CAsendingSort Asend;
		CDesendingSort Dsend;
		Bubble_sort_functor(iArray, sizeof(iArray) / sizeof(int), Asend);	// ������������ �ϰڴ�. 

		// �ӽ� ��ü ��� 
		Bubble_sort_functor(iArray, sizeof(iArray) / sizeof(int), CDesendingSort()); // �ٵ� �̰͵� ĳ�����ΰ�? �Ű������� �θ��� ���۷� �Ǿ��ִµ� �ڳ��ӽ� ��ü�� �Ѱ����ݾ�. 
			// �̷��� ������(�Լ� ��ü)�� �׳� �ӽ� ��ü�� �θ��⵵��. 
			// ������ �̰� �츮�� �����ڷμ��� ��ü�� ���ϴ°��� �̰� ��ä �����ؼ� �� ���ڴٴ°� �ƴϱ� �����̴�. 
	}
}
	

// ���� ���ÿ����� �Լ� ��ü�� ����� ���·� �����༭ �����Լ��� �����ߴµ� ���� �����ڷ� ���� �Լ� ��ü�� ������·� �����ϴ� ���� ���� ����. 
// �����ڷ� ���� �Լ����� ���Ǵ� �ζ��εǵ��� �����ؼ� �ӵ����� �̵��� ���ڴٴ� ���ε� �����Լ��� ������� �ζ����� �ȵǱ� �����̴�. 