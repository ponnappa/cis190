#include "Observation.h"
#include <string>
#include <vector>
#include <set>
#include <map>
/*#include "Item.h"
#include "Game.h"*/
using namespace std;

Observation::Observation(string _name, string _description, Game *_game){
    description = _description;
    name = _name;
    game = _game;
    item = NULL;
}

bool Observation::equals(Observation *o){
    return (getName().compare((*o).getName()))==0;
}

string Observation::getName(){
    return name;
}
string Observation::getDescription(){
    return description;
}

void Observation::addItem(Item *i){
    item = i;
}

bool Observation::hasItem(){
    return item!=NULL;
}

bool Observation::hasTake(){
    return take!=NULL;
}

Item* Observation::removeTake(){
    Item *temp = take;
    take = NULL;
    return temp;
}

Item* Observation::removeItem(){
    Item *temp = item;
    item = NULL;
    return temp;
}

void Observation::addTrigger(int i){
    triggers.insert(i);
}

set<int> Observation::getTriggers(){
    return triggers;
}

void Observation::addChange(int i,bool b){
    changes[i]=b;
}

map<int,bool> Observation::getChanges(){
    return changes;
}
