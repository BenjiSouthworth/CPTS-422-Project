#include "Transition_Function.h"
#include "Transition.h"
#include "Tape_Alphabet.h"
#include "States.h"
#include "Final_States.h"
#include "Direction.h"
#include "Uppercase.h"

#include<vector>
#include <fstream>
#include <iostream>

using namespace std;

void Transition_Function::load(ifstream& definition, bool& valid)
{
	string value;

	string source_state;
	char read_character;
	string destination_state;
	char write_character;
	direction move_direction;

	definition >> value;

	while (uppercase(value) != "INITIAL_STATE:")
	{
		if ((value != "\\") &&
			(value != "[") && (value != "]") &&
			(value != "<") && (value != ">") &&
			(value != "!") && (value != "~"))
		{
			source_state = value;
			definition >> value;

			if ((value.length() == 1) &&
				(value[0] != '\\') &&
				(value[0] != '[') && (value[0] != ']') &&
				(value[0] != '<') && (value[0] != '>') &&
				(value[0] >= '!') && (value[0] <= '~'))
			{
				read_character = value[0];
				definition >> value;

				if (((value != "\\") &&
					(value != "[") && (value != "]") &&
					(value != "<") && (value != ">") &&
					(value != "!") && (value != "~")))
				{
					destination_state = value;
					definition >> value;

					if ((value.length() == 1) &&
						(value[0] != '\\') &&
						(value[0] != '[') && (value[0] != ']') &&
						(value[0] != '<') && (value[0] != '>') &&
						(value[0] >= '!') && (value[0] <= '~'))
						{
						write_character = value[0];
						definition >> value;

						if ((value.length() == 1) &&
							(value[0] != '\\') &&
							(value[0] != '[') && (value[0] != ']') &&
							(value[0] != '<') && (value[0] != '>') &&
							(value[0] >= '!') && (value[0] <= '~'))
						{
							move_direction = value[0];

							Transition Transition(source_state, read_character, destination_state, write_character, move_direction);
							transitions.push_back(Transition);
						}
						else
						{
							cout << "Invalid Direction in Transition Function" << endl;
							valid = false;
						}
						
					}
					else
					{
						cout << "Invalid Character in Transition Function" << endl;
						valid = false;
					}
				}
				else
				{
					cout << "Invalid State in Transition Function" << endl;
					valid = false;
				}
			}
			else
			{
				cout << "Invalid Character in Transition Function" << endl;
				valid = false;
			}
			
		}
		else
		{
			cout << "Invalid State in Transition Function" << endl;
			valid = false;
		}
		if (definition.eof())
		{
			cout << "Missing Keyword." << endl;
			valid = false;
			return;
		}
		definition >> value;
	}
}

void Transition_Function::validate(const Tape_Alphabet& tape_alphabet,
	const States& states,
	const Final_States& final_states,
	bool& valid) const
{
	for (int index = 0; index < transitions.size(); index++)
	{
		if (final_states.is_element(transitions[index].source_state()))
		{
			cout << "Source State" << transitions[index].source_state() << "is in final states.\n";
			valid = false;
		}
		if (!states.is_element(transitions[index].source_state()))
		{
			cout << "Source State" << transitions[index].source_state() << "is not final states.\n";
			valid = false;
		}
		if (!tape_alphabet.is_element(transitions[index].read_character()))
		{
			cout << "Read Character" << transitions[index].read_character() << "is not in tape alphabet.\n";
			valid = false;
		}
		if (!states.is_element(transitions[index].destination_state()))
		{
			cout << "Destination State" << transitions[index].destination_state() << "is not in states.\n";
			valid = false;
		}
		if (!tape_alphabet.is_element(transitions[index].write_character()))
		{
			cout << "Write Character" << transitions[index].write_character() << "is not in tape alphabet.\n";
			valid = false;
		}
	}
}


void Transition_Function::view() const
{
	for (int i = 0; i < transitions.size(); i++)
	{
		cout << transitions[i].source_state() << " ";
	}
}


void Transition_Function::find_transition(string source_state,
	char read_character,
	string& destination_state,
	char& write_character,
	direction& move_direction,
	bool& found) const
{
	for (int index = 0; index < transitions.size(); index++)
	{
		if ((transitions[index].source_state() == source_state) && (transitions[index].read_character() == read_character))
		{
			destination_state = transitions[index].destination_state();
			write_character = transitions[index].write_character();
			move_direction = transitions[index].move_direction();
			found = true;
			return;
		}
		found = false;
	}
}