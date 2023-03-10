#pragma once
class GradeCard
{
private:
	char szName[20];
	int m_iKro;
	int m_iMath;
	int m_iEng;
	int m_iTotal;
	float m_fAvg;
	void CalcAvg();
public:
	GradeCard();
	~GradeCard();
	void Draw();
	void SetScore();
	
	const char* GetName() const;
};

