#ifndef __OBSERVATION_H__
#define __OBSERVATION_H__

#include <string>
#include <vector>
#include <set>
#include <map>
#include "Item.h"
#include "Game.h"

using namespace std;

class Game;
class Item;

class Observation{

private:
	string name;
	string description;
	Item *item;
	Item *take;
	set<int> triggers;
	map<int,bool> changes;
	Game *game;
public:
	Observation(string _name, string _description, Game *_game);
	bool equals(Observation *o);
	string getName();
	string getDescription();
	void addItem(Item *i);
	bool hasItem();
	Item* removeItem();
	bool hasTake();
	Item* removeTake();
	void addTrigger(int i);
	set<int> getTriggers();
	void addChange(int i, bool b);
	map<int,bool> getChanges();
};
#endif // OBSERVATION_H
