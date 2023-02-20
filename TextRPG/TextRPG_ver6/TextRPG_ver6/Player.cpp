#include "stdafx.h"
#include "FieldCreature.h"
#include "Player.h"


CPlayer::CPlayer()
{
    memset(&m_stPINFO, 0, sizeof(PINFO));
    m_stPINFO.iLv = 1;
}

CPlayer::~CPlayer()
{
}

void CPlayer::Initialize()
{
    SetName();
    SetJob();

    // default item (for index) 
    INVENITEMINFO defaultItem;
    memset(&defaultItem, 0, sizeof(INVENITEMINFO));
    m_stPINFO.vInventory.push_back(defaultItem);

    // gold test �� ���� �ڵ� 
    m_stFcINFO.iGold = 300;
}

void CPlayer::DisplayINFO() const
{
    cout << "_____________________________________________________________" << endl;
    cout << "| Name: " << m_stFcINFO.szName << " (" << m_stPINFO.szJob << ")\tLv: " << m_stPINFO.iLv << endl;
    cout << "| HP: " << m_stFcINFO.iCurrHP << "/" << m_stFcINFO.iTotalHP << "\t Offence Power: " << m_stFcINFO.iOffencePower << "\t Gold: "<<m_stFcINFO.iGold<<endl;
    cout << "_____________________________________________________________" << endl;
}

void CPlayer::LevelUp()
{
    m_stPINFO.iLv++;
    m_stFcINFO.iTotalHP = m_stFcINFO.iTotalHP + 20;
    m_stFcINFO.iCurrHP = m_stFcINFO.iTotalHP;
    m_stFcINFO.iOffencePower = m_stFcINFO.iOffencePower + 2;
}

void CPlayer::ShowInventory() const
{
    for (int i = 1; i < m_stPINFO.vInventory.size(); i++) {
        cout << "*******************************" << endl;
        cout << "No. " << i << "\t�̸�: " << m_stPINFO.vInventory[i].stItemInfo.szName << endl;
        cout << "����: " << m_stPINFO.vInventory[i].stItemInfo.iResellPrice << " Gold\t����: "<< m_stPINFO.vInventory[i].iCnt<<"��" << endl;
        cout << "����: " << m_stPINFO.vInventory[i].stItemInfo.strInfo << endl;
    }
    cout << "*******************************" << endl;
}

int CPlayer::FindItemIndex(int _iItemId) const
{
    int iReturn(0);
    bool isFound(false);
    for (int i = 0; i < m_stPINFO.vInventory.size(); i++) {
        if (m_stPINFO.vInventory[i].stItemInfo.iId == _iItemId) {
            iReturn = i;
            isFound = true;
            break;
        }
    }
    if (!isFound) iReturn = -1;
    return iReturn;
}

void CPlayer::RemoveItem(int _iItemIndex)
{
    if (m_stPINFO.vInventory[_iItemIndex].iCnt == 1) {
        if (m_stPINFO.vInventory.size()-1 == _iItemIndex) {
            cout << "case1" << endl; m_stPINFO.vInventory.pop_back();
        }
        else { cout << "case2" << endl; m_stPINFO.vInventory.erase(m_stPINFO.vInventory.begin() + _iItemIndex); }
    } 
    else {
        m_stPINFO.vInventory[_iItemIndex].iCnt--;
    }
}

void CPlayer::EarnItem(ITEMINFO _item)
{
    int iIndex = FindItemIndex(_item.iId);
    bool isExist(false);
    // �̹� ������ �ִ� �������� ��� 
    if (iIndex >= 0) {
        m_stPINFO.vInventory[iIndex].iCnt++;
    }
    else if (!isExist) {
        // ó�� ȹ���ϴ� ���, 
        INVENITEMINFO newItem = { _item, 1 };
        m_stPINFO.vInventory.push_back(newItem);
    }
    
}

int CPlayer::GetResellPrice(int _iItemIndex) const
{
    return m_stPINFO.vInventory[_iItemIndex].stItemInfo.iResellPrice;
}

int CPlayer::GetInventoryCnt() const
{
    return m_stPINFO.vInventory.size();
}

void CPlayer::SetJob()
{   
    // setting job , hp, offencepower
    int _iJob(0);

    cout << "[�����̼�] ������ �����ϼ��� (1.����, 2.����, 3.�ü�): ";
    while(1){
        cin >> _iJob;

        if (_iJob == 1) {
            m_stFcINFO.iTotalHP = 100;
            m_stFcINFO.iOffencePower = 10;
            strcpy_s(m_stPINFO.szJob, MAXNAMESIZE, "����");
            break;
        }
        else if (_iJob == 2) {
            m_stFcINFO.iTotalHP = 80;
            m_stFcINFO.iOffencePower = 25;
            strcpy_s(m_stPINFO.szJob, MAXNAMESIZE, "����");
            break;
        }
        else if (_iJob == 3) {
            m_stFcINFO.iTotalHP = 90;
            m_stFcINFO.iOffencePower = 15;
            strcpy_s(m_stPINFO.szJob, MAXNAMESIZE, "����");
            break;
        }
        else {
            cout << "[�����̼�] �ٽ� �����ϼ��� (1.����, 2.����, 3.�ü�): ";
        }
    }
    m_stFcINFO.iCurrHP = m_stFcINFO.iTotalHP;
}

void CPlayer::SetName()
{
    char _szName[MAXNAMESIZE];
    
    cout << "[�����̼�]  ĳ���� �̸��� �Է����ּ��� (1~10��): ";
    while (1) {
        cin >> _szName;
        if (strlen(_szName) <= 0 || strlen(_szName) >= 10) {
            cout << "[�����̼�] �ٽ� �Է����ּ��� (1~10��): ";
        }
        else {
            strcpy_s(m_stFcINFO.szName, MAXNAMESIZE, _szName);
            break;
        }
    }
    
    cin.ignore();
}

void CPlayer::EarnGold(int _iGold)
{
    m_stFcINFO.iGold = m_stFcINFO.iGold + _iGold;
}

void CPlayer::PurchaseGold(int _iGold) {
    m_stFcINFO.iGold = m_stFcINFO.iGold - _iGold;
}