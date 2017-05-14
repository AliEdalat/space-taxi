#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <string>

class Spaceship
{
public:
	Spaceship(std::string _spaceship_number,std::string _spaceship_model,std::string _production_year,std::string _color);
	std::string get_number(){return spaceship_number;}
	std::string get_model(){return spaceship_model;}
	std::string get_production_year(){return production_year;}
	std::string get_color(){return color;}
private:
	std::string spaceship_number;
	std::string spaceship_model;
	std::string production_year;
	std::string color;
};

#endif