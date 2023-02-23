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
	cout << "이름: " << szName<< "\t평균: "<< m_fAvg << endl;
	cout << "국어: " << m_iKro << "\t영어: " << m_iEng << "\t수학: " << m_iMath << endl;
	cout << endl;
}

void GradeCard::SetScore()
{
	cout << "이름: ";
	cin >> szName;
	cout << "국어, 영어, 수학 점수를 입력하세요: ";
	cin >> m_iKro;
	cin >> m_iEng;
	cin >> m_iMath;

	CalcAvg();
}

const char* GradeCard::GetName() const
{
	return szName;
}

