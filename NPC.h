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
    Npc(string _name);
  
    string getName();
    
    void getSpeech();
    
    void addSpeech(string s);
    
    void getAllowed();
    
    void addAllowed(bool b);
};
