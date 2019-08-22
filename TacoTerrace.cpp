/** Program Name: TacoTerrace.cpp
 ** Author: Thomas Fattah
 ** Date: 2019-08-08
 ** Description: Definition file for TacoTerrace class, which is inherited from Space. Simulates the "TacoTerrace"
 ** location in "Earl."
 */

#include "TacoTerrace.hpp"
#include "inputValidation.hpp"
using std::cout;
using std::endl;

// default constructor which calls Space constructor, setting "Mall" to location name. Sets clothes, food, and puppies
// bool to false
TacoTerrace::TacoTerrace()
	: Space("Taco Terrace"), bathroom(false), gameOver(false)
{
}

// Overriden from Space. Accepts as a parameter, an Earl reference object. Prompts user for input and validates that
// input with getInt() from inputValidation.hpp Depending on user input, calls useBathroom() or buyTaco().
// useBathroom() is a parameter for setConfidence() on earlObj. Function runs while !gameOver. After first run, sets
// gameOver to true if option 2 or 3 are selected.
void TacoTerrace::interact(Earl &earlObj)
{
	while(!gameOver)
	{
		cout << "You've made it to Taco Terrace! What do you want to interact with?" << endl;
		cout << "1. Use the bathroom" << endl;
		cout << "2. Walk up to the register" << endl;
		cout << "3. Go back home" << endl;

		int choice = 0;
		while(choice < 1 || choice > 3)
		{
			choice = getInt();
			if(choice < 1 || choice > 3)
			{
				cout << "Quit messing around. Enter a number 1 through 4. Earl's hungry!" << endl;
			}
		}
		if(choice == 3)
		{
			cout << "You went through all that just to chicken out at the last minute. Life's tough. Earl's still hungry."
					" You blew it. Game over." << endl;
			gameOver = true;
		}

		while(!gameOver && choice != 3)
		{
			switch (choice)
			{
				case 1:
					earlObj.setConfidence(useBathroom());
					break;
				case 2:
					buyTaco(earlObj);
					gameOver = true;
					break;
			}
			if(!gameOver)
			{
				cout << "You've made it to Taco Terrace! What do you want to interact with?" << endl;
				cout << "1. Use the bathroom" << endl;
				cout << "2. Walk up to the register" << endl;
				cout << "3. Go back home" << endl;
				choice = getInt();
				if(choice < 1 || choice > 3)
				{
					cout << "Quit messing around. Enter a number 1 through 3. Earl's hungry!" << endl;
				}
				if(choice == 3)
				{
					cout << "You went through all that just to chicken out at the last minute. Life's tough. Earl's still hungry."
							" You blew it. Game over." << endl;
					gameOver = true;
				}
			}
		}
	}
}

// if !bathroom return 2 and set bathroom to true, otherwise return 0
int TacoTerrace::useBathroom()
{
	int conf = 0;
	if(!bathroom)
	{
		cout << "Earl uses the bathroom. He feels a rush of confidence. He earns 3 confidence." << endl;
		conf = 2;
		bathroom = true;
	}
	else
	{
		cout << "Earl has already been there." << endl;
	}
	return conf;
}

// If earl has enough money, purchase a taco, burrito, or burrito bonanza. Validates input with getInt() from
// inputValidation.hpp. Checks if user has enough money and then calls setCash() and setFinalScore() on earlObj and
// then sets gameOver to true.
void TacoTerrace::buyTaco(Earl &earlObj)
{
	while (!gameOver)
	{
		int choice = 0;
		cout << "This is it. Earl anxiously approaches the register. The teenage cashier's voice squeaks as he asks"
	   " \"How can I help you?\" Earl feels the pounding in his chest." << endl;
		cout << "You can only buy one. Choose wisely! This determines your final score." << endl;
		cout << "1. Buy a taco $3" << endl;
		cout << "2. Buy a burrito $6" << endl;
		cout << "3. Buy a burrito bonanza $9" << endl;
		cout << "4. Nothing (THIS IS GAME OVER)" << endl;
		while (choice < 1 || choice > 4)
		{
			choice = getInt();
			if (choice < 1 || choice > 4)
			{
				cout << "Quit messing around. Enter a number 1 through 4. Earl's hungry!" << endl;
			}
		}

		switch (choice)
		{
			case 1:
				if(earlObj.getCash() > 2)
				{
					cout << "Earl buys a taco. It's somewhat satisfying. Well done!" << endl;
					for(int i=0; i < 3; i++)
					{
						earlObj.subTractCash();
					}
					earlObj.setFinalScore(10);
				}
				else
				{
					cout << "Earl doesn't have enough money." << endl;
				}
				break;
			case 2:
				if(earlObj.getCash() > 5)
				{
					cout << "Earl buys a burrito. It's juices will leave Earl feeling satisfied for a few hours." << endl;
					for(int i=0; i < 6; i++)
					{
						earlObj.subTractCash();
					}
					earlObj.setFinalScore(20);
				}
				else
				{
					cout << "Earl doesn't have enough money." << endl;
				}
				break;
			case 3:
				if(earlObj.getCash() > 8)
				{
					cout << "Earl is a rich man and gets the burrito bonanza! He'll be full for days. Clear the "
							"bathroom!" << endl;
					for(int i=0; i < 9; i++)
					{
						earlObj.subTractCash();
					}
					earlObj.setFinalScore(30);
				}
				else
				{
					cout << "Earl doesn't have enough money." << endl;
				}
				break;
		}
		gameOver = true;
	}
}

// calls setFinalScore(), adding Earl's confidence as a bonus. Displays final score to the user.
void TacoTerrace::fight(Earl &earlObj)
{
	// no fight in Taco Terrace. Instead, displays Earl's final score!
	if(gameOver)
	{
		earlObj.setFinalScore(earlObj.getConfidence());
		cout << "======================================================================================" << endl;
		cout << "   ____                            _         _       _   _                 _ \n"
				"  / ___|___  _ __   __ _ _ __ __ _| |_ _   _| | __ _| |_(_) ___  _ __  ___| |\n"
				" | |   / _ \\| '_ \\ / _` | '__/ _` | __| | | | |/ _` | __| |/ _ \\| '_ \\/ __| |\n"
				" | |__| (_) | | | | (_| | | | (_| | |_| |_| | | (_| | |_| | (_) | | | \\__ \\_|\n"
				"  \\____\\___/|_| |_|\\__, |_|  \\__,_|\\__|\\__,_|_|\\__,_|\\__|_|\\___/|_| |_|___(_)\n"
				"                   |___/                                                     " << endl;
		cout << "======================================================================================" << endl;
		cout << "Earl has made it to Taco Terrace with your help. You must be a great person to be"
		  " so selfless. Your final score is: " << earlObj.getFinalScore() << "!" << endl;
	}
}

// cout some information about the location
void TacoTerrace::displayLocationInfo()
{
	cout << "================================================================================================" << endl;
	cout << "This is it! The magnificent, glorious Taco Terrace! Earl feels the excitement in the air." << endl;
}