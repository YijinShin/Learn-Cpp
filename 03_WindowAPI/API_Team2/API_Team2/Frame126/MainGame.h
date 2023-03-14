#pragma once

#include "Include.h"

enum ObjType
{
	OBJ_PLAYER,
	OBJ_MONSTER,
	OBJ_BULLET,
	OBJ_END
};

class CObj;
class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void		Initialize();	// �����͸� �ʱ�ȭ�ϴ� �Լ�
	void		Update();		// �� �����Ӹ��� �����ϴ� �Լ�
	void		LateUpdate();	// ������Ʈ ���� �����ϴ� �Լ�
	void		Render();		// �� �����Ӹ��� ����ϴ� �Լ�
	void		Release();		// ��ü �ı� �� �޸� ���� �Լ�

private:
	list<CObj*> m_objList[OBJ_END];

	HDC			m_DC;

	int			m_iStage;

private:
	void Set_ObjList();		// setting m_ObjList


};

