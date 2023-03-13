#pragma once
#include "Include.h"
#include "CObj.h"

class CMonster: public CObj
{
protected:
	MONSTERTYPE	m_eType;
public:
	CMonster();
	virtual ~CMonster();

	virtual void		Initialize()	override;
	virtual int			Update()		override;
	virtual void		Late_Update()	override;
	virtual void		Render(HDC hDC)	override;
	virtual void		Release()		override;

	virtual void		CollisionCheck(CObj* targetObj) {}
	virtual void		Set_Type(MONSTERTYPE _type) { m_eType = _type; }

	MONSTERTYPE Get_type() { return m_eType; }
};

