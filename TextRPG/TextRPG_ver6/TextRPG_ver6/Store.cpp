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

	// item ����Ʈ ����
	ClearItemList();

	// ����� Ÿ�Կ� �´� ������ ����Ʈ �����ͼ� info �����ϱ� 
	if (_iStoreType == 1) {
		m_stStoreInfo.iItemCnt = 2;
		strcpy_s(m_stStoreInfo.szName, MAXNAMESIZE, "00������");
		ITEMINFO itemlist[2] = { {1, "�ܴ��� Į", "���ݷ� +5", 200, 70, 5,0,0,0},
								{ 2, "�ܴ��� ����", "���� +5", 150, 70, 0,5,0,0 } };
		for(int i=0;i< m_stStoreInfo.iItemCnt;i++) m_stStoreInfo.itemList.push_back(itemlist[i]);
	}
	else if (_iStoreType == 2) {
		m_stStoreInfo.iItemCnt = 2;
		strcpy_s(m_stStoreInfo.szName, MAXNAMESIZE, "00��ȭ��");
		ITEMINFO itemlist[2] = { {1, "HP����", "HP�� 5��ŭ ä���ش�.", 100, 70, 0,0,5,0},
								{ 2, "��ź", "���Ϳ��� 30�� �������� �ش�", 120, 70, 0,0,0,30 } };
		for (int i = 0; i < m_stStoreInfo.iItemCnt; i++) m_stStoreInfo.itemList.push_back(itemlist[i]);
	}	
}

void CStore::SellMenu()
{
	// �غ���
	cout << "[�ý���] ���� �غ����Դϴ�." << endl;
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
	for (int i = 0; i < m_stStoreInfo.iItemCnt; i++) {
		cout << "*******************************" << endl;
		cout << "�̸�: " << m_stStoreInfo.itemList[i].szName << endl;
		cout << "����: " << m_stStoreInfo.itemList[i].strInfo << endl;
	}
	cout << "*******************************" << endl;
}

void CStore::Sell()
{
	// �غ���
}

void CStore::Buy(int _iItem)
{
	// �غ���
	cout << m_stStoreInfo.itemList[_iItem].szName << "�� �����ߴ�!" << endl;
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
