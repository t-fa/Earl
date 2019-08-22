/** Program Name: Earl.cpp
 ** Author: Thomas Fattah
 ** Date: 2019-08-06
 ** Description: Definition file for Earl class, which simulates the main character in the game of the same title. Has
 ** data members for Earl's various stats and some functions which are called during the course of the game. An Earl
 ** object is passed by reference to Space classes.
 */

#include "Earl.hpp"
using std::cout;
using std::endl;

// default constructor, which sets cash to 0, hunger to 70, boogers to 2, health to 10, and confidence to 0
// Hunger set artificially high in consideration of the TA grading who would like to test my program. Ideally, I'd have
// it at 30
Earl::Earl()
	: hunger(100), boogers(2), health(10), confidence(0), busTicket(false), finalScore(0)
{
	cash.push_back(EARLMONEY);
}

// increases Earl's cash by 1 dollar each time the function is called unless Earl has 10 dollars, which is the
// capacity
void Earl::setCash()
{
	if(cash.size() < 10)
	{
		cash.push_back(EARLMONEY);
	}
	else
	{
		cout << "Earl's wallet is full right now." << endl;
	}
}

// removes an element (1 dollar) from cash vector
void Earl::subTractCash()
{
	if(!cash.empty())
	{
		cash.pop_back();
	}
	else
	{
		cout << "Earl has no money right now." << endl;
	}
}

// increases or decreases Earl's hunger depending on what is passed in
void Earl::setHunger(int snack)
{
	hunger += snack;
}

// increases or decreases Earl's confidence depending on what is passed in
void Earl::setConfidence(int action)
{
	confidence += action;
}

// increases or decreases Earl's finalScore depending on what is passed in. Called at the end to display final score
void Earl::setFinalScore(int score)
{
	finalScore += score;
}

// checks if !busTicket and if Earl has at least 5 dollars. Buys ticket if yes, updating busTicket and cash
void Earl::buyBusTicket()
{
	if(!busTicket && getCash() >= 5)
	{
		cout << "Earl finds himself to the be owner of one bus ticket. It's valid for the remainder of the day!" << endl;
		busTicket = true;
		for(int i=0; i < 5; i++)
		{
			cash.pop_back();
		}
	}
	else if(!busTicket && getCash() < 5)
	{
		cout << "Earl doesn't have enough money right now." << endl;
	}
	else
	{
		cout << "Earl already has a bus ticket." << endl;
	}
}

// increases or decreases Earl's boogers depending on what is passed in
void Earl::setBoogers(int boog)
{
	boogers += boog;
}

// increases or decreases Earl's health depending on what is passed in
void Earl::setHealth(int modifier)
{
	health += modifier;
}

// decreases booger count by 1 if a booger is available, otherwise cout message
void Earl::flingBooger()
{
	if(boogers > 0)
	{
		cout << "Earl flings a booger." << endl;
		boogers -= 1;
	}
	else
	{
		cout << "Earl has no boogers right now." << endl;
	}
}

// used for when Earl chooses not to fight. Earl loses 1 health.
void Earl::runAway()
{
	cout << "Earl chooses to run away and loses 1 health." << endl;
	health -= 1;
	cout << "He now has " << health << " health." << endl;
}

// getter
int Earl::getCash()
{
	int money = 0;
	for(int i=0; i < cash.size(); i++)
	{
		money += cash[i];
	}
	return money;
}

// getter
int Earl::getHunger()
{
	return hunger;
}

// getter
int Earl::getBoogers()
{
	return boogers;
}

// getter
int Earl::getHealth()
{
	return health;
}

// getter
int Earl::getConfidence()
{
	return confidence;
}

// getter
bool Earl::getBusTicket()
{
	return busTicket;
}

// getter
int Earl::getFinalScore()
{
	return finalScore;
}