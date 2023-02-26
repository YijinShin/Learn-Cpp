#pragma once
#include <string>
#include <vector>
using namespace std;

#define MAXNAMESIZE 20


template <typename T>
void Safe_Delete(T& temp) {
	delete temp;
	temp = nullptr;
}

#pragma region  Item
	// CItemBase --------------------------------
	typedef struct stBaseItem_INFO {
		int iId;
		int iType;	// 1. 장비, 2. 소비
		char szName[MAXNAMESIZE];
		string strInfo;
		int iPrice;
		int iResellPrice;
	}BITEMINFO;

	// CEquipmentItem, CConsumableItem --------------------------------
	typedef struct stEquipmentItem_INFO {
		int iEffect_OffencePower;
		int iEffect_DefencePower;
	}EITEMINFO;

	typedef struct stConsumableItem_INFO {
		int iEffect_HillHP;
		int iEffect_DamageHP;
	}CITEMINFO;
#pragma endregion


#pragma region Inventory
	template <typename T>
	struct stInvenItem_INFO {
		T stItemInfo;
		int iCnt;

		stInvenItem_INFO(T _stITemInfo) :iCnt(0) {stItemInfo = _stItemInfo};
	};
#pragma endregion



#pragma region Creature
	// CBaseCreature --------------------------------
	typedef struct stBase_INFO {
		char szName[MAXNAMESIZE];
		int iTotalHP;
		int iCurrHP;
		int iOffencePower;
		int iGold;
	}BCINFO;

	// CPlayer, CMonster --------------------------------

	typedef struct stPlayer_INFO {
		char szJob[MAXNAMESIZE];
		int iLv;
		int iDefencePower;
	}PINFO, * PPINFO;

#pragma endregion



typedef struct stStoreINFO {
	int iStoreType;
	char szName[MAXNAMESIZE];
	int iItemCnt;
}STOREINFO, * PSTOREINFO;