#ifndef TRIP_H
#define TRIP_H

#include "passenger.h"
#include <vector>

class Trip
{
public:
	Trip(Passenger* _passenger,Address* _source_address,std::vector<Address*> _destinations);
private:
	Address* source_address;
	Passenger* passenger;
	std::vector<Address*> destinations;
};

#endif