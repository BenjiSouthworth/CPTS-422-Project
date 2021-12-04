#include "Commands.h"
#include "Turing_Machine.h"
#include "Input_Strings.h"
#include "Configuration_Settings.h"


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

Commands::Commands(ifstream& definition, ifstream& stringfile, string def_file, string str_file)
{//this is the case if both files exist
	
	configuration_settings.set_truncate(32);
	
	//read in the definition file
	turing_machine.load(def_file);
	
	cout << def_file << " has been successfully loaded!" << endl;


	//check strings in string file
	string value;
	ifstream string_file;
	string_file.open(str_file);

	string_file >> value;
	while (string_file.eof() == 0)
	{
		input_strings.write_string(value);
		string_file >> value;
	}

	//loop until user exits
	runtime();
	input_strings.write_file(str_file);
}

Commands::Commands(ifstream& definition)
{
	//this is the case if only definition file exists
	
}

void Commands::runtime()
{

	while (exitcase == 0)
	{

		char input;

		cout << endl << "Command: ";
		cin >> input;
		cin.ignore();

		switch (input)
		{
		case 'D': case 'd':
			delete_string();
			break;

		case 'X': case 'x':
			exit_application();
			break;

		case 'H': case 'h':
			help();
			break;

		case 'I': case 'i':
			insert_string();
			break;

		case 'L': case 'l':
			list();
			break;

		case 'Q': case 'q':
			break;

		case 'R': case 'r':
			run();
			break;

		case 'E': case 'e':
			set();
			break;

		case 'W': case 'w':
			show();
			break;

		case 'T': case 't':
			truncate();
			break;

		case 'V': case 'v':
			break;

		default:
			cout << "Please Enter a valid Command" << endl;
		}
	}
}

void Commands::delete_string()
{
	int i;
	cout << "Select Input String Number: ";
	cin >> i;


}

void Commands::exit_application()
{
	exitcase = 1;
}

void Commands::help()
{
	cout << "D - Delete      Delete a String from input\nX - Exit        Exit the application\nH - Help        Display list of Commands\nI - Insert      Insert an input string into the list\nL - List        List all input strings\nQ - Quit        Quit operation of TM on input string\nR - Run         Run TM on input string\nE - Set         Set maximum amount of transitions to perform\nW - Show        Show status of application\nT - Truncate    Truncate instantanious descriptions\nV - View        View the TM";
	cout << endl;
}

void Commands::insert_string()
{
	string value = "";

	cout << "Enter an Input String: ";
	getline(cin, value);
	if (value == "")
	{
		cout << "\n";
		return;
	}

	else if (turing_machine.is_valid_input_string(value) == false)
	{
		cout << "Error: String Not Permitted";
		return;
	}
	input_strings.write_string(value);

}

void Commands::list()
{
	input_strings.view();
}

void Commands::truncate() //need to setup checking values, and return if press enter
{
	int trun = 0;
	cout << "Number of Cells[" << configuration_settings.get_truncate() << "]: ";
	cin >> trun;
	if (trun < 0)
	{
		cout << "Please enter a number larger than 0." << endl;
		return;
	}
	configuration_settings.set_truncate(trun);
	cout << "Number of Transitions changed to " << configuration_settings.get_truncate() << endl;

}


void quit()
{

}

void Commands::run()
{
	string input_str;
	int str_num;
	cout << "Select Input String Number: \n";
	
	turing_machine.initialize(input_str);
}

void Commands::set() //need to setup checking values here, so that its only ints, and if press enter exit command.
{
	int num;
	int transitions = configuration_settings.get_transitions();
	cout << "Number of Transitions[" << transitions << "]: ";
	cin >> num;
	if (cin.fail()) // Because 'value' is an integer, cin.fail() will be true, because it did not receive an integer
	{
		cout << "Error! Please enter an int" << endl;
	}
	//getline(cin, num);
	//if (num != int)
	{
		//cout << "\n";
		//return;
	}
	if (num < 0)
	{
		cout << "Please enter a number larger than 0." << endl;
		return;
	}
	configuration_settings.set_transitions(num);
	cout << "Number of Transitions changed to " << configuration_settings.get_transitions() << endl;

}

void Commands::show()
{
	cout << "Course: CPTS322 \nSemester: Spring\nYear: 2020\nInstructor: Neil Corrigan\nAuthor: Benjamin Southworth\nVersion: 0.9.0\n\n";
	cout << "Transitions: " << configuration_settings.get_transitions() << endl << "Truncate: " << configuration_settings.get_truncate() << endl;
	cout << "Name: anbn" << endl;
	cout << "Status: \n";
	cout << "Status of List of Input Strings: \n";
}

void Commands::view()
{
}
