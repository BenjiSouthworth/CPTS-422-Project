#include "Configuration_Settings.h"

#include <iostream>
using namespace std;

Configuration_Settings::Configuration_Settings()
{
	int truncate_int = 32;
	int transitions_int = 1;
}

void Configuration_Settings::set_truncate(int val)
{
	//check to see if it is > 0;
	if (val < 0)
	{
		cout << "Please enter a value greater than 0" << endl;
			return;
	}
	truncate_int = val;
}

int Configuration_Settings::get_truncate()
{
	return truncate_int;
}

void Configuration_Settings::set_transitions(int val)
{
	if (val < 0)
	{
		cout << "Please enter a value greater than 0" << endl;
			return;
	}
	transitions_int = val;
}

int Configuration_Settings::get_transitions()
{
	return transitions_int;
}