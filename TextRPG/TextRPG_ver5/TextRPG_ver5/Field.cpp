#include "stdafx.h"
#include "Field.h"

using namespace std;

CField::CField()
{
	m_pCmonster = nullptr;
}

CField::~CField()
{
	Release();
}

void CField::Initalize(CPlayer* pCplayer)
{
	m_pCplayer = pCplayer;
}

void CField::Update()
{
	int iMenu(1);
	bool isEnd(false);

	while (1) {
		system("cls");

		cout << "[����] ������ �������ּ��� (1. �ʱ�, 2.�߱�, 3.���, 4.���ư���): ";
		cin >> iMenu;

		switch (iMenu)
		{
		case 1:
			Battle(1);
			break;
		case 2:
			Battle(2);
			break;
		case 3:
			Battle(3);
			break;
		case 4:
			isEnd = true;
			break;
		default:
			cout << "[����] �߸��� �Է��Դϴ�. " << endl;
			break;
		}

		if (isEnd) break;
		system("pause");
	}
}

void CField::Release()
{
	SAFE_DELETE(m_pCmonster);
}

void CField::Battle(int fieldLv)
{	
	// set monster
	m_pCmonster = new CMonster;
	m_pCmonster->Initialize(fieldLv);

	// start battle
	int iMenu(1);
	bool isEnd(false);
	bool isWin(false);

	while (1) {
		system("cls");

		m_pCplayer->DisplayInfo();
		m_pCmonster->DisplayInfo();

		cout << "[����]  1. �����Ѵ� 2. �������� : ";
		cin >> iMenu;

		switch (iMenu)
		{
		case 1:
			Attack(isEnd, isWin);
			break;
		case 2:
			Run(isEnd);
			break;
		default:
			cout << "[����] �߸��� �Է��Դϴ�. " << endl;
			break;
		}

		if (isEnd) {
			if (isWin) {
				m_pCplayer->LevelUp();
				m_pCplayer->SetCurrHP(m_pCplayer->GetPlayerInfo().iTotalHP_ - m_pCplayer->GetPlayerInfo().iCurrHP_);	// full hill
			}
			else {
				m_pCplayer->SetCurrHP(m_pCplayer->GetPlayerInfo().iTotalHP_ - m_pCplayer->GetPlayerInfo().iCurrHP_);	// full hill
			}
			break;
		}
		system("pause");
	}
}

void CField::Attack(bool& isEnd, bool& isWin)
{
	// player attack monster
	cout << "[����] ���͸� �����մϴ�!  ("<< (-1) * m_pCplayer->GetPlayerInfo().iOffencePower_ <<")" << endl;
	m_pCmonster->SetCurrHP( (-1)*m_pCplayer->GetPlayerInfo().iOffencePower_);

	// check is monster dead
	if (m_pCmonster->IsDead()) {
		cout << "[����] ���͸� ����Ʈ�Ƚ��ϴ�!"<<endl;
		isWin = true;
		isEnd = true;
		return;
	}

	// monster attack player
	cout << "[����] ���Ϳ��� ���ݴ��߽��ϴ�! ("<< (-1) * m_pCmonster->GetOffencePower() <<")" << endl;
	m_pCplayer->SetCurrHP((-1) * m_pCmonster->GetOffencePower());

	// check is player dead
	if (m_pCplayer->IsDead()) {
		cout << "[����] ����� ���������ϴ�. ������ ���ư��ϴ�."<<endl;
		isWin = false;
		isEnd = true;
		return;
	}
	m_pCplayer->DisplayInfo();
	m_pCmonster->DisplayInfo();

}



void CField::Run(bool& refIsEnd)
{
	cout << "[����]  ���ͷκ��� �������ϴ�." << endl;
	refIsEnd = true;
}
