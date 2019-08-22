/** Program Name: BusStation.hpp
 ** Author: Thomas Fattah
 ** Date: 2019-08-08
 ** Description: Header file for Bus class, which is inherited from Space. Simulates the "BusStation" location in "Earl."
 */

#ifndef BUSSTATION_HPP
#define BUSSTATION_HPP

#include "Space.hpp"
#include <iostream>

class BusStation : public Space
{
private:
	bool butt;
	bool vending;
public:
	BusStation();
	virtual void interact(Earl&) override;
	virtual void fight(Earl&) override;
	virtual void displayLocationInfo() override;
	int scratchButt();
	int checkVendingMachine();
};

#endif //BUSSTATION_HPP
