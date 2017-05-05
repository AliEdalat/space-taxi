#ifndef TRIP_H
#define TRIP_H

//#include "passenger.h"
#include "driver.h"
#include "date_time.h"
#include <vector>

class Trip
{
public:
	Trip(std::string passenger_username,Address* _source_address,std::vector<Address*> _destinations,int _cost,Date_time* _date_time);
	void add_driver(Driver* _driver){driver=_driver;}
private:
	Address* source_address;
	std::string username;
	Date_time* date_time;
	Driver* driver;
	int cost;
	bool accepted;
	std::vector<Address*> destinations;
};

#endif