#include "stdafx.h"
#include "MainGame.h"

using namespace std;



int main() {

	CMainGame mainGame;

	// init game setting
	mainGame.Initialize();

	// start game
	mainGame.Update();

	// release => destructor가 알아서 
}