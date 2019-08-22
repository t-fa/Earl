/** Program Name: Bus.hpp
 ** Author: Thomas Fattah
 ** Date: 2019-08-08
 ** Description: Header file for Bus class, which is inherited from Space. Simulates the "Bus" location in "Earl."
 */

#ifndef BUS_HPP
#define BUS_HPP

#include "Space.hpp"
#include <iostream>

class Bus : public Space
{
private:
	bool begOne;
	bool begTwo;
	bool begThree;
	bool pickOne;
	bool pickTwo;
public:
	Bus();
	virtual void interact(Earl&) override;
	virtual void fight(Earl&) override;
	virtual void displayLocationInfo() override;
	int beg();
	int pickNose();
	void readNewspaper();
};

#endif //BUS_HPP
