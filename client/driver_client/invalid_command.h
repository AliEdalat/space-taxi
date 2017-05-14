#ifndef INVALID_COMMAND_H
#define INVALID_COMMAND_H

#include <string>

class invalid_command
{
public:
	invalid_command(std::string _error);
	std::string get_error(){return error;}
private:
	std::string error;
	
};

#endif