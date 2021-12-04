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

void States::view()
{

}

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