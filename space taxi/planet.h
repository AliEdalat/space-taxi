#ifndef PLANET_H
#define PLANET_H

#include <vector>
#include <string>

class Planet
{
public:
	Planet(std::string _name);
	void add_adjacent_planet(Planet* planet);
	std::string get_name(){return name;}
	std::vector<Planet*> get_planets(){return planets;}
	//~Planet();
private:
	std::string name;
	std::vector<Planet*> planets;
};

#endif