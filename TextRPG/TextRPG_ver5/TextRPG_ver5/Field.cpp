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

		cout << "[마을] 던전을 선택해주세요 (1. 초급, 2.중급, 3.고급, 4.돌아간다): ";
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
			cout << "[던전] 잘못된 입력입니다. " << endl;
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
	cout << "[던전] 몬스터를 공격합니다!  ("<< (-1) * m_pCplayer->GetPlayerInfo().iOffencePower_ <<")" << endl;
	m_pCmonster->SetCurrHP( (-1)*m_pCplayer->GetPlayerInfo().iOffencePower_);

	// check is monster dead
	if (m_pCmonster->IsDead()) {
		cout << "[던전] 몬스터를 쓰러트렸습니다!"<<endl;
		isWin = true;
		isEnd = true;
		return;
	}

	// monster attack player
	cout << "[던전] 몬스터에게 공격당했습니다! ("<< (-1) * m_pCmonster->GetOffencePower() <<")" << endl;
	m_pCplayer->SetCurrHP((-1) * m_pCmonster->GetOffencePower());

	// check is player dead
	if (m_pCplayer->IsDead()) {
		cout << "[던전] 당신은 쓰러졌습니다. 마을로 돌아갑니다."<<endl;
		isWin = false;
		isEnd = true;
		return;
	}
	m_pCplayer->DisplayInfo();
	m_pCmonster->DisplayInfo();

}



void CField::Run(bool& refIsEnd)
{
	cout << "[던전]  몬스터로부터 도망갑니다." << endl;
	refIsEnd = true;
}
