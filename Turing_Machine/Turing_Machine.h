#ifndef Turing_Machine_H
#define Turing_Machine_H

#include "Tape.h"
#include "input_alphabet.h"
#include "Tape_Alphabet.h"
#include "Transition_Function.h"
#include "States.h"
#include "Final_States.h"

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

class Turing_Machine 
{
private:
	Tape tape;
	Input_Alphabet input_alphabet;
	Tape_Alphabet tape_alphabet;
	Transition_Function transition_function;
	States states;
	Final_States final_states;

	vector<string> description;

	string initial_state;
	string current_state;
	string original_input_string;
	int number_of_transitions;

	bool valid;
	bool used;
	bool operating;
	bool accepted;
	bool rejected;

public:
	Turing_Machine();
	
	void load(string definition_file_name);

	void view_definition() const;

	void view_instentaneous_Description(int maximum_number_of_cells) const;

	void initialize(string input_string);
	void perform_transitions(int maximum_number_of_transitions);
	void terminate_operation();
	string input_string() const;
	int total_number_of_transitions() const;

	bool is_valid_definition() const;
	bool is_valid_input_string(string value) const;
	bool is_used() const;
	bool is_operating() const;
	bool is_accepted_input_string() const;
	bool is_rejected_input_string() const;
};

#endif
