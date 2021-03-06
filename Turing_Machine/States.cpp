#include "States.h"
#include "Direction.h"
#include "Uppercase.h"

#include <fstream>

using namespace std;

//States::States()
//{
//	names = {};
//}

void States::load(ifstream& definition, bool& valid)
{
	string value;
	definition >> value;

	while (uppercase(value) != "INPUT_ALPHABET:")
	{
		if ((value != "\\")&& 
			(value != "[") && (value != "]") &&
			(value != "<") && (value != ">") &&
			(value != "!") && (value != "~"))
		{
			names.push_back(value);
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

//vector<string> names;

void States::view()
{
	if (names.empty())
	{
 		cout << "Error: States list is empty\n\n";
	}
	else
	{
		cout << "STATES: ";
		for (unsigned int i = 0; i < names.size(); ++i)
		{
			cout << names[i] << " ";
		}
		cout << "\n\n";
	}
}

//vector<string> string_list;

// void Input_Strings::view() const
// {
// 	if (string_list.empty())
// 	{
// 		cout << "Error: Input string list is empty\n\n";
// 	}
// 	else
// 	{
// 		for (unsigned int i = 0; i < string_list.size(); ++i)
// 		{
// 			int count = i + 1;
// 			cout << count << ". " << string_list[i] << endl;
// 		}
// 		cout << "\n";
// 	}
// }

bool States::is_element(string in_value) const
{
	for (int i = 0; i < names.size(); i++)
	{
		if (in_value == names[i])
		{
			return true;
		}
	}
	return false;
}