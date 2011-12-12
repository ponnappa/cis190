//Game Engine
#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include "Player.cpp"

using namespace std;

int getUserInput(int n){

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


int main(){
	string s;
	Room *r = new Room("Bedroom");
	Room *at = new Room("Attic");
	Room *ha = new Room("Hall");
	(*r).addExit(at);
	(*at).addExit(r);//fix addExit to duplicate
	(*r).addExit(ha);
	(*ha).addExit(r);
	Player *p = new Player("John",r);
	cout<<"player "<<(*p).getName()<<" in area "<<(*(*p).getCurrentRoom()).getName()<<endl;
	
	while(true){
		cout<<"1)Move"<<endl;
		cout<<"2)Observe area"<<endl;
		cout<<"3)Talk to people"<<endl;
		cout<<"4)Look at journal"<<endl;
		cout<<"5)Get Description"<<endl;
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
			continue;
		}
		if(input==3){
			continue;
		}
		if(input==4){
			cout<<"Player "<<(*p).getName()<<" is in area "<<(*(*p).getCurrentRoom()).getName()<<endl<<endl;
			continue;
		}
		if(input==5){
			(*(*p).getCurrentRoom()).getDescription();
		}
	}
	


	return 0;
}