#pragma once

template <typename T>
class CAbstractFactory {
public:
	CAbstractFactory() {}
	~CAbstractFactory() {}

	static CObj*	Create(void) {
		CObj* pObj = new T;
		pObj->Initialize();

		return pObj;
	}

	static CObj* Create(float _fX, float _fY) {
		CObj* pObj = new T;
		pObj->Initialize();
		pObj->Set_Pos(_fX, _fY);

		return pObj;
	}

	static CObj*	Create(float _fX, float _fY, DIR _Dir) {
		CObj* pObj = new T;
		pObj->Initialize();
		pObj->Set_Pos(_fX, _fY);
		pObj->Set_Dir(_Dir);

		return pObj;
	}
};