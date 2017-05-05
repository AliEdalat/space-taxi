#ifndef VIP_TRIP_H
#define VIP_TRIP_H

#include "trip.h"

class Vip_trip
{
public:
	Vip_trip(std::string passenger_username,Address* _source_address,std::vector<Address*> _destinations,int _cost,Date_time* _date_time):Trip(passenger_username,_source_address, _destinations, _cost, _date_time){};
private:
	bool is_vip;	
};

#endif