#include "stack_alphabet.h"
#include "Direction.h"
#include "Uppercase.h"

#include <fstream>
#include <iostream>


using namespace std;

void Tape_Alphabet::load(ifstream& definition, bool& valid)
{
	string value;
	definition >> value;
	while (uppercase(value) != "TRANSITION_FUNCTION:")
	{
		if ((value.length() == 1) &&
			(value[0] != '\\') &&
			(value[0] != '[') && (value[0] != ']') &&
			(value[0] != '<') && (value[0] != '>') &&
			(value[0] >= '!') && (value[0] <= '~'))
		{
			tape_alphabet.push_back(value[0]);
		}
		else
		{
			cout << "Error: Ivalid Tape Alphabet Character." << endl;
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

void Tape_Alphabet::view()
{
	for (int i = 0; i < tape_alphabet.size(); i++)
	{
		cout << tape_alphabet[i] << " ";
	}
}

bool Tape_Alphabet::is_element(char value) const
{
	return true;
}