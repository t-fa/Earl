/** Program Name: GasStation.hpp
 ** Author: Thomas Fattah
 ** Date: 2019-08-09
 ** Description: Header file for Bus class, which is inherited from Space. Simulates the "GasStation" location in "Earl."
 */

#ifndef GASSTATION_HPP
#define GASSTATION_HPP

#include "Space.hpp"
#include <iostream>

class GasStation : public Space
{
private:
	bool bathroom;
public:
	GasStation();
	virtual void interact(Earl&) override;
	virtual void fight(Earl&) override;
	virtual void displayLocationInfo() override;
	int inhaleGas();
	int checkBathroom();
};

#endif //GASSTATION_HPP
