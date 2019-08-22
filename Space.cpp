/** Program Name: Space.cpp
 ** Author: Thomas Fattah
 ** Date: 2019-08-05
 ** Description: Abstract class which has data members for 4 Space pointers (one in each direction). Space simulates a
 ** location within Earl.
 */

#include "Space.hpp"
using std::string;

// default constructor which sets all pointers to nullptr and fightDone to false. Accepts as a parameter a string which
// represents the name of the location
Space::Space(string placeName)
{
	North = nullptr;
	East = nullptr;
	South = nullptr;
	West = nullptr;
	locationName = placeName;
	fightDone = false;
}

// getter
Space* Space::getNorth()
{
	return North;
}

// getter
Space* Space::getEast()
{
	return East;
}

// getter
Space* Space::getSouth()
{
	return South;
}

// getter
Space* Space::getWest()
{
	return West;
}

// getter
string Space::getLocation()
{
	return locationName;
}

// setter
void Space::setNorth(Space *nDir)
{
	North = nDir;
}

// setter
void Space::setEast(Space *eDir)
{
	East = eDir;
}

// setter
void Space::setSouth(Space *sDir)
{
	South = sDir;
}

// setter
void Space::setWest(Space *wDir)
{
	West = wDir;
}

// destructor used by inherited classes
Space::~Space()
{
}