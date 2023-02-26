#pragma once
#include "stdafx.h"

#define MAXNAMESIZE 20


#define SAFE_DELETE(p) {if(p) delete p; p = nullptr;}
#define SAFE_ARRAY_DELETE(p) {if(p) delete[] p; p = nullptr;}



// Base structure -------------------------------

typedef struct stItemINFO {
	int iId;
	int iType;	// 1. 무기, 2. 방어구, 3. 힐 소비템, 4.공격 소비템
	char szName[MAXNAMESIZE];
	string strInfo;
	int iPrice;
	int iResellPrice;
	int iEffect_OffencePower;
	int iEffect_DefencePower;
	int iEffect_HillHP;
	int iEffect_DamageHP;
}ITEMINFO;

typedef struct stEquipmentItemINFO {	// no use
	int iEffect_OffencePower;
	int iEffect_DefencePower;
}EQUIITEMINFO;

typedef struct stConsumableItemINFO {	// no use
	int iEffect_HillHP;
	int iEffect_DamageHP;
}CONITEMINFO;

typedef struct stInventoryItemINFO {
	ITEMINFO stItemInfo;
	int iCnt;
}INVENITEMINFO;

// ----------------------------------------------

typedef struct stFieldCreatureINFO{
	char szName[MAXNAMESIZE];
	int iTotalHP;
	int iCurrHP;
	int iOffencePower;
	int iGold;
}FCINFO, *PFCINFO;

typedef struct stPlayerINFO {
	char szJob[MAXNAMESIZE];
	int iLv;
	int iDefencePower;
	ITEMINFO stCurrWeapon;
	ITEMINFO stCurrShield;
	vector<INVENITEMINFO> vInventory;
}PINFO, *PPINFO;

typedef struct stMonsterINFO {
	
}MINFO, *PMINFO;

typedef struct stStoreINFO {
	int iStoreType;
	char szName[MAXNAMESIZE];
	int iItemCnt;
	vector<ITEMINFO> vItemList;
}STOREINFO, * PSTOREINFO;
