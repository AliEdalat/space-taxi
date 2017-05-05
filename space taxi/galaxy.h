#ifndef GALAXY_H
#define GALAXY_H

#include "planet.h"
#include <string>
#include <iostream>

class Galaxy
{
public:
	Galaxy(std::string _name);
	std::string get_name(){return name;}
	int calculate_distance(std::string from_planet,std::string to_planet);
	int calculate_distance_to(std::string planet_name);
	bool find_planet(std::string planet_name);
	void add_root(Planet* _root);
	//~Galaxy();
private:
	std::string name;
	Planet* root;
};

#endif