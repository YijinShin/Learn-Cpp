#include "stdafx.h"
#include "Define.h"
#include "Store.h"

CStore::CStore()
{
	memset(&m_stStoreInfo, 0, sizeof(STOREINFO));
}

CStore::~CStore()
{
}

void CStore::SetType(int _iStoreType)
{
	m_stStoreInfo.iStoreType = _iStoreType;

	// item 리스트 비우기
	ClearItemList();

	// 스토어 타입에 맞는 아이템 리스트 가져와서 info 세팅하기 
	if (_iStoreType == 1) {
		m_stStoreInfo.iItemCnt = 2;
		strcpy_s(m_stStoreInfo.szName, MAXNAMESIZE, "00장비상점");
		ITEMINFO itemlist[2] = { {1, "단단한 칼", "공격력 +5", 200, 70, 5,0,0,0},
								{ 2, "단단한 방패", "방어력 +5", 150, 70, 0,5,0,0 } };
		for(int i=0;i< m_stStoreInfo.iItemCnt;i++) m_stStoreInfo.itemList.push_back(itemlist[i]);
	}
	else if (_iStoreType == 2) {
		m_stStoreInfo.iItemCnt = 2;
		strcpy_s(m_stStoreInfo.szName, MAXNAMESIZE, "00잡화점");
		ITEMINFO itemlist[2] = { {1, "HP포션", "HP를 5만큼 채워준다.", 100, 70, 0,0,5,0},
								{ 2, "폭탄", "몬스터에게 30의 데미지를 준다", 120, 70, 0,0,0,30 } };
		for (int i = 0; i < m_stStoreInfo.iItemCnt; i++) m_stStoreInfo.itemList.push_back(itemlist[i]);
	}	
}

void CStore::SellMenu()
{
	// 준비중
	cout << "[시스템] 서비스 준비중입니다." << endl;
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
	for (int i = 0; i < m_stStoreInfo.iItemCnt; i++) {
		cout << "*******************************" << endl;
		cout << "이름: " << m_stStoreInfo.itemList[i].szName << endl;
		cout << "설명: " << m_stStoreInfo.itemList[i].strInfo << endl;
	}
	cout << "*******************************" << endl;
}

void CStore::Sell()
{
	// 준비중
}

void CStore::Buy(int _iItem)
{
	// 준비중
	cout << m_stStoreInfo.itemList[_iItem].szName << "를 구매했다!" << endl;
}

void CStore::ClearItemList()
{
	m_stStoreInfo.itemList.clear();
	vector<ITEMINFO>().swap(m_stStoreInfo.itemList);
}

void CStore::Initialize()
{
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
