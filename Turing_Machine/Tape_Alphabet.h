#ifndef Tape_Alphabet_H
#define Tape_Alphabet_H

#include "Direction.h"
#include <fstream>
#include <vector>

using namespace std;

class Tape_Alphabet
{
private:
	vector<char> tape_alphabet = {};

public:
	void load(ifstream& definition, bool& valid);

	void view();

	bool is_element(char value) const;

};

#endif
