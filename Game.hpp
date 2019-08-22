/** Program Name: Game.hpp
 ** Author: Thomas Fattah
 ** Date: 2019-08-06
 ** Description: Header file for Game class, which simulates a Game of Earl. #includes Earl class, Space class, and
 ** all classes derived from Space. Contains data members for an Earl object, Space pointers, and a boolean to continue
 ** or stop gameplay.
 */

#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "Earl.hpp"
#include "Space.hpp"
#include "House.hpp"
#include "Street.hpp"
#include "BusStation.hpp"
#include "Bus.hpp"
#include "Mall.hpp"
#include "GasStation.hpp"
#include "TacoTerrace.hpp"

class Game
{
private:
	Earl earl;
	Space* head;
	Space* tail;
	Space* tailWest;
	Space* current;
	bool keepPlaying;
public:
	Game();
	~Game();
	void start();
	void displayStats();
	void generateWorld();
	void move();
	void showMap();
	void gamePlay();
	bool quitMenu();
};

#endif //GAME_HPP
