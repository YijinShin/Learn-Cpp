#pragma once
#include "CObj.h"

class CFlag: public CObj
{
private:
	bool			m_bIsStageEnd;

public:
	CFlag();
	virtual ~CFlag();

	virtual void	Initialize()	override;
	virtual int		Update()		override;
	virtual void	Late_Update()	override;
	virtual void	Render(HDC hDC)	override;
	virtual void	Release()		override;

	void			Set_IsStageEnd(bool _bIsStageEnd) { m_bIsStageEnd = _bIsStageEnd; }
};

