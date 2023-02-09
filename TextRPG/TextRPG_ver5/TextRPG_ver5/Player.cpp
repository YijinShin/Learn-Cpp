#include "stdafx.h"
#include "Player.h"
//#include <string>

CPlayer::CPlayer()
{
    memset(&m_playerInfo, 0, sizeof(m_playerInfo));
    m_playerInfo.iLv_ = 1;
}

CPlayer::~CPlayer()
{

}

void CPlayer::DisplayInfo()
{
    cout << "_____________________________________________________________" << endl;
    cout << "| Name: " << m_playerInfo.strName_ << " (" << m_playerInfo.strJob_ << ")\tLv: " << m_playerInfo.iLv_ << endl;
    cout << "| HP: " << m_playerInfo.iCurrHP_ << "/" << m_playerInfo.iTotalHP_ << "\t Offence Power: " << m_playerInfo.iOffencePower_ << endl;
    cout << "_____________________________________________________________" << endl;
}


void CPlayer::Initialize()
{
    SetName();
    SelecteJob();
}

void CPlayer::SetName()
{
    cout << "[나레이션]  캐릭터 이름을 입력해주세요: ";
    getline(cin, m_playerInfo.strName_);
    cin.ignore();
}

void CPlayer::SelecteJob()
{
    int iSeleteJob(0);

    cout << "[나레이션] 직업을 선택하세요 (1.전사, 2.법사, 3.궁수): ";
    cin >> iSeleteJob;

    switch (iSeleteJob)
    {
    case 1:
        m_playerInfo.strJob_ = "전사";
        m_playerInfo.iTotalHP_ = 100;
        m_playerInfo.iOffencePower_ = 10;
        break;
    case 2:
        m_playerInfo.strJob_ = "법사";
        m_playerInfo.iTotalHP_ = 80;
        m_playerInfo.iOffencePower_ = 25;
        break;
    case 3:
        m_playerInfo.strJob_ = "궁수";
        m_playerInfo.iTotalHP_ = 90;
        m_playerInfo.iOffencePower_ = 15;
        break;
    default:
        break;
    }

    m_playerInfo.iCurrHP_ = m_playerInfo.iTotalHP_;
}

void CPlayer::SetCurrHP(int _alpaHP)
{
    m_playerInfo.iCurrHP_ = m_playerInfo.iCurrHP_ + _alpaHP;
}

void CPlayer::LevelUp()
{
    cout << "[던전]  축하합니다! 레벨이 올랐습니다! 체력이 30, 공격력이 2증가합니다."<<endl;
    m_playerInfo.iLv_++;
    m_playerInfo.iTotalHP_ = m_playerInfo.iTotalHP_ + 30;
    m_playerInfo.iOffencePower_ = m_playerInfo.iOffencePower_ + 2;
}

bool CPlayer::IsDead()
{
    if (m_playerInfo.iCurrHP_ <= 0) return true;
    else return false;
}

PLAYERINFO CPlayer::GetPlayerInfo()
{
    return m_playerInfo;
}
