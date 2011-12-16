#include <iostream>
#include <string>
using namespace std;
#include "Item.h"

        Item::Item(string _name){
                name = _name;
        }

        string Item::getName () {
                return name;
        }

        /*int getNumber(){
                return number;
        }*/

        bool Item::equals(Item *i){
                return(((*i).getName().compare(getName()))==0);
        }
