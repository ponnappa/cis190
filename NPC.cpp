#include <string>
#include <vector>

class Npc{

  private:
    string name;

    vector<string> speech;
    /*vector<Item> inventory;
      vector<Observation> observations;
      Should this be handled as part of the room class?
      I see complications if we have two separate logs
      of items/observations in a room*/
    vector<bool> allowed_topics;
    /*This will interface with the speech,
      to let us control which things we can talk about
      at a given game state. Other ideas?*/
  public:
    Npc(string _name){
      name=_name;
    }
  
    string getName(){
      return name;
    }
    
    void getSpeech(){
      return speech;
    }
    
    void addSpeech(string s){
      speech.push_back(s);
    }
    
    void getAllowed(){
      return allowed_topics;
    }
    
    void addAllowed(bool b){
      allowed_topics.push_back(b);
    }
