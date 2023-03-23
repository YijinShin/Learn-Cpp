#pragma once
#include "Include.h"

class CScene
{
protected:
	int				m_eStageID;	
public:
	CScene();
	virtual ~CScene();
public:
	virtual void	Initialize()	PURE;
	virtual void	Update()		PURE;
	virtual void	Late_Update()	PURE;
	virtual void	Render(HDC hDC)	PURE;
	virtual void	Release()		PURE;

	virtual int		Get_StageID() { return m_eStageID; }
};
