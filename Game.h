#ifndef __GAME_H__
#define __GAME_H__

#include "Player.h"
#include "Observation.h"

class Player;
class Observation;

class Game{
  private:
    bool state[40];
    
  public:
    Game();
    bool *getState();
    void run();
	int getUserInput(int);
    void updateGame(Observation *o, Player *p);
    
};

#endif // GAME_H
