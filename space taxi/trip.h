#ifndef TRIP_H
#define TRIP_H

//#include "passenger.h"
//#include "driver.h"
#include "address.h"
#include "date_time.h"
#include <vector>
#include <iostream>

class Trip
{
public:
	Trip(std::string passenger_username,Address* _source_address,std::vector<Address*> _destinations,int _cost,Date_time* _date_time);
	//void add_driver(Driver* _driver){driver=_driver;}
	bool get_is_accepted(){return accepted;}
	void set_is_accepted(bool status){accepted=status;}
	bool get_is_finished(){return finished;}
	std::string get_model(){return model;}
	bool is_rated(){return rated;}
	Address* get_address(){return source_address;}
	void set_driver_name(std::string username){driver_username=username;}
	std::string get_driver_name(){return driver_username;}
	std::string get_username(){return username;}
	virtual void show_trip_information();
protected:
	Address* source_address;
	std::string username;
	Date_time* date_time;
	std::string driver_username;
	int cost;
	bool accepted;
	bool finished;
	bool rated;
	std::string model;
	std::vector<Address*> destinations;
};

#endif