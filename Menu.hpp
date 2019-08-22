/** Program Name: Menu.hpp
 ** Author: Thomas Fattah
 ** Date: 2019-08-05
 ** Description: Header file for Menu class which has a data member for choice and some menu functions.
 */

#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>

class Menu
{
private:
	int choice;
public:
	Menu();
	void ascii();
	void startMenu();
};

#endif //MENU_HPP
