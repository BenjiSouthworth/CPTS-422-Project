#include "Transition.h"
#include "Direction.h"
#include <string>

using namespace std;

Transition::Transition(string source_state, char read_character, string destination_state, char write_character, direction move_direction) :
	source(source_state),
	read(read_character),
	destination(destination_state),
	write(write_character),
	move(move_direction)
{
}

string Transition::source_state() const
{
	return source;
}

char Transition::read_character() const
{
	return read;
}

string Transition::destination_state() const
{
	return destination;
}

char Transition::write_character() const
{
	return write;
}

direction Transition::move_direction() const
{
	return move;
}