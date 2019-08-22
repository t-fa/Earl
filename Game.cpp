/** Program Name: Game.cpp
 ** Author: Thomas Fattah
 ** Date: 2019-08-06
 ** Description: Definition file for Game class, which simulates a Game of Earl. #includes Earl class, Space class, and
 ** all classes derived from Space. Contains data members for an Earl object, Space pointers, and a boolean to continue
 ** or stop gameplay.
 */

#include "inputValidation.hpp"
#include "Game.hpp"
using std::cout;
using std::endl;

// default constructor which sets all Space pointers to nullptr and keepPlaying to true
Game::Game()
	: head(nullptr), tail(nullptr), tailWest(nullptr), current(nullptr), keepPlaying(true)
{
}

// Calls generateWorld(), couts some game info, and calls gamePlay()
void Game::start()
{
	generateWorld();
	displayStats();
	cout << "The objective is to make it to Taco Terrace with at least 3 bucks. You'll need money to buy tacos. Earl's "
		 "an honest man. He's not about to steal. You'll have various opportunities to earn more cash." << endl;
	cout << "\nEarl's main stat is hunger. Every time Earl enters a new space, he loses 5 hunger. If it falls to 0, "
		 "it's game over. Throughout the game, you might find snacks to help stave off hunger. Don't let Earl down."
		 << endl;
	cout << "\nEarl's primary attack method is flinging boogers. It's not very painful, but it usually makes Earl's "
		 "enemies leave him alone. Boogers can be found in a variety of places. Earl can carry at most 5 boogers."
		 << endl;
	cout << "\nEarl's health stat shows how much health he has remaining. Earl will face various obstacles which will"
		 " diminish his health. If it falls to 0, it's game over. Earl doesn't like blood, so be careful, ok?" << endl;
	cout << "\nFinally, there's Earl's confidence. If you finish the game with a high level of confidence, you'll get"
		 " a higher score. Plus, Earl will feel really great about himself, and you can't put a metric on that, can "
   "you?" << endl;
	gamePlay();
}

// Works with current Space*, which is used to traverse through each Space. While keepPlaying is true, calls
// displayLocationInfo(), interact(), and fight() on most Spaces. If Space is Bus Station, checks whether earl's
// busTicket boolean is true before allowing earl to move to Bus Space. If location is Taco Terrace, sets keepPlaying
// to false, to break out of while loop. Otherwise, calls move(), showMap(), quitMenu(), and displayStats(). Checks
// whether earl has enough hunger and health to continue playing.
void Game::gamePlay()
{
	while(keepPlaying)
	{
		current->displayLocationInfo();
		current->interact(earl);
		if(earl.getHealth() < 1)
		{
			cout << "Earl has died :(" << endl;
			keepPlaying = false;
		}
		current->fight(earl);
		if(earl.getHealth() < 1)
		{
			cout << "Earl has died :(" << endl;
			keepPlaying = false;
		}

		if(current->getLocation() == "Taco Terrace")
		{
			keepPlaying = false;
		}

		if(current->getLocation() == "Bus Station")
		{
			if(!earl.getBusTicket())
			{
				int busChoice = 0;
				cout << "\nPlease purchase a bus ticket if you wish to board the bus." << endl;
				cout << "You have " << earl.getCash() << " bucks. What do you want to do?" << endl;
				cout << "1. Buy a bus ticket and board the bus" << endl;
				cout << "2. Go back to Old New Mexico Street" << endl;
				while(busChoice < 1 || busChoice > 2)
				{
					busChoice = getInt();
					if(busChoice < 1 || busChoice > 2)
					{
						cout << "Enter only 1 or 2." << endl;
					}
					if(busChoice == 1 && earl.getCash() < 5)
					{
						cout << "Earl doesn't have enough money, dude!" << endl;
						busChoice = 0;
					}
				}
				if(busChoice == 1)
				{
					earl.buyBusTicket();
					current = current->getNorth();
					earl.setHunger(-5);
				}
				else if(busChoice == 2)
				{
					current = current->getWest();
					earl.setHunger(-5);
				}
			}
			else
			{
				if(keepPlaying)
				{
					move();
					showMap();
				}
			}
		}
		else
		{
			if(keepPlaying)
			{
				move();
				showMap();
			}
		}

		if(earl.getHunger() < 1)
		{
			cout << "Earl is too hungry to carry on." << endl;
			keepPlaying = false;
		}
		if(keepPlaying)
		{
			keepPlaying = quitMenu();
		}
		displayStats();
	}
}

// Called at the beginning of each new location. Prompts the user if they would like to keep playing. If no, is used
// to set keepPlaying to false in gamePlay(). Validates input with getInt() from inputValidation.hpp
bool Game::quitMenu()
{
	int quit = 0;
	cout << "Keep playing?" << endl;
	cout << "1. Yes" << endl;
	cout << "2. No" << endl;
	while(quit < 1 || quit > 2)
	{
		quit = getInt();
		if(quit < 1 || quit > 2)
		{
			cout << "Enter 1 or 2 only." << endl;
		}
	}
	if(quit == 1)
	{
		return true;
	}
	else if(quit == 2)
	{
		return false;
	}
}

// users earl's getter functions to display his stats at the start of each level
void Game::displayStats()
{
	cout << "=============================" << endl;
	cout << "These are Earl's stats: " << endl;
	cout << "Cash: " << earl.getCash() << " bucks" << endl;
	cout << "Hunger: " << earl.getHunger() << endl;
	cout << "Boogers: " << earl.getBoogers() << endl;
	cout << "Health: " << earl.getHealth() << endl;
	cout << "Confidence: " << earl.getConfidence() << endl;
	cout << "=============================" << endl;
}

// Creates a linked list, where each Space has 4 pointers to other Spaces (often nullptr). Is used at the start of
// the game to generate the linked list structure used to simulate the world Earl lives in. A visual representation
// of this world is in showMap().
void Game::generateWorld()
{
	// House with all 4 directions null
	head = new House();
	tail = head;
	current = head;

	// street
	tail = new Street("Old New Mexico St");
	tail->setSouth(head);
	head->setNorth(tail);
	tailWest = tail; //tailWest == street

	// bus station
	tail = new BusStation();
	tail->setWest(tailWest);
	tailWest->setEast(tail);
	Space* copyPtr = tail;

	// bus
	tail = new Bus();
	tail->setSouth(copyPtr);
	copyPtr->setNorth(tail);
	copyPtr = tail;

	// taco terrace
	tail = new TacoTerrace();
	tail->setSouth(copyPtr);
	copyPtr->setNorth(tail);
	copyPtr = tailWest;

	// mall
	tailWest = new Mall();
	tailWest->setEast(copyPtr);
	copyPtr->setWest(tailWest);
	copyPtr = tailWest;

	// street 2
	tailWest = new Street("Garbage St");
	tailWest->setSouth(copyPtr);
	copyPtr->setNorth(tailWest);
	copyPtr = tailWest;

	// gas station
	tailWest = new GasStation();
	tailWest->setSouth(copyPtr);
	copyPtr->setNorth(tailWest);

	// link west to tail
	tailWest->setEast(tail);
	tail->setEast(tailWest);
}

// An ASCII representation of the world Earl lives in. Calls a getter to display which Space Earl is currently in.
void Game::showMap()
{
	cout << "=====================" << endl;
	cout << "======World Map======" << endl;
	cout << "=====================" << endl;
	cout << endl;
	cout << "Earl is currently in: " << current->getLocation() << endl;
	cout << endl;
	cout << "################   ################" << endl;
	cout << "#              #   #              #" << endl;
	cout << "# Gas Station  #---# TACO TERRACE #-----------|" << endl;
	cout << "#              #   #              #           |" << endl;
	cout << "################   ################           |" << endl;
	cout << "        |                                     |" << endl;
	cout << "################                      ################" << endl;
	cout << "#    Garbage   #                      #              #" << endl;
	cout << "#    Street    #                      #      Bus     #" << endl;
	cout << "#              #                      #              #" << endl;
	cout << "################                      ################" << endl;
	cout << "        |                                     |" << endl;
	cout << "################   ################   ################" << endl;
	cout << "#              #   #    Old New   #   #              #" << endl;
	cout << "#     Mall     #---# Mexico Street#---#  Bus Station #" << endl;
	cout << "#              #   #              #   #              #" << endl;
	cout << "################   ################   ################" << endl;
	cout << "                           |       " << endl;
	cout << "                   ################" << endl;
	cout << "                   #              #" << endl;
	cout << "                   # Earl's House #" << endl;
	cout << "                   #              #" << endl;
	cout << "                   ################" << endl;
}

// Provides user with option to traverse the linked list in each of the possible directions. Uses bools one, two,
// three, four to verify that that direction is not set to nullptr, otherwise displays location and allows user to
// pick that location. If northern location is Bus, makes sure user has purchased a bus ticket before allowing that
// as a choice. After a successful move, updates Earl's hunger by subtracting 5 hunger with setHunger().
void Game::move()
{
	bool one = false;
	bool two = false;
	bool three = false;
	bool four = false;
	int choice = 0;

	cout << "\n---------------------------------------" << endl;
	cout << "Which direction would you like to move?" << endl;
	cout << "Available directions: " << endl;

	Space* copyPtr;

	if(current->getNorth() != nullptr)
	{
		copyPtr = current->getNorth();
		if(copyPtr->getLocation() == "Bus")
		{
			if(!earl.getBusTicket())
			{
				cout << "1. North - " << copyPtr->getLocation() << ". Please purchase a bus ticket." << endl;
				one = false;
			}
			else
			{
				cout << "1. North - " << copyPtr->getLocation() << endl;
				one = true;
			}
		}
		else
		{
			cout << "1. North - " << copyPtr->getLocation() << endl;
			one = true;
		}
	}
	if(current->getEast() != nullptr)
	{
		copyPtr = current->getEast();
		cout << "2. East - " << copyPtr->getLocation() << endl;
		two = true;
	}
	if(current->getSouth() != nullptr)
	{
		copyPtr = current->getSouth();
		cout << "3. South - " << copyPtr->getLocation() << endl;
		three = true;
	}
	if(current->getWest() != nullptr)
	{
		copyPtr = current->getWest();
		cout << "4. West - " << copyPtr->getLocation() << endl;
		four = true;
	}

	while(choice < 1 || choice > 4)
	{
		choice = getInt();
		if(choice < 1 || choice > 4)
		{
			cout << "Enter one of the listed choices." << endl;
		}

		switch (choice)
		{
			case 1:
				if(!one)
				{
					cout << "Invalid choice. Make a different selection." << endl;
					choice = 0;
				}
				else
				{
					current = current->getNorth();
					earl.setHunger(-5);
				}
				break;
			case 2:
				if(!two)
				{
					cout << "Invalid choice. Make a different selection." << endl;
					choice = 0;
				}
				else
				{
					current = current->getEast();
					earl.setHunger(-5);
				}
				break;
			case 3:
				if(!three)
				{
					cout << "Invalid choice. Make a different selection." << endl;
					choice = 0;
				}
				else
				{
					current = current->getSouth();
					earl.setHunger(-5);
				}
				break;
			case 4:
				if(!four)
				{
					cout << "Invalid choice. Make a different selection." << endl;
					choice = 0;
				}
				else
				{
					current = current->getWest();
					earl.setHunger(-5);
				}
				break;
		}
	}

}

// deletes all dynamically allocated Space objects
Game::~Game()
{
	// delete house
	Space* copyPtr = head;
	copyPtr = copyPtr->getNorth();
	delete head;
	head = nullptr;

	// street
	head = copyPtr; // head == street

	// bus station
	copyPtr = copyPtr->getEast();
	Space* nodePtr = copyPtr;
	copyPtr = copyPtr->getNorth();
	delete nodePtr;

	// bus - tail points to taco terrace
	delete copyPtr;
	copyPtr = nullptr;

	// back to street - moving to mall
	copyPtr = head;
	copyPtr = copyPtr->getWest();
	delete head;
	head = nullptr;

	// mall
	head = copyPtr;
	copyPtr = copyPtr->getNorth();
	delete head;

	// street 2 - tailWest points to gas station
	delete copyPtr;

	// gas station
	delete tailWest;

	// taco terrace
	delete tail;
}