#include "Input_Strings.h"

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

Input_Strings::Input_Strings()
{

}

void Input_Strings::write_file(string write_file_name)
{
	cout << "Writing to file!" << endl;

	string value;
	ofstream out_file;
	out_file.open(write_file_name);

	if (out_file.is_open()) {
		for (unsigned int i = 0; i < string_list.size(); ++i)
		{
			out_file << string_list[i] << "\n";
		}
		cout << "Successful write to input string file: " << write_file_name << endl;
	}
	else
	{
		cout << "Error: Unsucessful write to input string file: " << write_file_name << endl;
	}

	out_file.close();
}

bool Input_Strings::write_string(string insert_string)
{
	for (unsigned i = 0; i < string_list.size(); i++)
	{
		if (string_list.at(i) == insert_string)
		{
			return false;
		}
	}
	string_list.push_back(insert_string);
	return true;
}

void Input_Strings::delete_string(unsigned int string_value)
{

}

string Input_Strings::read_string(unsigned int string_value, bool& valid)
{

}

void Input_Strings::view() const
{
	if (string_list.empty())
	{
		cout << "Error: Input string list is empty\n\n";
	}
	else
	{
		for (unsigned int i = 0; i < string_list.size(); ++i)
		{
			int count = i + 1;
			cout << count << ". " << string_list[i] << endl;
		}
		cout << "\n";
	}
}