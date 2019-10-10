all: team

team: main.o Team.o Node.o Character.o Vampire.o Barbarian.o BlueMen.o Medusa.o HarryPotter.o
	g++ -std=c++11 main.o Team.o Node.o Character.o Vampire.o Barbarian.o BlueMen.o Medusa.o HarryPotter.o -o team

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Team.o: Team.cpp
	g++ -std=c++11 -c Team.cpp

Node.o: Node.cpp
	g++ -std=c++11 -c Node.cpp

Character.o: Character.cpp
	g++ -std=c++11 -c Character.cpp

Vampire.o: Vampire.cpp
	g++ -std=c++11 -c Vampire.cpp

Barbarian.o: Barbarian.cpp
	g++ -std=c++11 -c Barbarian.cpp

BlueMen.o: BlueMen.cpp
	g++ -std=c++11 -c BlueMen.cpp

Medusa.o: Medusa.cpp
	g++ -std=c++11 -c Medusa.cpp

HarryPotter.o: HarryPotter.cpp
	g++ -std=c++11 -c HarryPotter.cpp

zip:
	zip Project4_Lee_David.zip -D *.cpp *.hpp *.pdf makefile 

clean:
	rm *.o team