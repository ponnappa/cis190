# Here is an example of a Makefile that uses variables to define everything.
# This provides a layer of abstraction, and is helpful if you ever want to
# change names of files, compilers, flags, etc. You only have to change them
# once.

CC                   = g++
FLAGS                = -Wall -g -c -O2 #is one of gcc's optimization flags

all: Item.o Observation.o Npc.o Player.o Room.o Game.o GameEngine.o MysteryGame

Item.o: Item.cpp
	$(CC) $(FLAGS) -o Item.o Item.cpp

Observation.o: Observation.cpp
	$(CC) $(FLAGS) -o Observation.o Observation.cpp

Observation.o: Observation.h Item.h Game.h

Npc.o: Npc.cpp
	$(CC) $(FLAGS) -o Npc.o Npc.cpp

Npc.o: Npc.h Observation.h Game.h

Player.o: Player.cpp
	$(CC) $(FLAGS) -o Player.o Player.cpp

Player.o: Player.h Room.h Item.h Observation.h

Room.o: Room.cpp 
	$(CC) $(FLAGS) -o Room.o Room.cpp

Room.o: Room.h Npc.h Item.h Observation.h Game.h

Game.o: Game.cpp
	$(CC) $(FLAGS) -o Game.o Game.cpp

Game.o: Game.h Player.h Observation.h

GameEngine.o: GameEngine.cpp
	$(CC) $(FLAGS) -o GameEngine.o GameEngine.cpp

GameEngine.o: Game.h Player.h Observation.h Room.h Npc.h Item.h

MysteryGame: GameEngine.o Game.o Room.o Player.o Npc.o Observation.o Item.o	
	$(CC) -Wall -g -o MysteryGame GameEngine.o Game.o Room.o Player.o Npc.o Observation.o Item.o

clean:
	rm -f Game.o GameEngine.o Item.o Npc.o Observation.o Player.o Room.o 
	
cleanest: clean
	rm -f MysteryGame