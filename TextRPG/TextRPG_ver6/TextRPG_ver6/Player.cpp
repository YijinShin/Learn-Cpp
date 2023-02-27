#include "stdafx.h"
#include "Define.h"
#include "FieldCreature.h"
#include "Player.h"


CPlayer::CPlayer()
{
    memset(&m_stPINFO, 0, sizeof(PINFO));
    m_stPINFO.iLv = 1;

    ITEMINFO basicShield = { 0,2, "그냥 방패", "방어력 +0", 100, 50, 0,0,0,0 };
    ITEMINFO basicWeapon = { 0,1, "그냥 칼", "공격력 +0", 100, 50, 0,0,0,0 };
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

    // gold test 를 위한 코드 
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
        cout << "No. " << i << "\t이름: " << m_stPINFO.vInventory[i].stItemInfo.szName << endl;
        cout << "가격: " << m_stPINFO.vInventory[i].stItemInfo.iResellPrice << " Gold\t개수: "<< m_stPINFO.vInventory[i].iCnt<<"개" << endl;
        cout << "설명: " << m_stPINFO.vInventory[i].stItemInfo.strInfo << endl;
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
    // 이미 가지고 있는 아이템인 경우 
    if (iIndex >= 0) {
        m_stPINFO.vInventory[iIndex].iCnt++;
    }
    else {
        // 처음 획득하는 경우, 
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

    cout << "[나레이션] 직업을 선택하세요 (1.전사, 2.법사, 3.궁수): ";
    while(1){
        cin >> _iJob;

        if (_iJob == 1) {
            m_stFcINFO.iTotalHP = 100;
            m_stFcINFO.iOffencePower = 10;
            strcpy_s(m_stPINFO.szJob, MAXNAMESIZE, "전사");
            break;
        }
        else if (_iJob == 2) {
            m_stFcINFO.iTotalHP = 80;
            m_stFcINFO.iOffencePower = 25;
            strcpy_s(m_stPINFO.szJob, MAXNAMESIZE, "법사");
            break;
        }
        else if (_iJob == 3) {
            m_stFcINFO.iTotalHP = 90;
            m_stFcINFO.iOffencePower = 15;
            strcpy_s(m_stPINFO.szJob, MAXNAMESIZE, "도적");
            break;
        }
        else {
            cout << "[나레이션] 다시 선택하세요 (1.전사, 2.법사, 3.궁수): ";
        }
    }
    m_stFcINFO.iCurrHP = m_stFcINFO.iTotalHP;
}

void CPlayer::SetName()
{
    char _szName[MAXNAMESIZE];
    
    cout << "[나레이션]  캐릭터 이름을 입력해주세요 (1~10자): ";
    while (1) {
        cin >> _szName;
        if (strlen(_szName) <= 0 || strlen(_szName) >= 10) {
            cout << "[나레이션] 다시 입력해주세요 (1~10자): ";
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
        cout << "[인벤토리] 무엇을 사용할까 (iIndex입력.사용, 0. 돌아가기): ";
        cin >> iMenu;
       
        if (iMenu == 0) isEnd = true;
        else {
            if (m_stPINFO.vInventory[iMenu].stItemInfo.iType == 1) {
                cout << "여기1" << endl;
                cout << "[인벤토리] " << m_stPINFO.vInventory[iMenu].stItemInfo.szName << "을 착용했습니다." << endl;

                // effect
                m_stFcINFO.iOffencePower -= m_stPINFO.stCurrWeapon.iEffect_OffencePower;
                m_stFcINFO.iOffencePower += m_stPINFO.vInventory[iMenu].stItemInfo.iEffect_OffencePower;

                // change 
                ITEMINFO currItem = m_stPINFO.stCurrWeapon;
                m_stPINFO.stCurrWeapon = m_stPINFO.vInventory[iMenu].stItemInfo;
                m_stPINFO.vInventory[iMenu].stItemInfo = currItem;
            }
            else if (m_stPINFO.vInventory[iMenu].stItemInfo.iType == 2) {
                cout << "여기2" << endl;

                cout << "[인벤토리] " << m_stPINFO.vInventory[iMenu].stItemInfo.szName << "을 착용했습니다." << endl;

                // effect
                m_stPINFO.iDefencePower = m_stPINFO.vInventory[iMenu].stItemInfo.iEffect_DefencePower;
                //change
                ITEMINFO currItem = m_stPINFO.stCurrShield;
                m_stPINFO.stCurrShield = m_stPINFO.vInventory[iMenu].stItemInfo;
                m_stPINFO.vInventory[iMenu].stItemInfo = currItem;
            }
            else if (m_stPINFO.vInventory[iMenu].stItemInfo.iType == 3) {
                if (m_stFcINFO.iCurrHP == m_stFcINFO.iTotalHP) cout << "[인벤토리] 지금은 포션을 마실 필요가 없습니다!" << endl;
                else{
                    Hilled(m_stPINFO.vInventory[iMenu].stItemInfo.iEffect_HillHP);
                    cout << "[인벤토리] "<< m_stPINFO.vInventory[iMenu].stItemInfo.szName<<"을 사용했다! HP가 "<< m_stPINFO.vInventory[iMenu].stItemInfo.iEffect_HillHP<<"만큼 채워졌습니다." << endl;
                }
            }
            else if (m_stPINFO.vInventory[iMenu].stItemInfo.iType == 4) {
                if(!isField) cout << "[인벤토리] 지금은 사용할 수 없는 아이템입니다." << endl;
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