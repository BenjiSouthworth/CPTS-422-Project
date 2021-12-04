#include "Uppercase.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <locale>

using namespace std;

string uppercase(const string input)
{
	locale settings;
	string converted;

	for (short i = 0; i < input.size(); ++i)
		converted += (std::toupper(input[i], settings));

	return converted;
}

char uppercase(const char input)
{
	char converted = input;

	converted = toupper(converted);
	
	return converted;
}