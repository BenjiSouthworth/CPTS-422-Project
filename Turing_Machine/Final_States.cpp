#include "Final_States.h"

#include <iostream>
#include <vector>
#include <fstream>

void Final_States::load(ifstream& definition, bool& valid)
{
	string value;
	definition >> value;

	while (definition.eof() == 0)
	{
		if ((value != "\\") &&
			(value != "[") && (value != "]") &&
			(value != "<") && (value != ">") &&
			(value != "!") && (value != "~"))
		{
			final_states_list.push_back(value);
		}
		else
		{
			cout << "Error: Invalid State." << endl;
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

void Final_States::validate(bool& valid)
{

}

void Final_States::view()
{
	for (int i = 0; i < final_states_list.size(); i++)
	{
		cout << final_states_list[i];
	}
}

bool Final_States::is_element(string in_value) const
{
	return true;
}