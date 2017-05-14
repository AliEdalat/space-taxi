#include "trip.h"

using namespace std;

Trip::Trip(std::string passenger_username,Address* _source_address,std::vector<Address*> _destinations,int _cost,int _distance,Date_time* _date_time){
	username=passenger_username;
	source_address=_source_address;
	//destinations=_destinations;
	for (int i = 0; i < _destinations.size(); ++i)
	{
		destinations.push_back(_destinations[i]);
	}

	cost=_cost;
	distance=_distance;
	accepted=false;
	date_time=_date_time;
	start_date_time=new Date_time(_date_time->get_date_time());
	end_date_time=new Date_time(_date_time->get_date_time());
	finished=false;
	rated=false;
	model="trip";
	rate=0;
}
string Trip::show_trip_information(){
	string temp=username+' '+source_address->get_galaxy()+','+source_address->get_planet()+' ';
	cout<<username<<' '<<source_address->get_galaxy()<<','<<source_address->get_planet()<<' ';
	for (int i = 0; i < destinations.size(); ++i)
	{
		temp=temp+destinations[i]->get_galaxy()+','+destinations[i]->get_planet()+' ';
		cout<<destinations[i]->get_galaxy()<<','<<destinations[i]->get_planet()<<' ';
	}
	temp=temp+to_string(cost)+' '+to_string(distance);
	cout<<cost<<' '<<distance<<endl;
	return temp;
}
Trip::~Trip(){
	delete date_time;
	delete start_date_time;
	delete end_date_time;
	delete source_address;
	for (int i = 0; i < destinations.size(); ++i)
	{
		delete destinations[i];
	}
	destinations.clear();
}