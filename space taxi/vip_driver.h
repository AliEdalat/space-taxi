#ifndef VIP_DRIVER_H
#define VIP_DRIVER_H

#include <iostream>
#include "driver.h"

class Vip_driver:public Driver
{
public:
	Vip_driver(std::string _user_name,std::string _password,std::string spaceship_number,std::string spaceship_model,std::string production_year,std::string color):Driver(_user_name, _password,spaceship_number,spaceship_model,production_year,color){};
	void show_information();
	~Vip_driver();
};

#endif