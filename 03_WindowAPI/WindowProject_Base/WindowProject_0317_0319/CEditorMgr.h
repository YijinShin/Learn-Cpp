#pragma once
class CEditorMgr
{

public:
	CEditorMgr() {}
	~CEditorMgr() {}

public:
	static void			Initialize();
	static void			Update();
	static void			Render(HDC hDC);
	static void			Release();
	

	static void			Key_Input();
};

