/** Program Name: GasStation.cpp
 ** Author: Thomas Fattah
 ** Date: 2019-08-09
 ** Description: Definition file for Bus class, which is inherited from Space. Simulates the "GasStation" location in
 ** "Earl."
 */

#include "GasStation.hpp"
#include "inputValidation.hpp"
using std::cout;
using std::endl;

// default constructor which calls Space constructor, setting "Gas Station" to location name. Sets bathroom bool to false
GasStation::GasStation()
	: Space("Gas Station"), bathroom(false)
{
}

// Overriden from Space. Accepts as a parameter, an Earl reference object. Prompts user for input and validates that
// input with getInt() from inputValidation.hpp Depending on user input, calls inhaleGas() or checkBathroom().
// inhaleGas() is a parameter for setHealth() on earlObj. checkBathroom() is a parameter for setCash() on
// earlObj.
void GasStation::interact(Earl &earlObj)
{
	cout << "You're at the gas station. What do you want to interact with?" << endl;
	cout << "1. Inhale some of that famous gasoline" << endl;
	cout << "2. Check the bathroom" << endl;
	cout << "3. Move to the next area" << endl;

	int choice = 0;
	while(choice < 1 || choice > 3)
	{
		choice = getInt();
		if(choice < 1 || choice > 3)
		{
			cout << "Quit messing around. Enter a number 1 through 3. Earl's hungry!" << endl;
		}
	}
	if(choice == 3)
	{
		cout << "You decide to leave the gas station." << endl;
	}

	while(choice != 3)
	{
		switch (choice)
		{
			case 1:
				earlObj.setHealth(inhaleGas());
				break;
			case 2:
				for(int i=0; i < checkBathroom(); i++)
				{
					earlObj.setCash();
				}
				break;
		}
		cout << "\nYou're still at the gas station. What do you want to interact with?" << endl;
		cout << "1. Inhale some of that famous gasoline" << endl;
		cout << "2. Check the bathroom" << endl;
		cout << "3. Move to the next area" << endl;
		choice = getInt();
		if(choice < 1 || choice > 4)
		{
			cout << "Quit messing around. Enter a number 1 through 3. Earl's hungry!" << endl;
		}
		if(choice == 4)
		{
			cout << "You decide to leave the gas station." << endl;
		}
	}
}

// returns 1
int GasStation::inhaleGas()
{
	cout << "Earl takes a deep breath and gets a nice unleaded gasoline buzz. He loses 1 health." << endl;
	return 1;
}

// if !bathroom, returns 1 and sets bathroom to true. Otherwise return 0
int GasStation::checkBathroom()
{
	if(!bathroom)
	{
		cout << "Earl walks into the gas station bathroom and finds a dollar on the floor. It's on the floor of a gas "
				"station bathroom, but money is money, right? ¯\\_(ツ)_/¯" << endl;
		bathroom = true;
		return 1;
	}
	else
	{
		cout << "There's nothing else to be found in there." << endl;
		return 0;
	}
}

// Overriden from Space. Accepts as a parameter, an Earl reference object. Prompts user for input and validates that
// input with getInt() from inputValidation.hpp Depending on user input, calls flingBooger() or runAway() if !fightDone,
// otherwise does nothing.
void GasStation::fight(Earl &earlObj)
{
	if(!fightDone)
	{
		cout << "But a scary looking man asks Earl for directions." << endl;
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
					cout << "The scary looking man steps into the light and was just a nice old man. He takes out a "
			 "handkerchief from his pocket, wipes his face, and walks away, muttering something about today's youth."
	" Earl feels bad, but at least he's safe." << endl;
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
void GasStation::displayLocationInfo()
{
	cout << "================================================================================================" << endl;
	cout << "Earl is at the gas station! He doesn't drive, but sometimes he comes by to get a fresh smell of gas. More"
		 " notably, this is the place to stock up on candy before heading to Taco Terrace." << endl;
}