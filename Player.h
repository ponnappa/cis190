#ifndef __PLAYER_H__
#define __PLAYER_H__

#include<string>
#include<vector>
#include "Room.h"
#include "Item.h"
#include "Observation.h"

class Room;
class Item;
class Observation;

using namespace std;

class Player {
  
  private:
    string name;
    Room *currentRoom;
    vector<Observation*> journal;
    vector<Item*> items;
  public:
    Player(string _name, Room *_curr);
    string getName();
    void setName(string _name);
    Room *getCurrentRoom();
    void setCurrentRoom(Room *r);
    void addItem(Item *i);
    bool removeItem(Item *remit);
	vector<Item*> getItems();
};
    
#endif // PLAYER_H