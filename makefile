### Program Name: makefile
### Author: Thomas Fattah
### Date: 8/5/19
### Description: makefile for Final Project, which compiles and cleans relevant files. Can also run valgrind.

CXX = g++
CXXFLAGS = -g
CXXFLAGS += -Wall
DEPS = inputValidation.hpp Earl.hpp Space.hpp House.hpp Street.hpp BusStation.o Bus.hpp Mall.o GasStation.o TacoTerrace.hpp
objects = main.o inputValidation.o Menu.o Space.o House.o Street.o BusStation.o Bus.o Mall.o GasStation.o TacoTerrace.o Earl.o Game.o
filename = earl


$(filename): $(objects)
	$(CXX) -std=c++11 $(objects) $(CXXFLAGS) -o $(filename)

main.o: main.cpp Menu.hpp
	$(CXX) -std=c++11 -c main.cpp

inputValidation.o: inputValidation.cpp
	$(CXX) -std=c++11 -c inputValidation.cpp

Menu.o: Menu.cpp Menu.hpp inputValidation.hpp Game.hpp
	$(CXX) -std=c++11 -c Menu.cpp

Space.o: Space.cpp Space.hpp
	$(CXX) -std=c++11 -c Space.cpp

House.o: House.cpp House.hpp Space.hpp
	$(CXX) -std=c++11 -c House.cpp

Street.o: Street.cpp Street.hpp Space.hpp
	$(CXX) -std=c++11 -c Street.cpp

BusStation.o: BusStation.cpp BusStation.hpp Space.hpp
	$(CXX) -std=c++11 -c BusStation.cpp

Bus.o: Bus.cpp Bus.hpp Space.hpp
	$(CXX) -std=c++11 -c Bus.cpp

Mall.o: Mall.cpp Mall.hpp Space.hpp
	$(CXX) -std=c++11 -c Mall.cpp

GasStation.o: GasStation.cpp GasStation.hpp Space.hpp
	$(CXX) -std=c++11 -c GasStation.cpp

TacoTerrace.o: TacoTerrace.cpp TacoTerrace.hpp Space.hpp
	$(CXX) -std=c++11 -c TacoTerrace.cpp

Earl.o: Earl.cpp Earl.hpp
	$(CXX) -std=c++11 -c Earl.cpp

Game.o: Game.cpp Game.hpp $(DEPS)
	$(CXX) -std=c++11 -c Game.cpp

clean:
	rm *.o $(filename)

valgrind:
	valgrind --leak-check=full ./$(filename)