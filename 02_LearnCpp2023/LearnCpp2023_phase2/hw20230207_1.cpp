#include "stdafx.h"
#include "hw20230207_1.h"

using namespace std;
using namespace hw20230207_1;

Report::Report() :m_iMath(0), m_iKra(0), m_iEng(0), m_fAvg(0.f), m_szName(""), m_cScore(NULL) {
	
}

void Report::InitReport(int _iKra, int _iMath, int _iEng, char _szName[]) {
	cout << "in init" << endl;
	m_iKra = _iKra;
	m_iEng = _iEng;
	m_iMath = _iMath;
	strcpy_s(m_szName, _szName);
	CalcAvg();
	CalcScore();
}

int Report::GetiMath() { return m_iMath; }
int Report::GetiKra() { return m_iKra; }
int Report::GetiEng() { return m_iEng; }
const char* Report::GetszName() { return m_szName; }
char Report::GetcScore() { return m_cScore; }

void Report::SetiMath(int _iMath) { m_iMath = _iMath; }
void Report::SetiKra(int _iKra) { m_iKra = _iKra; }
void Report::SetiEng(int _iEng) { m_iEng = _iEng; }
void Report::SetszName(char _szName[]) { strcpy_s(m_szName, _szName); }


void Report::ShowReport() {
	cout << endl;
	cout << "주소:" << &m_iMath << endl;
	cout << "이름: " << m_szName << endl;
	cout << "국어: " << m_iKra << " / 영어: " << m_iEng << " / 수학: " << m_iMath << endl;
	cout << "총점: " << m_iKra + m_iEng + m_iMath << " / 평균: " << m_fAvg << endl;
}
void Report::CalcAvg() {
	m_fAvg = (m_iMath + m_iKra + m_iEng) / 3.f;
}

void Report::CalcScore() {
	if (m_fAvg >= 90) m_cScore = 'A';
	else if (m_fAvg >= 80) m_cScore = 'B';
	else if (m_fAvg >= 70) m_cScore = 'C';
	else if (m_fAvg >= 60) m_cScore = 'D';
	else if (m_fAvg >= 50) m_cScore = 'E';
	else m_cScore = 'F';
}

void Report::CopyReport(const Report& _report) {
	this->m_iKra = _report.m_iKra;
	this->m_iEng = _report.m_iEng;
	this->m_iKra = _report.m_iKra;
	this->m_fAvg = _report.m_fAvg;
	strcpy_s(this->m_szName, _report.m_szName);
	this->m_cScore = _report.m_cScore;
}