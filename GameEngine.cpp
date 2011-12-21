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
	while(*((*g).getState()+9)==false){
		(*g).run();
	}
	cout<<"You figured out your name! You win!"<<endl;
	return 0;
}