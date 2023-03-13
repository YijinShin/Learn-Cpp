#pragma once
#include "CObj.h"


template <typename T>
class CAbstractFactory {
public:
	CAbstractFactory(){}
	~CAbstractFactory(){}

	static CObj*	Create() {
		CObj* newObj = new T;
		newObj->Initialize();
		return newObj;
	}

	static CObj*	Create(float _fX, float _fY) {
		CObj* newObj = new T;
		newObj->Initialize();
		newObj->Set_Pos(_fX, _fY);
		return newObj;
	}
};
