#include "trip.h"

using namespace std;

Trip::Trip(Passenger* _passenger,Address* _source_address,std::vector<Address*> _destinations){
	passenger=_passenger;
	source_address=_source_address;
	destinations=_destinations;
}