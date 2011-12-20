#include "Game.h"
#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
/*#include "Observation.h"
#include "Player.h"
*/
using namespace std;


//constructor
Game::Game(){
    
    /*state[1]=false; // 1 talked to Zach Zarrow once
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
    state[12]=false; // 12 have 4 bucks*/
}

void Game::updateGame(Observation *o, Player *p){
	if((*o).hasTake()){
		(*p).removeItem((*o).removeTake());
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

    //create rooms
	Room *br = new Room("Bedroom", "This is your dorm room. It's rancid.",this);
	Room *hall = new Room("Hall","Halls are exciting places.",this);
	Room *quad = new Room("Quad", "What a pretty place the quad is.",this);
	Room *lab = new Room("Computer Lab", "Wewt.",this);
	
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
	Observation *computer_obs = new Observation("computer","You computer has a blue screen of death",this);
	Observation *notes_obs = new Observation("class notes","There is mentioning of a project due in CIS190",this);
	
	Observation *vending_obs = new Observation("vending machine","A soda would be delicious.",this);
	Observation *door_obs = new Observation("door to your room", "You notice that while other doors have student name tags, yours does not",this);
	
	Observation *knife_obs = new Observation("knife","",this);
	Observation *squirrel_obs = new Observation("squirrel","",this);
	
	Observation *printer_obs = new Observation("printer","out of ink",this);
	Observation *chair_obs = new Observation("chair","",this);
	
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
	Npc *bob = new Npc("Bob","You hate living with Bob.",this);
	
	Npc *nurse = new Npc("nursing student","The nursing student that lives down the hall. You forget her name too.",this);
	
	Npc *zach = new Npc("Zach Zarrow", "Zach Zarrow is a jolly good fellow.",this);
	Npc *wharton = new Npc("Whartonite", "He's wearing a suit.",this);
	Npc *troll = new Npc("troll", "The troll looks like he's in a trolling mood.",this);
	
	Npc *itaman = new Npc("ITA Manager", "The ITA manager is playing Starcraft.",this);
	Npc *student1 = new Npc("Student1", "This student is working at a computer.",this);
	Npc *student2 = new Npc("Student2", "This student is working at a computer.",this);
	
	//create "observations" that are npc dialogue
	
    ////////////bob
	state[0]=true;  //bob is happy
    state[1]=false; //have talked to bob
    
	Observation *bob1= new Observation("hey","hi im bob im your roommate i think you're pretty cool",this);
    (*bob1).addTrigger(0);
	(*bob1).addChange(0,false);
	(*bob1).addChange(1,true);
	
	Observation *bob2= new Observation("hey","leave me alone",this);
	(*bob2).addTrigger(1);
	
	
	(*bob).addResponse(bob1);
	(*bob).addResponse(bob2);
	
	    //nursing student
	Observation *nurse1 = new Observation("hey","la dee dah dee dah nothing to see here",this);
	(*nurse).addRespoinse(nurse1);
	
	    //random student
	Observation *wharton1 = new Observation("hey","herp derp finance accounting herp derp",this);
	(*wharton).addRespoinse(wharton1):
	
	
    ///////////////Zach Zarrow
	state[2]=true; //have not talked to Zach
	state[3]=false; //know you need money
	state[4]=false; //know zach will give you money
	state[5]=false; //have 3 quarters
	
	Observation *zach1 = new Observation ("hey", "Hi, I'm Zach Zarrow. You look familiar. I think you're in my class.",this);
	(*zach1).addTrigger(2);
	(*zach1).addChange(2,false);
	
	Observation *zach2 = new Observation ("ask about name", "I could probably tell your first name if you can tell me your last name.",this);
	
	Observation *zach3 = new Observation ("ask about money", "I'll give you 75 cents if you dance for me.",this);
	(*zach3).addTrigger(3);
	(*zach3).addChange(4,true);
	
	Observation *zach4 = new Observation ("dance for Zach", "You're pathetic. Here's your money",this);
	(zach4).addTrigger(4);
	(zach4).addChange(5,true);
	
	Observation *zach5 = new Observation("hey", "Good luck figuring out your name. Remember I can always tell you your last name.",this);
	(zach5).addTrigger(5);
	
	(*zach).addResponse(zach1);
	(*zach).addResponse(zach2);	
	(*zach).addResponse(zach3);
	(*zach).addResponse(zach4);
	(*zach).addResponse(zach5);
	
	
    /////////////////////Troll
    state[6]=true; //have not talked to the troll
    state[7]=false; //have 4 dollars
    state[8]=false; //have a soda
    state[9]=false; //know your name
    state[10]=true; //dont have 4 dollars
    state[11]=true; //dont have a soda
    state[12]=true; //dont have 4 dollars and a soda
    
    
    Observation *troll1 = new Observation("hey","Hi, I'm LaPlace's Demon. I can tell you your name if you do me a small favor.\nBring me 4 dollar and a can of soda and I'll tell you your name.",this);
    (*troll1).addTrigger(6);
    (*troll1).addChange(6,false);
    (*troll1).addChange(3,true);
    
    
    Observation *troll2 = new Observation("what's my name?","You need to fetch me the money and the soda before I reveal this.",this);
    (*troll2).addTrigger(12);
    
    
    Observation *troll3 = new Observation("what's my name?","Your name is Jinesh Desai",this);
    (*troll3).addTrigger(7);
    (*troll3).addTrigger(8);
    (*troll3).addChange(9);
	
	
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
		cout<<endl<<"1)Move"<<endl;
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
			
			Observation *o = (obs.at(playobs-1));
			cout<<(*o).getDescription()<<endl;
			updateGame(o,p);
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
			updateGame(o,p);
			continue;
			
		}
		if(input==4){
			cout<<"Player "<<(*p).getName()<<" is in area "<<(*(*p).getCurrentRoom()).getName()<<endl<<endl;
			continue;
		}
		/*if(input==4){
			(*(*p).getCurrentRoom()).printDescription();
		}*/
	}
}