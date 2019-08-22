/** Program Name: Earl.hpp
 ** Author: Thomas Fattah
 ** Date: 2019-08-06
 ** Description: Header file for Earl class, which simulates the main character in the game of the same title. Has
 ** data members for Earl's various stats and some functions which are called during the course of the game. An Earl
 ** object is passed by reference to Space classes.
 */

#ifndef EARL_HPP
#define EARL_HPP

#include <iostream>
#include <vector>

const int EARLMONEY = 1;

class Earl
{
private:
	std::vector<int> cash;
	int hunger;
	int boogers;
	int health;
	int confidence;
	bool busTicket;
	int finalScore;
public:
	Earl();
	void setCash();
	void subTractCash();
	void setHunger(int);
	void setBoogers(int);
	void setHealth(int);
	void setConfidence(int);
	void setFinalScore(int);
	void buyBusTicket();
	void flingBooger();
	void runAway();
	int getCash();
	int getHunger();
	int getBoogers();
	int getHealth();
	int getConfidence();
	bool getBusTicket();
	int getFinalScore();
};

#endif //EARL_HPP
