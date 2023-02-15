#include "stdafx.h"
#include "Field.h"

CField::CField():m_cpMonster(nullptr), m_cpPlayer(nullptr)
{
}

CField::~CField()
{
	Release();
}

void CField::Initialize(CPlayer* _cpPlayer)
{
	m_cpMonster = new CMonster;

	// init player
	m_cpPlayer = _cpPlayer;
}

void CField::Update()
{
	int iMenu(0);
	bool isEnd(false);

	while (1) {
		system("cls");

		//select menu
		cout << "[����] ������ �������ּ��� (1. �ʱ�, 2.�߱�, 3.���, 4.���ư���): ";
		cin >> iMenu;
		if (iMenu == 1 || iMenu == 2 || iMenu == 3) {
			Battle(3);
		}
		else if(iMenu == 4) isEnd = true;
		else cout << "[����] �߸��� �Է��Դϴ�. " << endl;

		if (isEnd) break;
		system("pause");
	}
}

void CField::Release()
{
	SAFE_DELETE(m_cpMonster);
}

void CField::Battle(int _iFieldLv)
{
	// set monster
	m_cpMonster->SetType(_iFieldLv);

	// start battle
	int iMenu(1);
	bool isEnd(false);
	bool isWin(false);

	while (1) {
		system("cls");

		m_cpPlayer->DisplayINFO();
		m_cpMonster->DisplayINFO();

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
				m_cpPlayer->LevelUp();
			}
			else {
				// full hill
				m_cpPlayer->SetCurrHP(m_cpPlayer->GetTotalHP());
			}
			break;
		}
		system("pause");
	}
}

void CField::Attack(bool& refIsEnd, bool& refIsWin)
{
	// player attack monster
	cout << "[����] ���͸� �����մϴ�!  (" << (-1) * m_cpPlayer->GetOffencePower()<< ")" << endl;
	m_cpMonster->Damaged(m_cpPlayer->GetOffencePower());

	// check is monster dead
	if (m_cpMonster->IsDead()) {
		cout << "[����] ���͸� ����Ʈ�Ƚ��ϴ�!" << endl;
		refIsWin = true;
		refIsEnd = true;
		return;
	}

	// monster attack player
	cout << "[����] ���Ϳ��� ���ݴ��߽��ϴ�! (" << (-1) * m_cpMonster->GetOffencePower() << ")" << endl;
	m_cpMonster->Damaged( m_cpMonster->GetOffencePower());

	// check is player dead
	if (m_cpPlayer->IsDead()) {
		cout << "[����] ����� ���������ϴ�. ������ ���ư��ϴ�." << endl;
		refIsWin = false;
		refIsEnd = true;
		return;
	}
	m_cpPlayer->DisplayINFO();
	m_cpMonster->DisplayINFO();
}

void CField::Run(bool& refIsEnd)
{
	cout << "[����]  ���ͷκ��� �������ϴ�." << endl;
	refIsEnd = true;
}
