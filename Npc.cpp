#include "Npc.h"
/*#include <string>
#include <vector>
#include "Observation.h"
#include "Game.h"*/
using namespace std;

	Npc::Npc(string _name, string _description, Game *_game){
		name=_name;
	 	description=_description;
		game = _game;
	}
  
    string Npc::getName(){
      return name;
    }
	
	string Npc::getDescription(){
		return description;
	}
    
    vector<Observation*> Npc::getResponses(){
        vector<Observation*> newresp;
        vector<Observation*>::iterator it;
        for(it=responses.begin(); it<responses.end(); it++){
            Observation* o = (*it);
            set<int>::iterator it2;
            bool flag = true;
			set<int> temp = (*o).getTriggers();
            for(it2=temp.begin(); it2 != temp.end(); it2++){
                if(!(*((*game).getState()+(*it2)))){
                    flag = false;
                    break;
                }
            }
            if(flag){
                newresp.push_back(o);
            }
        }

        return newresp;
    }
    
	    void Npc::addResponse(Observation *o){
	      responses.push_back(o);
	    }


	bool Npc::equals(Npc *n){
		return (getName().compare((*n).getName()))==0;
	}