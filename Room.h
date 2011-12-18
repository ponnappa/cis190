#ifndef __ROOM_HEADER__
#define __ROOM_HEADER__

#include <string>
#include <vector>
#include "Npc.h"
#include "Item.h"
#include "Observation.h"
#include "Game.h"
class Game;
class Item;
class Observation;
class Npc;

using namespace std;


class Room {
private:
    string name;
    vector<Room*> exits;
    vector<Npc*> npcs;
    vector<Observation*> observations; 
	string description;
	Game *game;
public:
    Room(string _name, string _description, Game *g);
    
    string getName();
    
    //void printDescription();
    
    vector<Room*> getExits();
    void addExit(Room *r);
    bool removeExit(Room *r);
    
    vector<Npc*> getNpcs();
    void addNpc(Npc *n);
    bool removeNpc(Npc *n);
    
    vector<Item*> getItems();
    void addItem(Item *i);
    bool removeItem(Item *i);
    
    vector<Observation*> getObservations();
    void addObservation(Observation *o);
    bool removeObservation(Observation *o); 
	
	bool equals(Room *r);
};

#endif