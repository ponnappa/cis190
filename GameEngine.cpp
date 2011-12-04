//Game Engine
#include <vector>
#include <string>
#include <iostream>
using namespace std;


int getUserInput(int n){

	string in;
	while(true){
        	cout<<"Please enter a selection from 1 to " <<n<<endl;
        	cin>>in;
        	if (in.compare("q")==0) exit(0);
        	for(int i=1;i<=n;i++){
	            if (atoi(in.c_str())==i) return atoi(in.c_str());
	        }
    }
    
}



int main(){

	Room *r = new Room("Bedroom");
	Player *p = new Player("John",r);
	cout<<"player "<<(*p).getName()<<" in room "<<(*(*p).getCurrentRoom()).getName()<<endl;
	int in = getUserInput(5);
    
	cout<<in<<endl;

	return 0;
}