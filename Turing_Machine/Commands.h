#ifndef Commands_H
#define Commands_H

#include "pushdown_automaton.h"
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

	//newly added variables below
	int is_pda_running = 0; //0 No, 1 Yes
	int is_pda_loaded = 0; //0 No, 1 Yes

public:
	Commands(ifstream& definition, ifstream& stringfile, string def_file, string str_file);
	Commands(ifstream& definition);
	void runtime();

	int close();
	
    int display();
	
	int exit_application();

	int help();

	int insert_string();

	int list();

    int open();

	int quit();

	int run();

	void set();

	int show();

	int view();
};

#endif
