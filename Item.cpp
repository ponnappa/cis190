#include <iostream>
#include <string>

class Item {
	private:
		string name;
		int number;
	public:
		string getName () {
			return name;
		}
		
		int getNumber(){
			return number;
		}
		
		bool equals(Item i){
			return((i.getName().compare(getName()))==0)
	
		}
}