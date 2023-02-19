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

void CPlayer::AddGold(int _iGold)
{
    m_stFcINFO.iGold = m_stFcINFO.iGold + _iGold;
}
