#include <string>
#include <vector>

class Room{

 private:
    string name;
    //string description; ?
    
    vector<Room> exits;
    vector<Npc> npcs;
    vector<Item> items;
    vector<Observation> observations;       
    
    
 public:
    //constructor
    Room(string _name){
        name=_name;
    }

    string getName(){
        return name;
    }
    
    //void addDescription(string){}  //possibly?
    //string getDescription(){}
    
    vector<Room> getExits(){
        return exits;
    }
    
    void addExit(Room r){
        exits.push_back(r);
    }
    
    bool removeExit(Room r){
        vector<Exit>::iterator it;
        for(it=exits.begin(); it<exits.end(); it++){
            if(r==*it){
                exits.erase(it);
                return true;
            }
        }
        return false;
    }
    
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
    
    void getObservations(){
        return observations;
    }
    
    void addObservation(Observation o){
        observations.push_back(o);
    }
    
    bool removeObservation(Observation o){
        vector<Observation>::iterator it;
        for(it=observations.begin(); it<observations.end(); it++){
            if(o==*it){
                observations.erase(it);
                return true;
            }
        }
        return false;
    }

}
    

class Exit{
 private:
    Room room1;
    Room room2;

 public:
    Exit(Room r1,Room r2){
        room1=r1;
        room2=r2;
    }
 
    Room getRoom1(){
        return room1;
    }
    Room getRoom2(){
        return room2;
    }
}
