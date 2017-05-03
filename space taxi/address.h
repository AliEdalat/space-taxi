#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

class Address
{
public:
	Address(std::string _galaxy,std::string _planet);
	std::string get_galaxy(){return galaxy;}
	std::string get_planet(){return planet;}
	~Address();
private:
	std::string galaxy;
	//Address* adjacent;
	std::string planet;
};

#endif