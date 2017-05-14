#ifndef VIP_DRIVER_H
#define VIP_DRIVER_H

#include <iostream>
#include "driver.h"
#include "date_time.h"

class Vip_driver:public Driver
{
public:
	Vip_driver(std::string _user_name,std::string _password,std::string spaceship_number,std::string spaceship_model,std::string production_year,std::string color,Date_time* birth_date):Driver(_user_name, _password,spaceship_number,spaceship_model,production_year,color,birth_date){
		model="vip";
	};
	std::string show_information();
};

#endif