#include <iostream>
#include <string>
#include "bass.h"
class Flag {
	private:
		string eventDescription;
	public:
		int getIndex() {
			return index;
		}
		string getDescription () {
			return eventDescription;
		}
		void trigger () {
			//updates game engine global state
			//will require access to a data structure holding all of the dialogues
		}
}
//must have class ItemFlag that extends Flag to include exact window output for default item //pickup/drop (exceptions to the defaults will be handled by normal Flag objects)
class Item {
	private:
		string name;
		bool triggersFlag; /* checks if the item triggers a plotline flag (i.e. changing the global state of the game engine) */
	public:
		string getName () {
			return name;
		}
		bool doesTrigger () {
			return triggersFlag;
		}
		Flag *getFlag () {
			return flagTriggered;
		}
		void triggerFlags() {
			itemPickedUp->trigger(*this);  /* refers to global flag 'itemPickedUp', which should be triggered whenever triggerFlag is called (i.e. whenever an item is picked up). This flag updates the game engine with respect to plot-unrelated information, such as adding the item to the players inventory, removing it from the current room, and displaying the standard item picked up text. */
			if (triggersFlag) { flagTriggered->trigger(); } //see above descriptions
		}
}
