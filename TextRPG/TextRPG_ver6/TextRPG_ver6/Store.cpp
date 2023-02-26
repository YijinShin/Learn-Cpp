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

		cout << "[" << m_stStoreInfo.szName << "] ������� " << m_stStoreInfo.szName << "�Դϴ�. ������ �Ͻðڽ��ϱ�? (1.���, 2.�Ǵ�, 3.������): " ;
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

	// item ����Ʈ ����
	ClearItemList();

	// default item (for index) 
	ITEMINFO defaultItem;
	memset(&defaultItem, 0, sizeof(ITEMINFO));
	m_stStoreInfo.vItemList.push_back(defaultItem);

	// ����� Ÿ�Կ� �´� ������ ����Ʈ �����ͼ� info �����ϱ� 
	if (_iStoreType == 1) {
		m_stStoreInfo.iItemCnt = 2;
		strcpy_s(m_stStoreInfo.szName, MAXNAMESIZE, "00������");
		ITEMINFO itemlist[2] = {{1,1, "�ܴ��� Į", "���ݷ� +5", 200, 70, 5,0,0,0},
								{2,2, "�ܴ��� ����", "���� +5", 150, 70, 0,5,0,0 }};
		for (int i = 0; i < m_stStoreInfo.iItemCnt; i++) m_stStoreInfo.vItemList.push_back(itemlist[i]);
	}
	else if (_iStoreType == 2) {
		m_stStoreInfo.iItemCnt = 2;
		strcpy_s(m_stStoreInfo.szName, MAXNAMESIZE, "00��ȭ��");
		ITEMINFO itemlist[2] = {{10,3, "HP����", "HP�� 5��ŭ ä���ش�.", 100, 70, 0,0,5,0},
								{11,4, "��ź", "���Ϳ��� 30�� �������� �ش�", 120, 70, 0,0,0,30 }};
		for (int i = 0; i < m_stStoreInfo.iItemCnt; i++) m_stStoreInfo.vItemList.push_back(itemlist[i]);
	}
}

void CStore::SellMenu()
{
	int iMenu(0);
	bool isEnd(false);
	// show inventory
	m_cpPlayer->ShowInventory();
	cout << "[" << m_stStoreInfo.szName << "] ������ �Ǹ��Ͻðڽ��ϱ�? (0:���ư���): ";
	cin >> iMenu;

	if (iMenu<0 || iMenu > m_cpPlayer->GetInventoryCnt()) cout << "[" << m_stStoreInfo.szName << "] �׷� ������ �����ϴ�. " << endl;
	else if (iMenu == 0) isEnd = true;
	else Sell(iMenu);
}

void CStore::BuyMenu()
{
	int iMenu(0);
	bool isEnd(false);

	while (1) {
		system("cls");

		cout << "[" << m_stStoreInfo.szName << "] �����غ�����! �̷��͵��� �Ȱ� �ֽ��ϴ�. " << endl;
		ShowItemList();
		cout << "[" << m_stStoreInfo.szName << "] ������ �����Ͻðڽ��ϱ�? (0:���ư���): ";
		cin >> iMenu;

		if (iMenu<0 || iMenu > m_stStoreInfo.iItemCnt) cout << "[" << m_stStoreInfo.szName << "] �׷� ������ �����ϴ�. " << endl;
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
		cout << "No. " << i << "\t�̸�: " << m_stStoreInfo.vItemList[i].szName << endl;
		cout << "����: " << m_stStoreInfo.vItemList[i].iPrice << " Gold" << endl;
		cout << "����: " << m_stStoreInfo.vItemList[i].strInfo << endl;
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
		cout << m_stStoreInfo.vItemList[_iItemIndex].szName << "�� �����ߴ�!" << endl;
	}
	else {
		cout << "[" << m_stStoreInfo.szName << "] ��尡 �����մϴ�! " << endl;
	}
}


void CStore::Sell(int _iItemIndex)
{
	// EarnGold
	m_cpPlayer->EarnGold(m_cpPlayer->GetResellPrice(_iItemIndex));
	// RemoveItem from inventory
	m_cpPlayer->RemoveItem(_iItemIndex);
}
