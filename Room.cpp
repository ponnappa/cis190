#include "Room.h"
using namespace std;


    Room::Room(string _name, string _description){
        name=_name;
        description=_description;
    }
	
    
    
    void Room::printDescription(){
        cout << "You are in the " << name <<" " << description << endl;
        cout << "The " << name << " contains the following people:";
        vector<Npc*>::iterator it1;
        for(it1=npcs.begin(); it1<npcs.end(); it1++){
            cout<< (*(*it1)).getName() << " ";
        }
		cout<<endl;
		//modify
        /*cout<< endl << "and the following items:";
        vector<Item*>::iterator it2;
        for(it2=items.begin(); it2<items.end(); it2++){
            cout<< *it2.getName(); << " ";
        }*/
    
    }

    string Room::getName(){
        return name;
    }
    
	bool equals(Room *r){
		return (getName().compare((*r).getName()))==0;
	}

    
    vector<Room*> Room::getExits(){
        return exits;
    }
    
    void Room::addExit(Room *r){
        vector<Room*>::iterator it;
        for(it=exits.begin(); it<exits.end(); it++){
            if((*r).equals(*it)){
                return;
            }
        }
		exits.push_back(r);
    }
    
    bool Room::removeExit(Room *r){
        vector<Room*>::iterator it;
        for(it=exits.begin(); it<exits.end(); it++){
            if((*r).equals(*it)){
                exits.erase(it);
                return true;
            }
        }
        return false;
    }
    
    
    vector<Npc*> Room::getNpcs(){
        return npcs;
    }
    
    void Room::addNpc(Npc *n){
        vector<Npc*>::iterator it;
        for(it=npcs.begin(); it<npcs.end(); it++){
            if((*n).equals(*it)){
                return;
            }
        }
		npcs.push_back(n);
    }
    
    bool Room::removeNpc(Npc *n){
        vector<Npc*>::iterator it;
        for(it=npcs.begin(); it<npcs.end(); it++){
            if((*n).equals(*it)){
                npcs.erase(it);
                return true;
            }
        }
        return false;
    }
    /*
    vector<Item*> getItems(){
        return items;
    }
    
    void addItem(Item *i){
        vector<Item*>::iterator it;
        for(it=items.begin(); it<items.end(); it++){
            if((*i).equals(*it)){
                return;
            }
        }
		npcs.push_back(i);
    }
    
    bool removeItem(Item *i){
        vector<Item*>::iterator it;
        for(it=items.begin(); it<items.end(); it++){
            if((*i).equals(*it)){
                npcs.erase(it);
                return true;
            }
        }
        return false;
    }
    */
    
    vector<Observation*> Room::getObservations(){
        return observations;
    }
    
    void Room::addObservation(Observation *o){
        vector<Observation*>::iterator it;
        for(it=observations.begin(); it<observations.end(); it++){
            if((*o).equals(*it)){
                return;
            }
        }
		observations.push_back(o);
    }
    
    bool Room::removeObservation(Observation *o){
        vector<Observation*>::iterator it;
        for(it=observations.begin(); it<observations.end(); it++){
            if((*o).equals(*it)){
               observations.erase(it);
                return true;
            }
        }
        return false;
    }

    
