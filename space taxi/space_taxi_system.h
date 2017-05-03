#ifndef SPCE_TAXI_SYSTEM_H
#define SPCE_TAXI_SYSTEM_H

#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include "galaxy.h"
#include "planet.h"
#include "passenger.h"
#include "trip.h"
#include "driver.h"
#include "vip_driver.h"
#include "address.h"
#include "code.h"
#include "admin.h"

#define ZERO_ASCII 48
#define NINE_ASCII 57



class taxi_system
{
public:
	taxi_system(){admin=new Admin("admin","s3cret");read_spaceship_models();};
	//add discount code
	void register_passenger(std::string username,std::string password,std::string phone_number,std::string code="0");
	void register_driver(std::string _user_name,std::string _password,std::string _spaceship_number,std::string _spaceship_model,std::string _production_year,std::string _color,bool is_vip);
	void login_user(std::string username);
	void logout_user(std::string username);
	void accept_registeration(std::string username);
	void reject_registeration(std::string username);
	void show_registeration_requests();
	int calculate_distance(Address* from,Address* to);
	void genarate_discount_code(std::string username); 
	void read_topology();
	void read_spaceship_models();
	//~taxi_system();
private:
	bool find_username(std::string username);
	bool find_spaceship_number(std::string number);
	bool find_phone_number(std::string phone);
	bool find_code(std::string code);
	bool find_model(std::string model);
	User* find_user(std::string username);
	void delete_driver_registeration(std::string username);
	int credit;
	Admin* admin;
	std::vector<Passenger*> passengers;
	std::vector<Driver*> drivers;
	std::vector<Trip*> trips;
	std::vector<Galaxy*> galaxies;
	std::vector<Code*> codes;
	std::vector<std::string> models;
};

#endif