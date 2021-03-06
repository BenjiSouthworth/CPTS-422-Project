#include "Commands.h"
#include "pushdown_automaton.h"
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
	
	configuration_settings.set_transitions(5);
	
	//read in the definition file
	turing_machine.load(def_file); //THIS IS WHAT NEEDS TO BE MODIFIED TO WORK WITH NEW DEF FILE TYPE
	//cout << def_file << " has been successfully loaded!" << endl;


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
	//configuration_settings.set_truncate(32);
	runtime(); //loop until user exits
	
}

void Commands::runtime()
{
	configuration_settings.set_transitions(1);

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

int Commands::close() //closes the currently running PDA, allows the user to load a new PDA
{
	if(is_pda_loaded == 1)
	{
		cout << "Closing the Current Pushdown Automaton..\n\nPlease Select a new PDA with the 'Open' Command\n";
		is_pda_loaded = 0;
		
		return 0;
	}
	else if (is_pda_loaded == 0)
	{
		cout << "Error: No PDA has been loaded.\n";
		
		return 1;
	}
	//Update a variable that tells the program that PDA cannot be ran currently
}

int Commands::display() 	//displays current paths through the PDA, will only work if PDA is currently running
{
	if(is_pda_running == 0)
	{
		cout << "Error: No PDA is Currently Running\n";
		
		return 1;
	}
	else if(is_pda_running == 1)
	{
		//print all current paths of the PDA
		
		return 0;
	}

}

int Commands::exit_application()
{ //exits the application
	exitcase = 1;
	
	return 0;
}

int Commands::help()
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
	
	return 0;
}

int Commands::insert_string()
{
	string value = "";

	cout << "Enter an Input String: ";
	getline(cin, value);
	if (value == "")
	{
		cout << "\n";
		
		return 1;
	}

	else if (turing_machine.is_valid_input_string(value) == false)
	{
		cout << "Error: String Not Permitted";

		return 2;
	}
	// now the input is valid
	input_strings.write_string(value);
	
	return 0;
}

int Commands::list()
{
	input_strings.view();
	
	return 0;
}

int Commands::open()
{
//LOAD THE DEFINITION FILE
	string pda_def_name;
	string string_file_name;

	ifstream def_file;
	string def = ".def";
	
	cout << "Enter PDA File Name: ";
	getline(cin,pda_def_name);
	if(pda_def_name == "")
	{
		cout << "\n";
		return 0;
	}
	string_file_name = pda_def_name;

	cout << "Opening " << pda_def_name << "...\n";
	pda_def_name.append(def);

	def_file.open(pda_def_name);

	if (def_file.is_open() == 0)
	{
		cout << "Error: the Definition File failed to open!" << endl;
	}
	else if(def_file.is_open() == 1)
	{
		//begin reading in the definition file
		turing_machine.load(pda_def_name);
		pda_file = pda_def_name;
		is_pda_loaded = 1;
		cout << "Success " << pda_def_name << " Opened\n";
	}
	def_file.close();

//LOAD THE INPUT STRING FILE
	ifstream string_file;
	string value;

	string str = ".str";
	string_file_name.append(str);
	string_file.open(string_file_name);

	if (string_file.is_open() == 0)
	{
		cout << "Error: the Input String file failed to open!" << endl;
	}
	else if(string_file.is_open() == 1)
	{
		string_file >> value;
		while (string_file.eof() == 0)
		{
			input_strings.write_string(value);
			string_file >> value;
		}
		cout << "Success " << string_file_name << " Opened\n";
	}

}

int Commands::quit()
{
	if(is_pda_running == 0)
	{
		cout << "Error: No PDA is currently Running on an input string\n";
		
		return 1;
	}
	else if(is_pda_running == 1)
	{
		cout << "Quitting running on the current input string\n";
		//delete current running tree and stop running.
		is_pda_running = 0;
		
		return 0;
	}
}

int Commands::run()
{
	if(is_pda_loaded == 0)	// if pda is not loaded
	{
		cout << "Error: Open a PDA definition file before running\n";
		
		return 1;
	}
	else if(is_pda_running == 0 && is_pda_loaded == 1)	// if pda is loaded but not running
	{

		string input_str;
		int str_num;
		input_strings.view();
		cout << "Select Input String Number: \n";
		cin >>str_num;
		cout << "Begin Running on Input String " << str_num<< endl;
		
		//turing_machine.initialize(input_str);
		is_pda_running = 1;
		
		return 0;
	}
	else if(is_pda_running == 1)	// if pda is running and loaded
	{
		//continue running the PDA
		return 0;
	}
}

void Commands::set() //need to setup checking values here, so that its only ints, and if press enter exit command.
{
	string number;
	int num;
	int transitions = configuration_settings.get_transitions();

	cout << "Number of Transitions[" << transitions << "]: ";
	getline(cin,number);
	//cin >> num;
	if(number == "")
	{
		//cout << "\n";
		return;
	}
	//num =stoi(number);

	if (cin.fail()) // Because 'value' is an integer, cin.fail() will be true, because it did not receive an integer
	{
		cout << "\nError! Please enter an int" << endl;
		cin >> num;
		return;
	}
	num =stoi(number);

	// else if(num == '\0')
	// {
	// 	cout << "\n";
	// 	return;
	// }

	//getline(cin, num);
	//if (num != int)
	//{
		//cout << "\n";
		//return;
	//}
	if (num < 0)
	{
		cout << "Please enter a number larger than 0." << endl;
		return;
	}
	else
	{
		configuration_settings.set_transitions(num);
		cout << "Number of Transitions changed to " << configuration_settings.get_transitions() << endl;
	}
}

int Commands::show()
{
	cout << "Course: CPTS422 \nSemester: Fall\nYear: 2021\nInstructor: Luis De La Torre\nVersion: 1.0.0\n\n";
	cout << "Transitions: " << configuration_settings.get_transitions()<< endl;
	cout << "Name: " << pda_file << endl;
	if(is_pda_running == 1)
	{
		cout << "Status: PDA is currently running on an Input String\n";
	}
	else
	{
		cout << "Status: PDA is currently not running\n";
	}
	
	return 0;
}

int Commands::view()
{
	if(is_pda_loaded== 1)
	{
		turing_machine.view_definition();
		
		return 0;
	}
	else
	{
		cout << "Error: No PDA Definition has been loaded\n";
		
		return 1;
	}
}