/** Program Name: Space.hpp
 ** Author: Thomas Fattah
 ** Date: 2019-08-05
 ** Description: Abstract class which has data members for 4 Space pointers (one in each direction). Space simulates a
 ** location within Earl.
 */

#ifndef SPACE_HPP
#define SPACE_HPP

#include "Earl.hpp"
#include <string>

class Space
{
protected:
	Space *North;
	Space *East;
	Space *South;
	Space *West;
	Space(std::string);
	std::string locationName;
	bool fightDone;
public:
	virtual ~Space();
	virtual void interact(Earl&) = 0;
	virtual void fight(Earl&) = 0;
	virtual void displayLocationInfo() = 0;
	Space* getNorth();
	Space* getEast();
	Space* getSouth();
	Space* getWest();
	std::string getLocation();
	void setNorth(Space*);
	void setEast(Space*);
	void setSouth(Space*);
	void setWest(Space*);
};

#endif //SPACE_HPP
