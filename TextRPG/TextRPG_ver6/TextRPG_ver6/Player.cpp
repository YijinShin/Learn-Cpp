#include "stdafx.h"
#include "Define.h"
#include "FieldCreature.h"
#include "Player.h"


CPlayer::CPlayer()
{
    memset(&m_stPINFO, 0, sizeof(PINFO));
    m_stPINFO.iLv = 1;

    ITEMINFO basicShield = { 0,2, "�׳� ����", "���� +0", 100, 50, 0,0,0,0 };
    ITEMINFO basicWeapon = { 0,1, "�׳� Į", "���ݷ� +0", 100, 50, 0,0,0,0 };
    m_stPINFO.stCurrShield = basicShield;
    m_stPINFO.stCurrWeapon = basicWeapon;

    m_stFcINFO.iGold = 1000;
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
    cout << "| HP: " << m_stFcINFO.iCurrHP << "/" << m_stFcINFO.iTotalHP << "\t Offence Power: " << m_stFcINFO.iOffencePower << "\t Defence Power: " << m_stPINFO.iDefencePower << "\t Gold: "<<m_stFcINFO.iGold<<endl;
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
            m_stPINFO.vInventory.pop_back();
        }
        else { m_stPINFO.vInventory.erase(m_stPINFO.vInventory.begin() + _iItemIndex); }
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
    else {
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

void CPlayer::WorkInventory(bool isField)
{
    int iMenu(0);
    bool isEnd(false);

    while (1) {
        system("cls");
        DisplayINFO();
        ShowInventory();
        // select menu
        cout << "[�κ��丮] ������ ����ұ� (iIndex�Է�.���, 0. ���ư���): ";
        cin >> iMenu;
       
        if (iMenu == 0) isEnd = true;
        else {
            if (m_stPINFO.vInventory[iMenu].stItemInfo.iType == 1) {
                cout << "����1" << endl;
                cout << "[�κ��丮] " << m_stPINFO.vInventory[iMenu].stItemInfo.szName << "�� �����߽��ϴ�." << endl;

                // effect
                m_stFcINFO.iOffencePower -= m_stPINFO.stCurrWeapon.iEffect_OffencePower;
                m_stFcINFO.iOffencePower += m_stPINFO.vInventory[iMenu].stItemInfo.iEffect_OffencePower;

                // change 
                ITEMINFO currItem = m_stPINFO.stCurrWeapon;
                m_stPINFO.stCurrWeapon = m_stPINFO.vInventory[iMenu].stItemInfo;
                m_stPINFO.vInventory[iMenu].stItemInfo = currItem;
            }
            else if (m_stPINFO.vInventory[iMenu].stItemInfo.iType == 2) {
                cout << "����2" << endl;

                cout << "[�κ��丮] " << m_stPINFO.vInventory[iMenu].stItemInfo.szName << "�� �����߽��ϴ�." << endl;

                // effect
                m_stPINFO.iDefencePower = m_stPINFO.vInventory[iMenu].stItemInfo.iEffect_DefencePower;
                //change
                ITEMINFO currItem = m_stPINFO.stCurrShield;
                m_stPINFO.stCurrShield = m_stPINFO.vInventory[iMenu].stItemInfo;
                m_stPINFO.vInventory[iMenu].stItemInfo = currItem;
            }
            else if (m_stPINFO.vInventory[iMenu].stItemInfo.iType == 3) {
                if (m_stFcINFO.iCurrHP == m_stFcINFO.iTotalHP) cout << "[�κ��丮] ������ ������ ���� �ʿ䰡 �����ϴ�!" << endl;
                else{
                    Hilled(m_stPINFO.vInventory[iMenu].stItemInfo.iEffect_HillHP);
                    cout << "[�κ��丮] "<< m_stPINFO.vInventory[iMenu].stItemInfo.szName<<"�� ����ߴ�! HP�� "<< m_stPINFO.vInventory[iMenu].stItemInfo.iEffect_HillHP<<"��ŭ ä�������ϴ�." << endl;
                }
            }
            else if (m_stPINFO.vInventory[iMenu].stItemInfo.iType == 4) {
                if(!isField) cout << "[�κ��丮] ������ ����� �� ���� �������Դϴ�." << endl;
                else {

                }
            }
        }

        if (isEnd) break;
        system("pause");
    }
}

void CPlayer::EarnGold(int _iGold)
{
    m_stFcINFO.iGold = m_stFcINFO.iGold + _iGold;
}

void CPlayer::PurchaseGold(int _iGold) {
    m_stFcINFO.iGold = m_stFcINFO.iGold - _iGold;
}