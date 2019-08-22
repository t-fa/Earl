/** Program Name: main.cpp
 ** Author: Thomas Fattah
 ** Date: 2019-08-05
 ** Description: main file for Final Project, which simulates a game of "Earl." main creates a Menu object and calls
 ** ascii() on it.
 */

#include <iostream>
#include "Menu.hpp"

int main()
{
	// adapted from Gaddis p 135
	unsigned seed;
	seed = time(0);
	srand(seed);

	Menu obj;
	obj.ascii();

	return 0;
}