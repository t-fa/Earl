/** Program Name: House.hpp
 ** Author: Thomas Fattah
 ** Date: 2019-08-06
 ** Description: Header file for Bus class, which is inherited from Space. Simulates the "House" location in "Earl."
 */

#ifndef HOUSE_HPP
#define HOUSE_HPP

#include <iostream>
#include "Space.hpp"

class House : public Space
{
private:
	bool fridge;
	bool couch;
	bool hair;
public:
	House();
	virtual void interact(Earl&) override;
	virtual void fight(Earl&) override;
	virtual void displayLocationInfo() override;
	int checkFridge();
	int checkUnderCouch();
	int combHair();
};

#endif //HOUSE_HPP
