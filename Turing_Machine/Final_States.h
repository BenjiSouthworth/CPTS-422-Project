#ifndef Final_States_H
#define Final_States_H

#include "Direction.h"

#include <vector>
#include <fstream>

using namespace std;

class Final_States
{
private:
	vector<string> final_states_list;

public:

	void load(ifstream& definition, bool& valid);

	void validate(bool& valid);

	void view();

	bool is_element(string in_value) const;
};

#endif