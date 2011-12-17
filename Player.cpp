#include "Player.h"

using namespace std;


		Player::Player(string _name, Room *_curr){
			name = _name;
			currentRoom = _curr;
		}
		
		string Player::getName(){
			return name;
		}
		
		void Player::setName(string _name){
			name = _name;
		}
		
		Room *Player::getCurrentRoom(){
			return currentRoom;
		}
		
		void Player::setCurrentRoom(Room *r){
			currentRoom = r;
		}
		
		void Player::addItem(Item *i){
			items.push_back(i);
		}
		
		bool Player::removeItem(Item *remit){
			vector<Item*>::iterator it;
			for(it=items.begin(); it<items.end(); it++){
				if((*remit).equals((*it))){
					items.erase(it);
					return true;
				}
			}
        return false;
		}
		
		xvector<Item*>Player::getItems(){
			return items;
		}



