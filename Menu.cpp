/** Program Name: Menu.cpp
 ** Author: Thomas Fattah
 ** Date: 2019-08-05
 ** Description: Definition file for Menu class which contains a constructor, ascii(), and startMenu()
 */

#include "Menu.hpp"
#include "Game.hpp"
#include "inputValidation.hpp"
using std::cout;
using std::endl;

// default constructor which initializes choice to 0
Menu::Menu()
	: choice(0)
{
}

// shows some cool art and then calls startMenu()
void Menu::ascii()
{
	// artwork generated by http://www.patorjk.com/software/taag/#p=display&f=Doh&t=Earl
	cout << "                                                                  \n"
			"EEEEEEEEEEEEEEEEEEEEEE                                    lllllll \n"
			"E::::::::::::::::::::E                                    l:::::l \n"
			"E::::::::::::::::::::E                                    l:::::l \n"
			"EE::::::EEEEEEEEE::::E                                    l:::::l \n"
			"  E:::::E       EEEEEE  aaaaaaaaaaaaa  rrrrr   rrrrrrrrr   l::::l \n"
			"  E:::::E               a::::::::::::a r::::rrr:::::::::r  l::::l \n"
			"  E::::::EEEEEEEEEE     aaaaaaaaa:::::ar:::::::::::::::::r l::::l \n"
			"  E:::::::::::::::E              a::::arr::::::rrrrr::::::rl::::l \n"
			"  E:::::::::::::::E       aaaaaaa:::::a r:::::r     r:::::rl::::l \n"
			"  E::::::EEEEEEEEEE     aa::::::::::::a r:::::r     rrrrrrrl::::l \n"
			"  E:::::E              a::::aaaa::::::a r:::::r            l::::l \n"
			"  E:::::E       EEEEEEa::::a    a:::::a r:::::r            l::::l \n"
			"EE::::::EEEEEEEE:::::Ea::::a    a:::::a r:::::r           l::::::l\n"
			"E::::::::::::::::::::Ea:::::aaaa::::::a r:::::r           l::::::l\n"
			"E::::::::::::::::::::E a::::::::::aa:::ar:::::r           l::::::l\n"
			"EEEEEEEEEEEEEEEEEEEEEE  aaaaaaaaaa  aaaarrrrrrr           llllllll\n"
			"                                                                  " << endl;
	startMenu();
}

// Cout some info about the game, then prompts user for choice if they would like to start the game or quit. Validates
// input with getInt() from inputValidation.hpp. If user selects option 1, creates a Game object and calls start().
void Menu::startMenu()
{
	cout << "==================================================================" << endl;
	cout << "You are playing the role of Earl, a middle aged balding man who doesn’t let life get him down. He still "
		 "wears purple patterned 80s styled shorts, has a beer belly, and rocks a mullet. Earl just woke up from a nap"
   " and he’s really hungry. The problem is that there is no food at Earl’s house. Your goal is to help Earl make it to"
   " the closest Taco Terrace so he can keep on keepin’ on, man. You’d better do it before he gets too hungry, or he’ll"
   " be pretty mad about it." << endl;
	cout << "==================================================================" << endl;
	cout << "\nSo what do you wanna do?" << endl;
	cout << "1. Be a bro and help him out" << endl;
	cout << "2. Leave him to his own devices" << endl;

	while(choice < 1 || choice > 2)
	{
		choice = getInt();
		if(choice < 1 || choice > 2)
		{
			cout << "Come on, Man. Earl needs you. Enter only 1 or 2." << endl;
		}
	}

	if(choice == 1)
	{
		Game game;
		game.start();
	}
	else
	{
		cout << "Earl will remember that. He knows who his real friends are." << endl;
	}
}