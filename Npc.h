#ifndef __NPC_HEADER__
#define __NPC_HEADER__
#include <string>
#include <vector>
#include <map>
#include "Observation.h"
#include "Game.h"

class Game;
class Observation;

using namespace std;
class Npc{

  private:
    string name;
    string description;
    vector<Observation*> responses;
    Game *game;


  public:
    Npc(string _name, string _description, Game *_game);
  
    string getName();
	
	  string getDescription();
    
    vector<Observation*> getResponses();
    
    void addResponse(Observation *o);
	
	  void updateNPC();

	  bool equals(Npc *n);
};
#endif