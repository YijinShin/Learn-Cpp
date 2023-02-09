#pragma once
#include "stdafx.h"	// to use string
#include <string>	// to use string


#define SAFE_DELETE(p) {if(p) delete p; p = nullptr;}
#define SAFE_ARRAY_DELETE(p) {if(p) delete[] p; p = nullptr;}

using namespace std;	// to use string

typedef struct tagPlayerInfo {
	string strName_;
	string strJob_;

	int iLv_;

	int iCurrHP_;
	int iTotalHP_;

	int iOffencePower_;
}PLAYERINFO, *PPLAYERINFO;

typedef struct tagMonsterInfo {
	int iCurrHP_;
	int iTotalHP_;

	int iOffencePower_;
}MONSTERINFO, *PMONSTERINFO;