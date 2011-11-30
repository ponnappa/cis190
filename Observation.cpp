#include <string>
#include <vector>

class Observation{

	private:
		string description;
		Item item;
		
	public:
		Observation(string descrip){
			description = descrip;
		}
		
		void linkItem(Item i){
			item = i;
		}
		
		bool hasItem(){
			return item!=NULL;
		}

















}