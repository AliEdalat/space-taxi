#include "trip.h"

using namespace std;

Trip::Trip(std::string passenger_username,Address* _source_address,std::vector<Address*> _destinations,int _cost,Date_time* _date_time){
	username=passenger_username;
	source_address=_source_address;
	//destinations=_destinations;
	for (int i = 0; i < _destinations.size(); ++i)
	{
		destinations.push_back(_destinations[i]);
	}

	cost=_cost;
	accepted=false;
	date_time=_date_time;
	start_date_time=_date_time;
	end_date_time=_date_time;
	finished=false;
	rated=false;
	model="trip";
	rate=0;
}
void Trip::show_trip_information(){
	cout<<username<<' '<<source_address->get_galaxy()<<','<<source_address->get_planet()<<' ';
	for (int i = 0; i < destinations.size(); ++i)
	{
		cout<<destinations[i]->get_galaxy()<<','<<destinations[i]->get_planet()<<' ';
	}
	cout<<cost<<' '<<cost<<endl;
}
