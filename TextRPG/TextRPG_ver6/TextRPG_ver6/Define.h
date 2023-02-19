#pragma once
#include "Define.h"

#define MAXNAMESIZE 20


#define SAFE_DELETE(p) {if(p) delete p; p = nullptr;}
#define SAFE_ARRAY_DELETE(p) {if(p) delete[] p; p = nullptr;}



// Base structure -------------------------------

typedef struct stItemBaseINFO {	// no use
	char szName[MAXNAMESIZE];
	string strInfo;
	int iPrice;
	int iResellPrice;
}ITEMBASEINFO;

typedef struct stConsumableItemINFO {	// no use
	stItemBaseINFO stItemBaseInfo;
	int iEffect_HillHP;
}CONSUMABLEITEMINFO;

typedef struct stEquipmentItemINFO {	// no use
	stItemBaseINFO stItemBaseInfo;
	int iEffect_OffencePower;
	int iEffect_DefencePower;
}EQUIPMENTITEMINFO;

typedef struct stItemINFO {
	int iType;
	char szName[MAXNAMESIZE];
	string strInfo;
	int iPrice;
	int iResellPrice;
	int iEffect_OffencePower;
	int iEffect_DefencePower;
	int iEffect_HillHP;
	int iEffect_DamageHP;
}ITEMINFO;

// ----------------------------------------------

typedef struct stFieldCreatureINFO{
	char szName[MAXNAMESIZE];
	int iTotalHP;
	int iCurrHP;
	int iOffencePower;
}FCINFO, *PFCINFO;

typedef struct stPlayerINFO {
	char szJob[MAXNAMESIZE];
	int iLv;
}PINFO, *PPINFO;

typedef struct stMonsterINFO {
	
}MINFO, *PMINFO;

typedef struct stStoreINFO {
	int iStoreType;
	char szName[MAXNAMESIZE];
	int iItemCnt;
	vector<ITEMINFO> itemList;
}STOREINFO, * PSTOREINFO;


/*
ITEMINFO _ iType
	: 상점 정렬을 위해 숫자를 넣음. 
	- 장비상점: 1.무기 2.방패
	- 잡화상점: 1.HP포션 2.폭탄


*/