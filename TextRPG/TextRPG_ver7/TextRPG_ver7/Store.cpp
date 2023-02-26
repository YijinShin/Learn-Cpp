#include "Store.h"

#include "stdafx.h"
#include "Define.h"
#include "Player.h"
#include "ConsumableItem.h"
#include "EquipmentItem.h"

CStore::CStore() : m_cpPlayer(nullptr)
{
	memset(&m_stStoreInfo, 0, sizeof(STOREINFO));
}

CStore::~CStore()
{
	Release();
}

void CStore::Initialize(CPlayer* _cpPlayer)
{
	m_cpPlayer = _cpPlayer;

}

void CStore::Update()
{
	int iMenu(0);
	int isEnd(false);

	while (1) {
		system("cls");

		cout << "[" << m_stStoreInfo.szName << "] 어서오세요 " << m_stStoreInfo.szName << "입니다. 무엇을 하시겠습니까? (1.산다, 2.판다, 3.나가기): ";
		cin >> iMenu;

		if (iMenu == 1) BuyMenu();
		else if (iMenu == 2) SellMenu();
		else isEnd = true;

		if (isEnd) break;
		system("pause");
	}
}

void CStore::Release()
{
}


void CStore::SetType(int _iStoreType)
{
	m_stStoreInfo.iStoreType = _iStoreType;

	// item 리스트 비우기
	ClearItemList();

	// default item (for index) 
	m_vecEquipments.push_back(new CEquipmentItem);
	m_vecConsumables.push_back(new CConsumableItem);

	// 스토어 타입에 맞는 아이템 리스트 가져와서 info 세팅하기 
	if (_iStoreType == 1) {
		m_stStoreInfo.iItemCnt = 2;
		strcpy_s(m_stStoreInfo.szName, MAXNAMESIZE, "00장비상점");
		BITEMINFO itemlist[2] = { {1,1, "단단한 칼", "공격력 +5", 200, 70},
								{2,1, "단단한 방패", "방어력 +5", 150, 70} };
		m_vecEquipments.push_back(new CEquipmentItem(itemlist[0], 5, 0));
		m_vecEquipments.push_back(new CEquipmentItem(itemlist[1], 0, 5));
	}
	else if (_iStoreType == 2) {
		m_stStoreInfo.iItemCnt = 2;
		strcpy_s(m_stStoreInfo.szName, MAXNAMESIZE, "00잡화점");
		BITEMINFO itemlist[2] = { {10,2, "HP포션", "HP를 5만큼 채워준다.", 100, 70},
								{11,2, "폭탄", "몬스터에게 30의 데미지를 준다", 120, 70} };
		m_vecConsumables.push_back(new CConsumableItem(itemlist[0], 5, 0));
		m_vecConsumables.push_back(new CConsumableItem(itemlist[0], 0, 5));
	}
}

void CStore::SellMenu()
{
	int iMenu(0);
	bool isEnd(false);
	// show inventory
	m_cpPlayer->Rander();
	cout << "[" << m_stStoreInfo.szName << "] 무엇을 판매하시겠습니까? (0:돌아가기): ";
	cin >> iMenu;
	
	if (m_cpPlayer->isExist()) {
		cout << "[" << m_stStoreInfo.szName << "] 감사합니다. " << endl;
	}
	else cout << "[" << m_stStoreInfo.szName << "] 그런 물건을 가지고 있지 않습니다. " << endl;
}

void CStore::BuyMenu()
{
	int iMenu(0);
	bool isEnd(false);

	while (1) {
		system("cls");

		cout << "[" << m_stStoreInfo.szName << "] 구경해보세요! 이런것들을 팔고 있습니다. " << endl;
		ShowItemList();
		cout << "[" << m_stStoreInfo.szName << "] 무엇을 구매하시겠습니까? (0:돌아가기): ";
		cin >> iMenu;

		if (iMenu<0 || iMenu > m_stStoreInfo.iItemCnt) cout << "[" << m_stStoreInfo.szName << "] 그런 물건은 없습니다. " << endl;
		else if (iMenu == 0) isEnd = true;
		else Buy(iMenu);

		if (isEnd) break;
		system("pause");
	}
}

void CStore::ShowItemList()
{
	if (m_stStoreInfo.iStoreType == 1) {
		// m_vecConsumables
	}else if (m_stStoreInfo.iStoreType == 2) {
		// m_vecConsumables 출력하기 
	}
}

void CStore::ClearItemList()
{
	m_vecEquipments.clear();
	vector<CEquipmentItem*>().swap(m_vecEquipments);

	m_vecConsumables.clear();
	vector<CConsumableItem*>().swap(m_vecConsumables);
}


void CStore::Buy(int _iItemIndex)
{
	// check gold 
	if (m_cpPlayer->GetGold() >= m_stStoreInfo.vItemList[_iItemIndex].iPrice) {
		m_cpPlayer->PurchaseGold(m_stStoreInfo.vItemList[_iItemIndex].iPrice);
		m_cpPlayer->EarnItem(m_stStoreInfo.vItemList[_iItemIndex]);
		cout << m_stStoreInfo.vItemList[_iItemIndex].szName << "를 구매했다!" << endl;
	}
	else {
		cout << "[" << m_stStoreInfo.szName << "] 골드가 부족합니다! " << endl;
	}
}


void CStore::Sell(int _iItemIndex)
{
	// EarnGold
	m_cpPlayer->EarnGold(m_cpPlayer->GetResellPrice(_iItemIndex));
	// RemoveItem from inventory
	m_cpPlayer->(_iItemIndex);
}

