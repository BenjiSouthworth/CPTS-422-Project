#include "Commands.h"
#include "Turing_Machine.h"
#include "Input_Strings.h"
#include "Configuration_Settings.h"


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

extern string pda_file;

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

	runtime(); //loop until user exits
	
	
	//input_strings.write_file(str_file);
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
		case 'C': case 'c':
            close();
            break;

		case 'P': case 'p':
            display();
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

		case 'O': case 'o':
			open();
			break;

		case 'Q': case 'q':
			quit();
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

		case 'V': case 'v':
            view();
			break;

		default:
			cout << "Please Enter a valid Command" << endl;
		}
	}
}

void Commands::close() //closes the currently running PDA, allows the user to load a new PDA
{
	if(is_pda_loaded == 1)
	{
		cout << "Closing the Current Pushdown Automaton..\n\nPlease Select a new PDA with the 'Open' Command\n";
		is_pda_loaded = 0;
	}
	else if (is_pda_loaded == 0)
	{
		cout << "Error: No PDA has been loaded.\n";
	}
	//Update a variable that tells the program that PDA cannot be ran currently
}

void Commands::display() 	//displays current paths through the PDA, will only work if PDA is currently running
{
	if(is_pda_running == 0)
	{
		cout << "Error: No PDA is Currently Running\n";
	}
	else if(is_pda_running == 1)
	{
		//print all current paths of the PDA
	}

}

void Commands::exit_application()
{ //exits the application
	exitcase = 1;
}

void Commands::help()
{
	//cout << "D - Delete      Delete a String from input\nX - Exit        Exit the application\nH - Help        Display list of Commands\nI - Insert      Insert an input string into the list\nL - List        List all input strings\nQ - Quit        Quit operation of TM on input string\nR - Run         Run TM on input string\nE - Set         Set maximum amount of transitions to perform\nW - Show        Show status of application\nT - Truncate    Truncate instantanious descriptions\nV - View        View the TM";
	cout << "C - Close \tClose the Pushdown Automaton\n";
	cout << "P - Display\tDisplay the Pushdown Automaton\n";
	cout << "X - Exit\tExit the Application\n";
	cout << "H - Help\tHelp Command\n";
	cout << "I - Insert\tInsert an Input String into the Input Strings List\n";
	cout << "L - List\tList all Input Strings held in the Input Strings File\n";
	cout << "O - Open\tOpen a Pushdown Automaton Definition File\n";
	cout << "Q - Quit\tQuit Operation of a Pushdown Automaton on an Input String\n";
	cout << "R - Run \tRun Pushdown Automaton on a Input String\n";
	cout << "E - Set \tSet the Maximum number of Transitions\n";
	cout << "W - Show\tShow the Status of the Application\n";
	cout << "V - View\tView the Current Pushdown Automaton";

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

void Commands::open()
{
	string pda_def_name = "";

	cout << "Enter PDA File Name: ";
	getline(cin,pda_def_name);
	if(pda_def_name == "")
	{
		cout << "\n";
		return;
	}

	cout << "Attempting to open " << pda_def_name << "...\n";

	//if successful, update is_pda_loaded to 1
	is_pda_loaded = 1;
}

void Commands::quit()
{
	if(is_pda_running == 0)
	{
		cout << "Error: No PDA is currently Running on an input string\n";
	}
	else if(is_pda_running == 1)
	{
		cout << "Quitting running on the current input string\n";
		is_pda_running = 0;
	}
}

void Commands::run()
{
	if(is_pda_loaded == 0)
	{
		cout << "Error: Open a PDA definition file before running\n";
	}
	else if(is_pda_running == 0 && is_pda_loaded == 1)
	{
		string input_str;
		int str_num;
		cout << "Select Input String Number: \n";
		cin >>str_num;
		
		//turing_machine.initialize(input_str);
		cout << "Begin running on string " << str_num<< endl;
		is_pda_running = 1;
	}
	else if(is_pda_running == 1)
	{
		//continue running the PDA
	}
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
	cout << "Course: CPTS422 \nSemester: Fall\nYear: 2021\nInstructor: Luis De La Torre\nAuthor: Benjamin Southworth\nVersion: 1.0.0\n\n";
	cout << "Transitions: " << configuration_settings.get_transitions() << endl << "Truncate: " << configuration_settings.get_truncate() << endl;
	cout << "Name: anbn" << endl;
	cout << "Status: \n";
	cout << "Status of List of Input Strings: \n";
}

void Commands::view()
{
    ifstream f(pda_file);

    if(f.is_open())
        cout << f.rdbuf();
}