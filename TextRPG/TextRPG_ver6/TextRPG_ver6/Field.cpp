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
		cout << "[마을] 던전을 선택해주세요 (1. 초급, 2.중급, 3.고급, 4.돌아간다): ";
		cin >> iMenu;
		if (iMenu == 1 || iMenu == 2 || iMenu == 3) {
			Battle(3);
		}
		else if(iMenu == 4) isEnd = true;
		else cout << "[던전] 잘못된 입력입니다. " << endl;

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

		cout << "[던전]  1. 공격한다 2. 도망간다 : ";
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
			cout << "[던전] 잘못된 입력입니다. " << endl;
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
	cout << "[던전] 몬스터를 공격합니다!  (" << (-1) * m_cpPlayer->GetOffencePower()<< ")" << endl;
	m_cpMonster->Damaged(m_cpPlayer->GetOffencePower());

	// check is monster dead
	if (m_cpMonster->IsDead()) {
		cout << "[던전] 몬스터를 쓰러트렸습니다!" << endl;
		refIsWin = true;
		refIsEnd = true;
		return;
	}

	// monster attack player
	cout << "[던전] 몬스터에게 공격당했습니다! (" << (-1) * m_cpMonster->GetOffencePower() << ")" << endl;
	m_cpMonster->Damaged( m_cpMonster->GetOffencePower());

	// check is player dead
	if (m_cpPlayer->IsDead()) {
		cout << "[던전] 당신은 쓰러졌습니다. 마을로 돌아갑니다." << endl;
		refIsWin = false;
		refIsEnd = true;
		return;
	}
	m_cpPlayer->DisplayINFO();
	m_cpMonster->DisplayINFO();
}

void CField::Run(bool& refIsEnd)
{
	cout << "[던전]  몬스터로부터 도망갑니다." << endl;
	refIsEnd = true;
}
