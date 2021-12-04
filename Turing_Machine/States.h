#ifndef States_H
#define States_H

#include "Direction.h"

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class States
{
private:
	vector<string> names;

public:

	//States();

	void load(ifstream& definition, bool& valid);

	void view();

	bool is_element(string in_value) const;
};

#endif