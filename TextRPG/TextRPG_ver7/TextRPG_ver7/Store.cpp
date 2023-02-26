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

		cout << "[" << m_stStoreInfo.szName << "] ������� " << m_stStoreInfo.szName << "�Դϴ�. ������ �Ͻðڽ��ϱ�? (1.���, 2.�Ǵ�, 3.������): ";
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
	m_vecEquipments.push_back(new CEquipmentItem);
	m_vecConsumables.push_back(new CConsumableItem);

	// ����� Ÿ�Կ� �´� ������ ����Ʈ �����ͼ� info �����ϱ� 
	if (_iStoreType == 1) {
		m_stStoreInfo.iItemCnt = 2;
		strcpy_s(m_stStoreInfo.szName, MAXNAMESIZE, "00������");
		BITEMINFO itemlist[2] = { {1,1, "�ܴ��� Į", "���ݷ� +5", 200, 70},
								{2,1, "�ܴ��� ����", "���� +5", 150, 70} };
		m_vecEquipments.push_back(new CEquipmentItem(itemlist[0], 5, 0));
		m_vecEquipments.push_back(new CEquipmentItem(itemlist[1], 0, 5));
	}
	else if (_iStoreType == 2) {
		m_stStoreInfo.iItemCnt = 2;
		strcpy_s(m_stStoreInfo.szName, MAXNAMESIZE, "00��ȭ��");
		BITEMINFO itemlist[2] = { {10,2, "HP����", "HP�� 5��ŭ ä���ش�.", 100, 70},
								{11,2, "��ź", "���Ϳ��� 30�� �������� �ش�", 120, 70} };
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
	cout << "[" << m_stStoreInfo.szName << "] ������ �Ǹ��Ͻðڽ��ϱ�? (0:���ư���): ";
	cin >> iMenu;
	
	if (m_cpPlayer->isExist()) {
		cout << "[" << m_stStoreInfo.szName << "] �����մϴ�. " << endl;
	}
	else cout << "[" << m_stStoreInfo.szName << "] �׷� ������ ������ ���� �ʽ��ϴ�. " << endl;
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
	if (m_stStoreInfo.iStoreType == 1) {
		// m_vecConsumables
	}else if (m_stStoreInfo.iStoreType == 2) {
		// m_vecConsumables ����ϱ� 
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
	m_cpPlayer->(_iItemIndex);
}

