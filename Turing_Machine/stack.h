#ifndef Tape_H
#define Tape_H

#include "input_alphabet.h"
#include "stack_alphabet.h"
#include "Direction.h"
#include <string>

#include <fstream>

using namespace std;

class Tape
{
    private:
	string Cells;
	int Current_Cell;
	char Blank_Character;

    public:
	Tape();
	void Load(ifstream &definition, bool &valid);

	void Validate(const Input_Alphabet &Input_Alphabet, const Tape_Alphabet &Tape_Alphabet, bool &valid) const;

	void View() const;

	void Initialize(string input_string);

	void Update(char write_character, direction move_direction);

	string Left(int maximum_number_of_cells) const;
	string Right(int maximum_number_of_cells) const;

	char Current_Character() const;

	bool Is_First_Cell() const;

};

#endif
