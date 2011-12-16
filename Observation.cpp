#include "Observation.h"
using namespace std;
//12/16 early update
Observation::Observation(string _name, string _description){
    description = _description;
    name = _name;
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
