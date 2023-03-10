#pragma once
#include "Define.h"

class CObj
{
private:
	RECT m_tFence;
protected:
	CObj();
	virtual ~CObj();

	INFO m_tInfo;	// ������Ʈ�� �߽���, ���μ��α��� 
	RECT m_tRect;	// ������Ʈ�� �׸� �� ���
	float m_fSpeed;	// ������Ʈ�� �ӵ� 
	DIRECTION m_eDir;

	void Update_Rect();

public:
	virtual void Initialize() PURE;
	virtual int Update() PURE;
	virtual void Render(HDC hDC) PURE;
	virtual void Release() PURE;

	void Set_Dir(DIRECTION _eDir) { m_eDir = _eDir; }
	void Set_Fence(RECT _tFence);
	void Set_Pos(float _fX, float _fY) {
		m_tInfo.fX = _fX;
		m_tInfo.fY = _fY;
	}
};

