#include <string>
#include <vector>
//class Item;
class Observation{

	private:
		string description;
		//Item item;
		
	public:
		Observation(string descrip);
		
		bool equals(Observation o);
		
		string getDescription();
		/*
		void linkItem(Item i);
		
		bool hasItem();
*/



};
