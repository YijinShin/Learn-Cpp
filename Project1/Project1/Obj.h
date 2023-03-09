#pragma once
#include "Define.h"

/* ObjŬ������ ��� ������Ʈ�� ��밡 �Ǵ� Ŭ�����̴�. 
���� ����� ���, �ɹ��� �������ִ�. */

class CObj
{
private:
	/* ������ �߻� Ŭ���� �̱� ������ �������� ��ü�� �� �� ����. */
	CObj();
	virtual		~CObj();
public:
	virtual	void	Initialize()	PURE;
	virtual int		Update()	PURE;
	virtual void	Render()	PURE;
	virtual void	Release()	PURE;
};

