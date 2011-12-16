#ifndef OBSERVATION_H
#define OBSERVATION_H

#include <string>
#include <vector>
#include "Item.h"

class Observation{

private:
	string name;
	string description;
	Item *item;
public:
	Observation(string _name, string _description);
	bool equals(Observation *o);
	string getName();
	string getDescription();
	void addItem(Item *i);
	bool hasItem();
};
#endif // OBSERVATION_H

