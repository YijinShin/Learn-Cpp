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
	void		Initialize();	// 데이터를 초기화하는 함수
	void		Update();		// 매 프레임마다 갱신하는 함수
	void		LateUpdate();	// 업데이트 이후 갱신하는 함수
	void		Render();		// 매 프레임마다 출력하는 함수
	void		Release();		// 객체 파괴 시 메모리 해제 함수

private:
	list<CObj*> m_objList[OBJ_END];

	HDC			m_DC;

	int			m_iStage;

private:
	void Set_ObjList();		// setting m_ObjList


};

