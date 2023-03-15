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

	// ���� ��ġ 
	static CObj* Create(float _fX, float _fY) {
		CObj* pObj = new T;
		pObj->Initialize();
		pObj->Set_Pos(_fX, _fY);

		return pObj;
	}

	// ���� ��ġ, ũ��, ���� 
	static CObj* Create(INFO _tInfo, float _fDegree) {
		CObj* pObj = new T;
		pObj->Initialize();
		pObj->Set_Pos(_tInfo.fX, _tInfo.fY);
		pObj->Set_Size(_tInfo.fX, _tInfo.fY);
		pObj->Set_Degree(_fDegree);
		return pObj;
	}

	// ���� ��ġ, ũ��, ���� 
	static CObj* Create(INFO _tInfo) {
		CObj* pObj = new T;
		pObj->Initialize();
		pObj->Set_Pos(_tInfo.fX, _tInfo.fY);
		pObj->Set_Vector2(_tInfo.Dir);
		return pObj;
	}

	// ������ ====================================================

	// ������ ====================================================

	// �ȿ��� ====================================================

	// ��ȣ�� ====================================================
};