#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

#include "Commands.h"
#include "Uppercase.h"

using namespace std;

int main(int argc, char* argv[])
{

	if (argc == 1)
	{
		cout << "Error: No input given. Please enter name of Definiton File" << endl;
		return 0;
	}
	else if (argc == 3)
	{
		cout << "Error: Too many files" << endl;
		return 0;
	}

	ifstream def_file;
	ifstream str_file;

	string def = ".def";
	string str = ".str";
	
	string definition = argv[1];
	string string_file = argv[1];
	
	definition.append(def);
	string_file.append(str);


	def_file.open(definition);
	str_file.open(string_file);

	if (def_file.is_open() == 0)
	{
		cout << "Error: the definition file failed to open!" << endl;
		return 0;
	}
	else if(str_file.is_open() == 1)
	{
		//begin reading in the definition file
		Commands command(def_file, str_file, definition, string_file);
	}
	else
	{
		Commands command(def_file);
	}

	//may not need this from here down
	if (str_file.is_open() == 0)
	{
		//create new file, append it with .str
	}
	else
	{
		//read through file, indicate invalid strings
	}


	def_file.close();

	return 0;
}
