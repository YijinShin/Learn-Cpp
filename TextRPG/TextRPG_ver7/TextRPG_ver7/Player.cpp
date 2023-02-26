#include "stdafx.h"
#include "Player.h"

#include "BaseCreature.h"
#include "Inventory.h"

CPlayer::CPlayer():m_cpInventory(nullptr)
{
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
    m_cpInventory = new CInventory;
    m_cpInventory->Initialize();

	SetName();
	SetJob();
}

void CPlayer::Release()
{
	delete m_cpInventory;
	m_cpInventory = nullptr;
}

void CPlayer::Rander() const
{
	cout << "_____________________________________________________________" << endl;
	cout << "| Name: " << m_stBCINFO.szName << " (" << m_stPINFO.szJob << ")\tLv: " << m_stPINFO.iLv << endl;
	cout << "| HP: " << m_stBCINFO.iCurrHP << "/" << m_stBCINFO.iTotalHP << "\t Offence Power: " << m_stBCINFO.iOffencePower << "\t Gold: " << m_stBCINFO.iGold << endl;
	cout << "_____________________________________________________________" << endl;
}

void CPlayer::LevelUp()
{
    m_stPINFO.iLv++;
    m_stBCINFO.iTotalHP = m_stBCINFO.iTotalHP + 20;
    m_stBCINFO.iCurrHP = m_stBCINFO.iTotalHP;
    m_stBCINFO.iOffencePower = m_stBCINFO.iOffencePower + 2;
}

void CPlayer::SetJob()
{
    // setting job , hp, offencepower
    int _iJob(0);

    cout << "[나레이션] 직업을 선택하세요 (1.전사, 2.법사, 3.궁수): ";
    while (1) {
        cin >> _iJob;

        if (_iJob == 1) {
            m_stBCINFO.iTotalHP = 100;
            m_stBCINFO.iOffencePower = 10;
            strcpy_s(m_stPINFO.szJob, MAXNAMESIZE, "전사");
            break;
        }
        else if (_iJob == 2) {
            m_stBCINFO.iTotalHP = 80;
            m_stBCINFO.iOffencePower = 25;
            strcpy_s(m_stPINFO.szJob, MAXNAMESIZE, "법사");
            break;
        }
        else if (_iJob == 3) {
            m_stBCINFO.iTotalHP = 90;
            m_stBCINFO.iOffencePower = 15;
            strcpy_s(m_stPINFO.szJob, MAXNAMESIZE, "도적");
            break;
        }
        else {
            cout << "[나레이션] 다시 선택하세요 (1.전사, 2.법사, 3.궁수): ";
        }
    }
    m_stBCINFO.iCurrHP = m_stBCINFO.iTotalHP;
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
            strcpy_s(m_stBCINFO.szName, MAXNAMESIZE, _szName);
            break;
        }
    }

    cin.ignore();
}

void CPlayer::EarnGold(int _iGold)
{
	m_stBCINFO.iGold = m_stBCINFO.iGold + _iGold;
}

void CPlayer::PurchaseGold(int _iGold) {
	m_stBCINFO.iGold = m_stBCINFO.iGold - _iGold;
}
