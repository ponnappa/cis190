#ifndef __ITEM_HEADER__

#define __ITEM_HEADER__
#include <iostream>
#include <string>
using namespace std;

class Item {
	private:
		string name;
		//int number;
	public:
		
		Item(string _name);
		
		string getName ();
		
		/*int getNumber(){
			return number;
		}*/
		
		bool equals(Item *i);
};
#endif