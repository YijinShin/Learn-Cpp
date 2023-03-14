#pragma once

template <typename T>
class CAbstractFactory {
public:
	CAbstractFactory() {}
	~CAbstractFactory() {}

	static CObj* Create(void) {
		CObj* pObj = new T;
		pObj->Initialize();

		return pObj;
	}

	// 시작 위치 
	static CObj* Create(float _fX, float _fY) {
		CObj* pObj = new T;
		pObj->Initialize();
		pObj->Set_Pos(_fX, _fY);

		return pObj;
	}

	// 시작 크기 
	static CObj* Create(float _fCX, float _fCY) {
		CObj* pObj = new T;
		pObj->Initialize();
		pObj->Set_SIze(_fCX, _fCY);

		return pObj;
	}

	// 시작 위치, 크기 
	static CObj* Create(INFO _tInfo) {
		CObj* pObj = new T;
		pObj->Initialize();
		pObj->Set_Pos(_tInfo.fX, _tInfo.fY);
		pObj->Set_Pos(_tInfo.fCX, _tInfo.fCY);

		return pObj;
	}

	// 시작 위치, 크기, 각도 
	static CObj* Create(INFO _tInfo, float _fDegree) {
		CObj* pObj = new T;
		pObj->Initialize();
		pObj->Set_Pos(_tInfo.fX, _tInfo.fY);
		pObj->Set_Size(_tInfo.fX, _tInfo.fY);
		pObj->Set_Degree(_fDegree);
		return pObj;
	}


	// 안진서 ====================================================

	// 신의진 ====================================================

	// 안요한 ====================================================

	// 설호현 ====================================================
};