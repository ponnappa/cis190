#include <string>
#include <vector>
#include "Item.h"
using namespace std;

class Npc{

  private:
    string name;
	string description;
	Item *item;
	string speech;
    vector<string> responses;
    /*vector<Item> inventory;
      vector<Observation> observations;
      Should this be handled as part of the room class?
      I see complications if we have two separate logs
      of items/observations in a room*/
    //vector<bool> allowed_topics;
    /*This will interface with the speech,
      to let us control which things we can talk about
      at a given game state. Other ideas?*/
  public:
    Npc(string _name, string _description){
      name=_name;
	  description=_description;
	  speech ="";
    }
  
    string getName(){
      return name;
    }
	
	string getDescription(){
		return description;
	}
    
	string getSpeech(){
		return speech;
	}
	
	void changeSpeech(string s){
		speech = s;
	}
	
    vector<string> getResponses(){
      return responses;
    }
    
    void addResponse(string r){
      responses.push_back(r);
    }
	
	bool equals(Npc *n){
			return (getName().compare((*n).getName()))==0;
	}
		
    /*
    void getAllowed(){
      return allowed_topics;
    }
    
    void addAllowed(bool b){
      allowed_topics.push_back(b);
    }*/
};
