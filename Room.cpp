#include <string>
#include <vector>
#include "Observation.cpp"
using namespace std;

class Room{

 private:
    string name;
    //string description; ?
    
    vector<Room*> exits;
    //vector<Npc> npcs;
    //vector<Item> items;
    vector<Observation*> observations;       
    
    
 public:
    //constructor
    Room(string _name){
        name=_name;
    }
	
	//Room(){}

    string getName(){
        return name;
    }
    
	bool equals(Room *r){
		return (getName().compare((*r).getName()))==0;
	}
    //void addDescription(string){}  //possibly?
    //string getDescription(){}
    
    vector<Room*> getExits(){
        return exits;
    }
    
    void addExit(Room *r){
        vector<Room*>::iterator it;
        for(it=exits.begin(); it<exits.end(); it++){
            if((*r).equals(*it)){
                return;
            }
        }
		exits.push_back(r);
    }
    
    bool removeExit(Room *r){
        vector<Room*>::iterator it;
        for(it=exits.begin(); it<exits.end(); it++){
            if((*r).equals(*it)){
                exits.erase(it);
                return true;
            }
        }
        return false;
    }
    /*
    vector<Npc> getNpcs(){
        return npcs;
    }
    
    void addNpc(Npc n){
        npcs.push_back(n);
    }
    bool removeNpc(Npc n){
        vector<Npc>::iterator it;
        for(it=npcs.begin(); it<npcs.end(); it++){
            if(n==*it){
                npcs.erase(it);
                return true;
            }
        }
        return false;
    }
    
    vector<Item> getItems(){
        return items;
    }
    
    void addItem(Item i){
        items.push_back(i);
    }
    
    bool removeItem(Item i){
        vector<Item>::iterator it;
        for(it=items.begin(); it<items.end(); it++){
            if(i==*it){
                items.erase(it);
                return true;
            }
        }
        return false;
    }
    */
    vector<Observation*> getObservations(){
        return observations;
    }
    
    void addObservation(Observation *o){
        observations.push_back(o);
    }
    
    bool removeObservation(Observation *o){
        vector<Observation*>::iterator it;
        for(it=observations.begin(); it<observations.end(); it++){
            if((*o).equals(*it)){
                observations.erase(it);
                return true;
            }
        }
        return false;
    }

};
    
