/** Program Name: Mall.cpp
 ** Author: Thomas Fattah
 ** Date: 2019-08-09
 ** Description: Definition file for Mall class, which is inherited from Space. Simulates the "Mall" location in "Earl."
 */

#include "Mall.hpp"
#include "inputValidation.hpp"
using std::cout;
using std::endl;

// default constructor which calls Space constructor, setting "Mall" to location name. Sets clothes, food, and puppies
// bool to false
Mall::Mall()
	: Space("Mall"), clothes(false), food(false), puppies(false)
{
}

// Overriden from Space. Accepts as a parameter, an Earl reference object. Prompts user for input and validates that
// input with getInt() from inputValidation.hpp Depending on user input, calls tryClothes(), foodCourt(), or
// viewPuppies(). tryClothes() is a parameter for setConfidence() on earlObj. foodCourt() is a parameter for setHunger()
// on earlObj. viewPuppies() is a parameter for setHealth() on earlObj.
void Mall::interact(Earl &earlObj)
{
	cout << "You're at the mall. What do you want to interact with?" << endl;
	cout << "1. Try on clothes" << endl;
	cout << "2. Walk around the food court" << endl;
	cout << "3. Look at puppies" << endl;
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
		cout << "You decide to leave the mall." << endl;
	}

	while(choice != 4)
	{
		switch (choice)
		{
			case 1:
				earlObj.setConfidence(tryClothes());
				break;
			case 2:
				earlObj.setHunger(foodCourt());
				break;
			case 3:
				earlObj.setHealth(viewPuppies());
				break;
		}
		cout << "\nYou're still at the mall. What do you want to interact with?" << endl;
		cout << "1. Try on clothes" << endl;
		cout << "2. Walk around the food court" << endl;
		cout << "3. Look at puppies" << endl;
		cout << "4. Move to the next area" << endl;
		choice = getInt();
		if(choice < 1 || choice > 4)
		{
			cout << "Quit messing around. Enter a number 1 through 4. Earl's hungry!" << endl;
		}
		if(choice == 4)
		{
			cout << "You decide to leave the mall." << endl;
		}
	}
}

// Overriden from Space. Accepts as a parameter, an Earl reference object. Prompts user for input and validates that
// input with getInt() from inputValidation.hpp Depending on user input, calls flingBooger() or runAway() if !fightDone,
// otherwise does nothing.
void Mall::fight(Earl &earlObj)
{
	cout << "But a group of teenagers is playing hacky sack in front of the exit. Time to fight!" << endl;
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
				cout << "After the onslaught of boogers, the teenagers laugh and step aside." << endl;
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

// cout some information about the location
void Mall::displayLocationInfo()
{
	cout << "================================================================================================" << endl;
	cout << "Earl is at the Mall! He used to spend a lot of time here in his youth. Now a days, Abercrombie &"
		 " Fitch doesn't fit him like it used to." << endl;
}

// if !clothes, return 3 and set clothes to true, otherwise return 0
int Mall::tryClothes()
{
	if(!clothes)
	{
		cout << "Earl walks into a chic men's clothing store for dad bods. He tries on a sweet blazer and feels great "
				"about himself. He gains 3 confidence." << endl;
		clothes = true;
		return 3;
	}
	else
	{
		cout << "Earl doesn't want to waste any more time." << endl;
		return 0;
	}
}

// if !food return 2 and set food to true, otherwise return 0
int Mall::foodCourt()
{
	if(!food)
	{
		cout << "Earl walks through the food court and collects free samples of food. He gains 2 hunger." << endl;
		food = true;
		return 2;
	}
	else
	{
		cout << "Earl doesn't want to get stuffed before Taco Terrace." << endl;
		return 0;
	}
}

// if !puppies, return 2 and set puppies to true, otherwise return 0
int Mall::viewPuppies()
{
	if(!puppies)
	{
		cout << "Earl goes to the puppy store and pets some cute puppers. He gains 2 health." << endl;
		puppies = true;
		return 2;
	}
	else
	{
		cout << "Earl doesn't want to overstay his welcome." << endl;
		return 0;
	}
}