#ifndef SPCE_TAXI_SYSTEM_H
#define SPCE_TAXI_SYSTEM_H

#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <algorithm>
#include "galaxy.h"
#include "planet.h"
#include "passenger.h"
#include "trip.h"
#include "Vip_trip.h"
#include "driver.h"
#include "vip_driver.h"
#include "address.h"
#include "code.h"
#include "admin.h"
#include "date_time.h"

#define ZERO_ASCII 48
#define NINE_ASCII 57

typedef struct driver_info driver_info;
struct driver_info
{
	Driver* driver;
	int rate;
	int distance;
};


class taxi_system
{
public:
	taxi_system(){date_time=new Date_time("1-00:00:00");admin=new Admin("admin","s3cret",date_time);};
	//add discount code
	void register_passenger(std::string username,std::string password,std::string phone_number,std::string code="0");
	void register_driver(std::string _user_name,std::string _password,std::string _spaceship_number,std::string _spaceship_model,std::string _production_year,std::string _color,bool is_vip);
	void login_user(std::string username , std::string password);
	void logout_user(std::string username);
	void accept_registeration(std::string username);
	void reject_registeration(std::string username);
	void show_registeration_requests();
	int calculate_distance_between(Address* from,Address* to);
	void genarate_discount_code(std::string username); 
	void read_topology();
	void read_spaceship_models();
	void set_status_available(std::string username,Address* address);
	void set_status_unavailable(std::string username);
	void estimate_trip(std::string username,bool is_vip,Address* source_address,std::vector<Address*> destinations);
	void request_trip(std::string username, bool is_vip,Address* source_address,std::vector<Address*> destinations);
	void cancel_trip_request(std::string username);
	void show_trip_requests(std::string username);
	void accept_trip_request(std::string driver_username,std::string passenger_username);
	void trip_status(std::string passenger_username);
	void arrived(std::string driver_username);
	void end_trip(std::string driver_username);
	void rate_driver(std::string username,int rate);
	void charge_account(std::string username,int credit);
	void get_credit(std::string username);
	void set_time(std::string _date_time);
	void passenger_report(std::string username);
	void driver_report(std::string username,std::string from_date,std::string to_date);
	void system_report();
	void system_report_with_date(std::string from_date,std::string to_date);
	void determine_excellent_passengers(Date_time* date_time);
	~taxi_system();
private:
	bool find_username(std::string username);
	bool find_spaceship_number(std::string number);
	bool find_phone_number(std::string phone);
	bool find_code(std::string code);
	bool find_model(std::string model);
	User* find_user(std::string username);
	bool find_address(Address* address);
	Galaxy* find_galaxy(std::string galaxy_name);
	int calculate_cost_of_trip(bool is_vip,bool is_excellent_passenger,Address* source_address,std::vector<Address*> destinations);
	int calculate_length_of_path(Address* source_address,std::vector<Address*> destinations);
	void delete_driver_registeration(std::string username);
	bool send_trip_to_drivers(Trip*& trip);
	void sort_drivers(std::vector<Driver*>& drivers,Address* trip_address);
	void delete_request_in_driver(Trip* trip);
	int system_credit(std::string from_date,std::string to_date);
	int number_of_trips(std::string from_date,std::string to_date);
	int number_of_drivers(std::string from_date,std::string to_date);
	int number_of_passengers(std::string from_date,std::string to_date);
	int credit;
	Date_time* date_time;
	Admin* admin;
	std::vector<Passenger*> passengers;
	std::vector<Driver*> drivers;
	std::vector<Trip*> trips;
	std::vector<Galaxy*> galaxies;
	std::vector<Code*> codes;
	std::vector<std::string> models;
};

#endif