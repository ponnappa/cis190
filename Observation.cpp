#include <string>
#include <vector>
#include "Item.h"
using namespace std;

class Observation{

	private:
		string name;
		string description;
		Item *item;
		
	public:
		Observation(string _name, string _description){
			description = _description;
			name = _name;
			item = NULL;
		}
		
		bool equals(Observation *o){
			return (getName().compare((*o).getName()))==0;
		}
		
		string getName(){
			return name;
		}
		string getDescription(){
			return description;
		}
		
		void addItem(Item *i){
			item = i;
		}
		
		bool hasItem(){
			return item!=NULL;
		}



};