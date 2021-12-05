#include "pushdown_automaton.h"
#include "States.h"
#include "input_alphabet.h"
#include "Uppercase.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


Turing_Machine::Turing_Machine() :tape(), input_alphabet(), tape_alphabet(), transition_function(), states(), final_states(),
description({}), initial_state(" "), current_state(" "), original_input_string(" "), number_of_transitions(0), valid(true), used(false), operating(false),
accepted(false), rejected(false)
{}


void Turing_Machine::load(string definition_file_name) //loading a PDA from a PDA.def
{
	string value;
	ifstream def_file;
	def_file.open(definition_file_name);

	if (def_file.is_open())
	{
		while (def_file >> value)
		{


			if (uppercase(value) != "STATES:")
			{
				description.push_back(value);
			}
			else if (def_file.eof())
			{
				cout << "Missing STATES: keyword" << endl;
				valid = false;
			}

			if (uppercase(value) == "STATES:")
			{
				states.load(def_file, valid);
				input_alphabet.load(def_file, valid);
				tape_alphabet.load(def_file, valid);
				transition_function.load(def_file, valid);

				
				def_file >> value;
				initial_state = value; //need error checking for initial_state
				//cout << initial_state << endl;

				def_file >> value;
				tape.Load(def_file, valid);
				final_states.load(def_file, valid);
			}
		}
	}
	def_file.close();
}

bool Turing_Machine::is_valid_input_string(string value) const
{
	for (unsigned int i = 0; i < value.length(); i++)
	{
		if (!input_alphabet.is_element(value[i]))
		{
			return false;
		}
		return true;
	}
}

void Turing_Machine::initialize(string input_string)
{
	tape.Initialize(input_string);
}


void Turing_Machine::view_definition() const
{
	
}
