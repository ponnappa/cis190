#ifndef __ROOM_HEADER__
#define __ROOM_HEADER__

#include <string>
#include <vector>
#include "Npc.h"
#include "Item.h"
#include "Observation.h"



class Room {
public:
    Room(string _name);
    
    string getName();
    
    vector<Room> getExits();
    void addExit(Room r);
    bool removeExit(Room r);
    
    vector<Npc> getNpcs();
    void addNpc(Npc n);
    bool removeNpc(Npc n);
    
    vector<Item> getItems();
    void addItem(Item i);
    bool removeItem(Item i);
    
    vector<Observation> getObservations();
    void addObservation(Observation o);
    bool removeObservation(Observation o);

private:
    string name;
    vector<Room> exits;
    vector<Npc> npcs;
    vector<Item> items;
    vector<Observation> observations;  
};

#endif