/** Program Name: TacoTerrace.hpp
 ** Author: Thomas Fattah
 ** Date: 2019-08-08
 ** Description: Header file for TacoTerrace class, which is inherited from Space. Simulates the "TacoTerrace"
 ** location in "Earl."
 */

#ifndef TACOTERRACE_HPP
#define TACOTERRACE_HPP

#include "Space.hpp"
#include <iostream>

class TacoTerrace : public Space
{
private:
	bool bathroom;
	bool gameOver;
public:
	TacoTerrace();
	virtual void interact(Earl&) override;
	virtual void fight(Earl&) override;
	virtual void displayLocationInfo() override;
	int useBathroom();
	void buyTaco(Earl&);
};

#endif //TACOTERRACE_HPP
