#include "stdafx.h"
#include "MainGame.h"

MainGame::MainGame()
{
	m_player = nullptr;
}

MainGame::~MainGame()
{
	Release();
}

void MainGame::Initialize()
{
	m_player = new CPlayer;	// create player
	m_player->Initialize();	// initialize player
}

void MainGame::Update()
{

}

void MainGame::Release()
{
	delete m_player;
}
