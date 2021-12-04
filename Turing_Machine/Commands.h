#ifndef Commands_H
#define Commands_H

#include "Turing_Machine.h"
#include "Input_Strings.h"
#include "Configuration_Settings.h"

#include <string>

class Commands
{
private:
	int exitcase = 0;
	Turing_Machine turing_machine;
	Input_Strings input_strings;
	Configuration_Settings configuration_settings;

public:
	Commands(ifstream& definition, ifstream& stringfile, string def_file, string str_file);
	Commands(ifstream& definition);

	void runtime();

	void delete_string();
	
	void exit_application();

	void help();

	void insert_string();

	void list();

	void quit();

	void run();

	void set();

	void show();

	void truncate();

	void view();

};

#endif