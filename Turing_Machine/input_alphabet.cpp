#include "input_alphabet.h"
#include "stack_alphabet.h"
#include "Transition.h"
#include "Direction.h"
#include "Uppercase.h"

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;


void Input_Alphabet::load(ifstream& definition, bool& valid)
{
	string value;
	definition >> value;
	while (uppercase(value) != "TAPE_ALPHABET:")
	{
		if ((value.length() == 1) &&
			(value[0] != '\\') &&
			(value[0] != '[') && (value[0] != ']') &&
			(value[0] != '<') && (value[0] != '>') &&
			(value[0] >= '!') && (value[0] <= '~'))
		{
			alphabet.push_back(value[0]);
		}
		else
		{
			cout << "Error: Ivalid Input Alphabet Character." << endl;
			valid = false;
			return;
		}
		if (definition.eof())
		{
			cout << "Missing Keyword." << endl;
			valid = false;
			return;
		}
		definition >> value;
	}
}

void Input_Alphabet::validate(const Tape_Alphabet& tape_alphabet, bool& valid) const
{
	//check to see if input character is within alphabet character vector, if true return true
}


void Input_Alphabet::view() const
{
	if (alphabet.empty())
	{
 		cout << "Error: Input Alphabet list is empty\n\n";
	}
	else
	{
		cout << "INPUT_ALPHABET: ";
		for (unsigned int i = 0; i < alphabet.size(); ++i)
		{
			
			cout << alphabet[i] << " ";
		}
		cout << "\n\n";
	}
}


bool Input_Alphabet::is_element(char value) const
{
	for (int i = 0; i < alphabet.size(); i++)
	{
			if (value == alphabet[i])
			{
				return true;
			}		
	}
	return false;
}