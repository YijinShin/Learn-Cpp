#pragma once
#include "Define.h"

class Item
{
private:
	ITEMINFO* stInfo;
public:
	Item();
	~Item();

	void Initialize();
	void Release();

	virtual void Render();
};

