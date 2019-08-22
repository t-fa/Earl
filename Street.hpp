/** Program Name: Street.hpp
 ** Author: Thomas Fattah
 ** Date: 2019-08-06
 ** Description: Header file for Street class, which is inherited from Space. Simulates the "Street" location in "Earl."
 */

#ifndef STREET_HPP
#define STREET_HPP

#include <iostream>
#include <string>
#include "Space.hpp"

class Street : public Space
{
private:
	bool yelled;
	bool trash;
public:
	Street(std::string);
	virtual void interact(Earl&) override;
	virtual void fight(Earl&) override;
	virtual void displayLocationInfo() override;
	int playInTraffic();
	int yell();
	int digThroughTrash();
};

#endif //STREET_HPP
