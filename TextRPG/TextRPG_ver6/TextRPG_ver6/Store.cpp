#include "stdafx.h"
#include "Define.h"
#include "Player.h"
#include "Store.h"

CStore::CStore()
{
	memset(&m_stStoreInfo, 0, sizeof(STOREINFO));
}

CStore::~CStore()
{
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

		cout << "[" << m_stStoreInfo.szName << "] 어서오세요 " << m_stStoreInfo.szName << "입니다. 무엇을 하시겠습니까? (1.산다, 2.판다, 3.나가기): " ;
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
	ITEMINFO defaultItem;
	memset(&defaultItem, 0, sizeof(ITEMINFO));
	m_stStoreInfo.vItemList.push_back(defaultItem);

	// 스토어 타입에 맞는 아이템 리스트 가져와서 info 세팅하기 
	if (_iStoreType == 1) {
		m_stStoreInfo.iItemCnt = 2;
		strcpy_s(m_stStoreInfo.szName, MAXNAMESIZE, "00장비상점");
		ITEMINFO itemlist[2] = {{1,1, "단단한 칼", "공격력 +5", 200, 70, 5,0,0,0},
								{2,2, "단단한 방패", "방어력 +5", 150, 70, 0,5,0,0 }};
		for (int i = 0; i < m_stStoreInfo.iItemCnt; i++) m_stStoreInfo.vItemList.push_back(itemlist[i]);
	}
	else if (_iStoreType == 2) {
		m_stStoreInfo.iItemCnt = 2;
		strcpy_s(m_stStoreInfo.szName, MAXNAMESIZE, "00잡화점");
		ITEMINFO itemlist[2] = {{10,3, "HP포션", "HP를 5만큼 채워준다.", 100, 70, 0,0,5,0},
								{11,4, "폭탄", "몬스터에게 30의 데미지를 준다", 120, 70, 0,0,0,30 }};
		for (int i = 0; i < m_stStoreInfo.iItemCnt; i++) m_stStoreInfo.vItemList.push_back(itemlist[i]);
	}
}

void CStore::SellMenu()
{
	int iMenu(0);
	bool isEnd(false);
	// show inventory
	m_cpPlayer->ShowInventory();
	cout << "[" << m_stStoreInfo.szName << "] 무엇을 판매하시겠습니까? (0:돌아가기): ";
	cin >> iMenu;

	if (iMenu<0 || iMenu > m_cpPlayer->GetInventoryCnt()) cout << "[" << m_stStoreInfo.szName << "] 그런 물건은 없습니다. " << endl;
	else if (iMenu == 0) isEnd = true;
	else Sell(iMenu);
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
	for (int i = 1; i <= m_stStoreInfo.iItemCnt; i++) {
		cout << "*******************************" << endl;
		cout << "No. " << i << "\t이름: " << m_stStoreInfo.vItemList[i].szName << endl;
		cout << "가격: " << m_stStoreInfo.vItemList[i].iPrice << " Gold" << endl;
		cout << "설명: " << m_stStoreInfo.vItemList[i].strInfo << endl;
	}
	cout << "*******************************" << endl;
}

void CStore::ClearItemList()
{
	m_stStoreInfo.vItemList.clear();
	vector<ITEMINFO>().swap(m_stStoreInfo.vItemList);
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
	m_cpPlayer->RemoveItem(_iItemIndex);
}
