#include "Tape.h"
#include "input_alphabet.h"
#include "Tape_Alphabet.h"
#include "Direction.h"
#include "Uppercase.h"
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

Tape::Tape() :
	Cells(" "),
	Current_Cell(0),
	Blank_Character(' ')
{
}

void Tape::Load(ifstream& definition, bool& valid)
{
	string value;
	if ((definition >> value) &&
		(value.length() == 1) && (value[0] != '\\') &&
		(value[0] != '[') && (value[0] != ']') &&
		(value[0] != '<') && (value[0] != '>') &&
		(value[0] >= '!') && (value[0] <= '~'))
	{
		Blank_Character = value[0];
	}
	else
	{
		cout << "Illegal Blank Character.\n";
		valid = false;
	}
	if ((!(definition >> value)) || (uppercase(value) != "FINAL_STATES:"))
	{
	cout << "Missing keyword after blank character.\n";
	valid = false;
	}
	
}

void Tape::Validate(const Input_Alphabet& Input_Alphabet, const Tape_Alphabet& Tape_Alphabet, bool& valid) const
{
	if (Input_Alphabet.is_element(Blank_Character))
	{
		cout << "Blank Character" << Blank_Character << " is in input alphabet.\n";
		valid = false;
	}
	if (!Tape_Alphabet.is_element(Blank_Character))
	{
		cout << "Blank Character" << Blank_Character << " is not in tape alphabet.\n";
		valid = false;
	}
}

void Tape::View() const
{
	cout << "B= " << Blank_Character << "\n\n";
}

void Tape::Initialize(string input_string)
{
	Cells = input_string + Blank_Character;
	Current_Cell = 0;
}

void Tape::Update(char write_character, direction move_direction)
{
	
	move_direction = uppercase(move_direction);
	if ((move_direction == 'L') && (Current_Cell == 0))
	{
		return;
	}
	if ((move_direction == 'R') && (Current_Cell == Cells.length() - 1))
	{
		Cells += Blank_Character;
	}
	Cells[Current_Cell] = write_character;
	if (move_direction == 'L')
	{
		--Current_Cell;
	}
	else
	{
		++Current_Cell;
	}
}

string Tape::Left(int maximum_number_of_cells) const
{
	int first_cell = max(0, Current_Cell - maximum_number_of_cells);
	string value = Cells.substr(first_cell, Current_Cell - first_cell);
	if (value.length() < Current_Cell)
		value.append(">");
	return value;
}

string Tape::Right(int maximum_number_of_cells) const
{
	int end_cell = Cells.length() - 1;
	while ((end_cell >= Current_Cell) && (Cells[end_cell] == Blank_Character))
	{
		--end_cell;
	}
	int last_cell = min(end_cell, Current_Cell + maximum_number_of_cells - 1);
	string value = Cells.substr(Current_Cell, last_cell - Current_Cell + 1);
	if (value.length() < end_cell - Current_Cell + 1)
		value.append(">");
	return value;
}

char Tape::Current_Character() const
{
	return Cells[Current_Cell];
}

bool Tape::Is_First_Cell() const
{
	return (Current_Cell == 0);
}