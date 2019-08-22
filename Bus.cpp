/** Program Name: Bus.cpp
 ** Author: Thomas Fattah
 ** Date: 2019-08-08
 ** Description: Definition file for Bus class, which is inherited from Space. Simulates the "Bus" location in "Earl."
 */

#include "Bus.hpp"
#include "inputValidation.hpp"
using std::cout;
using std::endl;
using std::string;

// Default constructor, which calls Space constructor, passing in "Bus" for locationName. Sets all bool to false
Bus::Bus()
	: Space("Bus"), begOne(false), begTwo(false), begThree(false), pickOne(false), pickTwo(false)
{
}

// Overriden from Space. Accepts as a parameter, an Earl reference object. Prompts user for input and validates that
// input with getInt() from inputValidation.hpp Depending on user input, calls beg(), pickNose(), or readNewspaper().
// beg() is a parameter for setCash() on earlObj. pickNose() is a parameter for setBoogers() on earlObj.
void Bus::interact(Earl &earlObj)
{
	cout << "You're on a bus. What do you want to interact with?" << endl;
	cout << "1. Beg your fellow passengers for money" << endl;
	cout << "2. Sit down and pick your nose" << endl;
	cout << "3. Flip through a discarded newspaper" << endl;
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
		cout << "You decide to get off the bus." << endl;
	}

	while(choice != 4)
	{
		switch (choice)
		{
			case 1:
			{
				int loopRun = beg();
				if(loopRun > 0)
				{
					for(int i=0; i < loopRun; i++)
					{
						earlObj.setCash();
					}
				}
				else if(loopRun < 0)
				{
					loopRun *= -1; // make loopRun positive for for loop
					for(int i=0; i < loopRun; i++)
					{
						earlObj.subTractCash();
					}
				}
				break;
			}
			case 2:
				earlObj.setBoogers(pickNose());
				break;
			case 3:
				readNewspaper();
				break;
		}
		cout << "\nYou're on a bus. What do you want to interact with?" << endl;
		cout << "1. Beg your fellow passengers for money" << endl;
		cout << "2. Sit down and pick your nose" << endl;
		cout << "3. Flip through a discarded newspaper" << endl;
		cout << "4. Nothing" << endl;
		choice = getInt();
		if(choice < 1 || choice > 4)
		{
			cout << "Quit messing around. Enter a number 1 through 4. Earl's hungry!" << endl;
		}
		if(choice == 4)
		{
			cout << "You decide to get off the bus." << endl;
		}
	}
}

// Returns 2, 1, -3, or 0 depending upon booleans begOne, begTwo, and begThree
int Bus::beg()
{
	int dollars = 0;
	if(!begOne)
	{
		cout << "A kind passenger takes pity on Earl and gives him two dollars." << endl;
		dollars = 2;
		begOne = true;
	}
	else if(!begTwo)
	{
		cout << "Earl is still at it. Someone else gives him a dollar. Earl feels like he shouldn't push his "
		  "luck anymore." << endl;
		dollars = 1;
		begTwo = true;
	}
	else if(!begThree)
	{
		cout << "Earl ignores his instincts and continues begging. All the passengers get mad at him and demand their"
		  " money back. Earl loses three dollars." << endl;
		dollars = -3;
		begThree = true;
	}
	else
	{
		cout << "Earl has learned his lesson." << endl;
	}
	return dollars;
}

// returns 1, 1, or 0 depending upon booleans pickOne and pickTwo
int Bus::pickNose()
{
	int boogers = 0;
	if(!pickOne)
	{
		cout << "Earl picks his left nostril and scores a mean looking booger." << endl;
		boogers = 1;
		pickOne = true;
	}
	else if(!pickTwo)
	{
		cout << "Earl picks his right nostril and scores a juicy booger." << endl;
		boogers = 1;
		pickTwo = true;
	}
	else
	{
		cout << "Earl doesn't want to get a nosebleed." << endl;
	}
	return boogers;
}

// couts 1 of 10 possible fun facts
void Bus::readNewspaper()
{
	int fact = rand() % 10 + 1;
	cout << "Earl picks up a newspaper someone has left behind. He flips through and learns";

	switch (fact)
	{
		case 1:
			cout << " to call Cellino & Barnes, personal injury attorneys, in case he suffers from a personal injury."
			<< endl;
			break;
		case 2:
			cout << " the word of the day is \"katzenjammer.\"" << endl;
			break;
		case 3:
			cout << " it's cuffing season." << endl;
			break;
		case 4:
			cout << " the NASDAQ and Dow Jones aren't the same thing." << endl;
			break;
		case 5:
			cout << " he can stop being embarrassed by his crooked smile with the help of Dr. Zizmor." << endl;
			break;
		case 6:
			cout << " Bobby The Bowler has broken a world record for how many bowling hats can fit on a head." << endl;
			break;
		case 7:
			cout << " chicken teriyaki may both cause and cure cancer." << endl;
			break;
		case 8:
			cout << " it will rain tomorrow." << endl;
			break;
		case 9:
			cout << " Tupac and Biggie are still alive and are roommates living together in Buenos Aires." << endl;
			break;
		case 10:
			cout << " dogs can smell bacon from up to 7 miles away." << endl;
			break;
	}
}

// Overriden from Space. If !fightDone, simulates a fight with a door. Earl can either flingBooger() or runAway().
// If fightDone, does nothing.
void Bus::fight(Earl &earlObj)
{
	if(!fightDone)
	{
		cout << "But the door is stuck! Earl tries to fight it, ignoring the instructions of the bus driver." << endl;
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
					cout << "A confused bus driver pulls over and opens the door for Earl. Victory!" << endl;
					break;
				}
				else
				{
					cout << "Earl has no boogers right now." << endl;
				}
			case 2:
				cout << "Earl forces his way through the door." << endl;
				earlObj.runAway();
		}
		fightDone = true;
	}
}

// displays some information about the current location
void Bus::displayLocationInfo()
{
	cout << "================================================================================================" << endl;
	cout << "Earl is in the big leagues now! He's cruising down the street in a bus at 15 MPH. He's not used to the "
			"luxurious lifestyle of public transportation." << endl;
}