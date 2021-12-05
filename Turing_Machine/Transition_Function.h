#ifndef Transition_Function_H
#define Transition_Function_H

#include "Transition.h"
#include "stack_alphabet.h"
#include "States.h"
#include "Final_States.h"
#include "Direction.h"

#include <string>
#include<vector>
#include <fstream>

using namespace std;

class Transition_Function
{
private:
	vector<Transition> transitions;

public:
	void load(ifstream& definition, bool& valid);

	void validate(const Tape_Alphabet& tape_alphabet,
		const States& states,
		const Final_States& final_states,
		bool& valid) const;

	void view() const;

	void find_transition(string source_state,
		char read_character,
		string& destination_state,
		char& write_character,
		direction& move_direction,
		bool& found) const;
};

#endif