


all : game game_engine item npc observation player room

game : Game.cpp
	g++ -Wall -g -O2 -o game Game.cpp

game_engine : GameEngine.cpp
	g++ -Wall -g -O2 -o game_engine GameEngine.cpp

item: Item.cpp
	g++ -Wall -g -O2 -o item Item.cpp

npc : Npc.cpp
	g++ -Wall -g -O2 -o npc Npc.cpp

observation : Observation.cpp
	g++ -Wall -g -O2 -o observation Observation.cpp

player : Player.cpp
	g++ -Wall -g -O2 -o player Player.cpp

room : Room.cpp
	g++ -Wall -g -O2 -o room Room.cpp

clean :
	rm -f game game_engine item npc observation player room