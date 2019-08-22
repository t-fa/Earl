/** Program Name: Mall.hpp
 ** Author: Thomas Fattah
 ** Date: 2019-08-09
 ** Description: Header file for Mall class, which is inherited from Space. Simulates the "Mall" location in "Earl."
 */

#ifndef MALL_HPP
#define MALL_HPP

#include "Space.hpp"
#include <iostream>

class Mall : public Space
{
private:
	bool clothes;
	bool food;
	bool puppies;
public:
	Mall();
	virtual void interact(Earl&) override;
	virtual void fight(Earl&) override;
	virtual void displayLocationInfo() override;
	int tryClothes();
	int foodCourt();
	int viewPuppies();
};

#endif //MALL_HPP
