#pragma once
class CMonster: public CFieldCreature
{
private:
	MINFO m_stMINFO;
public:
	CMonster();
	~CMonster();

	void DisplayINFO() const;
};

