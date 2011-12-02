#include <string>
#include <vector>
#include "Room.cpp"

using namespace std;

class Player{
	
	private:
		string name;
		Room currentRoom;
		//vector<Items> items;
	
	public:
		//constructor
		Player(string _name, Room _curr){
			name = _name;
			currentRoom = _curr;
		}
		
		string getName(){
			return name;
		}
		
		Room getCurrentRoom(){
			return currentRoom;
		}
		
		void setCurrentRoom(Room r){
			currentRoom = r;
		}
		/*
		void addItem(Item i){
			items.push_back(i);
		}
		
		bool removeItem(Item remit){
			vector<Item>::iterator it;
			for(it=items.begin(); it<items.end(); it++){
				if(remit==*it){
					npcs.erase(it);
					return true;
				}
			}
        return false;
		}
		
		vector<Item> getItems(){
			return items;
		}
*/



};