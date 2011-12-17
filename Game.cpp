//Game class
#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include "Player.cpp"

using namespace std;


//constructor
Game::Game(){
    state[0]=false; // 0 have asked bob your name
    state[1]=false; // 1 talked to Zach Zarrow once
    state[2]=false; // 2 have danced for Zach Zarrow
    state[3]=false; // 3 have received 3 quarters
    state[4]=false; // 4 talked to laplaces demon once
    state[5]=false; // 5 have a soda
    state[6]=false; // 6 talked to ITA manager once    
    state[7]=false; // 7 talked to student1 once
    state[8]=false; // 8 talked to student2 once
    state[9]=false; // 9 solved student1's problem
    state[10]=false; // 10 solved student2's problem
    state[11]=false; // 11 aware that you need money
    state[12]=false; // 12 have 4 bucks
}

void Game::updateGame(Observation *o, Player *p){
	if((*o).hasTake()){
		(*p).removeItem((*o).getTake());
	}
	if((*o).hasItem()){
		(*p).addItem((*o).removeItem());
	}
	map<int,bool> m = (*o).getChanges();
	map<int,bool>::iterator it;
	for (it=m.begin() ; it != m.end(); it++){
		state[(*it).first] = (*it).second;
	}
}

int Game::getUserInput(int n){
	string in;
    while(true){
	    cout<<"Please enter a selection from 1 to " <<n<<endl;
	    cin>>in;
    	if (in.compare("back")==0) return -1;
	    if(in.compare("q")==0) exit(0);
	    for(int i=1;i<=n;i++){
	    	if (atoi(in.c_str())==i) return atoi(in.c_str());
	    }
    }
}


bool * Game::getState(){
    return state;
}


void Game::run(){

	Room *br = new Room("Bedroom", "This is your dorm room. It's rancid." );
	Room *hall = new Room("Hall","Halls are exciting places.");
	Room *quad = new Room("Quad", "What a pretty place the quad is.");
	Room *lab = new Room("Computer Lab", "Wewt.");
	
	//create exits
	(*br).addExit(hall);
	(*hall).addExit(br);
	
	(*hall).addExit(quad);
	(*quad).addExit(hall);
	
	(*quad).addExit(lab);
	(*lab).addExit(hall);
	
	//create Items
	Item *computer = new Item("computer");
	Item *notes = new Item("class notes");
	
	Item *vending = new Item("vending machine");
	Item *door = new Item("door to your room");

	Item *knife = new Item("knife");
	Item *squirrel = new Item("squirrel");
	
	Item *printer = new Item("printer");
	Item *chair = new Item("char");
	
	//create observations
	Observation *computer_obs = new Observation("computer","You computer has a blue screen of death");
	Observation *notes_obs = new Observation("class notes","There is mentioning of a project due in CIS190");
	
	Observation *vending_obs = new Observation("vending machine","A soda would be delicious.");
	Observation *door_obs = new Observation("door to your room", "You notice that while other doors have student name tags, yours does not");
	
	Observation *knife_obs = new Observation("knife","");
	Observation *squirrel_obs = new Observation("squirrel","");
	
	Observation *printer_obs = new Observation("printer","out of ink");
	Observation *chair_obs = new Observation("chair","");
	
	//add items to observations
	(*computer_obs).addItem(computer);
	(*notes_obs).addItem(notes);
	
	(*vending_obs).addItem(vending);
	(*door_obs).addItem(door);
	
	(*knife_obs).addItem(knife);
	(*squirrel_obs).addItem(squirrel);
	
	(*printer_obs).addItem(printer);
	(*chair_obs).addItem(chair);
	
	//add observations to rooms
	(*br).addObservation(computer_obs);
	(*br).addObservation(notes_obs);
	(*hall).addObservation(vending_obs);
	(*hall).addObservation(door_obs);
	(*quad).addObservation(knife_obs);
	(*quad).addObservation(squirrel_obs);
	(*lab).addObservation(printer_obs);
	(*lab).addObservation(chair_obs);
	
	//create NPCs
	Npc *bob = new Npc("Bob","You hate living with Bob.");
	
	Dialogue *d = new Dialogue();
	(*d).setOption("What type of laptop do you have?");
	(*d).addResponse("I have an alienware. It's awesome.");
	(*d).addResponse("Leave me alone dude.");
	
	(*bob).addResponse(d);
	
	
	Npc *nurse = new Npc("nursing student","The nursing student that lives down the hall. You forget her name too.");
	
	Npc *zach = new Npc("Zach Zarrow", "Zach Zarrow is a jolly good fellow.");
	Npc *wharton = new Npc("Whartonite", "He's wearing a suit.");
	Npc *troll = new Npc("troll", "The troll looks like he's in a trolling mood.");
	
	Npc *itaman = new Npc("ITA Manager", "The ITA manager is playing Starcraft.");
	Npc *student1 = new Npc("Student1", "This student is working at a computer.");
	Npc *student2 = new Npc("Student2", "This student is working at a computer.");
	
	//add Npcs to rooms
	(*br).addNpc(bob);
	(*hall).addNpc(nurse);
	(*quad).addNpc(zach);
	(*quad).addNpc(wharton);
	(*quad).addNpc(troll);
	(*lab).addNpc(itaman);
	(*lab).addNpc(student1);
	(*lab).addNpc(student2);

    //create the player
	Player *p = new Player("UnknownName",br);

	cout<<"player "<<(*p).getName()<<" in area "<<(*(*p).getCurrentRoom()).getName()<<endl;
	
		while(true){
		cout<<"1)Move"<<endl;
		cout<<"2)Observe area"<<endl;
		cout<<"3)Talk to people"<<endl;
		//cout<<"4)Look at journal"<<endl;
		cout<<"4)Get Description"<<endl;
		int input= getUserInput(4);
		if(input==1){
			vector<Room*> ex = (*(*p).getCurrentRoom()).getExits();
			for(unsigned int i=0; i<ex.size();i++){
				cout<<(i+1)<<")"<<(*(ex.at(i))).getName()<<endl;
			}
			cout<<"type \"back\" to go back"<<endl<<endl;
			int movein = getUserInput(ex.size());
			if(movein==-1)
				continue;
			(*p).setCurrentRoom(ex.at(movein-1));
			continue;
		}
		if(input==2){
			vector<Observation*> obs = (*(*p).getCurrentRoom()).getObservations();
			for(unsigned int i=0; i<obs.size();i++){
				cout<<(i+1)<<")"<<(*(obs.at(i))).getName()<<endl;
			}
			cout<<"type \"back\" to go back"<<endl<<endl;
			int playobs = getUserInput(obs.size());
			if(playobs==-1){
				continue;
			}
			
			Observation o = (*(obs.at(playobs-1)));
			cout<<(*o).getDescription()<<endl;
			update_game(o,p);
			continue;
		}
		if(input==3){
			vector<Npc*> npcs = (*(*p).getCurrentRoom()).getNpcs();
			for(unsigned int i=0; i<npcs.size();i++){
				cout<<(i+1)<<")"<<(*(npcs.at(i))).getName()<<endl;
			}
			cout<<"type \"back\" to go back"<<endl<<endl;
			int npcchoose = getUserInput(npcs.size());
			if(npcchoose==-1){
				continue;
			}
			Npc n = *(npcs.at(npcchoose-1));
			vector<Observation*> resps = n.getResponses();
			for(unsigned int i=0; i<resps.size();i++){
				cout<<(i+1)<<")"<<(*(resps.at(i))).getName()<<endl;
			}
			cout<<"type \"back\" to go back"<<endl<<endl;
			int respchoose = getUserInput(resps.size());
			if(respchoose==-1){
				continue;
			}
			Observation *o = (resps.at(respchoose-1));
			cout<<(*o).getDescription()<<endl;
			update_game(o,p);
			continue;
			
		}
		/*if(input==4){
			cout<<"Player "<<(*p).getName()<<" is in area "<<(*(*p).getCurrentRoom()).getName()<<endl<<endl;
			continue;
		}*/
		if(input==4){
			(*(*p).getCurrentRoom()).printDescription();
		}
	}


}