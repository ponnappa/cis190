//Game Engine
#include <iostream>
#include <stdlib.h>
#include "Game.h"
#include "Player.h"
#include "Observation.h"
#include "Room.h"
#include "Npc.h"
#include "Item.h"


int main(){
    Game *g = new Game();
	(*g).setup();
	while(true)
		(*g).run();
	return 0;
}