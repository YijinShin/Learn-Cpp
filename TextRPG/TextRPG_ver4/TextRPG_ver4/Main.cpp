/* Text RPG ver4  (2023.02.08 ~)
- class ���(������, �Ҹ���)
*/

#include "stdafx.h"
#include "MainGame.h"

using namespace std;

int main(){
	int iMenu(0);
	MainGame mainGame;
	Player* player = new Player;
	
	// setting player
	mainGame.SettingPlayer(&player);

	// start game
	mainGame.Game(player);

	mainGame.Release(player);

}