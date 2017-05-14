#include "planet.h"

using namespace std;

Planet::Planet(string _name){
	name=_name;
}
void Planet::add_adjacent_planet(Planet* planet){
	planets.push_back(planet);
}