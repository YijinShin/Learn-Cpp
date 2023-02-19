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

void CPlayer::AddGold(int _iGold)
{
    m_stFcINFO.iGold = m_stFcINFO.iGold + _iGold;
}
