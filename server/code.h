#ifndef CODE_H
#define CODE_H

#include "passenger.h"
#include <iostream>

class Code
{
public:
	Code(std::string _code,Passenger* _owner);
	std::string get_code(){return code;}
	int get_counter(){return counter;}
	void use_code();
private:
	std::string code;
	int counter=5;
	Passenger* owner;
	
};

#endif