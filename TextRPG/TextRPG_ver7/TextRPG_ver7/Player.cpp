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

    cout << "[�����̼�] ������ �����ϼ��� (1.����, 2.����, 3.�ü�): ";
    while (1) {
        cin >> _iJob;

        if (_iJob == 1) {
            m_stBCINFO.iTotalHP = 100;
            m_stBCINFO.iOffencePower = 10;
            strcpy_s(m_stPINFO.szJob, MAXNAMESIZE, "����");
            break;
        }
        else if (_iJob == 2) {
            m_stBCINFO.iTotalHP = 80;
            m_stBCINFO.iOffencePower = 25;
            strcpy_s(m_stPINFO.szJob, MAXNAMESIZE, "����");
            break;
        }
        else if (_iJob == 3) {
            m_stBCINFO.iTotalHP = 90;
            m_stBCINFO.iOffencePower = 15;
            strcpy_s(m_stPINFO.szJob, MAXNAMESIZE, "����");
            break;
        }
        else {
            cout << "[�����̼�] �ٽ� �����ϼ��� (1.����, 2.����, 3.�ü�): ";
        }
    }
    m_stBCINFO.iCurrHP = m_stBCINFO.iTotalHP;
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
