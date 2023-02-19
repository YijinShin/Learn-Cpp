#pragma once
class CPlayer;
class CStore;

class CMall
{
private:
	CPlayer* m_cpPlayer;
	CStore* m_cpStore;
public:
	CMall();
	~CMall();

	void Initialize(CPlayer* player);
	void Update();
	void Release();


};

