#ifndef Configuration_Settings_H
#define Configuration_Settings_H

class Configuration_Settings
{
private:
	int truncate_int;
	int transitions_int;

public:

	Configuration_Settings();

	void set_truncate(int val);

	int get_truncate();

	void set_transitions(int val);

	int get_transitions();
};

#endif