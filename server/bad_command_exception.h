#ifndef BAD_COMMAND_EXCEPTION_H
#define BAD_COMMAND_EXCEPTION_H

#include <string>

class bad_command_exception
{
public:
	bad_command_exception(std::string _exception);
	std::string get_exception(){return exception;}
private:
	std::string exception;
};

#endif