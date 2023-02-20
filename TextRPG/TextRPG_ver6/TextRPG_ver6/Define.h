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
	int iId;
	char szName[MAXNAMESIZE];
	string strInfo;
	int iPrice;
	int iResellPrice;
	int iEffect_OffencePower;
	int iEffect_DefencePower;
	int iEffect_HillHP;
	int iEffect_DamageHP;
}ITEMINFO;

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
