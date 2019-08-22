/** Program Name: inputValidation.hpp
 ** Author: Thomas Fattah
 ** Date: 6/28/19
 ** Description: Input validation function definition, which contains getInt function that ensures a user may only
 ** enter an integer and prompts user until they do so correctly. If user correctly enters an integer, it returns
 ** that integer.
 **/

// With assistance from https://www.learncpp.com/cpp-tutorial/185-stream-states-and-input-validation/

#include "inputValidation.hpp"
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::stringstream;


int getInt()
{
	int intNum = 0;
	string strNum = "";

	bool isValid = false;

	do
	{
		getline(cin, strNum);

		int length = strNum.length();
		for (int i = 0; i < length; i++)
		{
			if(!isdigit(strNum[i]))
			{
				cout << "Please enter valid input." << endl;
				return 0; // essentially break
			}
			else
			{
				if (i == length - 1)
				{
					{
						isValid = true;
					}
				}
			}

		}
	} while(!isValid);

	stringstream inputStream;
	inputStream << strNum;
	inputStream >> intNum;

	return intNum;
}