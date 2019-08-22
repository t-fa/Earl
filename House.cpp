/** Program Name: House.cpp
 ** Author: Thomas Fattah
 ** Date: 2019-08-06
 ** Description: Definition file for Bus class, which is inherited from Space. Simulates the "House" location in "Earl."
 */

#include "inputValidation.hpp"
#include "House.hpp"
using std::cout;
using std::endl;
using std::string;

// default constructor which calls Space constructor, setting "Earl's House" to location name. Sets bathroom  and hair
// bool to false
House::House()
	: Space("Earl's House"), fridge(false), couch(false), hair(false)
{
	cout << "Earl appreciates that. Whelp. You're in this together now. Just you and Earl against the world." << endl;
}


// Overriden from Space. Accepts as a parameter, an Earl reference object. Prompts user for input and validates that
// input with getInt() from inputValidation.hpp Depending on user input, calls checkFridge(), checkUnderCouch(), or
// combHair(). checkFridge() is a parameter for setHunger() on earlObj. checkUnderCouch() is a parameter for setBoogers()
// on earlObj. combHair() is a parameter for setConfidence() on earlObj.
void House::interact(Earl& earlObj)
{
	cout << "You're in Earl's house. What do you want to interact with?" << endl;
	cout << "1. Check fridge" << endl;
	cout << "2. Check under couch" << endl;
	cout << "3. Comb hair" << endl;
	cout << "4. Move to the next area" << endl;

	int choice = 0;
	while(choice < 1 || choice > 4)
	{
		choice = getInt();
		if(choice < 1|| choice > 4)
		{
			cout << "Quit messing around. Enter a number 1 through 4. Earl's hungry!" << endl;
		}
	}
	if(choice == 4)
	{
		cout << "You decide to leave the house." << endl;
	}

	while(choice != 4)
	{
		switch (choice)
		{
			case 1:
				earlObj.setHunger(checkFridge());
				break;
			case 2:
				earlObj.setBoogers(checkUnderCouch());
				break;
			case 3:
				earlObj.setConfidence(combHair());
				break;
		}
		cout << "\nYou're still in Earl's house. What do you want to interact with?" << endl;
		cout << "1. Check fridge" << endl;
		cout << "2. Check under couch" << endl;
		cout << "3. Comb hair" << endl;
		cout << "4. Move to the next area" << endl;
		choice = getInt();
		if(choice < 1 || choice > 4)
		{
			cout << "Quit messing around. Enter a number 1 through 4. Earl's hungry!" << endl;
		}
		if(choice == 4)
		{
			cout << "You decide to leave the house." << endl;
		}
	}
}

// if !fridge has a random chance of returning -5, 7, or 0 and then sets fridge to true. Otherwise return 0
int House::checkFridge()
{
	int hungerModifier = 0;

	if(!fridge)
	{
		cout << "Earl checks the fridge. He finds ";
		int chance = rand() % 3 + 1;

		switch (chance)
		{
			case 1:
				cout << "a moldy mushroom. Gross! Earl loses 5 hunger." << endl;
				hungerModifier = -5;
				break;
			case 2:
				cout << "a piece of last night's pepperoni pizza. Awesome. Earl gains 7 hunger." << endl;
				hungerModifier = 7;
				break;
			case 3:
				cout << "nothing. Should've stocked up sooner. Classic Earl." << endl;
				hungerModifier = 0;
				break;
		}
		fridge = true;
		return hungerModifier;
	}
	else
	{
		cout << "You already checked the fridge." << endl;
		return 0;
	}
}

// if !couch has a random chance of returning 1, 3, or -1 and then sets couch to true. Otherwise return 0
int House::checkUnderCouch()
{
	int bonusBooger = 0;

	if(!couch)
	{
		cout << "Earl checks under the couch cushions. He finds ";
		int chance = rand() % 3 + 1;
		switch (chance)
		{
			case 1:
				cout << "a booger! That's a keeper." << endl;
				bonusBooger = 1;
				break;
			case 2:
				cout << "a huge booger! Earl can break it 3 into pieces." << endl;
				bonusBooger = 3;
				break;
			case 3:
				cout << "nothing. Earl loses a booger in the process. Bad luck." << endl;
				bonusBooger = -1;
				break;
		}
		couch = true;
		return bonusBooger;
	}
	else
	{
		cout << "You already checked under the couch." << endl;
		return 0;
	}
}

// if !hair returns 2 and sets hair to true, otherwise returns 0
int House::combHair()
{
	int hairBonus = 0;
	if(!hair)
	{
		cout << "Earl combs what's left of his hair. It doesn't do much, except increase his confidence by 2. Heck yeah."
		<< endl;
		hair = true;
		hairBonus = 2;
		return hairBonus;
	}
	else
	{
		cout << "Easy on the hair. It's fragile." << endl;
		return 0;
	}
}

// Overriden from Space. Accepts as a parameter, an Earl reference object. Prompts user for input and validates that
// input with getInt() from inputValidation.hpp Depending on user input, calls flingBooger() or runAway() if !fightDone,
// otherwise does nothing.
void House::fight(Earl &earlObj)
{
	if(!fightDone)
	{
		cout << "But a cockroach blocks the doorway! Time to fight!" << endl;
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
					cout << "The cockroach is grossed out and leaves. Earl must have nasty boogers." << endl;
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
void House::displayLocationInfo()
{
	cout << "================================================================================================" << endl;
	cout << "Welcome to Earl's house. It's a mid-century ranch house that's seen better days. But this isn't HGTV. "
		 "Earl's belly is a rumblin'!" << endl;
}