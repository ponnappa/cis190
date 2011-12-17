#ifndef PLAYER_H
#define PLAYER_H

#include<string>
#include<vector>
#include "Room.cpp"
#include "Item.cpp"

class Player {
  
  private:
    string name;
    Room *currentRoom;
    vector<Observation*> journal;
    vector<Item*> items;
  public:
    Player(string _name, Room *_curr);
    string getName();
    setName(string _name);
    Room *getCurrentRoom();
    setCurrentRoom(Room *r);
    addItem(Item *i);
    removeItem(Item *remit);
};
    
#endif // PLAYER_H