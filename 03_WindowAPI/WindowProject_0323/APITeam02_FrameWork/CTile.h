#pragma once
#include "CObj.h"

class CTile : public CObj
{
private:
	int			m_iDrawID;
	int			m_iOption;

public:
	CTile();
	virtual ~CTile();

public:
	// CObj을(를) 통해 상속됨
	virtual void Initialize() override;

	virtual int Update() override;

	virtual void Late_Update() override;

	virtual void Render(HDC hDC) override;

	virtual void Release() override;

public:
	int			Get_DrawID(void) { return m_iDrawID; }
	int			Get_Option(void) { return m_iOption; }

	void		Set_DrawID(int _iDrawID) { m_iDrawID = _iDrawID; }
	void		Set_Option(int _iOption) { m_iOption = _iOption; }
};

