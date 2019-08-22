/** Program Name: BusStation.cpp
 ** Author: Thomas Fattah
 ** Date: 2019-08-08
 ** Description: Definition file for Bus class, which is inherited from Space. Simulates the "BusStation" location in
 ** "Earl."
 */

#include "BusStation.hpp"
#include "inputValidation.hpp"
using std::cout;
using std::endl;

// default constructor which calls Space constructor, passing "Bus Station" to location name. Sets butt and vending to
// false
BusStation::BusStation()
	: Space("Bus Station"), butt(false), vending(false)
{
}

// Overriden from Space. Accepts as a parameter, an Earl reference object. Prompts user for input and validates that
// input with getInt() from inputValidation.hpp Depending on user input, calls scratchButt() or checkVendingMachine().
// scratchButt() is a parameter for setBoogers() on earlObj. checkVendingMachine() is a parameter for setCash() on
// earlObj.
void BusStation::interact(Earl &earlObj)
{
	cout << "You're at the bus station. What do you want to interact with?" << endl;
	cout << "1. Scratch your butt" << endl;
	cout << "2. Check vending machine" << endl;
	cout << "3. Buy a bus ticket $5" << endl;
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
		cout << "You decide to leave the bus station." << endl;
	}

	while(choice != 4)
	{
		switch (choice)
		{
			case 1:
				earlObj.setBoogers(scratchButt());
				break;
			case 2:
			{
				int loopRun = checkVendingMachine();
				for(int i=0; i < loopRun; i++)
				{
					earlObj.setCash();
				}
				break;
			}
			case 3:
				earlObj.buyBusTicket();
				break;
		}
		cout << "\nYou're still at the bus station. What do you want to interact with?" << endl;
		cout << "1. Scratch your butt" << endl;
		cout << "2. Check vending machine" << endl;
		cout << "3. Buy a bus ticket $5" << endl;
		cout << "4. Move to the next area" << endl;
		choice = getInt();
		if(choice < 1 || choice > 4)
		{
			cout << "Quit messing around. Enter a number 1 through 4. Earl's hungry!" << endl;
		}
		if(choice == 4)
		{
			cout << "You decide to leave the bus station." << endl;
		}
	}
}

// if !butt, returns 2 and sets butt to true, otherwise returns 0
int BusStation::scratchButt()
{
	if(!butt)
	{
		cout << "Earl scratches his butt. He finds 2 boogers! Best not to ask questions." << endl;
		butt = true;
		return 2;
	}
	else
	{
		cout << "Easy there. We ARE in public." << endl;
		return 0;
	}
}

// overrides fight() from Space class, but doesn't do anything. There is no fight in BusStation
void BusStation::fight(Earl &earlObj)
{
	// no fight in the bus station
}

// cout some information about the location
void BusStation::displayLocationInfo()
{
	cout << "================================================================================================" << endl;
	cout << "Earl makes his way over to the local bus station. If he can navigate through the perils of a bus station,"
		 " taking a bus might get him to Taco Terrace faster!" << endl;
}

// if !vending, sets vending to true and returns 2, otherwise returns 0
int BusStation::checkVendingMachine()
{
	if(!vending)
	{
		cout << "Earl checks underneath the vending machine and finds 2 bucks!" << endl;
		vending = true;
		return 2;
	}
	else
	{
		cout << "Earl has already looked under there." << endl;
		return 0;
	}
}