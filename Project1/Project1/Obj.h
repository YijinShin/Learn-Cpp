#pragma once
#include "Define.h"

/* Obj클래스는 모든 오브젝트의 토대가 되는 클래스이다. 
아주 공통된 기능, 맴버를 가지고있다. */

class CObj
{
private:
	/* 어차피 추상 클래스 이기 때문에 독립적인 객체가 될 수 없음. */
	CObj();
	virtual		~CObj();
public:
	virtual	void	Initialize()	PURE;
	virtual int		Update()	PURE;
	virtual void	Render()	PURE;
	virtual void	Release()	PURE;
};

