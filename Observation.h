#include <string>
#include <vector>
//class Item;
class Observation{

	private:
		string description;
		//Item item;
		
	public:
		Observation(string descrip){
			description = descrip;
		}
		
		bool equals(Observation o){
			return (getDescription().compare(o.getDescription()))==0;
		}
		
		string getDescription(){
			return description;
		}
		/*
		void linkItem(Item i){
			item = i;
		}
		
		bool hasItem(){
			return item!=NULL;
		}
*/



};
