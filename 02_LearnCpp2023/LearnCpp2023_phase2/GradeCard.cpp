#include "stdafx.h"
#include "GradeCard.h"

using namespace std;

void GradeCard::CalcAvg()
{
	m_fAvg = (m_iKro + m_iMath + m_iEng) / 3.0f;
}

GradeCard::GradeCard(): m_iKro(0), m_iMath(0), m_iEng(0), m_iTotal(0), m_fAvg(0)
{
}

GradeCard::~GradeCard()
{
}

void GradeCard::Draw()
{
	cout << "�̸�: " << szName<< "\t���: "<< m_fAvg << endl;
	cout << "����: " << m_iKro << "\t����: " << m_iEng << "\t����: " << m_iMath << endl;
	cout << endl;
}

void GradeCard::SetScore()
{
	cout << "�̸�: ";
	cin >> szName;
	cout << "����, ����, ���� ������ �Է��ϼ���: ";
	cin >> m_iKro;
	cin >> m_iEng;
	cin >> m_iMath;

	CalcAvg();
}

const char* GradeCard::GetName() const
{
	return szName;
}

