#ifndef Input_Alphabet_H
#define Input_Alphabet_H

#include "Direction.h"
#include "stack_alphabet.h"

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

class Input_Alphabet
{
private:
	vector<char> alphabet;

public:
	//Input_Alphabet();

	void load(ifstream& definition, bool& valid);

	void validate(const Tape_Alphabet& tape_alphabet, bool& valid) const;

	void view() const;

	bool is_element(char value) const;
};

#endif