/** Program Name: Street.cpp
 ** Author: Thomas Fattah
 ** Date: 2019-08-06
 ** Description: Definition file for Street class, which is inherited from Space. Simulates the "Street" location in "Earl."
 */

#include "Street.hpp"
#include "inputValidation.hpp"
using std::cout;
using std::endl;

// default constructor which calls Space constructor, setting name to location name. Sets yelled and trash bool to false
Street::Street(std::string name)
	: Space(name), yelled(false), trash(false)
{
}

// Overriden from Space. Accepts as a parameter, an Earl reference object. Prompts user for input and validates that
// input with getInt() from inputValidation.hpp Depending on user input, calls playInTraffic(), yell(), or
// digThroughTrash(). playInTraffic() is a parameter for setHealth() on earlObj. yell() is a parameter for
// setConfidence() on earlObj. digThroughTrash() is a parameter for setCash() on earlObj.
void Street::interact(Earl &earlObj)
{
	cout << "You're on a street. What do you want to interact with?" << endl;
	cout << "1. Play in traffic" << endl;
	cout << "2. Yell into the night sky" << endl;
	cout << "3. Dig through a trash can" << endl;
	cout << "4. Move to the next area" << endl;

	int choice = 0;
	while(choice < 1 || choice > 4)
	{
		choice = getInt();
		if(choice < 1 || choice > 4)
		{
			cout << "Quit messing around. Enter a number 1 through 4. Earl's hungry!" << endl;
		}
	}
	if(choice == 4)
	{
		cout << "You decide to leave the street." << endl;
	}

	while(choice != 4)
	{
		switch (choice)
		{
			case 1:
				earlObj.setHealth(playInTraffic());
				break;
			case 2:
				earlObj.setConfidence(yell());
				break;
			case 3:
				int loopRun = digThroughTrash();
				for(int i=0; i < loopRun; i++)
				{
					earlObj.setCash();
				}
				break;
		}
		cout << "\nYou're still on a street. What do you want to interact with?" << endl;
		cout << "1. Play in traffic" << endl;
		cout << "2. Yell into the night sky" << endl;
		cout << "3. Dig through a trash can" << endl;
		cout << "4. Move to the next area" << endl;
		choice = getInt();
		if(choice < 1 || choice > 4)
		{
			cout << "Quit messing around. Enter a number 1 through 4. Earl's hungry!" << endl;
		}
		if(choice == 4)
		{
			cout << "You decide to leave the street." << endl;
		}
	}
}

// returns a random number from 1 through 4 and returns the negative of it
int Street::playInTraffic()
{
	int damage = rand() % 4 + 1;
	cout << "Earl decides to run into the street, but he doesn't quite make it and is hit by a rogue stop sign. He "
		 "loses " << damage << " health." << endl;
	return -damage;
}

// if !yelled returns -1 and sets yelled to true, otherwise returns 0
int Street::yell()
{
	int conf = 0;

	if(!yelled)
	{
		cout << "Earl shouts at the moon. He notices people crossing to the other side of the street. He loses "
		  "confidence." << endl;
		conf = -1;
		yelled = true;
		return conf;
	}
	else
	{
		cout << "Earl yells into the night sky. He feels at peace." << endl;
		return 0;
	}
}

// chance returns a random int from 1 through 3. If !trash, returns 1, 4, or 0 and sets trash to true. Otherwise return 0
int Street::digThroughTrash()
{
	int chance = rand() % 3 + 1;
	int money = 0;

	if(!trash)
	{
		cout << "Earl digs through the trash can. He finds ";

		switch (chance)
		{
			case 1:
				cout << "a buck. Sweet!" << endl;
				money = 1;
				break;
			case 2:
				cout << "four bucks. Pay day!" << endl;
				money = 4;
				break;
			case 3:
				cout << "nothing but an empty feeling in his heart. Poor Earl." << endl;
				break;
		}
		trash = true;
	}
	else
	{
		cout << "Earl has already gotten the best stuff out of there." << endl;
	}

	return money;
}

// Overriden from Space. Accepts as a parameter, an Earl reference object. Prompts user for input and validates that
// input with getInt() from inputValidation.hpp Depending on user input, calls flingBooger() or runAway() if !fightDone,
// otherwise does nothing.
void Street::fight(Earl &earlObj)
{
	if(!fightDone)
	{
		cout << "But a scary looking shadow blocks his path. Time to fight!" << endl;
		cout << "***********************************" << endl;
		// courtesy of http://www.patorjk.com/software/taag/#p=display&f=Small&t=BATTLE!
		cout << "  ___   _ _____ _____ _    ___ _ \n"
				" | _ ) /_\\_   _|_   _| |  | __| |\n"
				" | _ \\/ _ \\| |   | | | |__| _||_|\n"
				" |___/_/ \\_\\_|   |_| |____|___(_)\n"
				"                                 " << endl;
		cout << "***********************************" << endl;
		cout << "Earl has " << earlObj.getBoogers() << " boogers. What do you want to do?" << endl;
		cout << "1. Fling a booger" << endl;
		cout << "2. Run away" << endl;
		int choice = 0;
		while(choice < 1 || choice > 2)
		{
			choice = getInt();
			if(choice < 1 || choice > 2)
			{
				cout << "Enter only 1 or 2." << endl;
			}
		}
		switch (choice)
		{
			case 1:
				if(earlObj.getBoogers() > 0)
				{
					earlObj.flingBooger();
					cout << "Earl can't bear to see the result and runs along. It's a success story, of sorts." << endl;
					break;
				}
				else
				{
					cout << "Earl has no boogers right now." << endl;
				}
			case 2:
				earlObj.runAway();
		}
		fightDone = true;
	}
}

// cout some information about the location
void Street::displayLocationInfo()
{
	cout << "================================================================================================" << endl;
	cout << "Earl finds himself on a street. One of many on the way to Taco Terrace. Let's try not to make a fool of"
			" ourselves." << endl;
}