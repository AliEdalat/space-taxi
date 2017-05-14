#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <iostream>
#include <vector>
#include "invalid_command.h"

class Command
{
public:
	Command(std::string line);
	std::string get_username(){return username;}
	std::string get_type(){return type;}
	std::string get_parameter(int index){return parameters[index];}
	int get_num_of_parameters(){return parameters.size();}
	int get_num_of_spaces(){return spaces;}
	std::string get_line(){return command_line;}
	~Command();
private:
	std::string username;
	std::string type;
	int spaces;
	std::vector<std::string> parameters;
	std::string command_line;
};

#endif