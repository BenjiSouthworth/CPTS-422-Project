#ifndef Input_Strings_H
#define Input_Strings_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Input_Strings
{
private: 

	vector<string> string_list;

public:

	Input_Strings();

	void write_file(string write_file_name);

	bool write_string(string insert_string);

	void delete_string(unsigned int string_value);

	string read_string(unsigned int string_value, bool& valid);

	void view() const;
};

#endif