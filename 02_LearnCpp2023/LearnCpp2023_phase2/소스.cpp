#include "stdafx.h"
using namespace std;

class CSortRule
{
public:
	virtual bool operator()(int _iA, int _iB) const = 0;
};

// ��������
class CAsendingSort : public CSortRule
{
public:
	virtual bool operator()(int _iA, int _iB) const
	{
		if (_iA > _iB)
			return true;
		else
			return false;
	}
};

// ��������
class CDesendingSort : public CSortRule
{
public:
	virtual bool operator()(int _iA, int _iB) const
	{
		if (_iA < _iB)
			return true;
		else
			return false;
	}
};


void	Bubble_Sort(int iArray[], int iSize, CSortRule& Functor);

void main(void)
{


	int		iArray[5] = { 5, 1, 2 ,4 ,3 };
	Bubble_Sort(iArray, sizeof(iArray) / sizeof(int), CDesendingSort());

	for (int i = 0; i < 5; ++i)
	{
		cout << iArray[i] << "\t";
	}
	cout << endl;


}
void	Bubble_Sort(int iArray[], int iSize, const CSortRule& Functor)
{
	for (int i = 0; i < iSize; ++i)
	{
		for (int j = 0; j < iSize - 1; ++j)
		{
			if (Functor(iArray[j], iArray[j + 1]))
			{
				int iTemp = iArray[j];
				iArray[j] = iArray[j + 1];
				iArray[j + 1] = iTemp;
			}
		}
	}
}