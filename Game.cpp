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

void Game::setup(){
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
	(*lab).addExit(quad);
	
	/*create Items
	Item *computer = new Item("computer");
	Item *notes = new Item("class notes");
	
	Item *vending = new Item("vending machine");
	Item *door = new Item("door to your room");

	Item *knife = new Item("knife");
	Item *squirrel = new Item("squirrel");
	
	Item *printer = new Item("printer");
	Item *chair = new Item("char");*/
	
	//create observations
	Observation *computer_obs = new Observation("computer","You computer has a blue screen of death",this);
	Observation *notes_obs = new Observation("class notes","There is mentioning of a project due in CIS190",this);
	
	Observation *vending_obs1 = new Observation("vending machine","A 75 cent soda would be delicious.",this);
	(*vending_obs1).addTrigger(8,false);   //8 - have a soda
	(*vending_obs1).addChange(3,true);
	
	Observation *vending_obs1a = new Observation("vending machine","Your thirst has been quenched.",this);
	(*vending_obs1a).addTrigger(8,true);   //8 - have a soda


	Observation *vending_obs2 = new Observation("vending maching","You pay 75 cents for a soda.",this);
	(*vending_obs2).addTrigger(8,false);
	(*vending_obs2).addTrigger(5, true); // 5 - have 3 quarters
	(*vending_obs2).addTrigger(7,false);//7 - have 4 dollars
	(*vending_obs2).addChange(5,false);
	(*vending_obs2).addChange(8,true); //8- haev soda
	
	Observation *vending_obs3 = new Observation("vending maching","You pay 75 cents for a soda.",this);
	(*vending_obs3).addTrigger(8,false);
	(*vending_obs3).addTrigger(5,true); // 5 - have 3 quarters
	(*vending_obs3).addTrigger(7,true);//7 - have 4 dollars
	(*vending_obs3).addChange(5,false);
	(*vending_obs3).addChange(8,true);
	(*vending_obs3).addChange(12,true); //12 -have soda and 4 dollars
	
	Observation *door_obs = new Observation("door to your room", "You notice that while other doors have student name tags, yours does not",this);
	
	Observation *knife_obs = new Observation("knife","A shiny knife.",this);
	Observation *squirrel_obs = new Observation("squirrel","It asks you for an acorn.",this);
	
	Observation *printer_obs = new Observation("printer","The printer is not plugged in.",this);
	Observation *chair_obs = new Observation("chair","I love chairs!",this);
	
	
	
	
	
	/*add items to observations
	(*computer_obs).addItem(computer);
	(*notes_obs).addItem(notes);
	
	(*vending_obs).addItem(vending);
	(*door_obs).addItem(door);
	
	(*knife_obs).addItem(knife);
	(*squirrel_obs).addItem(squirrel);
	
	(*printer_obs).addItem(printer);
	(*chair_obs).addItem(chair);*/
	
	//add observations to rooms
	(*br).addObservation(computer_obs);
	(*br).addObservation(notes_obs);
	(*hall).addObservation(vending_obs1);
	(*hall).addObservation(vending_obs1a);
	(*hall).addObservation(vending_obs2);
	(*hall).addObservation(vending_obs3);
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
	state[0]=false;  //talked to bob
	//state[1] =true;
    
	Observation *bob1= new Observation("Hey","hi im bob im your roommate i think you're pretty cool",this);
    (*bob1).addTrigger(0,false);
	(*bob1).addChange(0,true);
	//(*bob1).addChange(1,true);
	
	Observation *bob2= new Observation("Hey","leave me alone",this);
	(*bob2).addTrigger(0,true);
	
	
	(*bob).addResponse(bob1);
	(*bob).addResponse(bob2);
	
	    //nursing student
	Observation *nurse1 = new Observation("Hey","la dee dah dee dah nothing to see here",this);
	(*nurse).addResponse(nurse1);
	
	    //random student
	Observation *wharton1 = new Observation("Hey","herp derp finance accounting herp derp",this);
	(*wharton).addResponse(wharton1);
	
	
    ///////////////Zach Zarrow
	state[1]=false; //Zach knows you need money
	state[2]=false; //have talked to Zach
	state[3]=false; //you know you need money
	state[4]=false; //danced for zach
	state[5]=false; //have 3 quarters
	
	Observation *zach1 = new Observation ("Hey", "Hi, I'm Zach Zarrow. You look familiar. I think you're in my class.",this);
	(*zach1).addTrigger(2,false);
	(*zach1).addChange(2,true);
	
	Observation *zach2 = new Observation ("Ask about name", "I could probably tell your first name if you can tell me your last name.",this);
	
	Observation *zach3 = new Observation ("Ask about money", "I'll give you 75 cents if you dance for me.",this);
	(*zach3).addTrigger(3,true);
	(*zach3).addTrigger(4,false);
	(*zach3).addChange(1,true);
	
	Observation *zach4 = new Observation ("Dance for Zach", "You're pathetic. Here's your money",this);
	(*zach4).addTrigger(1,true);
	(*zach4).addTrigger(4,false);
	(*zach4).addChange(4,true);
	(*zach4).addChange(5,true);
	
	Observation *zach5 = new Observation("Hey", "Good luck figuring out your name. Remember I can always tell you your last name.",this);
	(*zach5).addTrigger(5,true);
	
	(*zach).addResponse(zach1);
	(*zach).addResponse(zach2);	
	(*zach).addResponse(zach3);
	(*zach).addResponse(zach4);
	(*zach).addResponse(zach5);
	
	
    /////////////////////Troll
    state[6]=false; //have talked to the troll
    state[7]=false; //have 4 dollars
    state[8]=false; //have a soda
    state[9]=false; //know your name
    state[10]=false; //PLACEHOLDER
    state[11]=false; //PLACEHOLDER
    state[12]=false; //have 4 dollars and a soda
    
    
    Observation *troll1 = new Observation("Hey","Hi, I'm LaPlace's Demon. I can tell you your name if you do me a small favor.\nBring me 4 dollar and a can of soda and I'll tell you your name.",this);
    (*troll1).addTrigger(6,false);
    (*troll1).addChange(6,true);
    
    
    Observation *troll2 = new Observation("What's my name?","You need to fetch me the money and the soda before I reveal this.",this);
    (*troll2).addTrigger(7,false);
	(*troll2).addTrigger(8,false);
	
	Observation *troll2a = new Observation("What's my name?","You need to fetch me the money before I reveal this.",this);
    (*troll2a).addTrigger(7,false);
	(*troll2a).addTrigger(8,true);
	
	Observation *troll2b = new Observation("What's my name?","You need to fetch me the soda before I reveal this.",this);
    (*troll2b).addTrigger(7,true);
	(*troll2b).addTrigger(8,false);
    
    
    Observation *troll3 = new Observation("What's my name?","Your name is Jinesh Desai",this);
    (*troll3).addTrigger(7, true);
    (*troll3).addTrigger(8,true);
    (*troll3).addChange(9,true);
	
	(*troll).addResponse(troll1);
	(*troll).addResponse(troll2);
	(*troll).addResponse(troll2a);
	(*troll).addResponse(troll2b);
	(*troll).addResponse(troll3);
	
	//////////////////ITA Manager
	state[13]=true; //haven't talked to ITA manager
	state[14]=true; //haven't asked about money
	state[15]=false; //have helped student1
	state[16]=false; //have helped student2
	
	Observation *ita1 = new Observation("Hey","Hi, I'm the ITA manager here. You look vaguely familiar. \nYou must be an ITA. Why don't you help those students with their computer problems.",this);
	(*ita1).addTrigger(13, true);
	(*ita1).addChange(13,false);
	
	Observation *ita2 = new Observation("Money","Thanks for helping them. Here have 4 dollars.",this);
	(*ita2).addTrigger(15,true);
	(*ita2).addTrigger(16,true);
	(*ita2).addTrigger(7,false);
	(*ita2).addChange(7,true);
	
	Observation *ita2a = new Observation("Hey","Thanks for helping those students.",this);
	(*ita2a).addTrigger(15,true);
	(*ita2a).addTrigger(16,true);
	(*ita2a).addTrigger(7,true);
	
	Observation *ita3 = new Observation("Money","You still haven't helped all the students.",this);
	(*ita3).addTrigger(15,true);
	(*ita3).addTrigger(16,false);
	
	Observation *ita4 = new Observation("Money","You still haven't helped all the students.",this);
	(*ita4).addTrigger(15,false);
	(*ita4).addTrigger(16,true);
	
	Observation *ita5 = new Observation("Money","You still haven't helped all the students.",this);
	(*ita5).addTrigger(15,false);
	(*ita5).addTrigger(16,false);
	
	(*itaman).addResponse(ita1);
	(*itaman).addResponse(ita2);
	(*itaman).addResponse(ita2a);
	(*itaman).addResponse(ita3);
	(*itaman).addResponse(ita4);
	(*itaman).addResponse(ita5);
	
	/////////////////////Student1
	state[17]=false; //have talked to student1
	state[18]=false; //option: pour water on it is available
	state[19]=false; //option: buy a new computer is available
	state[20]=false; //option: press the power button is available
	state[21]=false; //option: STFU AND DIE is available
	
	Observation *student11 = new Observation("Do you need help?","Yes, how do I turn on this computer?",this);
	(*student11).addTrigger(17,false);
	(*student11).addChange(17,true);
	(*student11).addChange(18,true);
	(*student11).addChange(19,true);
	(*student11).addChange(20,true);
	(*student11).addChange(21,true);
	
	Observation *student12 = new Observation("Pour water on it.","That didn't work so well.",this);
	(*student12).addTrigger(18,true);
	
	Observation *student13 = new Observation("Buy a new computer.","Are you kidding me? I can't afford that.",this);
	(*student13).addTrigger(19,true);
	
	Observation *student14 = new Observation("Press the power button","Wow, that worked great! Thanks mister!",this);
	(*student14).addTrigger(20,true);
	(*student14).addChange(15,true);
	(*student14).addChange(18,false);
	(*student14).addChange(19,false);
	(*student14).addChange(20,false);
	(*student14).addChange(21,false);
	
	Observation *student15 = new Observation("STFU AND DIE!","Geez settle down.",this);
	(*student15).addTrigger(21,true);
	
	Observation *student16 = new Observation("Do you need help?","Nope, you solved my problem",this);
	(*student16).addTrigger(15,true);
	
	(*student1).addResponse(student11);
	(*student1).addResponse(student12);
	(*student1).addResponse(student13);
	(*student1).addResponse(student14);
	(*student1).addResponse(student15);
	(*student1).addResponse(student16);
	
	
	/////////////////////Student2
	state[22]=false; //have talked to student2
	state[23]=false; //option: out of ink is available
	state[24]=false; //option: not plugged in is available
	state[25]=false; //option: out of paper is available
	
	Observation *student21 = new Observation("Do you need help?","Why can't I print?",this);
	(*student21).addTrigger(22,false);
	(*student21).addChange(22,true);
	(*student21).addChange(23,true);
	(*student21).addChange(24,true);
	(*student21).addChange(25,true);
	
	Observation *student22 = new Observation("The printer is out of ink","Wait, no it isn't...",this);
	(*student22).addTrigger(23,true);
	
	Observation *student23 = new Observation("The printer is not plugged in","Wow, you're right. I feel like an idiot. Thanks.",this);
	(*student23).addTrigger(24,true);
	(*student23).addChange(16,true);
	(*student23).addChange(23,false);
	(*student23).addChange(24,false);
	(*student23).addChange(25,false);
	
	Observation *student24 = new Observation("The printer is out of paper","Dude it has plenty of paper.",this);
	(*student24).addTrigger(25,true);
	
	Observation *student25 = new Observation("Do you need help?","Nope, you solved my problem",this);
	(*student25).addTrigger(16,true);

	
	(*student2).addResponse(student21);
	(*student2).addResponse(student22);
	(*student2).addResponse(student23);
	(*student2).addResponse(student24);
	(*student2).addResponse(student25);
	
	
	
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
	p = new Player("UnknownName",br);

	cout<<"player "<<(*p).getName()<<" in area "<<(*(*p).getCurrentRoom()).getName()<<endl;

}





void Game::run(){
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
				return;
			(*p).setCurrentRoom(ex.at(movein-1));
			return;
		}
		if(input==2){
			vector<Observation*> obs = (*(*p).getCurrentRoom()).getObservations();
			for(unsigned int i=0; i<obs.size();i++){
				cout<<(i+1)<<")"<<(*(obs.at(i))).getName()<<endl;
			}
			cout<<"type \"back\" to go back"<<endl<<endl;
			int playobs = getUserInput(obs.size());
			if(playobs==-1){
				return;
			}
			
			Observation *o = (obs.at(playobs-1));
			cout<<(*o).getDescription()<<endl;
			updateGame(o,p);
			return;
		}
		if(input==3){
			vector<Npc*> npcs = (*(*p).getCurrentRoom()).getNpcs();
			for(unsigned int i=0; i<npcs.size();i++){
				cout<<(i+1)<<")"<<(*(npcs.at(i))).getName()<<endl;
			}
			cout<<"type \"back\" to go back"<<endl<<endl;
			int npcchoose = getUserInput(npcs.size());
			if(npcchoose==-1){
				return;
			}
			Npc n = *(npcs.at(npcchoose-1));
			vector<Observation*> resps = n.getResponses();
			for(unsigned int i=0; i<resps.size();i++){
				cout<<(i+1)<<")"<<(*(resps.at(i))).getName()<<endl;
			}
			cout<<"type \"back\" to go back"<<endl<<endl;
			int respchoose = getUserInput(resps.size());
			if(respchoose==-1){
				return;
			}
			Observation *o = (resps.at(respchoose-1));
			cout<<(*o).getDescription()<<endl;
			updateGame(o,p);
			return;
			
		}
		if(input==4){
			cout<<"Player "<<(*p).getName()<<" is in area "<<(*(*p).getCurrentRoom()).getName()<<endl<<endl;
			return;
		}
	}