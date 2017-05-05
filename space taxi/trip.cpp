#include "trip.h"

using namespace std;

Trip::Trip(std::string passenger_username,Address* _source_address,std::vector<Address*> _destinations,int _cost,Date_time* _date_time){
	username=passenger_username;
	source_address=_source_address;
	destinations=_destinations;
	cost=_cost;
	accepted=false;
	date_time=_date_time;
}